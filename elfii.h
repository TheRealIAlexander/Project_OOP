#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

int numar_acadele=0;

class Elfi{
	private:
	int nr_copii;
	int *lista_merit;
	//Declararea statica nu e recomandata si da alerte
	string atelier[14]={"titirez","masina","motoreta","pusca","lego","tren","avion","papusa","set de masa",
	"set de unghii","casa de papusi","set de gatit","margele","catel de plus"};
	int pret_jucarii[14]={10,40,35,60,80,80,60,50,50,30,90,60,10,70};
	string jucarie_standard_bun="urs de plus";
	string jucarie_standard_rau="spinner";
	int jucarie_standard_bun_pret=100;
	int jucarie_standard_rau_pret=10;
	int numar_lista_cadouri=1;
	vector<string> lista_cadouri;
	int numar_orase;
	vector<string>lista_orase;
	vector<float>coordonate_orase;
	public:
	void set_lista_merit(int x){
		this->nr_copii=x;
		srand(nr_copii);
		lista_merit= new(nothrow)int[x];
		for(int i=0;i<nr_copii;i++)
		{
		if(rand()%2==0)  //Am ales generarea random a listei de copii buni sau rai
		lista_merit[i]=100;
		else lista_merit[i]=10;
		}
	}
	void set_lista_cadouri(string x)
	{
		this->lista_cadouri.push_back(x);
	}
	void set_numar_orase(int x){
		this->numar_orase=x;
	}
	void set_lista_orase(string x)
	{
		this->lista_orase.push_back(x);
	}
	void set_coordonate_orase(float y,float x){
		this->coordonate_orase.push_back(y);
		this->coordonate_orase.push_back(x);
	}
	string get_lista_cadouri(int x){
		return this->lista_cadouri[x];
	}
	string get_lista_orase(int x){
		return this->lista_orase[x];
	}
	float get_coordonate_orase(int x){
		return this->coordonate_orase[x];
	}
	int get_nr_copii(){
		return this->nr_copii;
	}
	int get_numar_orase(){
		return this->numar_orase;
	}
	int get_numar_lista_cadouri(){
		return this->numar_lista_cadouri;
	}
	int get_lista_merit(int x){
		return this->lista_merit[x];
	}
	Elfi(int x){         //constructorul va primi numarul de copii care este egal cu nr de orase
		set_lista_merit(x);
		set_numar_orase(x+1);
		set_lista_orase("Rovaniemi"); //primul oras de pe lista mosului va fi orsaul din care acesta pleaca
		set_coordonate_orase(66.503944,25.729391); //coordonatele orasului
	}
	void pick_cadouri(Copil copil,int numar_copil){
	//	this->lista_cadouri.clear();  //Odata ce afisam cadourile fiecarui copil si trimitem numarul lor trolilor am
		this->numar_lista_cadouri=1;  //aleg sa scriu peste lista, intrucat nu ne mai trebuie in memorie cadourile
		int buget=lista_merit[numar_copil]; //fiecarui copil in parte; ele pot fi vazute la afisare
		for(int i=0;i<14;i++)
		{
			for(int j=0;j<copil.get_size_wishlist();j++)
			{
				if(copil.get_wishlist(j)==atelier[i])
				{
					if(buget-pret_jucarii[j]>0)
					{
						set_lista_cadouri(atelier[i]);//Cand gasim un cadou il trimited in lista si reglam bugetul
						buget=buget-pret_jucarii[j];
						this->numar_lista_cadouri++;
					}
					
				}
			}
		}
		if(lista_cadouri.empty()==true) //Verificam daca am putut sau nu adauga cadouri din atelier
		{
			if(lista_merit[numar_copil]==100)
			{
				set_lista_cadouri(jucarie_standard_bun); 
				buget=0;
			}
			if(lista_merit[numar_copil]==10)
			{
				set_lista_cadouri(jucarie_standard_rau);
				buget=0;
			}
		}
		numar_acadele=numar_acadele+ buget; //facem update la numarul de acadele
	}
	void pick_orase(Copil copil){ //Copil cu copil incarcam in lista orsaul lor si coordonatele
		set_lista_orase(copil.get_oras_nat());
		set_coordonate_orase(copil.get_oras_lat(),copil.get_oras_lon()); 
	}
	void afisare_cadouri(Copil copil ){ //O afisare usor personalizata pentru copii
		if(copil.get_culoare()=='a')
		{
			cout<<"\nMicutul "<<copil.get_nume()<<" a primit: ";
			for(int i=0;i<numar_lista_cadouri;i++)
			cout<<get_lista_cadouri(i)<<" ";
		}
		else
		{
			cout<<"\nMicuta "<<copil.get_nume()<<" a primit: ";
			for(int i=0;i<numar_lista_cadouri;i++)
			cout<<get_lista_cadouri(i)<<" ";
		}
	}
	~Elfi(){
		delete lista_merit;
		delete atelier;
		delete pret_jucarii;
		lista_cadouri.clear();
		lista_orase.clear();
		coordonate_orase.clear();
	}
		
	friend class Troli;	//Folosesc friend class aici. Nu vad de ce ar trebui sa generez clase copil pentru elfi
	friend class Doamna_Craciun;//Mi s-a parut mai curat sa lucrez astfel si cu mai putina memorie
	friend class Mos_Craciun;
};

