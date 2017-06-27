#Código parcialmente retirado de ftp://ftp.cea.fr/pub/unati/people/educhesnay/pystatml/StatisticsMachineLearningPythonDraft.pdf
import numpy as np
import pandas as pd
import pyevolve as pe

def eval_function(choromossome):
    score = 0.0
    tourLength = 0
    #escrever função de eval
    #embed?
    #transformar em vetor?
    score = 1/tourLength
    return score;

# Pairwaise distance between european cities
try:
    url = '../data/eurodist.csv'
    df = pd.read_csv(url)
except:
    url = 'https://raw.github.com/neurospin/pystatsml/master/data/eurodist.csv'
    df = pd.read_csv(url)

print(df.ix[:5, :5])
city = df["city"]
D = np.array(df.ix[:, 1:]) # Distance matrix

#Resto do código:
#Usar lista 2D? Sim!
#Fazer o mesmo que em R!

genome = pe.G2DList.G2DList(21)
genome.evaluator.set(eval_function)
ga = pe.GSimpleGA.GSimpleGA(genome)
ga.evolve(freq_stats=10)


print ga.bestIndividual()
