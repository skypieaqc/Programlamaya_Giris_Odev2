/********************************************************************************************
**					          SAKARYA ÜNİVERSİTESİ										   **
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ							   **
**				         BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ									   **
**				          PROGRAMLAMAYA GİRİŞİ DERSİ									   **
**																						   **
**				            ÖDEV NUMARASI: 2. Ödev										   **
**				            ÖĞRENCİ ADI: AHMET YUNUS ÇAVUŞ								   **
**				            ÖĞRENCİ NUMARASI: B221210082								   **
**				            DERS GRUBU: 1. Öğretim A									   **
*********************************************************************************************/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

class KarmasikSayi
{
private:
	double sanal;
	double reel;
public:
	KarmasikSayi(double r, double s)
	{
		sanal = s;
		reel = r;
	}

	KarmasikSayi()
	{
		sanal = 0;
		reel = 0;
	}

	void setKarmasikSayi()
	{
		double r, s;
		cout << endl;
		cout << "Karmasik Sayinizin reel kismini giriniz: ";
		cin >> r;

		cout << "Karmasik Sayinizin sanal kismini giriniz: ";
		cin >> s;

		cout << endl;
		reel = r;
		sanal = s;
	}

	double getsanal()
	{
		return sanal;
	}

	double getreel()
	{
		return reel;
	}

	void print()
	{
		if (sanal > 0)				//Sanal kisim 0dan buyuk ise normal sekilde karmasik sayi yazdirilir.
			cout << '(' << reel << " + " << sanal << "i" << ')';
		else if (sanal == 0)		//Sanal kisim 0a esik ise sadece reel kisim yazdirilir.
			cout << reel;
		else						//sanal kisim 0dan kucuk ise guzel gozukmesi icin duzenleme yaparak yazdirilir.
			cout << '(' << reel << " - " << -sanal << "i" << ')';
	}

	void kutupsalgosterim()
	{
		double pi = 3.14159;
		double degree, hipotenus;

		hipotenus = sqrt((reel * reel) + (sanal * sanal));

		if (reel >= 0 && sanal >= 0)						//nokta grafikte 1. bolgede ise arctan ve geometri yardimi ile acisi bulunur.
			degree = (atan(sanal / reel) * 180 / pi);

		else if (reel <= 0 && sanal >= 0)					//nokta grafikte 2. bolgede ise arctan ve geometri yardimi ile acisi bulunur. 
		{
			degree = (atan(sanal / -reel) * 180 / pi);
			degree = 180 - degree;
		}
		else if (reel <= 0 && sanal <= 0)					//nokta grafikte 3. bolgede ise arctan ve geometri yardimi ile acisi bulunur.
		{
			degree = (atan(sanal / reel) * 180 / pi);
			degree = 180 + degree;
		}
		else if (reel >= 0 && sanal <= 0)					//nokta grafikte 4. bolgede ise arctan ve geometri yardimi ile acisi bulunur.	
		{
			degree = (atan(-sanal / reel) * 180 / pi);
			degree = 360 - degree;
		}

		cout << "z = " << hipotenus << " x (cos" << degree << " + i x sin" << degree << ")\tVEYA\t" << "z = " << hipotenus << " x cis" << degree << endl;
	}

	KarmasikSayi operator+ (KarmasikSayi sayi2)
	{
		KarmasikSayi sonuc;

		sonuc.reel = reel + sayi2.reel;

		sonuc.sanal = sanal + sayi2.sanal;

		return sonuc;
	}

	KarmasikSayi operator- (KarmasikSayi sayi2)
	{
		KarmasikSayi sonuc;

		sonuc.reel = reel - sayi2.reel;

		sonuc.sanal = sanal - sayi2.sanal;

		return sonuc;
	}

	KarmasikSayi operator* (KarmasikSayi sayi2)
	{
		KarmasikSayi sonuc;

		sonuc.reel = (reel * sayi2.reel) - (sanal * sayi2.sanal);

		sonuc.sanal = (reel * sayi2.sanal) + (sanal * sayi2.reel);

		return sonuc;
	}

	KarmasikSayi operator/ (KarmasikSayi sayi2)
	{
		KarmasikSayi sonuc;
		KarmasikSayi pay, payda;

		pay.reel = (reel * sayi2.reel) - (sanal * (-sayi2.sanal));
		pay.sanal = (reel * (-sayi2.sanal)) + (sanal * (sayi2.reel));

		payda.reel = (sayi2.reel * sayi2.reel) - (sayi2.sanal * (-sayi2.sanal));
		payda.sanal = (sayi2.reel * (-sayi2.sanal)) + (sayi2.sanal * sayi2.reel);

		sonuc.reel = pay.reel / payda.reel;
		sonuc.sanal = pay.sanal / payda.reel;

		return sonuc;
	}

	void operator+= (KarmasikSayi sayi2)
	{
		reel = reel + sayi2.reel;
		sanal = sanal + sayi2.sanal;
	}

	void operator-= (KarmasikSayi sayi2)
	{
		reel = reel - sayi2.reel;
		sanal = sanal - sayi2.sanal;
	}

	void operator*= (KarmasikSayi sayi2)
	{
		reel = reel * sayi2.reel - sanal * sayi2.sanal;
		sanal = reel * sayi2.sanal + sanal * sayi2.reel;
	}

	void operator/= (KarmasikSayi sayi2)
	{
		KarmasikSayi pay, payda, sonuc;

		pay.reel = (reel * sayi2.reel) - (sanal * (-sayi2.sanal));
		pay.sanal = (reel * (-sayi2.sanal)) + (sanal * (sayi2.reel));

		payda.reel = (sayi2.reel * sayi2.reel) - (sayi2.sanal * (-sayi2.sanal));
		payda.sanal = (sayi2.reel * (-sayi2.sanal)) + (sayi2.sanal * sayi2.reel);

		sonuc.reel = pay.reel / payda.reel;
		sonuc.sanal = pay.sanal / payda.reel;

		reel = sonuc.reel;
		sanal = sonuc.sanal;
	}
};

int main()
{
	KarmasikSayi sayi1, sayi2, sayi3, sonuc;

	cout << "Karmasik sayilarda islem yapma makinesine hosgeldin.\n\n";

	cout << "Islem yapmak istedigin karmasik sayilari sirayla giriniz.\n\n1.Karmasik Sayinizi giriniz.";
	sayi1.setKarmasikSayi();

	cout << "2.Karmasik Sayinizi giriniz.";
	sayi2.setKarmasikSayi();

	char islem, devam;
	do
	{
		cout << "----------------------Islem listesi--------------------\n\n";
		cout << "1.Karmasik Sayi = ";
		sayi1.print();
		cout << "\t 2.Karmasik Sayi = ";
		sayi2.print();
		cout << endl << endl;
		cout << "1.Toplama islemi \n";
		cout << "2.Cikarma islemi \n";
		cout << "3.Carpma islemi \n";
		cout << "4.Bolme islemi \n";
		cout << "5.Sectigin sayiya ekleme yapma islemi \n";
		cout << "6.Sectigin sayiya cikarma yapma islemi \n";
		cout << "7.Sectigin sayiyi bir sayiyla carpma islemi \n";
		cout << "8.Sectigin sayiyi bir sayiyla bolme islemi \n";
		cout << "9.Sectigin sayiyi kutupsal gosterimi \n";

		do
		{
			cout << "Yapmak istediginiz islemi tuslayiniz.";
			islem = _getch();
			cout << endl << endl;

			if (!(islem == '1' || islem == '2' || islem == '3' || islem == '4' || islem == '5' || islem == '6' || islem == '7' || islem == '8' || islem == '9'))	//Islem 1ile9 arasinda degil ise kullanici uyarilir
				cout << "Lutfen gecerli bir islem seciniz!\n";

		} while (!(islem == '1' || islem == '2' || islem == '3' || islem == '4' || islem == '5' || islem == '6' || islem == '7' || islem == '8' || islem == '9'));	//Islem 1ile9 arasinda degil ise secim tekrarlanir

		switch (islem)		//Kullanicinin sectigi islem gerceklestirilir
		{
		case '1':
			sonuc = sayi1 + sayi2;

			sayi1.print();
			cout << " + ";
			sayi2.print();
			cout << " = ";
			sonuc.print();
			cout << endl << endl;
			break;

		case '2':
			sonuc = sayi1 - sayi2;

			sayi1.print();
			cout << " - ";
			sayi2.print();
			cout << " = ";
			sonuc.print();
			cout << endl << endl;
			break;

		case '3':
			sonuc = sayi1 * sayi2;

			sayi1.print();
			cout << " * ";
			sayi2.print();
			cout << " = ";
			sonuc.print();
			cout << endl << endl;
			break;

		case '4':
			sonuc = sayi1 / sayi2;

			sayi1.print();
			cout << " / ";
			sayi2.print();
			cout << " = ";
			sonuc.print();
			cout << endl << endl;
			break;

		case '5':
			char secim1;

			//Kullanicin gecerli sayiyi secmesi saylanir.
			do
			{
				cout << "Ekleme yapmak istedigin sayiyi sec. (1 veya 2)\n";

				cout << "Sayi 1: ";
				sayi1.print();

				cout << "\t Sayi 2: ";
				sayi2.print();

				secim1 = _getch();
				cout << endl << endl;

				if (!(secim1 == '1' || secim1 == '2'))
					cout << "Lutfen gecerli bir sayi seciniz!\n";

			} while (!(secim1 == '1' || secim1 == '2'));

			//Kullanici 1'i sectiyse 1e gore islemler gerceklesir.
			if (secim1 == '1')
			{
				cout << "Sayi 1'e eklemek istediginiz sayiyinin kisimlarini sirasiyla giriniz.\n";
				sayi3.setKarmasikSayi();

				sayi1.print();

				cout << " + ";

				sayi3.print();

				cout << " = ";

				sayi1 += sayi3;
				sayi1.print();

				cout << "\n1.Sayinin yeni hali = ";
				sayi1.print();

				cout << "\n\n";
			}
			//Kullanici 2'yi sectiyse 1e gore islemler gerceklesir.
			else
			{
				cout << "Sayi 2'e eklemek istediginiz sayiyinin kisimlarini sirasiyla giriniz.\n";
				sayi3.setKarmasikSayi();

				sayi2.print();

				sayi2 += sayi3;

				cout << " + ";

				sayi3.print();

				cout << " = ";

				sayi2.print();

				cout << "\n2.Sayinin yeni hali = ";
				sayi2.print();

				cout << "\n\n";
			}
			break;

		case '6':
			char secim2;

			//Kullanicin gecerli sayiyi secmesi saylanir.
			do
			{
				cout << "Cikarma yapmak istedigin sayiyi sec. (1 veya 2)\n";

				cout << "Sayi 1: ";
				sayi1.print();

				cout << "\t Sayi 2: ";
				sayi2.print();

				secim2 = _getch();
				cout << endl << endl;

				if (!(secim2 == '1' || secim2 == '2'))
					cout << "Lutfen gecerli bir sayi seciniz!\n";

			} while (!(secim2 == '1' || secim2 == '2'));

			//Kullanici 1'i sectiyse 1e gore islemler gerceklesir.
			if (secim2 == '1')
			{
				cout << "Sayi 1'den cikartmak istediginiz sayiyinin kisimlarini sirasiyla giriniz.\n";
				sayi3.setKarmasikSayi();

				sayi1.print();

				sayi1 -= sayi3;

				cout << " - ";

				sayi3.print();

				cout << " = ";

				sayi1.print();

				cout << "\n1.Sayinin yeni hali = ";
				sayi1.print();

				cout << "\n\n";
			}
			//Kullanici 2'yi sectiyse 1e gore islemler gerceklesir.
			else
			{
				cout << "Sayi 2'den cikarmak istediginiz sayiyinin kisimlarini sirasiyla giriniz.\n";
				sayi3.setKarmasikSayi();

				sayi2.print();

				sayi2 -= sayi3;

				cout << " - ";

				sayi3.print();

				cout << " = ";

				sayi2.print();

				cout << "\n2.Sayinin yeni hali = ";
				sayi2.print();

				cout << "\n\n";
			}
			break;

		case '7':
			char secim3;

			//Kullanicin gecerli sayiyi secmesi saylanir.
			do
			{
				cout << "Carpma yapmak istedigin sayiyi sec. (1 veya 2)\n";

				cout << "Sayi 1: ";
				sayi1.print();

				cout << "\t Sayi 2: ";
				sayi2.print();

				secim3 = _getch();
				cout << endl << endl;

				if (!(secim3 == '1' || secim3 == '2'))
					cout << "Lutfen gecerli bir sayi seciniz!\n";

			} while (!(secim3 == '1' || secim3 == '2'));

			//Kullanici 1'i sectiyse 1e gore islemler gerceklesir.
			if (secim3 == '1')
			{
				cout << "Sayi 1'i carpmak istediginiz sayiyinin kisimlarini sirasiyla giriniz.\n";
				sayi3.setKarmasikSayi();

				sayi1.print();

				sayi1 *= sayi3;

				cout << " * ";

				sayi3.print();

				cout << " = ";

				sayi1.print();

				cout << "\n1.Sayinin yeni hali = ";
				sayi1.print();

				cout << "\n\n";
			}
			//Kullanici 2'yi sectiyse 1e gore islemler gerceklesir.
			else
			{
				cout << "Sayi 2'yi carpmak istediginiz sayiyinin kisimlarini sirasiyla giriniz.\n";
				sayi3.setKarmasikSayi();

				sayi2.print();

				sayi2 *= sayi3;

				cout << " * ";

				sayi3.print();

				cout << " = ";

				sayi2.print();

				cout << "\n2.Sayinin yeni hali = ";
				sayi2.print();

				cout << "\n\n";
			}
			break;

		case '8':
			char secim4;

			//Kullanicin gecerli sayiyi secmesi saylanir.
			do
			{
				cout << "Bolme yapmak istedigin sayiyi sec. (1 veya 2)\n";

				cout << "Sayi 1: ";
				sayi1.print();

				cout << "\t Sayi 2: ";
				sayi2.print();

				secim4 = _getch();
				cout << endl << endl;

				if (!(secim4 == '1' || secim4 == '2'))
					cout << "Lutfen gecerli bir sayi seciniz!\n";

			} while (!(secim4 == '1' || secim4 == '2'));

			//Kullanici 1'i sectiyse 1e gore islemler gerceklesir.
			if (secim4 == '1')
			{
				cout << "Sayi 1'i bolmek istediginiz sayiyinin kisimlarini sirasiyla giriniz.\n";
				sayi3.setKarmasikSayi();

				sayi1.print();

				sayi1 /= sayi3;

				cout << " / ";

				sayi3.print();

				cout << " = ";

				sayi1.print();

				cout << "\n1.Sayinin yeni hali = ";
				sayi1.print();

				cout << "\n\n";
			}
			//Kullanici 2'yi sectiyse 1e gore islemler gerceklesir.
			else
			{
				cout << "Sayi 2'yi bolmek istediginiz sayiyinin kisimlarini sirasiyla giriniz.\n";
				sayi3.setKarmasikSayi();

				sayi2.print();

				sayi2 /= sayi3;

				cout << " / ";

				sayi3.print();

				cout << " = ";

				sayi2.print();

				cout << "\n2.Sayinin yeni hali = ";
				sayi2.print();

				cout << "\n\n";
			}
			break;

		case '9':
			char secim5;

			//Kullanicin gecerli sayiyi secmesi saylanir.
			do
			{
				cout << "Kutupsal gosterimini yapmak istedigin sayiyi sec. (1 veya 2)\n";

				cout << "Sayi 1: ";
				sayi1.print();

				cout << "\t Sayi 2: ";
				sayi2.print();

				secim5 = _getch();
				cout << endl << endl;

				if (!(secim5 == '1' || secim5 == '2'))
					cout << "Lutfen gecerli bir sayi seciniz!\n";

			} while (!(secim5 == '1' || secim5 == '2'));

			//Kullanici 1'i sectiyse 1e gore islemler gerceklesir.
			if (secim5 == '1')
			{
				cout << "1.Sayinin kutupsal gosterimi --> ";
				sayi1.kutupsalgosterim();
			}
			//Kullanici 2'yi sectiyse 1e gore islemler gerceklesir.
			else
			{
				cout << "2.Sayinin kutupsal gosterimi --> ";
				sayi2.kutupsalgosterim();
			}
			break;
		}

		//Programdan cikmak isteyip istemeyecegini kullaniciya soruyoruz.Cevabina gore program kapanir.
		do
		{
			cout << "Islem yapmaya devam etmek ister misin (E/H): ";
			devam = _getch();

			if ((devam != 'e' && devam != 'E') && (devam != 'H' && devam != 'h'))
				cout << "Lutfen E/e veya H/h tuslarini tuslayin aksi halde devam edemezsiniz.\n";

		} while (devam != 'e' && devam != 'E' && devam != 'H' && devam != 'h');

		system("cls");		//Kullaniciya daha guzel goruntu sunmak icin ekrani her islemden sonra siler.

	} while ((devam == 'E' || devam == 'e'));

	//Kullanici programdan cikmak isterse guzel bir veda ile ayrilir.
	if (devam == 'h' || devam == 'H')
	{
		cout << "Tekrar gorusmek uzere bay bay :)";
		Sleep(1000);
	}
	return 0;
}