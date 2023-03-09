//
// Created by Boss on 09.03.2023.
//

#ifndef COMPMATH2_LINEAR_H
#define COMPMATH2_LINEAR_H

#include <cmath>

class linear {
public:
    void get_triangle(double **matrix, int size){
        //search of maximum in a column
        for (int i = 0; i < size; i++){
            int index = 0;
            double max = 0;
            for (int j = i; j < size; j++){
                if (abs(matrix[j][i]) > max){
                    max = abs(matrix[j][i]);
                    index = j;
                }
            }

            //swap rows if needed
            for (int j = i; j < size + 1; j++){
                double tmp = matrix[i][j];
                matrix[i][j] = matrix[index][j];
                matrix[index][j] = tmp;
            }
            if (matrix[i][i] == 0){
                return;
            }
            //rationing of the row with the max value
            for (int k = size; k >= i; k--)
                if (matrix[i][i] != 0)
                    matrix[i][k] = matrix[i][k] / matrix[i][i];

            //rationing of other rows
            for (int k = i + 1; k < size; k++)
                for (int j = size; j >= i; j--)
                    matrix[k][j] -= matrix[k][i] * matrix[i][j];
        }

    }

    double *get_answers(double **matrix, int size){
        answers = new double[size];
        //x_i = (b_i - sum(a_ij * x_j) / a_ii;
        for (int i = size - 1; i >= 0; i--){
            double sum = 0;
            for (int j = i + 1; j < size; j++){
                sum += matrix[i][j] * answers[j];
            }
            answers[i] = (matrix[i][size] - sum) / matrix[i][i];
        }

        return answers;
    }
private:
    double *answers;
};


#endif //COMPMATH2_LINEAR_H
