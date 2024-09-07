#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <armadillo>  // or #include <Eigen/Dense>

namespace py = pybind11;

// Function to compute the inverse of a matrix
py::array_t<double> compute_inverse(py::array_t<double> input) {
    auto buf = input.request();
    int N = buf.shape[0];  // Assuming square matrix

    arma::mat A(reinterpret_cast<double*>(buf.ptr), N, N, false);  // Wrap input data in Armadillo matrix
    arma::mat A_inv = arma::inv(A);  // Compute inverse

    // Convert Armadillo matrix back to Numpy array
    auto result = py::array_t<double>({N, N});
    auto result_buf = result.request();
    double *result_ptr = static_cast<double*>(result_buf.ptr);
    std::memcpy(result_ptr, A_inv.memptr(), N * N * sizeof(double));

    return result;
}

// Function to multiply two matrices
py::array_t<double> multiply_matrices(py::array_t<double> mat1, py::array_t<double> mat2) {
    auto buf1 = mat1.request();
    auto buf2 = mat2.request();
    int N = buf1.shape[0];  // Assuming square matrices

    arma::mat A(reinterpret_cast<double*>(buf1.ptr), N, N, false);  // Wrap input data in Armadillo matrix
    arma::mat B(reinterpret_cast<double*>(buf2.ptr), N, N, false);  // Wrap input data in Armadillo matrix
    arma::mat C = A * B;  // Matrix multiplication

    // Convert Armadillo matrix back to Numpy array
    auto result = py::array_t<double>({N, N});
    auto result_buf = result.request();
    double *result_ptr = static_cast<double*>(result_buf.ptr);
    std::memcpy(result_ptr, C.memptr(), N * N * sizeof(double));

    return result;
}

PYBIND11_MODULE(mylib, m) {
    m.def("compute_inverse", &compute_inverse, "Compute the inverse of a matrix");
    m.def("multiply_matrices", &multiply_matrices, "Multiply two matrices");
}