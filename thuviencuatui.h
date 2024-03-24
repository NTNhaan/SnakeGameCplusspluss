#pragma once   // tránh dung do thu vien khi goi chong thu vien len nhau
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <ctime>   // thu vien ho tro ve thoi gian thuc
#include <windows.h>   // thu vien thay doi man hinh consol
using namespace std;

int whereX();

int whereY();

void gotoXY(int x, int y);

void SetColor(WORD color);

int inputKey();

void ShowCur();

