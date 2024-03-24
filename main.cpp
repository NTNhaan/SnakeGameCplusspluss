#include <iostream>
#include "thuviencuatui.h"
#define MAX 100
using namespace std;
int sl = 3;
void Ve_tuong_tren()
{
	int x = 10, y = 1;
	while(x < 100)
	{
		gotoXY(x, y);
		cout<<"_";
		x++;
	}
}
void Ve_tuong_duoi()
{
	int x = 10, y = 26;
	while(x <= 100)
	{
		gotoXY(x, y);
		cout<<"_";
		x++;
	}
}
void Ve_tuong_trai()
{
	int x = 10, y = 2;
	while(y <= 26)
	{
		gotoXY(x, y);
		cout<<"|";
		y++;
	}
}
void Ve_tuong_phai()
{
	int x = 100, y = 2;
	while(y <= 26)
	{
		gotoXY(x, y);
		cout<<"|";
		y++;
	}
}
void ve_tuong()
{
	SetColor(13);
	Ve_tuong_tren();
	Ve_tuong_duoi();
	Ve_tuong_trai();
	Ve_tuong_phai();
}
void tao_ran(int toadoX[] ,int toadoY[])
{
	int x = 50, y = 13;
	for(int i=0 ; i<sl ; i++)
	{
		toadoX[i] = x;
		toadoY[i] = y;
		x--;
	}
}
void ve_conran(int toadoX[], int toadoY[])
{
	for(int i=0 ; i<sl ; i++)
	{
		gotoXY(toadoX[i], toadoY[i]);
		{
			if(i == 0)
			{
				cout<<"O";
			}
			else
			{
				cout<<"o";
			}
		}
	}
}
void xoa_dulieu_cu(int toadoX[], int toadoY[])
{
	for(int i=0 ; i<sl ; i++)
	{
		gotoXY(toadoX[i], toadoY[i]);
		cout<<" ";
	}
}
void them(int a[], int x)
{
	for(int i=sl ; i>0 ; i--)
	{
		a[i] = a[i-1];
	}
	a[0] = x;
	sl++;
}
void xoa(int a[], int vt)
{
	for(int i=vt ; i<sl ; i++)
	{
		a[i] = a[i+1];
	}
	sl--;
}

bool ran_cham_tuong(int x0, int y0)
{
	if(y0 == 1 && x0>=10 && x0<=100)
	{
		return true; // gameover
	}
	else if(y0 == 26 && x0>=10 && x0<=100)
	{
		return true;
	}
	else if(x0 == 100 && y0>=1 && y0<=26)
	{
		return true;
	}
	else if(x0 == 10 && y0>=1 && y0<=26)
	{
		return true;
	}
	return false;
}
bool ran_cham_than(int toadoX[], int toadoY[])
{
	for(int i=1 ; i<sl ; i++)
	{
		if(toadoX[0] == toadoX[i] && toadoY[0] == toadoY[i])
		{
			return true;
		}
	}
	return false;
}
bool ktra_ran(int toadoX[], int toadoY[])
{
	bool kt1 = ran_cham_than(toadoX, toadoY); // gameover == true
	bool kt2 = ran_cham_tuong(toadoX[0], toadoY[0]);  // gameover == false
	if(kt1 == true || kt2 == true)
	{
		return true;
	}
	return false;
}
bool ktra_ran_de_qua(int xqua, int yqua, int toadoX[], int toadoY[])
{
	for(int i=0 ; i<sl ; i++)
	{
		if(xqua == toadoX[i] && yqua == toadoY[i]) 
		{
			return true;
		}
	}
	return false;
}
void tao_qua(int &xqua, int &yqua, int toadoX[],int toadoY[])
{
	do
	{
		xqua = rand() % (99 - 11 + 1) + 11;
		yqua = rand() % (25 - 2 + 1) + 2;
	}while(ktra_ran_de_qua(xqua, yqua, toadoX, toadoY) == true);
	int i=rand() % (15 -1 + 1) + 1;
	SetColor(i);
	gotoXY(xqua, yqua);
	cout<< "*";
	SetColor(7);
}
bool ran_an_qua(int xqua, int yqua, int x0, int y0)
{
	if(x0 == xqua && y0 == yqua)
	{
		return true;
	}
	return false;
}
void xu_ly_ran(int toadoX[], int toadoY[], int x, int y, int &xqua, int &yqua)
{
	int dem=0;
	them(toadoX, x);
	them(toadoY, y);
	if(ran_an_qua(xqua, yqua, toadoX[0], toadoY[0]) == false)
	{
		xoa(toadoX, sl - 1);
		xoa(toadoY, sl - 1);
	}
	else
	{
		tao_qua(xqua, yqua, toadoX, toadoY);
		dem++;
	}
	ve_conran(toadoX, toadoY);
}
int main()
{
	int xqua=0, yqua=0, x0, y0;
	int dem;
	bool gameover = false;
	int toadoX[MAX], toadoY[MAX];
	ve_tuong();
	tao_ran(toadoX,toadoY);
	ve_conran(toadoX, toadoY);
	
	if(ran_an_qua(xqua,yqua,x0,y0) == true)
	{
		dem++;
		gotoXY(120, 10);
		cout<<"diem: " << dem;
	}
	
	// ktra và tao qua
	srand(time(NULL)); // ham random qua xuat hien tren map
	
	tao_qua(xqua, yqua, toadoX, toadoY);
	
	int x = 50, y = 13;
	int check = 2;
	// 0: di xuong
	// 1: di len
	// 2: di qua phai
	// 3: di qua trai
	while(gameover == false)
	{
	 	// backspace
		xoa_dulieu_cu(toadoX, toadoY);
		if(kbhit())
		{
			char kytu = getch();
			if(kytu == 'w'&& check != 0)
			{
				check = 1;
			}
			else if(kytu == 's' && check != 1)
			{
				check = 0;
			}
			else if(kytu == 'd' && check != 3)
			{
				check = 2;
			}
			else if(kytu == 'a' && check != 2)
			{
				check = 3;
			}
		}
		//ktra huong
		if(check == 0)
		{
			y++;
		}
		else if(check == 1)
		{
			y--;
		}
		else if(check == 2)
		{
			x++;
		}
		else if(check == 3)
		{
			x--;
		}
		xu_ly_ran(toadoX, toadoY, x, y, xqua, yqua);
		//KTRA
		gameover = ktra_ran(toadoX, toadoY);
		Sleep(150);
	}
	getch();
	return 0;
}


