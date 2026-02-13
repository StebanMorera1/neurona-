#include <iostream>
#include <vector>

using namespace std;

class neurona {
private:
    vector<int> pesos;
    int umbral;

public:
    neurona(vector<int> w, int t) : pesos(w), umbral(t) {}

    int activate(vector<int> entradas) {
        int sum = 0;
        for (size_t i = 0; i < entradas.size(); i++) {
            sum += entradas[i] * pesos[i];
        }
        return (sum >= umbral) ? 1 : 0;
    }
};

int main() {
    neurona z1({2, -1}, 2);
    neurona z2({-1, 2}, 2);
    neurona y({2, 2}, 2);

    vector<vector<int>> pruebas = {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };

    cout << "Entrada A | Entrada B | Salida XOR" << endl;
    cout << "-----------------------------------" << endl;

    for (const auto& fila : pruebas) {
        int res_z1 = z1.activate(fila);
        int res_z2 = z2.activate(fila);
        
        int resultado_final = y.activate({res_z1, res_z2});

        cout << "    " << fila[0] << "     |     " << fila[1] << "     |      " << resultado_final << endl;
    }

    return 0;
}