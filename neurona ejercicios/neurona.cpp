#include <iostream>
#include <vector>

using namespace std;

class Neurona {
private:
    vector<int> pesos;
    int umbral;

public:
    Neurona(vector<int> w, int t) : pesos(w), umbral(t) {}

    int activar(vector<int> entradas) {
        int sum = 0;
        for (size_t i = 0; i < entradas.size(); i++) {
            sum += entradas[i] * pesos[i]; 
        }
        return (sum >= umbral) ? 1 : 0;
    }
};

int main() {
    vector<int> p = {1, 1};
    int t = 1;

    Neurona Neurona(p, t);

    vector<vector<int>> pruebas = {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };

    cout << "Entradas | Salida" << endl;
    cout << "-----------------" << endl;

    for (const auto& fila : pruebas) {
        int resultado = Neurona.activar(fila);
        cout << "  " << fila[0] << ", " << fila[1] << "   |   " << resultado << endl;
    }

    return 0;

}
