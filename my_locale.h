//
// Created by Boss on 07.03.2023.
//

#ifndef COMPMATH2_MY_LOCALE_H
#define COMPMATH2_MY_LOCALE_H

#include <locale>

using namespace std;

class my_locale : public numpunct<char> {
public:
    char do_decimal_point() const {
        return ',';
    }
};


#endif //COMPMATH2_MY_LOCALE_H
