#include <stdio.h>
#include <iostream>
#include <fstream>
#include <tuple>
#include <cmath>
//#include <eigen3/Eigen/Dense>


// Defining constants
long double pi = 3.14159265358979323846;
long double pi2 = pi*pi;
long double hc = 197.3269718;

long double m0 = 939.56563; // Mass of nucleon
long double kk = 938.27231/m0;

// Range
long double nb_i = 0.1;
long double nb_f = 1.0;
long double dnb = 0.001;

long double n0 = 0.153;     // Saturation density

// Masses
long double mb[8] = {0.938272, 1.115683, 1.18937, 1.192642, 1.31486, 1.32171, 1.3872, 1.540};
long double ml[2] = {0.511, 105.658};
long double ms = 550.0;
long double mv = 783.0;
long double mr = 770.0;

// Variables
long double x[4] = {0.0, 0.0, 0.0, 0.0};    // x = {kf_e, sigma, omega}
long double fvec[4] = {0.0, 0.0, 0.0, 0.0};



// EOS Function
std::tuple<long double, long double> eos(long double x[3]){
    
    long double e = 0.0; long double p = 0.0;
    
    // EOS for baryons


    // EOS for leptons


    // EOS for mesons


    return std::make_tuple(e, p);
}

// Chemical Potential Function
long double mu(long double k, long double m){
    return sqrt(pow(k,2) + pow(m,2));
}


// Fermi Momenta Function
long double kf(long double n){
    return pow(3*pi2*n, 1.0/3.0);
}


int main() {
    std::ofstream outputfile("eos.dat");
    long double x[3] = {0.0, 0.0, 0.0};
    long double e = 0.0; long double p = 0.0;

    // main loop
    for (long double nb = nb_i; nb < nb_f; nb += dnb){
        

        std::tie(e, p) = eos(x);

        if ((e >= 0.0) and (p >= 0.0)){
            outputfile << nb*pow(kk,3) << "\t" << e*pow(kk,4) << "\t" << p*pow(kk,4) << std::endl;
        }
        
        //std::cout << "Density: " << nb*pow(kk,3) << " Energy: " << e*pow(kk,4) << " Pressure: " << p*pow(kk,4) << std::endl;
    }
    outputfile << "-1., -1., -1." << std::endl;
    outputfile.close();
    return 0;
}