//
// Created by Boss on 08.03.2023.
//

#ifndef COMPMATH2_IO_H
#define COMPMATH2_IO_H

#include <iostream>

using namespace std;

class io {
public:
    int get_task(){
        int task;
        cin >> task;
        if (!(task == 1 | task == 2)){
            cout << "Неверные данные" << endl;
            return NULL;
        }
        return task;
    }
    int get_example(int task){
        int example;
        cin >> example;
        switch (task){
            case 1:{
                if (example < 1 | example > 4){
                    cout << "Неверный номер примера" << endl;
                    return NULL;
                }
                return example;
            }
            case 2: {
                if (example < 1 | example > 2){
                    cout << "Неверный номер примера" << endl;
                    return NULL;
                }
                return example;
            }
        }
    }
    double get_accuracy(){
        double eps;
        cin >> eps;
        if (eps > 1 || eps < 0){
            cout << "Точность указана неверно" << endl;
            return NULL;
        }
        return eps;
    }
    void print_answer(double a, double b, double answer){
        if (answer == NULL)
            cout << "На интервале [" << a << ", " << b << "] корней нет" << endl;
        else
            cout << "Корень на интервале [" << a << ", " << b <<"]:  " << answer << endl;
    }
    void print_answers(double roots[], double eps){
        cout << "Найденные корни СНАУ: " << endl;
        for (int i = 0; i < 2; i++){
            cout << "x" << i << ":  " << round(roots[i] / eps) * eps << endl;
        }
    }
};


#endif //COMPMATH2_IO_H
