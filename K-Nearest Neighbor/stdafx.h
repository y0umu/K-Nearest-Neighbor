// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
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
// ���Ͷ���  !������
//enum VectType {
//	V_TYPE_1 = 0, V_TYPE_2, V_TYPE_3
//};

#define VECT_DIM 2
struct Vect {
	double arr[2];
//	size_t dim = VECT_DIM;  // ά��
	double tmpDistance = -1.0;     // ��ǰ��������������ľ���
	size_t vtype;           // ���޷���������ʾ��ͬ�ķ���
};
/********************************************************/
// ��������
int compareByDistance(const void *vect1, const void *vect2);
double distanceCalc(double *a, double *b, size_t dim);
size_t findMax(const int *a, size_t nLen);
size_t determineType(Vect *A, size_t nTypes, size_t k);
size_t knn(Vect trainData[], size_t numTrainData, Vect *testData,	size_t nDims, size_t nTypes, size_t k);
