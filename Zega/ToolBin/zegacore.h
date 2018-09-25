/*
 *  zegacore.h
 *  zegax
 *
 *  Created by Rick Sanchez on 21/09/18.
 *  Copyright 2018 ARDUINO VERSION - INFORMABOX TECH. All rights reserved.
 *
 */
#include <math.h>


#include <stdlib.h>


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
	
    double get_y(){
        return y;
    }

    double get_delta1(){
      return delta1;
    }

    double get_delta2(){
      return delta2;
    }

    double get_delta3(){
      return delta3;
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

    void add_delta1(double d){
        delta1 = delta1 + d;
    }

    void add_delta2(double d){
        delta2 = delta2 + d;
    }

    void addd_delta3(double d){
        delta3 = delta3 + d;
    }

private:
    double delta1;
    double delta2;
    double delta3;
    double y;
};
