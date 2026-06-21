#include "caminhamento.hpp"

#include <cstddef>
#include <stack>
#include <utility>

namespace paa {

void dfsMarcar(const Grafo& g, int origem, std::vector<char>& visitado) {
    if (visitado[origem]) return;
    std::stack<int> pilha;
    pilha.push(origem);
    visitado[origem] = 1;
    while (!pilha.empty()) {
        int u = pilha.top();
        pilha.pop();
        for (int w : g.vizinhos(u)) {
            if (!visitado[w]) {
                visitado[w] = 1;
                pilha.push(w);
            }
        }
    }
}

std::vector<char> alcancaveis(const Grafo& g, int origem) {
    std::vector<char> visitado(g.numVertices(), 0);
    dfsMarcar(g, origem, visitado);
    return visitado;
}

bool ehAciclico(const Grafo& g) {
    // 0 = branco (não visitado), 1 = cinza (em exploração), 2 = preto (pronto)
    const int n = g.numVertices();
    std::vector<char> cor(n, 0);
    // Pilha de (vértice, índice do próximo vizinho a explorar): DFS iterativa.
    std::vector<std::pair<int, std::size_t>> pilha;

    for (int s = 0; s < n; ++s) {
        if (cor[s] != 0) continue;
        pilha.push_back({s, 0});
        cor[s] = 1;
        while (!pilha.empty()) {
            auto& [u, i] = pilha.back();
            if (i < g.vizinhos(u).size()) {
                int w = g.vizinhos(u)[i++];
                if (cor[w] == 1) return false;  // aresta de retorno => ciclo
                if (cor[w] == 0) {
                    cor[w] = 1;
                    pilha.push_back({w, 0});
                }
            } else {
                cor[u] = 2;
                pilha.pop_back();
            }
        }
    }
    return true;
}

}  // namespace paa
