//
// Created by Earl Leonarda on 14/02/2020.
//

#ifndef TASK1_TASK1_HPP
#define TASK1_TASK1_HPP
using namespace std;

#define USAGE "Usage: [number] [baseSrc] [baseDst]\nExample: 111 01 0123456789\nThe number can only consist of baseSrc characters.\nThe base can only consist of various characters."

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

bool	checkBase(string base);
bool	checkNb(string nb, string base);
string	itoBase(string nb, string baseSrc, string baseDst);

#endif //TASK1_TASK1_HPP
