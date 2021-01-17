#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Doamna_Craciun{
	private:
		float s_extra=0;
		float s_total=0;
	public:
		void set_cheltuiala_extra(){
			this->s_extra=numar_carbuni*0.5+numar_acadele;
		}
		//Suma totala va reprezenta numarul de dolari pentru toate cadourile si acadelele plus cat trebuie adaugat
		//pentru carbuni
		void set_cheltuiala_totala(Elfi elfii){
			for(int i=0;i<elfii.get_nr_copii();i++)
			this->s_total+=elfii.get_lista_merit(i);
			this->s_total+=numar_carbuni*0.5;
		}
		float get_cheltuiala_extra(){
			return this->s_extra;
		}
		float get_cheltuiala_totala(){
			return this->s_total;
		}
		void afiseaza_suma_totala(){
			cout<<"Cheltuiala totala este de: "<<get_cheltuiala_totala();
		}
		//In cerinta se mentioneaza ca traseul este primit de doamna craciun si din ordonarea cerintei conclud ca
		//doamna craciun va fi cea care afiseaza pentru toata fabrica drumul mosului
		void afiseaza_traseu(Mos_Craciun mosul){
			cout<<"\nTraseul mosului este: ";
			for(int i=0;i<mosul.get_nr_orase();i++)
			cout<<mosul.get_traseu(i);
			cout<<"\nTot drumul va fi de "<<mosul.get_distanta_parcursa()<<" km";		
		}
		Doamna_Craciun(Elfi elfii){
			set_cheltuiala_extra();
			set_cheltuiala_totala(elfii);
		}
		~Doamna_Craciun(){
		}
};
