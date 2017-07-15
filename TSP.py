#Codigo parcialmente retirado de:
#ftp://ftp.cea.fr/pub/unati/people/educhesnay/pystatml/StatisticsMachineLearningPythonDraft.pdf
#http://pyevolve.sourceforge.net/0_6rc1/examples.html

import numpy as np
import pandas as pd
from pyevolve import GAllele
from pyevolve import GSimpleGA
from pyevolve import G1DList
from pyevolve import Consts
import sys, random
random.seed(1024)

def tour_length(matrix, tour):
   """ Retorna o tamanho total da rota escolhida """
   total = 0
   t = tour.getInternalList()
   print(tour)
   for i in range(21):
      j      = (i+1)%20
      total += matrix[t[i], t[j]]
   return total


def G1DListTSPInitializator(genome, **args):
    """ Inicializa lista com 21 numeros randomicos diferentes"""
      lst = [i for i in xrange(genome.getListSize())]
      random.shuffle(lst)
      genome.setInternalList(lst)

try:
   url = '../data/eurodist.csv'
   df = pd.read_csv(url)
except:
   url = 'https://raw.github.com/neurospin/pystatsml/master/data/eurodist.csv'
   df = pd.read_csv(url)

city = df["city"]
D = np.array(df.ix[:, 1:]) # matriz com as distancias

#Cria lista com 21 posicoes
genome = G1DList.G1DList(21)

#Inicializa a lista
genome.initializator.set(G1DListTSPInitializator)

#Usa como metodo de avaliacao o tamanho da rota
genome.evaluator.set(lambda chromosome: tour_length(D, chromosome))
ga = GSimpleGA.GSimpleGA(genome)
ga.setMinimax(Consts.minimaxType["minimize"])
ga.setGenerations(700)
ga.setMutationRate(0.2)
ga.setPopulationSize(50)
ga.evolve(freq_stats=200)

print("And the best individual is...")

print ga.bestIndividual()
