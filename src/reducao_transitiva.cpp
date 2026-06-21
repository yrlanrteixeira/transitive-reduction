#include "reducao_transitiva.hpp"

#include <algorithm>
#include <vector>

#include "caminhamento.hpp"

namespace paa {

// Uma aresta (u,v) é transitiva quando v é alcançável a partir de u por algum
// caminho de comprimento >= 2. Para cada u, marcamos via DFS tudo que é
// alcançável pelos sucessores dos sucessores de u e mantemos somente as
// arestas diretas cujo destino não foi marcado.
Grafo ReducaoTransitiva::reduzir(const Grafo& g) const {
    const int n = g.numVertices();
    Grafo reduzido(n);
    std::vector<char> visitado(n, 0);

    for (int u = 0; u < n; ++u) {
        for (int w : g.vizinhos(u))        // u -> w (comprimento 1)
            for (int x : g.vizinhos(w))    // u -> w -> x (comprimento >= 2)
                dfsMarcar(g, x, visitado);

        for (int v : g.vizinhos(u))
            if (!visitado[v]) reduzido.adicionarAresta(u, v);

        std::fill(visitado.begin(), visitado.end(), 0);
    }
    return reduzido;
}

}  // namespace paa
