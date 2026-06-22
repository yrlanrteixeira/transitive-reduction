#include "gerador_dag.hpp"

#include <random>

namespace paa {

Grafo GeradorDag::gerar(int numVertices, double probabilidade) const {
    std::mt19937 rng(semente_);
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    Grafo g(numVertices);
    for (int i = 0; i < numVertices; ++i)
        for (int j = i + 1; j < numVertices; ++j)
            if (dist(rng) < probabilidade) g.adicionarAresta(i, j);
    return g;
}

}  // namespace paa
