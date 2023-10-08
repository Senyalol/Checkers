#pragma once
#include "Shashka.h"


// Циферки для удобства
void Numbers(vector<vector<char>>& display);
 
// Границы доски
void Tablo(vector<vector<char>>& display);

// вывести доску в консоль
void ShowTablo(vector<vector<char>>& display);

// функция для проверки на строку или число
bool isNumber(const string& str);