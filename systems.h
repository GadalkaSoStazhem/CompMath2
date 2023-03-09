//
// Created by Boss on 08.03.2023.
//

#ifndef COMPMATH2_SYSTEMS_H
#define COMPMATH2_SYSTEMS_H
#include "equations.h"
#include "linear.h"

#include <iostream>
using namespace std;
class systems {
public:
    void get_ans(int number, double a, double b, double eps){
        int cnt = 0;
        bool flag = true;
        auto syst = eq.get_system(number);
        double deltas[] = {a, b};
        auto ders = eq.get_derivatives(syst, eps, deltas);
        set_lin_system(linear_system, ders, deltas, syst);

        calc.get_triangle(linear_system, syst.size());
        double* epses = new double [syst.size()];
        epses = calc.get_answers(linear_system, syst.size());

        while (!(max(abs(epses[0]), abs(epses[1])) <= eps)){
            deltas[0] += epses[0];
            deltas[1] += epses[1];
            set_lin_system(linear_system, ders, deltas, syst);
            calc.get_triangle(linear_system, syst.size());
            epses = calc.get_answers(linear_system, syst.size());
            cnt ++;
            if (cnt > 10000){
                cout << "Неправильно выбраны начальные приближения корней" << endl;
                flag = false;
            }

        }
        deltas[0] += epses[0];
        deltas[1] += epses[1];
        if (flag){
            cout << "Найденные корни СНАУ: " << endl;
            cout << "x1 " << round(deltas[0] / eps) * eps << endl;
            cout << "x2 " << round(deltas[1] / eps) * eps << endl;
        }

    }
private:
    equations eq;
    linear calc;
    double **linear_system;
    void set_lin_system(double **lin_system, double **ders, double deltas[], vector<function<double(double, double)>> syst){
        linear_system = new double * [syst.size()];
        for (int i = 0; i < syst.size(); i++){
            linear_system[i] = new double [syst.size() + 1];
            for (int j = 0; j <= syst.size(); j++){
                if (j != syst.size()){
                    linear_system[i][j] = ders[i][j];
                }
                else {
                    linear_system[i][j] = (-1) * syst[i](deltas[0], deltas[1]);
                }
            }
        }
    }

};


#endif //COMPMATH2_SYSTEMS_H
