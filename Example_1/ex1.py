import numpy as np

N = 1000;

# Step 1: Create a large random matrix A
A = np.random.rand(N, N)

# Step 2: Calculate the inverse of A
A_inv = np.linalg.inv(A)

# Step 3: Compute the product A * A^-1
product = np.dot(A, A_inv)

# Step 4: Compute the absolute value of each element in the product
abs_product = np.abs(product)

# Step 5: Sum all elements
result = np.sum(abs_product) - N

print(f"Error as absolute values of elements in A * A^-1: {result}")
