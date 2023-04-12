#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <chrono>

// Función para ordenar los caracteres en base a mayúsculas y minúsculas, y números al final
bool compareChars(char a, char b) {
    if (std::tolower(a) == std::tolower(b)) {
        return a < b;
    }
    else if (std::isdigit(a) && std::isalpha(b)) {
        return false;
    }
    else if (std::isalpha(a) && std::isdigit(b)) {
        return true;
    }
    else {
        return std::tolower(a) < std::tolower(b);
    }
}

// Función para eliminar caracteres no deseados
bool isUnwantedChar(char c) {
    return std::isspace(c) || std::ispunct(c);
}

int main() {
    const int numExecutions = 5; // Número de ejecuciones
    std::ifstream inputFile("C:\\Users\\Dogesito\\Desktop\\ARCO\\benchTest\\input.txt");
    std::ofstream outputFile("C:\\Users\\Dogesito\\Desktop\\ARCO\\benchTest\\output.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error: no se pudo abrir el archivo de entrada." << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Error: no se pudo abrir el archivo de salida." << std::endl;
        return 1;
    }

    std::string inputText;
    std::getline(inputFile, inputText);

    // Eliminar caracteres no deseados del texto de entrada
    inputText.erase(std::remove_if(inputText.begin(), inputText.end(), isUnwantedChar), inputText.end());

    // Medir el tiempo de ejecución
    auto startTime = std::chrono::steady_clock::now();

    // Realizar varias ejecuciones
    for (int i = 0; i < numExecutions; ++i) {
        // Ordenar los caracteres en base a mayúsculas y minúsculas, y números al final
        std::sort(inputText.begin(), inputText.end(), compareChars);

        outputFile << "Intento numero: " << i + 1 << "\n";

        // Insertar un salto de línea entre caracteres nuevos
        std::string outputText;
        char prevChar = '\0';
        for (char c : inputText) {
            if (c != prevChar) {
                outputText += '\n';
            }
            outputText += c;
            prevChar = c;
        }

        // Escribir el resultado en el archivo de salida
        outputFile << outputText << std::endl;
        outputFile << "Fin del intento numero " << i + 1 << "\n\n\n\n\n\n";
    }

    auto endTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    std::cout << "Archivo de salida generado correctamente." << std::endl;
    std::cout << "Tiempo total de ejecución: " << elapsedTime << " ms." << std::endl;
    std::cout << "Tiempo promedio por ejecución: " << elapsedTime / numExecutions << " ms." << std::endl;

    return 0;
}
