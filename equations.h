//
// Created by Boss on 07.03.2023.
//

#ifndef COMPMATH2_EQUATIONS_H
#define COMPMATH2_EQUATIONS_H

#include <cmath>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
class equations {
public:
    function <double(double)> get_equation(int number){
        switch(number){
            case 1:{
                cout << "Выбранное уравнение: x^2 + 5x + 6 = 0" << endl;
                return [](double x){return pow(x, 2) + 5 * x + 6;};
            }
            case 2:{
                cout << "Выбранное уравнение: x^3 - 5x + 0,6 = 0" << endl;
                return [](double x){return pow(x, 3) - 5 * x + 0.6;};
            }
            case 3:{
                cout << "Выбранное уравнение: x^3 - 0,2x^2 + 0,5x + 1,5 = 0" << endl;
                return [](double x){return pow(x, 3) - 0.2 * pow(x, 2) + 0.5 * x + 1.5;};
            }
            case 4:{
                cout << "Выбранное уравнение: log2(4 - x) - 4 = 0" << endl;
                return [](double x){return log2(4 - x) - 4;};
            }

        }
    }
    vector<function<double(double, double)>> get_system(int number){
        vector<function<double(double, double)>> system;
        switch (number) {
            case 1:{
                cout << "Выбранная СНАУ: \nx1 + x2 - 3 = 0 \nx1^2 + x2^2 - 9 = 0" << endl;
                system.push_back([](double x1, double x2){return  x1 + x2 - 3;});
                system.push_back([](double x1, double x2){return pow(x1, 2) + pow(x2, 2) - 9;});
                return system;
            }
            case 2:{
                cout << "Выбранная СНАУ: \nx1 + 3lg(x1) - x2^2 = 0 \n2x1^2 - x1 * x2 - 5 * x1 + 1 = 0" << endl;
                system.push_back([](double x1, double x2){return  x1 + 3 * log10(x1) - pow(x2, 2);});
                system.push_back([](double x1, double x2){return 2 * pow(x1, 2) - x1 * x2 - 5 * x1 + 1;});
                return system;
            }
        }
    }

    double ** get_derivatives (vector<function<double(double, double)>> system, double h, double roots[]){
        double **mas;
        mas = new double *[system.size()];
        for (int i = 0; i < system.size(); i++){
            mas[i] = new double [system.size() + 1];
        }
        mas[0][0] = (system[0](roots[0] + h, roots[1]) - system[0](roots[0], roots[1])) / h;
        mas[0][1] = (system[0](roots[0], roots[1] + h) - system[0](roots[0], roots[1])) / h;
        mas[1][0] = (system[1](roots[0] + h, roots[1]) - system[1](roots[0], roots[1])) / h;
        mas[1][1] = (system[1](roots[0], roots[1] + h) - system[1](roots[0], roots[1])) / h;
        if (mas[0][0] * mas[1][1] - mas[0][1] * mas[1][0] == 0){
            cout << "Якобиан равен 0, метод не применим" << endl;
            return NULL;
        }
        else {
            return mas;
        }
    }
};


#endif //COMPMATH2_EQUATIONS_H
