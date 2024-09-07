#include <iostream>
#include <armadillo>

int main() {
    int N = 1000;
    arma::mat A = arma::randu<arma::mat>(N, N);  // Create a random matrix
    arma::mat A_inv = arma::inv(A);  // Calculate the inverse
    arma::mat product = A * A_inv;   // Matrix multiplication
    
    // Calculate the sum of absolute values of each element in the product
    double sum_abs = arma::accu(arma::abs(product));

    std::cout << "Error of absolute values of elements in A * A^-1: " << sum_abs - N << std::endl;

    return 0;
};