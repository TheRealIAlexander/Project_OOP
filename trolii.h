#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

int numar_ambalaje_baieti=0;
int numar_ambalaje_fete=0;
int numar_carbuni=0;

class Troli{
	public:
		//Primesc nr cadourilor si se uita daca copil a carei lista o au e fata sau baiat; Decit ce ambalaj
		//sa foloseasca si cresc countarul pentru acel ambalaj; Tot aici se noteaza cati carbuni sa se adauge
		void impacheteaza(Elfi elfii,Copil copil,int nr_copil){ 
			if(copil.get_culoare()=='a')
			{
				if(elfii.get_lista_merit(nr_copil)==10)
				{
					numar_ambalaje_baieti+=(1+elfii.get_numar_lista_cadouri());
					numar_carbuni+=1;
					elfii.set_lista_cadouri("carbune");
				}
				else numar_ambalaje_baieti+=elfii.get_numar_lista_cadouri();
			}
			else
			{
				if(elfii.get_lista_merit(nr_copil)==10)
				{
					numar_ambalaje_fete+=(1+elfii.get_numar_lista_cadouri());
					numar_carbuni+=1;
					elfii.set_lista_cadouri("carbune");
				}
				else 	numar_ambalaje_fete+=elfii.get_numar_lista_cadouri();
			}
		}
		void afiseaza_cate_ambalaje(){
			cout<<"\nTrolii au folosit "<<numar_ambalaje_baieti<<" ambalaje pentru cadouri la baieti";
			cout<<"\nTrolii au folosit "<<numar_ambalaje_baieti<<" ambalaje pentru cadouri la fetite";
		}
		Troli(){
		}
		~Troli(){
		}

};
