#include <bits/stdc++.h>
using namespace std;


vector<int> solve(vector<int>& heights) {
    int maior = 0;
    vector<int> resposta;
    for (int i = heights.size() - 1; i >= 0; i--) {
        int indice = i;
        if (heights[i] > maior) {
            maior = heights[i];
            resposta.insert(resposta.begin(), i);
        }
    }
    return resposta;
}

int main() {
    vector<int> v = {1, 5, 5, 2, 3};
    vector<int> resposta = solve(v);
    for (int i = 0; i < resposta.size(); i++) {
        cout << resposta[i] << "\n";
    }
    return 0;
}