#include <iostream>
#include <cmath>
/****************************************************************************
**					           SAKARYA ÜNÝVERSÝTESÝ
**			          BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				           BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				             PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...:   ÖDEV1
**				ÖÐRENCÝ ADI...............: MARIAM AL REFAÝ
**				ÖÐRENCÝ NUMARASI.:B221210583
**				DERS GRUBU…………:1A
****************************************************************************/


using namespace std;

// Aþaðýda hem isim hem de soyisim için dizi oluþturdum.
string Ýsim[20] = { "Meryem","Ahmet","Mehmet","Sam,","Sýla","ömer","Halid","Hasan","Abdullah","Þeyma","Amira","Zeynep","Faruk","Anýl","Betül","Huda","Selma","Sümeyye","Murat","Danya" };
string Soyad[20] = { "Yýlmaz","Kaya","AL Refai","Akgün","Kara","Osmanoðlu","Mertoðlu","Ak","Kasap","Ekinci","Günaydýn","Türkeri","Aslan","Ceylan","Arý","Yakýn","Uzak","Eylül","Ada" };
string isim() { // isimi rastgele atýyacak bir fonkisyon
	int randd = rand() % 20;
	return Ýsim[randd];

}
string soyad() {// soyadý rastgele atýyacak bir fonksiyon
	int randd = rand() % 20;
	return Soyad[randd];
}

struct Ogrenci // öðrenci isimli bir veri yapsý oluþturdum   // içinde hem öðrenci bilgisi hem de notlarý
{
	string Soyad;
	string Ýsim;
	int Vize = 0; //vize %30 son notu etkileyecek
	int finaal = 0; // final %40 son notu etkileyecek
	int odev1 = 0;  // odev1 %5 son notu etkileyecek
	int odev2 = 0;  // odev2 %5 son notu etkileyecek
	int kýsasýnav = 0; // kýsasýnav %5 son notu etkileyecek
	int proje = 0;  // proje %15 son notu etkileyecek
	double puan = 0;  // burada 100 üzerinden son notu gözükecek;
	string harfnot;
}ogrenc[100];

// aþaðýdaki fonksiyonda bütün notlarý hesaplayýp son notu 100 üzerinden bulacak
double sonnot(double kýsasýnavv, double vizee, double finall, double odev11, double odev22, double projee) {
	double nott;
	kýsasýnavv = (0.05 * kýsasýnavv);
	vizee = (0.3 * vizee);
	finall = (0.4 * finall);
	odev11 = (0.05 * odev11);
	odev22 = (0.05 * odev22);
	projee = (0.15 * projee);
	nott = kýsasýnavv + vizee + finall + odev11 + odev22 + projee;
	return nott;


}
string Harf(double Puan) {// harf notuna çeviren fonkisyon
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



void dizi(Ogrenci ogrenc[]) { // bütün iþlemleri yapýcak fonkisyon

	cout << "*************************ÖÐRENCÝ SÝSTEMÝNE HOÞGELDÝNÝZ*****************************\n";
	cout << "Not=> Burdan Her Öðrencinin Notunu Harf Notunu Görebilirsiniz " << endl;
	cout << " ilk olarak öðrenci sayýsýný giriniz => ";
	int sýnýfsayý;
	cin >> sýnýfsayý;
	double ortalama = 0.00;
	int aa, ab, bb, bc, cc, cd, dd, df, ff;
	aa = ab = bb = bc = cc = cd = dd = df = ff = 0;

	double dusuk;
	double yuksek;
	for (int i = 1; i <= sýnýfsayý; i++)
	{
		ogrenc[i].Ýsim = isim();
		ogrenc[i].Soyad = soyad();
		ogrenc[i].kýsasýnav = rand() % (100 - 0 + 1) + 0;
		ogrenc[i].Vize = rand() % (100 - 0 + 1) + 0;
		ogrenc[i].finaal = rand() % (100 - 0 + 1) + 0;
		ogrenc[i].odev1 = rand() % (100 - 0 + 1) + 0;
		ogrenc[i].odev2 = rand() % (100 - 0 + 1) + 0;
		ogrenc[i].proje = rand() % (100 - 0 + 1) + 0;
		ogrenc[i].puan = sonnot(ogrenc[i].kýsasýnav, ogrenc[i].Vize, ogrenc[i].finaal, ogrenc[i].odev1, ogrenc[i].odev2, ogrenc[i].proje);
		ogrenc[i].harfnot = Harf(ogrenc[i].puan);

		ortalama += (ogrenc[i].puan); // sýnýfýn ortalamasýný hesaplamak için

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
	ortalama = (ortalama / sýnýfsayý);


	cout << "****************  MENU  ************************ \n";// menuyu oluþturdum 
	cout << "=> öðrenci listesi için 1 e\n";
	cout << "=> sýnýfýn notlarý için 2 e \n";
	cout << "=> sýnýfýn ortalamasý için 3 e \n";
	cout << "=> harf notlarý için 4 e \n";
	cout << "=> standart sapma için 5 e \n";
	cout << "=> her harftan kaç kiþi olduðunu öðrenmek için 6 a \n";
	cout << "=> En yüksek not için 7 e \n";
	cout << "=> En düþük not  için 8 e \n ";
	cout << "=> Sadece bir öðrencinin bütün notlarýný görmek için 9 a \n";
	cout << "              BASINIZ           \n";
	double verinokta = 0.0;






	char karar;
	do { // burda iþlemi tekrar yapmak isteyýp istemediðimizi kontrol edicek
		int secmek;
		cin >> secmek;

		switch (secmek)
		{
		case 1:// sýnýf listesini bulma
			for (int i = 1; i <= sýnýfsayý; i++) {
				cout << i << "  Numaralý öðrenci => " << ogrenc[i].Ýsim << "  " << ogrenc[i].Soyad << endl;


			}
			break;
		case 2:// sýnýfýn notlarýný bulma
			for (int i = 1; i <= sýnýfsayý; i++) {
				cout << i << "  Numaralý öðrenci => " << ogrenc[i].Ýsim << "  " << ogrenc[i].Soyad << " " << ogrenc[i].puan << endl;
			}

			break;
		case 3:// sýnýfýn ortalamasýný bulma
			cout << " sýnýfýn ortalamasý = " << ortalama << endl;
			break;
		case 4: // öðrencilerin harf notunu yazma
			for (int i = 1; i <= sýnýfsayý; i++) {
				cout << i << "  Numaralý öðrenci => " << ogrenc[i].Ýsim << "  " << ogrenc[i].Soyad << " " << ogrenc[i].puan << "  " << ogrenc[i].harfnot << endl;
			}

			break;
		case 5:// standart sapmayý bulmak

			for (int i = 0; i <= sýnýfsayý; i++) {
				verinokta += ((ortalama - ogrenc[i].puan) * (ortalama - ogrenc[i].puan));

			}
			cout << " STANDART SAPMA = " << sqrt((verinokta / (sýnýfsayý - 1))) << endl;

			break;
		case 6: // harf notuna çevirmek
			cout << "AA harfý alan kiþi sayýsý = " << aa << endl;
			cout << "BA harfý alan kiþi sayýsý = " << ab << endl;
			cout << "BB harfý alan kiþi sayýsý = " << bb << endl;
			cout << "CB harfý alan kiþi sayýsý = " << bc << endl;
			cout << "CC harfý alan kiþi sayýsý = " << cc << endl;
			cout << "DC harfý alan kiþi sayýsý = " << cd << endl;
			cout << "DD harfý alan kiþi sayýsý = " << dd << endl;
			cout << "DF harfý alan kiþi sayýsý = " << df << endl;
			cout << "FF harfý alan kiþi sayýsý = " << ff << endl;



			break;
		case 7:// en yüksek notu bulmak
			yuksek = ogrenc[1].puan;


			for (int i = 2; i <= sýnýfsayý; i++) {
				if (ogrenc[i].puan > yuksek)
					ogrenc[i].puan = yuksek;
			}
			cout << " En yüksek not = " << yuksek << endl;
			break;
		case 8://  en düþük notu bulmak
			dusuk = ogrenc[1].puan;
			for (int i = 2; i <= sýnýfsayý; i++) {
				if (ogrenc[i].puan < dusuk)
					ogrenc[i].puan = dusuk;
			}
			cout << " En Düþük not = " << dusuk << endl;



			break;
		case 9: // tek bir öðrencinin notlarýný bulmak
			int x;
			cout << ".........Notlarýný görmek isttediðiniz öðrencinin numarasýný giriniz.........." << endl;
			cout << " NUMARA = ";
			cin >> x;
			cout << endl;
			cout << " Öðrenci Numarasý : " << x << endl;
			cout << " Öðrenci ismi ve soyismi : " << ogrenc[x].Ýsim << "  " << ogrenc[x].Soyad << endl;
			cout << " kýsasýnav : " << ogrenc[x].kýsasýnav << endl;
			cout << " Ödev1 :  " << ogrenc[x].odev1 << endl;
			cout << " Ödev2 : " << ogrenc[x].odev2 << endl;
			cout << "Proje : " << ogrenc[x].proje << endl;
			cout << " Vize : " << ogrenc[x].Vize << endl;
			cout << "Final : " << ogrenc[x].finaal << endl;
			cout << " SON PUAN : " << ogrenc[x].puan << endl;
			cout << "HARF NOTU : " << ogrenc[x].harfnot << endl;


			break;


		default:
			cout << " !!!!!!!!!!!!!!!!!!!!!ÖYLE BÝR SEÇENEK YOK!!!!!!!!!!!!!!!!!!!!!!!\n";
			break;
		}
		cout << " Tekrar Denemek Ýsterseniz e harfine basýnýz  çýkýþ için h harfine basýnýz \n";
		cin >> karar;
		if (karar == 'e')
			cout << endl << "Tekrar bir sayý giriniz yukarýdaki menuden\n";
		else if (karar == 'h')
			cout << "------------------------------ÝÞLEM BÝTTÝ--------------------------------" << endl;

	} while (karar == 'e');



};
int main() {
	setlocale(LC_ALL, "Turkish");
	srand(time(0));
	// mainde fonksiyonu tanýma
	dizi(ogrenc);
	cout << "................ çýkýþ yapýldý .................." << endl;


	return 0;
}
