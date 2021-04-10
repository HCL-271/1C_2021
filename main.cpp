	#include<iostream>
	#include<stdio.h>
	#include<string>
	//#include<vector>
	#include<map>
	#include <cmath>
	using namespace std;
// Я ошибся с датой в форме и собирался решать задачу в пн, поэтому не был готов.
// Поэтому в этом коде может содержаться конечное число багов
// В любом случае, спасибо тому, кто читает этот код. Надеюсь и верю, что мне удастся пройти.
	int main() 
	{


		int arr[10000][10000] = { {} };//Допустим, что мы считали изображение в массив 10000 на 10000 пикселей
		//Белые пиксели - 0, черные - 1
		// Пусть (0;0) - это верхний левый угол
		int up_x;
		int up_y;
		for (int i = 0; i < 10000; i++) //Найдем первую точку сверху, причем мы идем слева сверху
		{
			for (int j = 0; j < 10000; j++) {
				if (arr[i][j] == 1) {
					up_x = j;
					up_y = i;
				}
			}

		}
		int down_x, down_y;
		for (int i = 10000; i >= 0; i = i -1) //Теперь найдем первую точку снизу, причем мы идем слева снизу
		{
			for (int j = 0; j < 10000; j++) {
				if (arr[i][j] == 1) {
					down_x = j;
					down_y = i;
				}
			}

		}

		int left_x = 0, left_y;
		for (int i = 0; i < 10000; i++) //Теперь найдем первую точку слева, причем мы идем сверху вниз, слева направо
		{
			for (int j = 0; j < 10000; j++) {
				if (arr[j][i] == 1) {
					left_x = i;
					left_y = j;
				}
			}

		}

		int right_x = 0;
		int right_y = 0;
		for (int i = 10000; i >= 0 ; i = i - 1) //Теперь найдем первую точку справа, и мы также идем сверху вниз, справа налево.
		{
			for (int j = 0; j < 10000; j++) {
				if (arr[j][i] == 1) {
					right_x = i;
					right_y = j;
				}
			}

		}

		/* Нам очень важно идти именно описанными методами, так как если у нас есть треугольник с горизонтальной стороной сверху,
		то так как мы ищем верхнюю точку слева, а правую справа, то даже для горизонтальной стороны, верхняя точка будет самой левой, а 
		правая - самой правой.*/
		double l1;
		double l2;
		double angle;
		double ang2;
		double l3;
		double p;
		double sq;

		int a;
		int b;
		int angla1;
		int angla2;
		
        //Когда у нас есть 4 точки, проверим их на попарное совпадение, если оно есть - это треугольник
		if (((up_x == right_x) && (up_y == right_y)) || ((down_x = right_x) && (down_y == right_y)) || ((down_x == left_x) && (down_y == left_y)) || ((left_x == up_x) && (left_y == up_y)))
		{
			if ((up_x == right_x) && (up_y == right_y)) //берем случай совпадения двух точек и считаем для него
			{
				l1 = sqrt((up_x - left_x) ^ 2 + (up_y - left_y) ^ 2);
				l2 = sqrt((up_x - down_x) ^ 2 + (up_y - down_y) ^ 2);
				l3 = sqrt((left_x - down_x) ^ 2 + (left_y - down_y) ^ 2);

			}

			if ((down_x == right_x) && (down_y == right_y)) // Просто переберем 4 случая попарных совпадений точек
			{
				l1 = sqrt((down_x - left_x) ^ 2 + (down_y - left_y) ^ 2);
				l2 = sqrt((down_x - up_x) ^ 2 + (down_y - up_y) ^ 2);
				l3 = sqrt((left_x - up_x) ^ 2 + (left_y - up_y) ^ 2);

			}

			if ((down_x == left_x) && (down_y == left_y)) // Просто переберем 4 случая попарных совпадений точек
			{
				l1 = sqrt((down_x - right_x) ^ 2 + (down_y - right_y) ^ 2);
				l2 = sqrt((down_x - up_x) ^ 2 + (down_y - up_y) ^ 2);
				l3 = sqrt((right_x - up_x) ^ 2 + (right_y - up_y) ^ 2);

			}

			if ((up_x == left_x) && (up_y == left_y)) //берем случай совпадения двух точек и считаем для него
			{
				l1 = sqrt((up_x - right_x) ^ 2 + (up_y - right_y) ^ 2);
				l2 = sqrt((up_x - down_x) ^ 2 + (up_y - down_y) ^ 2);
				l3 = sqrt((right_x - down_x) ^ 2 + (right_y - down_y) ^ 2);
			}

			
			//Найдем полупериметр, а затем площадь по формуле Герона, после чего выразим угол
			p = (l1 + l2 + l3) / 2;
			sq = sqrt(p * (p - l1) * (p - l2) * (p - l3));
			angle = 2 * sq / (l1 * l2);
			ang2 = 2 * sq / (l2 * l3);
			a = (int)l1;
			b = (int)l2;
			angla1 = (int)angle;
			angla2 = (int)ang2;
			std::cout << angla1 << " - angle 1 " << angla2 << " - angle 2 " << b << " - lenght of side "<< "Triangle" << endl;
			return 0;

		}

		//Если точек 4, то это либо окружность, либо прямоугольник. Для проверки на прямоугольник возьмем точку на середине отрезка между двумя краевыми точками. 
		//Если она черная - то это прямоугольник, если белая - окружность.
		double length = 0;
		double length1 = 0;
		int lg = 0;
		int lg2 = 0;

		if(((arr[(up_x + left_x) / 2][(up_y + left_y) / 2])) == 1) 
		{
			//Если это прямоугольник, то просто найдем длину стороны.
			length = sqrt((up_x - left_x) ^ 2 + (up_y - left_y) ^ 2);
			length1 = sqrt((up_x - right_x) ^ 2 + (up_y - right_y) ^ 2);
			
			lg = (int)length;
			lg2 = (int)length1;
			if (lg == lg2) 
			{					//Делаем проверку на равенство смежных сторон, если да, то квадрат.
				std::cout << lg << " - length " << "Square";
			}
			else // Если стороны не равны - это прямоугольник
				//rectangle
			{
				std::cout << lg << " - length of one side " << lg2 << " - length of another side " << "Rectangle";
			}
			return 0;
		}

		//Если же точка на отрезке белая - то отрезок хорда. Тогда возьмем самые левые и правые точки. Как окружность не крути, она окружностью останется, а эти точки будут концами диаметра.

		int diamt = 0;
		diamt = right_x - left_x;
		std:: cout << diamt << " " << "Round";


		return 0;
	}

	
