#include "algoritmos/checa_balanceamento.h"

#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
    stack<int> lifo;
    // Primeiro loop (* e /)
    bool mult_incoming = false;
    bool div_incoming = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {
            lifo.push(s[i]);
            mult_incoming = true;
            continue;
        }
        if (s[i] == '/') {
            lifo.push(s[i]);
            div_incoming = true;
            continue;
        }
        if (s[i] == '+' || s[i] == '-') {
            continue;
        }
        if (mult_incoming) {
            lifo.push(s[i]);
            mult_incoming = false;
            // Multiplicar dois números do top
            int elemento1 = lifo.top() - '0';
            lifo.pop();
            lifo.pop();
            int elemento2 = lifo.top() - '0';
            std::cout << elemento2 << "\n";
            lifo.pop();
            
            lifo.push(elemento1 * elemento2);

            continue;
        }
        if (div_incoming) {
            lifo.push(s[i]);
            for (int i = 0; lifo.size(); i++) {
                std::cout << lifo.top() - '0' << "\n";
                lifo.pop();
            }
            /*
            std::cout << s[i] << "\n";
            div_incoming = false;

            int elemento1 = lifo.top() - '0'; 
            lifo.pop();
            std::cout << "Abaixo de 2 : " << lifo.top() - '0' << "\n";
            lifo.pop();
            std::cout << "Abaixo de / : " << lifo.top() - '0' << "\n";
            std::cout << "Elemento 1: " << elemento1 << "\n";
            int elemento2 = lifo.top() - '0';
            lifo.pop();
            std::cout << "Elemento2: " << elemento2 << "\n";
            
            lifo.push(elemento2 / elemento1);
            */
            continue;
        }
        lifo.push(s[i]);
    }
}

int main() {
    std::string s = "3*5/2";
    solve(s);
}