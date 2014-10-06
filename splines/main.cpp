//
//  main.cpp
//  splines
//
//  Created by Piaras Hoban on 06/10/2014.
//  Copyright (c) 2014 Piaras Hoban. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "spline.h"

using namespace std;

int main(int argc, char** argv) {
	
	std::vector<double> X(6), Y(6);
	X[0]=0.1; X[1]=0.4; X[2]=1.2; X[3]=1.8; X[4]=2.0;X[5]=5;
	Y[0]=0.5; Y[1]=0.3; Y[2]=0.6; Y[3]=8;Y[4]=3;Y[5]=0.1;
	
	tk::spline s;
	s.set_points(X,Y);    // currently it is required that X is already sorted
	
	ofstream myfile("spline.txt");
	
	double ix;
	
	float n = 100;
	
	for (int i = 0 ; i <= n ; i++) {
		ix = (((X[(X.size() - 1 ) ] - X[0]) * (double)i/n)) + X[0];
		myfile << ix << " " << s(ix) << std::endl;
	}
	
	myfile.close();
	
	system("gnuplot spline.gnuplot");
	
	return 0;
}

