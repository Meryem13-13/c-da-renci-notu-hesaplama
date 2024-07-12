#include <iostream>
#include <cmath>
/****************************************************************************
**					           SAKARYA �N�VERS�TES�
**			          B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				           B�LG�SAYAR M�HEND�SL��� B�L�M�
**				             PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...:   �DEV1
**				��RENC� ADI...............: MARIAM AL REFA�
**				��RENC� NUMARASI.:B221210583
**				DERS GRUBU����:1A
****************************************************************************/


using namespace std;

// A�a��da hem isim hem de soyisim i�in dizi olu�turdum.
string �sim[20] = { "Meryem","Ahmet","Mehmet","Sam,","S�la","�mer","Halid","Hasan","Abdullah","�eyma","Amira","Zeynep","Faruk","An�l","Bet�l","Huda","Selma","S�meyye","Murat","Danya" };
string Soyad[20] = { "Y�lmaz","Kaya","AL Refai","Akg�n","Kara","Osmano�lu","Merto�lu","Ak","Kasap","Ekinci","G�nayd�n","T�rkeri","Aslan","Ceylan","Ar�","Yak�n","Uzak","Eyl�l","Ada" };
string isim() { // isimi rastgele at�yacak bir fonkisyon
	int randd = rand() % 20;
	return �sim[randd];

}
string soyad() {// soyad� rastgele at�yacak bir fonksiyon
	int randd = rand() % 20;
	return Soyad[randd];
}

struct Ogrenci // ��renci isimli bir veri yaps� olu�turdum   // i�inde hem ��renci bilgisi hem de notlar�
{
	string Soyad;
	string �sim;
	int Vize = 0; //vize %30 son notu etkileyecek
	int finaal = 0; // final %40 son notu etkileyecek
	int odev1 = 0;  // odev1 %5 son notu etkileyecek
	int odev2 = 0;  // odev2 %5 son notu etkileyecek
	int k�sas�nav = 0; // k�sas�nav %5 son notu etkileyecek
	int proje = 0;  // proje %15 son notu etkileyecek
	double puan = 0;  // burada 100 �zerinden son notu g�z�kecek;
	string harfnot;
}ogrenc[100];

// a�a��daki fonksiyonda b�t�n notlar� hesaplay�p son notu 100 �zerinden bulacak
double sonnot(double k�sas�navv, double vizee, double finall, double odev11, double odev22, double projee) {
	double nott;
	k�sas�navv = (0.05 * k�sas�navv);
	vizee = (0.3 * vizee);
	finall = (0.4 * finall);
	odev11 = (0.05 * odev11);
	odev22 = (0.05 * odev22);
	projee = (0.15 * projee);
	nott = k�sas�navv + vizee + finall + odev11 + odev22 + projee;
	return nott;


}
string Harf(double Puan) {// harf notuna �eviren fonkisyon
	string harff;
	if (Puan <= 100 && Puan >= 85)
		harff = "AA";

	else if (Puan <= 84 && Puan >= 75)
		harff = "BA";
	else if (Puan <= 74 && Puan >= 65)
		harff = "BB";
	else if (Puan <= 64 && Puan >= 60)
		harff = " CB";
	else if (Puan <= 59 && Puan >= 55)
		harff = "CC";
	else if (Puan <= 54 && Puan >= 50)
		harff = "CD";
	else if (Puan <= 49 && Puan >= 45)
		harff = "DD";
	else if (Puan <= 44 && Puan >= 40)
		harff = "DF";
	else if (Puan <= 39 && Puan >= 0)
		harff = "FF";
	return harff;

}



void dizi(Ogrenci ogrenc[]) { // b�t�n i�lemleri yap�cak fonkisyon

	cout << "*************************��RENC� S�STEM�NE HO�GELD�N�Z*****************************\n";
	cout << "Not=> Burdan Her ��rencinin Notunu Harf Notunu G�rebilirsiniz " << endl;
	cout << " ilk olarak ��renci say�s�n� giriniz => ";
	int s�n�fsay�;
	cin >> s�n�fsay�;
	double ortalama = 0.00;
	int aa, ab, bb, bc, cc, cd, dd, df, ff;
	aa = ab = bb = bc = cc = cd = dd = df = ff = 0;

	double dusuk;
	double yuksek;
	for (int i = 1; i <= s�n�fsay�; i++)
	{
		ogrenc[i].�sim = isim();
		ogrenc[i].Soyad = soyad();
		ogrenc[i].k�sas�nav = rand() % (100 - 0 + 1) + 0;
		ogrenc[i].Vize = rand() % (100 - 0 + 1) + 0;
		ogrenc[i].finaal = rand() % (100 - 0 + 1) + 0;
		ogrenc[i].odev1 = rand() % (100 - 0 + 1) + 0;
		ogrenc[i].odev2 = rand() % (100 - 0 + 1) + 0;
		ogrenc[i].proje = rand() % (100 - 0 + 1) + 0;
		ogrenc[i].puan = sonnot(ogrenc[i].k�sas�nav, ogrenc[i].Vize, ogrenc[i].finaal, ogrenc[i].odev1, ogrenc[i].odev2, ogrenc[i].proje);
		ogrenc[i].harfnot = Harf(ogrenc[i].puan);

		ortalama += (ogrenc[i].puan); // s�n�f�n ortalamas�n� hesaplamak i�in

		if (Harf(ogrenc[i].puan) == "AA")
			aa++;
		else if (Harf(ogrenc[i].puan) == "BA")
			ab++;
		else if (Harf(ogrenc[i].puan) == "BB")
			bb++;
		else if (Harf(ogrenc[i].puan) == "CB")
			bc++;
		else if (Harf(ogrenc[i].puan) == "CC")
			cc++;
		else if (Harf(ogrenc[i].puan) == "DC")
			cd++;
		else if (Harf(ogrenc[i].puan) == "DD")
			dd++;
		else if (Harf(ogrenc[i].puan) == "DF")
			df++;
		else
			ff++;




	}
	ortalama = (ortalama / s�n�fsay�);


	cout << "****************  MENU  ************************ \n";// menuyu olu�turdum 
	cout << "=> ��renci listesi i�in 1 e\n";
	cout << "=> s�n�f�n notlar� i�in 2 e \n";
	cout << "=> s�n�f�n ortalamas� i�in 3 e \n";
	cout << "=> harf notlar� i�in 4 e \n";
	cout << "=> standart sapma i�in 5 e \n";
	cout << "=> her harftan ka� ki�i oldu�unu ��renmek i�in 6 a \n";
	cout << "=> En y�ksek not i�in 7 e \n";
	cout << "=> En d���k not  i�in 8 e \n ";
	cout << "=> Sadece bir ��rencinin b�t�n notlar�n� g�rmek i�in 9 a \n";
	cout << "              BASINIZ           \n";
	double verinokta = 0.0;






	char karar;
	do { // burda i�lemi tekrar yapmak istey�p istemedi�imizi kontrol edicek
		int secmek;
		cin >> secmek;

		switch (secmek)
		{
		case 1:// s�n�f listesini bulma
			for (int i = 1; i <= s�n�fsay�; i++) {
				cout << i << "  Numaral� ��renci => " << ogrenc[i].�sim << "  " << ogrenc[i].Soyad << endl;


			}
			break;
		case 2:// s�n�f�n notlar�n� bulma
			for (int i = 1; i <= s�n�fsay�; i++) {
				cout << i << "  Numaral� ��renci => " << ogrenc[i].�sim << "  " << ogrenc[i].Soyad << " " << ogrenc[i].puan << endl;
			}

			break;
		case 3:// s�n�f�n ortalamas�n� bulma
			cout << " s�n�f�n ortalamas� = " << ortalama << endl;
			break;
		case 4: // ��rencilerin harf notunu yazma
			for (int i = 1; i <= s�n�fsay�; i++) {
				cout << i << "  Numaral� ��renci => " << ogrenc[i].�sim << "  " << ogrenc[i].Soyad << " " << ogrenc[i].puan << "  " << ogrenc[i].harfnot << endl;
			}

			break;
		case 5:// standart sapmay� bulmak

			for (int i = 0; i <= s�n�fsay�; i++) {
				verinokta += ((ortalama - ogrenc[i].puan) * (ortalama - ogrenc[i].puan));

			}
			cout << " STANDART SAPMA = " << sqrt((verinokta / (s�n�fsay� - 1))) << endl;

			break;
		case 6: // harf notuna �evirmek
			cout << "AA harf� alan ki�i say�s� = " << aa << endl;
			cout << "BA harf� alan ki�i say�s� = " << ab << endl;
			cout << "BB harf� alan ki�i say�s� = " << bb << endl;
			cout << "CB harf� alan ki�i say�s� = " << bc << endl;
			cout << "CC harf� alan ki�i say�s� = " << cc << endl;
			cout << "DC harf� alan ki�i say�s� = " << cd << endl;
			cout << "DD harf� alan ki�i say�s� = " << dd << endl;
			cout << "DF harf� alan ki�i say�s� = " << df << endl;
			cout << "FF harf� alan ki�i say�s� = " << ff << endl;



			break;
		case 7:// en y�ksek notu bulmak
			yuksek = ogrenc[1].puan;


			for (int i = 2; i <= s�n�fsay�; i++) {
				if (ogrenc[i].puan > yuksek)
					ogrenc[i].puan = yuksek;
			}
			cout << " En y�ksek not = " << yuksek << endl;
			break;
		case 8://  en d���k notu bulmak
			dusuk = ogrenc[1].puan;
			for (int i = 2; i <= s�n�fsay�; i++) {
				if (ogrenc[i].puan < dusuk)
					ogrenc[i].puan = dusuk;
			}
			cout << " En D���k not = " << dusuk << endl;



			break;
		case 9: // tek bir ��rencinin notlar�n� bulmak
			int x;
			cout << ".........Notlar�n� g�rmek isttedi�iniz ��rencinin numaras�n� giriniz.........." << endl;
			cout << " NUMARA = ";
			cin >> x;
			cout << endl;
			cout << " ��renci Numaras� : " << x << endl;
			cout << " ��renci ismi ve soyismi : " << ogrenc[x].�sim << "  " << ogrenc[x].Soyad << endl;
			cout << " k�sas�nav : " << ogrenc[x].k�sas�nav << endl;
			cout << " �dev1 :  " << ogrenc[x].odev1 << endl;
			cout << " �dev2 : " << ogrenc[x].odev2 << endl;
			cout << "Proje : " << ogrenc[x].proje << endl;
			cout << " Vize : " << ogrenc[x].Vize << endl;
			cout << "Final : " << ogrenc[x].finaal << endl;
			cout << " SON PUAN : " << ogrenc[x].puan << endl;
			cout << "HARF NOTU : " << ogrenc[x].harfnot << endl;


			break;


		default:
			cout << " !!!!!!!!!!!!!!!!!!!!!�YLE B�R SE�ENEK YOK!!!!!!!!!!!!!!!!!!!!!!!\n";
			break;
		}
		cout << " Tekrar Denemek �sterseniz e harfine bas�n�z  ��k�� i�in h harfine bas�n�z \n";
		cin >> karar;
		if (karar == 'e')
			cout << endl << "Tekrar bir say� giriniz yukar�daki menuden\n";
		else if (karar == 'h')
			cout << "------------------------------��LEM B�TT�--------------------------------" << endl;

	} while (karar == 'e');



};
int main() {
	setlocale(LC_ALL, "Turkish");
	srand(time(0));
	// mainde fonksiyonu tan�ma
	dizi(ogrenc);
	cout << "................ ��k�� yap�ld� .................." << endl;


	return 0;
}
