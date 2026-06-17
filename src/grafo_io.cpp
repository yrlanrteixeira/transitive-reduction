#include "grafo_io.hpp"

#include <fstream>
#include <istream>
#include <ostream>
#include <stdexcept>

namespace paa {

Grafo GrafoIO::ler(std::istream& entrada) {
    int n;
    long m;
    if (!(entrada >> n >> m) || n < 0 || m < 0)
        throw std::runtime_error("Entrada invalida: esperado 'n m' na primeira linha");

    Grafo g(n);
    for (long i = 0; i < m; ++i) {
        int u, v;
        if (!(entrada >> u >> v))
            throw std::runtime_error("Aresta invalida na linha " + std::to_string(i + 2));
        g.adicionarAresta(u, v);  // valida os vértices internamente
    }
    return g;
}

Grafo GrafoIO::lerArquivo(const std::string& caminho) {
    std::ifstream arquivo(caminho);
    if (!arquivo)
        throw std::runtime_error("Erro ao abrir o arquivo: " + caminho);
    return ler(arquivo);
}

void GrafoIO::escrever(const Grafo& g, std::ostream& saida) {
    saida << g.numVertices() << ' ' << g.numArestas() << '\n';
    for (int u = 0; u < g.numVertices(); ++u)
        for (int v : g.vizinhos(u)) saida << u << ' ' << v << '\n';
}

void GrafoIO::escreverArquivo(const Grafo& g, const std::string& caminho) {
    std::ofstream arquivo(caminho);
    if (!arquivo)
        throw std::runtime_error("Erro ao criar o arquivo: " + caminho);
    escrever(g, arquivo);
}

}  // namespace paa
