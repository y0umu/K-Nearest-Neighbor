// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <search.h>
#include <assert.h>
#include <math.h>
#include <memory.h>  // memcpy_s
/********************************************************/
// 类型定义  !已弃用
//enum VectType {
//	V_TYPE_1 = 0, V_TYPE_2, V_TYPE_3
//};

#define VECT_DIM 2
struct Vect {
	double arr[2];
//	size_t dim = VECT_DIM;  // 维度
	double tmpDistance = -1.0;     // 当前向量与待测向量的距离
	size_t vtype;           // 用无符号整数表示不同的分类
};
/********************************************************/
// 函数声明
int compareByDistance(const void *vect1, const void *vect2);
double distanceCalc(double *a, double *b, size_t dim);
size_t findMax(const int *a, size_t nLen);
size_t determineType(Vect *A, size_t nTypes, size_t k);
size_t knn(Vect trainData[], size_t numTrainData, Vect *testData,	size_t nDims, size_t nTypes, size_t k);
