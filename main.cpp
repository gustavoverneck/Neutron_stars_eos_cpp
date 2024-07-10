#include <iostream>
#include <stdio.h>
#include <armadillo>

// Functions
double funcv1(double x) {
    
    
    return x;
}



// Main

int main() {

    // Define variables
    arma::vec fvec = arma::vec(4).fill(0.0);
    arma::vec x = arma::vec(4);

    // Vector of baryon masses
    arma::vec mb = arma::vec(8);
    mb(0) = 0.938272;
    mb(1) = 1.115683;
    mb(2) = 1.18937;
    mb(3) = 1.192642;
    mb(4) = 1.31486;
    mb(5) = 1.32171;
    mb(6) = 1.3872;
    mb(7) = 1.540;
    
    double m = 0.938272; // Mass of nucleon / normalization constant
    
    // Vector of lepton masses
    arma::vec ml = arma::vec(2);   // Vector of lepton masses
    
    // Meson masses
    double ms; // mass of the scalar meson
    double mv; // mass of the vector meson
    double mr;



    // Initial x ansatz
    x(0) = 1.0; x(1) = 2.0; x(2) = 3.0; x(3) = 4.0;

    for (int i = 0; i < 4; i++) {
        std::cout << x(i) << std::endl;
    }




    // Initial x values





    return 0;
}