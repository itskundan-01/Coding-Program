import numpy as np

R = np.array([[0.8, 0.4], 
              [0.6, 0.7]])

S = np.array([[0.5, 0.9], 
              [0.3, 0.6]])

print("Matrix R:")
print(R)
print("\nMatrix S:")
print(S)

def min_max_composition(R, S):
    rows_R, cols_R = R.shape
    rows_S, cols_S = S.shape
    result = np.zeros((rows_R, cols_S))
    
    for i in range(rows_R):
        for j in range(cols_S):
            result[i, j] = max(min(R[i, k], S[k, j]) for k in range(cols_R))
    return result

def max_product_composition(R, S):
    rows_R, cols_R = R.shape
    rows_S, cols_S = S.shape
    result = np.zeros((rows_R, cols_S))
    
    for i in range(rows_R):
        for j in range(cols_S):
            result[i, j] = max(R[i, k] * S[k, j] for k in range(cols_R))
    return result

min_max_result = min_max_composition(R, S)
max_product_result = max_product_composition(R, S)

print("\n" + "="*50)
print("MIN-MAX COMPOSITION (R ∘ S):")
print(min_max_result)

print("\n" + "="*50)
print("MAX-PRODUCT COMPOSITION (R ∘ S):")
print(max_product_result)
