import numpy as np
import mylib  # Import the compiled C++ module

# Step 1: Create a random NxN matrix in Python
N = 1000
A = np.random.rand(N, N)

# Step 2: Use the C++ function to compute the inverse of the matrix
A_inv = mylib.compute_inverse(A)

# Step 3: Use the C++ function to multiply A * A_inv
product = mylib.multiply_matrices(A, A_inv)

# Step 4: Compute the absolute value of each element
abs_product = np.abs(product)

# Step 5: Sum all elements and subtract N
result = np.sum(abs_product) - N

print(f"Result: {result}")