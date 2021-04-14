#include <bits/stdc++.h>

template<typename T>
bool checa_balanceamento(std::string string_input, std::map<T, T> mapa) {

    std::stack<T> lifo;
    bool balanceado = true;

    for (int i = 0; i < string_input.size(); i++) {
        if (mapa.find(string_input[i]) != mapa.end()) {
            lifo.push(mapa[string_input[i]]);
        } else if (!lifo.empty() && lifo.top() == string_input[i]) {
            lifo.pop();
        } else {
            balanceado = false;
            break;
        }
    }
    if (!lifo.empty()) balanceado = false;
    return balanceado;
}