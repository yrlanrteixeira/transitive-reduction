#include <chrono>
#include <exception>
#include <iostream>

#include "caminhamento.hpp"
#include "grafo.hpp"
#include "grafo_io.hpp"
#include "reducao_transitiva.hpp"

// Uso: ./reducao_transitiva [entrada.txt [saida.txt]]
// Sem argumentos, lê de stdin e escreve em stdout; estatísticas em stderr.
int main(int argc, char** argv) {
    try {
        paa::Grafo g = (argc >= 2) ? paa::GrafoIO::lerArquivo(argv[1])
                                   : paa::GrafoIO::ler(std::cin);

        if (!paa::ehAciclico(g)) {
            std::cerr << "Erro: o grafo de entrada contem ciclos. O algoritmo "
                         "implementado pressupoe um DAG (ver relatorio).\n";
            return 2;
        }

        paa::ReducaoTransitiva algoritmo;
        auto inicio = std::chrono::steady_clock::now();
        paa::Grafo r = algoritmo.reduzir(g);
        auto fim = std::chrono::steady_clock::now();
        double ms = std::chrono::duration<double, std::milli>(fim - inicio).count();

        if (argc >= 3)
            paa::GrafoIO::escreverArquivo(r, argv[2]);
        else
            paa::GrafoIO::escrever(r, std::cout);

        std::cerr << "n=" << g.numVertices() << "  m=" << g.numArestas()
                  << "  m_reduzido=" << r.numArestas()
                  << "  removidas=" << (g.numArestas() - r.numArestas())
                  << "  tempo=" << ms << " ms\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
