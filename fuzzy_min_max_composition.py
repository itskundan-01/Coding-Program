
import numpy as np

R = np.array([[0.8, 0.4, 0.6],
              [0.3, 0.9, 0.5],
              [0.7, 0.2, 0.8]])

S = np.array([[0.5, 0.7],
              [0.6, 0.4],
              [0.9, 0.3]])

def min_max_composition(R, S):
    rows, cols_R = R.shape
    cols_S = S.shape[1]
    T = np.zeros((rows, cols_S))
    for i in range(rows):
        for j in range(cols_S):
            T[i, j] = max(min(R[i, k], S[k, j]) for k in range(cols_R))
    return T

T = min_max_composition(R, S)

print("Fuzzy Relation R:")
print(R)
print("\nFuzzy Relation S:")
print(S)
print("\nMin-Max Composition T = R ∘ S:")
print(T)

print ("\n Operation Completed")













