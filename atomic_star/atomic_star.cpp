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

long double kk = 938.27231/hc;

// Range
long double nb_i = 0.1;
long double nb_f = 1.0;
long double dnb = 0.001;

long double n0 = 0.153;

long double m0 = 939.56563;
long double m[3] = {939.56563/938.27231, 938.27231/938.27231, 0.5109991/938.27231};


// EOS Function
std::tuple<long double, long double> eos(long double x[3]){
    
    long double e = 0.0; long double p = 0.0;
    
    for(int i = 0; i < 3; i++){
        e += (1/(8*pi2))*(x[i]*sqrt(pow(x[i], 2) + pow(m[i],2))*(2*(pow(x[i],2))+pow(m[i],2)) - pow(m[i],4)*log((x[i]+sqrt(pow(x[i],2)+pow(m[i],2)))/(m[i])));
        p += (1/(24*pi2))*(((2*pow(x[i],5) - (pow(x[i],3))*pow(m[i],2) - 3*x[i]*pow(m[i],4))/(sqrt(pow(m[i],2) + pow(x[i],2)))) + (3*pow(m[i],4))*log(abs((x[i]*sqrt(pow(m[i],2) + pow(x[2],2)))/(m[i]))));
    }

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

// Proton Fermi Momentum
long double kf_p(long double kf_n){
    return (pow(kf_n, 2) + pow(m[0], 2) - pow(m[1], 2))/(2*sqrt(pow(kf_n, 2) + pow(m[0], 2)));
}

int main() {
    std::ofstream outputfile("eos.dat");
    long double x[3] = {0.0, 0.0, 0.0};
    long double e = 0.0; long double p = 0.0;

    for (long double nb = nb_i; nb < nb_f; nb += dnb){
        x[0] = kf(nb);
        x[1] = kf_p(kf(nb));
        x[2] = x[1];

        std::tie(e, p) = eos(x);

        if ((e >= 0.0) and (p >= 0.0)){
            outputfile << nb << "\t" << e << "\t" << p << std::endl;
        }
        
        std::cout << "Density: " << nb/n0 << " Energy: " << e << " Pressure: " << p << std::endl;
    }
    outputfile << "-1., -1., -1." << std::endl;
    outputfile.close();
    return 0;
}