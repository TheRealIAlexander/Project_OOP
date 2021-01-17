#include<iostream>
#include<string.h>
#include<vector>
#include<math.h>

using namespace std;

class Mos_Craciun{
	private:
		int nr_orase=0;
		float **matrix;
		vector<string>traseu;
		float distanta_parcursa=0;
	public:
		//Aici am vrut sa putem introduce si calcula pentru orice adesa,casa,hambar de pe glob o distanta
		//pentru traseul mosului. Folosesc aici formula haversine pentru a calcula traseul facut in zbor,de mos,
		//peste circumverinta pamantului
		float calc_distanta(Elfi elfii,float x,float y){
			float x1=elfii.get_coordonate_orase(x*2);
			float y1=elfii.get_coordonate_orase(x*2+1);
			float x2=elfii.get_coordonate_orase(y*2);
			float y2=elfii.get_coordonate_orase(y*2+1);
			float a=pow(sin((x1-x2)/2),2)+cos(y1)*cos(y2)*pow(sin((y1-y2)/2),2);
			float c=2*atan2(sqrt(a),sqrt(1-a));
			float R=6.371;
			return R*c;
		}
		void set_nr_orase(Elfi elfii){
			this->nr_orase=elfii.get_nr_copii();
		}
		//Generez o matrice de orase si orase corespondente lor; Stim aici ca putem ajunge de oriunde in orice alt punct
		void set_matrix(Elfi elfii){
			matrix=new float*[nr_orase];
			for(int i=0;i<nr_orase;i++)
			matrix[i]=new float[nr_orase];
			for(int i=0;i<nr_orase;i++)
			{
				for(int j=0;j<nr_orase;j++)
				{
					if(i==j)
					matrix[i][j]=0;//Insusi locatia va avea val 0 ca sa o putem ignora
					matrix[i][j]=calc_distanta(elfii,i,j);
				}
			}
		}
		//Aici noi vrem sa parcurgem matricea si sa gasim drumul cal mai scurt
		void set_traseu(Elfi elfii){
			int i=0;
			this->traseu.push_back(elfii.get_lista_orase(i));//Introducem pozitia de start
			while(traseu.size()<nr_orase)//Stim cate orase avem asa ca repedam procesul de alegere pt ele
			{
			float min=100000;
			for(int j=0;j<nr_orase;j++)
			{
				for(int w=0;w<nr_orase;w++)//Gasim drumul cel mai scurt care nu e insusi locatia
				{
					if(matrix[i][w]<min && matrix[i][j]!=0)
						min=matrix[i][w];
				}
				if(matrix[i][j]==min)	//Gand parcurgem si gasim val minima
				{
					this->traseu.push_back(elfii.get_lista_orase(j));//Introducem orasul in traseu
					this->distanta_parcursa+=matrix[i][j];//Crestem distanta parcursa
					for(int w=0;w<nr_orase;w++)
					{
						matrix[w][i]=0; //Facum toate drumurile din locatia veche 0 ca sa putem sa le ignoram
						//la citire pentru ca nu vrem sa sfarsim intr-un loop fara a trece prin toate orasele
					}
					i=j;		//Plecam din nou dar acum de la orasul ales;
				}
			}	
			}
		}
		int get_nr_orase(){
			return this->nr_orase;
		}
		string get_traseu(int x){
			return this->traseu[x];
		}
		float get_distanta_parcursa(){
			return this->distanta_parcursa;
		}
		Mos_Craciun(Elfi elfii){
			set_nr_orase(elfii);
			set_matrix(elfii);
			set_traseu(elfii);
		}
		~Mos_Craciun(){
			for(int i=0;i<nr_orase;i++)
			delete []matrix[i];
			delete []matrix;
			traseu.clear();
		}
		
	friend class Doamna_Craciun;		//Trimites sefei programul de munca
};
