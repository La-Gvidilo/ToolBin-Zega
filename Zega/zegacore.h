/*
 *  zegacore.h
 *  zegax
 *
 *  Created by Rick Sanchez on 21/09/18.
 *  Copyright 2018 __MyCompanyName__. All rights reserved.
 *
 */
#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <math.h>
#include <cstdlib>

#include <fstream>
#include <sstream>

#include <stdlib.h>


//#include <vector>
//#include <stack>
using namespace std;

class dataEntity{
public:
    void init(){
        delta1 = 0.733;
        delta2 = 0.267;
        delta3 = 0.585;
    }

    void calculus(int x){
        y = (x/sqrt(delta1)) * log(abs(int(cos(tan(delta2*x))))+x)+sin(tan(sqrt(sqrt(delta3*x))));
    }

	string get_formula(){
		stringstream formule;
		formule << "(x/sqrt("<<delta1<<")) * log(abs(int(cos(tan("<<delta2<<"*x))))+x)+sin(tan(sqrt(sqrt("<<delta3<<"*x))))";
		return formule.str(); 
	}
	
    double get_y(){
        return y;
    }

    void set_delta1(double d1){
        delta1 = d1;
    }

    void set_delta2(double d2){
        delta2 = d2;
    }

    void set_delta3(double d3){
        delta3 = d3;
    }

private:
    double delta1;
    double delta2;
    double delta3;
    double y;
};


map<int, string> get_formula_part(string expression){
	map<int, string> npia;
	int i = 0;
	stringstream buffer;
	int partaiz = 0;
	string temp;
	for (int it=0; it<expression.size(); it++){
		temp = expression[it];
		buffer << temp;
		if (temp == "(") {
			partaiz++;
		}
		if (temp == ")") {
			partaiz--;
			if (partaiz < 1){
				npia[i] = buffer.str();
				buffer.str("");
				i++;
			}
		}
	}
	
	if (partaiz>0) { cout << "ERROR" << endl; }
	return npia;
}

class coredata{
	public:
		void load(string namefile){
			int i = 1;
			ifstream fichier(namefile.c_str());
			string line;
			while (getline(fichier,line)){
				datanumber[i] = atoi(line.c_str());
				i++;
			}
		}
		
		void born(int numberz){
			for (int i=1; i<numberz; i++){
				Entityz[i] = dataEntity();
				Entityz[i].init();
				cout << "BORN("<<i<<")..." << endl;
			}
			maxent = numberz;
		}
		
		void mutationRandomAll(){
			int ordermut; 
			for (int i = 1; i<maxent; i++){
				cout << "MUTATE("<<i<<")..." << endl;
				ordermut = rand() % 3;
				switch (ordermut){
					case 0: {
						Entityz[i].set_delta1((double)rand() / 999);
						break;
					}
					case 1: {
						Entityz[i].set_delta2((double)rand() / 999);
						break;
					}
					case 2: {
						Entityz[i].set_delta3((double)rand() / 999);
						break;
					}
				}
			}
		}
		
		void evaluateAll(){
			double y;
			double correctpercent=0.0;
			int Ci=0;
			int Cok = 0;
			for (int i = 1; i<maxent; i++){
				Ci = 0;
				Cok = 0;
				for (map<int,int>::iterator it1=datanumber.begin(); it1!=datanumber.end(); it1++){
					Entityz[i].calculus(it1->first);
					y = Entityz[i].get_y();
					Ci++;
					//cout << round(y) << "  ::  " << it1->second <<endl;
					if (int(round(y)) == it1->second){
						Cok++;
					}
				}
				cout << "EVALUATE("<<i<<")..." << endl;
				correctpercent = Cok;
				percentokay[i] = correctpercent;
				//cout << i << ": " << correctpercent << " / "<<Ci<< endl;
			}
		}
		
		void get_best(){
			cout << "VERIF BEST..." << endl;
			int i=0;
			int ID;
			for (map<int, double>::iterator it1=percentokay.begin(); it1!=percentokay.end(); it1++){
				if (it1->second > i){
					i = it1->second;
					ID = it1->first;
				}
			}
			best = ID;
			cout << "Le meilleur c'est le numero: " << ID << " AVEC UN SCORE DE: " << i << endl; 
		}
		
		void evaluateDecalBest(){
			ofstream fichier;
			fichier.open("ForCorr.txt");
			double y;
			int i  = best;
			fichier << Entityz[i].get_formula()<<endl;
			fichier << "x0,y" << endl;
			for (map<int,int>::iterator it1=datanumber.begin(); it1!=datanumber.end(); it1++){
				Entityz[i].calculus(it1->first);
				y = Entityz[i].get_y();
				fichier << round(y) << "," << it1->second - round(y) << endl;
					
			}
			fichier.close();
				
				
		}
		
		void mutationAllFromBest(){
			Entityz[best].set_delta1((double)rand() / 1.1);
			Entityz[best].set_delta2((double)rand() / 1.1);
			Entityz[best].set_delta3((double)rand() / 1.1);
		}
		
		
		float progret;
		void born_brutforce(double rangemin, double rangemax, double stepper){
			progret = 0.0;
			Entityz[0] = dataEntity();
			Entityz[0].init();
			int Ci;
			int Cok;
			double y;
			int refscore=0;
			string refformula;
			ofstream fichier;
			fichier.open("formulas.txt");
			for (double d1=rangemin; d1<rangemax; d1=d1+stepper)
			{
				for (double d2=rangemin; d2<rangemax; d2=d2+stepper)
				{
					for (double d3=rangemin; d3<rangemax; d3=d3+stepper)
					{
						progret = (d1*d2*d3)/(rangemax*rangemax*rangemax);
						Entityz[0].set_delta1(d1);
						Entityz[0].set_delta2(d2);
						Entityz[0].set_delta3(d3);				
						Ci = 0;
						Cok = 0;
						for (map<int,int>::iterator it1=datanumber.begin(); it1!=datanumber.end(); it1++){
							Entityz[0].calculus(it1->first);
							y = Entityz[0].get_y();
							Ci++;
							if (int(round(y)) == it1->second){
								Cok++;
							}
						}
						if (Cok > refscore){
							refscore = Cok;
							refformula = Entityz[0].get_formula();
							fichier << Entityz[0].get_formula() << endl;
						}
						
						cout << refscore <<"/"<<Ci << "::" << d1 << " , " << d2 << " , " << d3 << endl;
					}
				}
			}
			
			fichier.close();
			cout << "BEST: " << refformula <<endl;
		}
		

		
	private:
		int maxent;
		int best;
		map<int,int> decallage;
		map<int,int> datanumber;
		map<int, dataEntity> Entityz;
		map<int, double> percentokay;
};

coredata coeur;

