#include <iostream>
#include <fstream>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

int satirSayma()
{
    int satirSayisi = 0;
    ifstream file("input.txt");
    string satir;
    while (getline(file, satir))
    {
        satirSayisi++;
    }
    file.close();
    return satirSayisi;
}

int sutunSayma()
{
    int sutunSayisi = 0;
    ifstream file("input.txt");
    file >> sutunSayisi;
    file.close();
    sutunSayisi++;
    return sutunSayisi;
}
std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter))
    {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}
int main()
{
    int i, j, temp, enKucuk;
    string tempString;
    int satirSayisi = satirSayma();
    int sutunSayisi = sutunSayma();
    string dizi[satirSayisi][sutunSayisi];
    int kacinciSatir = 0;
    ifstream file("input.txt");
    string satir;

    while (getline(file, satir))
    {
        std::vector<std::string> parcalananString = split(satir, ',');
        for (int i = 0; i < parcalananString.size(); i++)
            dizi[kacinciSatir][i] = parcalananString[i];
        kacinciSatir++;
    }
    file.close();
    string ogrenciID[satirSayisi - 2];
    int puanlar[satirSayisi - 2];
    for (i = 0; i < (satirSayisi - 2); i++)
    {
        ogrenciID[i] = dizi[i + 2][0];
        puanlar[i] = 0;
    }

    //int puan[satirSayisi - 2][2]
    //cout << "Satir sayisi: " << satirSayisi << " Sutun sayisi: " << sutunSayisi << endl;
    for (i = 2; i < satirSayisi; i++)
    {
        for (j = 1; j < sutunSayisi; j++)
        {
            if (dizi[i][j] == dizi[1][j - 1])
            {
                puanlar[i - 2] += 4;
            }
            else if (dizi[i][j] == "")
            {
                puanlar[i - 2] += 0;
            }
            else
            {
                puanlar[i - 2] -= 1;
            }
        }
    }
    
    //Selection sort siralama
    for (i = 0; i < (satirSayisi - 2) - 1; i++)
    {
        enKucuk = i;
        for (j = i + 1; j < (satirSayisi - 2); j++)
        {
            if (puanlar[j] > puanlar[enKucuk])
                enKucuk = j;
        }
        temp = puanlar[i];
        tempString = ogrenciID[i];
        puanlar[i] = puanlar[enKucuk];
        ogrenciID[i] = ogrenciID[enKucuk];
        puanlar[enKucuk] = temp;
        ogrenciID[enKucuk] = tempString;
    }
    
    int eDN,eBN,acik,top=0,pos;
    double ort,med;
    eDN = puanlar[satirSayisi-3];
    eBN = puanlar[0];
    for (i = 0; i < (satirSayisi - 2); i++)
    {
    	top += puanlar[i];
	}
	ort=top/(satirSayisi-2);
	if ((satirSayisi-2)%2==1)
	{
		pos = (satirSayisi-1)/2;
		med = puanlar[pos];
	} else 
	{
		pos = (satirSayisi-2)/2;
		med = (puanlar[pos-1]+puanlar[pos])/2;	
	}
	acik=eBN-eDN;
    
    ofstream fileW;
    fileW.open("output.txt");
    for (i = 0; i < (satirSayisi - 2); i++)
    {
        fileW << "Ogrenci: " << ogrenciID[i] << " Puan: " << puanlar[i] << endl;
    }
   	fileW << eDN << ",";
    fileW << eBN << ",";
    fileW << ort << ",";
    fileW << med << ",";
	fileW << acik << endl; 
	fileW.close();
}




//https://www.selimsilgu.com/2016/07/algoritma-ve-programlama.html
//http://www.oguzozkeroglu.com/siralama-algoritmalari-1-selection-sort/
//https://thispointer.com/how-to-split-a-string-in-c/
//https://www.youtube.com/watch?v=E-6ZvxCzqcU
//https://www.youtube.com/watch?v=UpQdjipl2OE&list=PLIHume2cwmHfmSmNlxXw1j9ZAKzYyiQAq
//https://www.youtube.com/watch?v=hhTZuWhYSkQ



