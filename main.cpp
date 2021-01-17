#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include"copii.h"
#include"elfii.h"
#include"trolii.h"
#include"mos_craciun.h"
#include"doamna_craciun.h"


using namespace std;


int main()
{	
	int nr_copii;
	cout<<"Introduceti numarul de copii: ";
	cin>>nr_copii;
	Copil lista_copii[nr_copii];
	for(int i=0;i<nr_copii;i++)//Optiunea de creare a listei de copii folosing o functie pentru realocare
	{
		string a,b,d;
		string e[10];
		int c,f;
		float x,y;
		string g;
		cout<<"\nIntroduceti numele si prenumene copilului "<<i+1<<", urmat de varsta acestuia:  ";
		cin>>a>>b>>c;
		cout<<"\nIntroduceti orasul natal: ";
		cin>>d;
		cout<<"\nIntroduceti latitudinea si longitudinea orasului natal( tip GSC): ";
		cin>>x>>y;
		cout<<"\nCate cadouri isi doreste copilul: ";
		cin>>f;
		cout<<"\nCare sunt aceste cadouri: ";
		for(int j=0;j<f;j++)
		cin>>e[j];
		cout<<"\nEste cumva baietel? (raspundeti cu da sau nu)";
			cin>>g;
			if(g=="da")
			lista_copii[i].generate_child(a,b,c,d,x,y,e,f,'a');
			if(g=="nu")
			lista_copii[i].generate_child(a,b,c,d,x,y,e,f,'r');
	}

	Elfi elfii(nr_copii);   //Aici cream elfii care au evidenta copiilor, ei vor calcula informatia relevanta
	Troli trolii;//Trolii sunt gata aici sa primeasca cadouri

	for(int i=0;i<nr_copii;i++)
	{
		elfii.pick_cadouri(lista_copii[i],i);//Generam pentru copii lista de cadouri
		elfii.pick_orase(lista_copii[i]);//Introducem copilul in lista de livrare
		{
			elfii.afisare_cadouri(lista_copii[i]);//Afisam cadourile alese
			trolii.impacheteaza(elfii,lista_copii[i],i);//Trimitem trolilor cadourile sa le poata impacheta
		}
	}
	//Dupa ce am trecut de procesul de alegere si ambalare; am facut lista de orase si am afisat cadourile
	Mos_Craciun mosul(elfii); //Mosul va calcula ruta cea mai buna(Stim ca nu ne intoarcem de la punctul de plecare)
	Doamna_Craciun doamna(elfii); //Doamna craciun calculeaza bugetul si primeste traseul de la mos
	trolii.afiseaza_cate_ambalaje(); //Trolii vor afisa numarul de pachete folosit
	doamna.afiseaza_suma_totala(); //Doamna Craciun va afisa cheltuiala facuta
	doamna.afiseaza_traseu(mosul);//Doamna Craciun va afisa atelierului trasel mosului pentru diseara

	for(int i=0;i<nr_copii;i++)
	{
	lista_copii[i].show_copii();
	cout<<endl;
	}
	return 0;
}
