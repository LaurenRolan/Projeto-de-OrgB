import numpy as np
import pandas as pd
import math

try:
  url = '../data/eurodist.csv'
  df = pd.read_csv(url)
except:
  url = 'https://raw.github.com/neurospin/pystatsml/master/data/eurodist.csv'
  df = pd.read_csv(url)

#print(df.ix[:5, :5])
city = df["city"]
D = np.array(df.ix[:, 1:]) # Distance matrix
M = np.zeros((21, 21))
R = np.zeros((21,21))
for i in range (0, 21):
  for j in range(0, 21):
    M[i][j] = 0.5 * (pow(D[1][j], 2) + pow(D[i][1], 2) - pow(D[i][j], 2))

result = np.linalg.matrix_rank(M)
w, v = np.linalg.eig(M)

print("oi");
