#include "grafo.hpp"

#include <stdexcept>

namespace paa {

Grafo::Grafo(int numVertices) : adj_(numVertices) {}

void Grafo::adicionarAresta(int u, int v) {
    if (!verticeValido(u) || !verticeValido(v))
        throw std::out_of_range("Grafo::adicionarAresta: vertice invalido");
    adj_[u].push_back(v);
}

long Grafo::numArestas() const {
    long m = 0;
    for (const auto& lista : adj_) m += static_cast<long>(lista.size());
    return m;
}

}  // namespace paa
