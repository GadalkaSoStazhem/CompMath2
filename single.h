//
// Created by Boss on 08.03.2023.
//

#ifndef COMPMATH2_SINGLE_H
#define COMPMATH2_SINGLE_H

#include "equations.h"

#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

class single {
public:
    void bisection(function<double(double)> func, double a, double b, double eps){
        double answer = NULL;
        double st_a = a;
        double st_b = b;

        clock_t begin = clock();

        while (abs(a - b) > eps){
            double tmp = (a + b) / 2;
            if (round(abs(func(tmp) - 0) / eps) * eps <= eps)
                answer = round(tmp / eps) * eps;
            if (func(a) * func(tmp) < 0)
                b = tmp;
            else {
                if (func(tmp) * func(b) < 0)
                    a = tmp;
                else
                    break;
            }
        }
        double time = (clock() - begin) / (double) CLOCKS_PER_SEC;
        io.print_answer(st_a, st_b, answer);
        cout << "Время выполнения: " << time << endl;
    }

    void secant (function<double(double)> func, double a, double b, double eps){
        double answer = NULL;
        double st_a = a;
        double st_b = b;

        clock_t begin = clock();

        while (abs(a - b) > eps){
            double h = NULL;
            double tmp = NULL;
            if (func(a) < 0 && func(b) > 0){
                h = (-1) * (func(a) / (func(b) - func(a))) * (b - a);
                tmp = a + h;
            }
            else{
                h = (-1) * (func(b) / (func(a) - func(b))) * (a - b);
                tmp = b + h;
            }

            if (round(abs(func(tmp) - 0) / eps) * eps <= eps){
                answer = round(tmp / eps) * eps;
                break;
            }
            if (func(a) * func(tmp) < 0)
                b = tmp;
            else {
                if (func(tmp) * func(b) < 0)
                    a = tmp;
                else
                    break;
            }
        }
        double time = (clock() - begin) / (double) CLOCKS_PER_SEC;
        io.print_answer(st_a, st_b, answer);
        cout << "Время выполнения: " << time << endl;
    }
private:
    io io;
};



#endif //COMPMATH2_SINGLE_H
