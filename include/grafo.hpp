#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>

namespace paa {

// Grafo direcionado representado por lista de adjacência.
class Grafo {
public:
    explicit Grafo(int numVertices = 0);

    void adicionarAresta(int u, int v);

    int numVertices() const { return static_cast<int>(adj_.size()); }
    long numArestas() const;

    const std::vector<int>& vizinhos(int u) const { return adj_[u]; }

    bool verticeValido(int u) const { return u >= 0 && u < numVertices(); }

private:
    std::vector<std::vector<int>> adj_;
};

}  // namespace paa

#endif  // GRAFO_HPP
