library(GA)

data("eurodist", package="datasets")
D <- as.matrix(eurodist)

#Calcula tamanho da rota
tourLength <- function(tour, distMatrix){
  tour <- c(tour, tour[1])
  route <- embed(tour, 2)[,2:1]
  sum(distMatrix[route])
}

#Quanto maior o fitness, menor a rota. Logo, 1/tourLength
tpsFitness <- function(tour, ...)
  1/tourLength(tour, ...)

#Explicando cada parâmetro:
#Tipo => permutação (reordenar a lista de cidades)
#fitness => o melhor/maior fitness é o menor caminho, o que é dado por 1/tourLength
#distMatrix => distância calculada a partir da matriz dada
#min => tamanho mínimo da busca
#max => tamanho máximo da busca
#popSize => Tamanho fixo da população
#maxiter => número máximo de iterações antes de abortar
#run => Nº máx. de iterações com populações que não melhoram o fitness
#pmutation => probabilidade de mutação na hora da reprodução

GA <- ga(type="permutation", fitness=tpsFitness, distMatrix=D,
         min=1, max=attr(eurodist, "Size"), popSize=50, maxiter=5000,
         run=500, pmutation=0.2)

#Imprime gráfico da evolução
plot(GA)

#Para exibir a tabela de distâncias, escreva no console:
#View(D)