#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float CAPITAL= 0;
    int bancos = 3;
    int anios = 3;
    float tasas[bancos][anios];
    float promedio[bancos];
    float anual[bancos];


    float trimestre[bancos];
    float mes[bancos];

    string nombreBancos[bancos] = { "Banco Provincia", "Banco Nacion", "Banco Hipotecario" };

    cout << "--- Analisis de Plazos Fijos ----";
    cout << "Ingrese el capital a invertir: $"<< endl;
    cin >> CAPITAL;

    // CARGO LAS TASAS SIN VALIDACIÓN
    for(int i = 0; i < bancos; i++) {
        system("cls");
        cout << "Ingrese las 3 tasas anuales en % de " << nombreBancos[i];
        for(int j = 0; j < anios; j++) {
            cout << "  Año " << j+1 << ": ";
            cin >> tasas[i][j];
        }
        cout << endl;
    }
    system("cls");

    // CALCULO EL PROMEDIO
    for(int i = 0; i < bancos; i++) {
        float suma = 0;
        for(int j = 0; j < anios; j++) {
            suma += tasas[i][j];
        }
        promedio[i] = suma / anios;
    }

    // FORMA ANUAL
    for(int i = 0; i < bancos; i++) {
        anual[i] = CAPITAL * (1 + (promedio[i] / 100.0));
    }

    // TRIMESTRAL
    for(int i = 0; i < bancos; i++) {
        float cap = CAPITAL;
        for(int t = 0; t < 4; t++) {
            cap += cap * (promedio[i] / 100.0) / 4;
        }
        trimestre[i] = cap;
    }

    // MENSUAL
    for(int i = 0; i < bancos; i++) {
        float cap = CAPITAL;
        for(int m = 0; m < 12; m++) {
            cap += cap * (promedio[i] / 100.0) / 12;
        }
        mes[i] = cap;
    }

    // MUESTRO LOS RESULTADOS
   cout << fixed << setprecision(2);
    cout << "--- RESULTADOS ---\n";
    for(int i = 0; i < bancos; i++) {
        cout << nombreBancos[i] << ":\n";
        cout << "  Promedio anual: " << promedio[i] << endl;
        cout << "  Monto final (1 año): $" << anual[i] << endl;
        cout << "  Monto final (trimestres): $" << trimestre[i] << endl;
        cout << "  Monto final (meses): $" << mes[i] << endl;
    }

    // BUSCO LA MEJOR OPCION
    float mejor = anual[0];
    int mejorBanco = 0;
    string modo = "Anual";

    // COMPARO PARA VER QUE BANCO ES MEJOR
    for(int i = 0; i < bancos; i++) {
        if(anual[i] > mejor) { mejor = anual[i]; mejorBanco = i; modo = "Anual"; }
        if(trimestre[i] > mejor) { mejor = trimestre[i]; mejorBanco = i; modo = "Trimestral"; }
        if(mes[i] > mejor) { mejor = mes[i]; mejorBanco = i; modo = "Mensual"; }
    }
   cout << fixed << setprecision(2);
    cout << "=== RECOMENDACION ===\n";
    cout << "Banco recomendado: " << nombreBancos[mejorBanco] << endl;
    cout << "Mejor modalidad: " << modo << endl;
    cout << "Monto final estimado: $" << mejor << endl;


    return 0;
}


