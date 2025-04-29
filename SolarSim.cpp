#include <iostream>
#include <iomanip>  // para definir casas decimais
using namespace std;

// Função para exibir o cabeçalho bonito
void mostrarCabecalho() {
    cout << "==============================" << endl;
    cout << "     SolarSim - Simulador     " << endl;
    cout << "  Energia Renovável e Estatística " << endl;
    cout << "==============================" << endl << endl;
}

int main() {
    // Variáveis de entrada
    int qtdPaineis;
    float potenciaPainel; // em Watts
    float horasSolDia;
    const float precoKWh = 0.6; // Preço médio do kWh em R$
    const float fatorCO2 = 0.092; // kg de CO2 evitado por kWh

    // Mostrar cabeçalho
    mostrarCabecalho();

    // Entrada de dados
    cout << "Quantos paineis solares voce pretende instalar? ";
    cin >> qtdPaineis;

    cout << "Qual a potencia de cada painel (em Watts)? ";
    cin >> potenciaPainel;

    cout << "Quantas horas de sol por dia em media na sua regiao? ";
    cin >> horasSolDia;

    // Cálculos
    float energiaDiaMedia = (qtdPaineis * potenciaPainel / 1000.0) * horasSolDia; // em kWh
    float energiaMes = energiaDiaMedia * 30; // 30 dias

    float economiaMensal = energiaMes * precoKWh; // em reais
    float co2EvitadoMensal = energiaMes * fatorCO2; // em kg de CO2

    // Cenários estatísticos
    float horasSolMin = horasSolDia - 1; // cenário ruim
    float horasSolMax = horasSolDia + 1; // cenário ótimo

    float energiaDiaMin = (qtdPaineis * potenciaPainel / 1000.0) * horasSolMin;
    float energiaDiaMax = (qtdPaineis * potenciaPainel / 1000.0) * horasSolMax;

    float energiaMesMin = energiaDiaMin * 30;
    float energiaMesMax = energiaDiaMax * 30;

    // Saída de resultados
    cout << fixed << setprecision(2); // 2 casas decimais
    cout << endl;
    cout << "===== Relatorio SolarSim =====" << endl;
    cout << "Energia gerada (mes): " << energiaMes << " kWh" << endl;
    cout << "Economia estimada: R$ " << economiaMensal << endl;
    cout << "CO2 evitado: " << co2EvitadoMensal << " kg por mes" << endl;

    cout << endl << "===== Analise Estatistica =====" << endl;
    cout << "Cenario Ruim (menos 1h de sol): " << energiaMesMin << " kWh/mes" << endl;
    cout << "Cenario Medio (entrada padrao): " << energiaMes << " kWh/mes" << endl;
    cout << "Cenario Otimo (mais 1h de sol): " << energiaMesMax << " kWh/mes" << endl;

    cout << endl << "Obrigado por usar o SolarSim!" << endl;

    return 0;
}
