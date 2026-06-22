#include <cstdlib>
#include <iostream>

#include "gerador_dag.hpp"
#include "grafo_io.hpp"

// Uso: ./gerador <n> <p> [semente] > grafo.txt
int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0] << " <n> <p> [semente]\n";
        return 1;
    }
    int n = std::atoi(argv[1]);
    double p = std::atof(argv[2]);
    unsigned semente = (argc >= 4) ? static_cast<unsigned>(std::atoi(argv[3])) : 42u;

    paa::GeradorDag gerador(semente);
    paa::GrafoIO::escrever(gerador.gerar(n, p), std::cout);
    return 0;
}
