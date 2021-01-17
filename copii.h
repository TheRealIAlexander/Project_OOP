#include<iostream>
#include<string.h>

using namespace std;

class Copil{
	private:
		string nume;
		string prenume;
		int varsta;
		string oras_nat;
		float oras_lat;
		float oras_lon;
		string* wishlist;
		int size_wishlist;
		char culoare;
	public:
		void set_nume(string x){
			this->nume=x;
		}
		void set_prenume(string x){
			this->prenume=x;
		}
		void set_varsta(int x){
			this->varsta=x;
		}
		void set_oras_nat(string x){
			this->oras_nat=x;
		}
		void set_pozitie(float x,float y){
			this->oras_lat=x;
			this->oras_lon=y;
		}
		void set_wishlist(string* x,int f){
			this->size_wishlist=f;
			wishlist= new(nothrow)string[f];
			for(int i=0;i<f;i++)
        	wishlist[i] = x[i];
		}
		void set_culoare(char x){
			if(x=='a' || x=='r')
			this->culoare=x;
		}
		string get_nume(){
			return this->nume;
		}
		string get_prenume(){
			return this->prenume;
		}
		int get_varsta(){
			return this->varsta;
		}
		string get_oras_nat(){
			return this->oras_nat;
		}
		float get_oras_lon(){
			return this->oras_lon;
		}
		float get_oras_lat(){
			return this->oras_lat;
		}
		string  get_wishlist(int x){
			return this->wishlist[x];
		}
		int get_size_wishlist(){
			return this->size_wishlist;
		}
		char get_culoare(){
			return this->culoare;
		}
		Copil(){
		}
		Copil(string a, string b, int c, string d,float x,float y, string e[], int f,char g){
			set_nume(a);
			set_prenume(b);
			set_varsta(c);
			set_oras_nat(d);
			set_pozitie(x,y);
			set_wishlist(e,f);
			set_culoare(g);
		}
		void generate_child(string a, string b, int c, string d,float x,float y, string e[], int f,char g){
			set_nume(a);
			set_prenume(b);
			set_varsta(c);
			set_oras_nat(d);
			set_pozitie(x,y);
			set_wishlist(e,f);
			set_culoare(g);
		}
		void show_copii(){
			cout<<get_nume()<<" ";
			cout<<get_prenume()<<" ";
			cout<<get_varsta()<<" ";
			int aux=get_size_wishlist();
			cout<<"isi doreste: ";
			for(int i=0;i<aux;i++)
			cout<<get_wishlist(i)<<" ";
			if(get_culoare()=='a')
			cout<<" Baietel"<<endl;
			else cout<<" Fetita"<<endl;
		}
		~Copil(){
			delete []wishlist;
		}
		friend class Elfi;
		friend class Troli;
};
