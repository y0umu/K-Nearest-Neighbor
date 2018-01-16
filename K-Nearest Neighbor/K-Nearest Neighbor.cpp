// K-Nearest Neighbor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main(int argc, char** argv) {
	//Vect trainData[9] = {
	//	{ {0.6213, 0.7373}, -1, V_TYPE_1  },
	//	{ { 0.5226, 0.8939 },-1, V_TYPE_1 },
		//{ { 0.9797, 0.6614 },-1, V_TYPE_1 },
		//{ { 0.9568, 0.0118 },-1, V_TYPE_2 },
		//{ { 0.8801, 0.1991 },-1, V_TYPE_2 },
		//{ { 0.8757, 0.0648 },-1, V_TYPE_2 },
		//{ { 0.1730, 0.2987 },-1, V_TYPE_3 },
		//{ { 0.2714, 0.2844 },-1, V_TYPE_3 },
		//{ { 0.2523, 0.4692 },-1, V_TYPE_3 }
	//};
/* 不知道是不是我写错了还是微软的的编译器不支持上面这种结构体初始化方法…… */

	Vect trainData[9];
	trainData[0].arr[0] = 0.6213; trainData[0].arr[1] = 0.7373; trainData[0].vtype = 0;
	trainData[1].arr[0] = 0.5226; trainData[1].arr[1] = 0.8939; trainData[1].vtype = 0;
	trainData[2].arr[0] = 0.9797; trainData[2].arr[1] = 0.6614; trainData[2].vtype = 0;
	trainData[3].arr[0] = 0.9568; trainData[3].arr[1] = 0.0118; trainData[3].vtype = 1;
	trainData[4].arr[0] = 0.8801; trainData[4].arr[1] = 0.1991; trainData[4].vtype = 1;
	trainData[5].arr[0] = 0.8757; trainData[5].arr[1] = 0.0648; trainData[5].vtype = 1;
	trainData[6].arr[0] = 0.1730; trainData[6].arr[1] = 0.2987; trainData[6].vtype = 2;
	trainData[7].arr[0] = 0.2714; trainData[7].arr[1] = 0.2844; trainData[7].vtype = 2;
	trainData[8].arr[0] = 0.2523; trainData[8].arr[1] = 0.4692; trainData[8].vtype = 2;

	Vect testData[5];
	testData[0].arr[0] = 0.9883; testData[0].arr[1] = 0.4329;
	testData[1].arr[0] = 0.5828; testData[1].arr[1] = 0.2259;
	testData[2].arr[0] = 0.4235; testData[2].arr[1] = 0.5798;
	testData[3].arr[0] = 0.5155; testData[3].arr[1] = 0.7604;
	testData[4].arr[0] = 0.3340; testData[4].arr[1] = 0.5298;

	for (size_t i = 0; i < 5; i++) {
		size_t tpy = knn(trainData, 9, testData + i, VECT_DIM, 3, 2);
		printf("Type of testData_%d (%.4f, %.4f) is type %d\n", 
			     i, testData[i].arr[0], testData[i].arr[1], (tpy+1));
	}
    return 0;
}

