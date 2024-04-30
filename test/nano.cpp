#include <bits/stdc++.h>



int main() {
    const char* directorio = "/Users/alexisortiz/Desktop";

    std::string comando = "if [ -d \"" + std::string(directorio) + "\" ]; then echo \"El directorio existe.\"; ls -l \"" + std::string(directorio) + "\"; fi";

    int resultado = system(comando.c_str());

    if (resultado == 0) {
        std::string archivo;
        std::cout << "Ingrese el nombre del archivo que desea editar: ";
        std::cin >> archivo;

        comando = "nano \"" + std::string(directorio) + "/" + archivo + "\"";

        system(comando.c_str());
    } else {
        std::cout << "El directorio no existe." << std::endl;
    }

    return 0;
}

