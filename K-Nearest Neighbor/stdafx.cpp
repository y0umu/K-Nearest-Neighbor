// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// K-Nearest Neighbor.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO: �� STDAFX.H �������κ�����ĸ���ͷ�ļ���
//�������ڴ��ļ�������


// ʹqsort��Ϊ��������ıȽϺ���
int compareByDistance(const void *vect1, const void *vect2) {
	double a = ((Vect *)vect1)->tmpDistance;
	double b = ((Vect *)vect2)->tmpDistance;
	return a > b ? 1 : (a < b ? -1 : 0);
}

// ������㺯��
double distanceCalc(double *a, double *b, size_t dim) {
	assert(dim > 0);
	double sum = 0.0;
	double diff;
	for (size_t i = 0; i < dim; i++) {
		diff = a[i] - b[i];
		sum += (diff * diff);
	}
	return sqrt(sum);
}

// ���������ֵ
size_t findMax(const int *a, size_t nLen) {
	size_t indexOfMax = 0;  // ���ֵ���ڵ��±�
	for (size_t i = 1; i < nLen; i++) {
		if (a[i] > a[indexOfMax]) {
			indexOfMax = i;
		}
	}
	return indexOfMax;
}

// ȷ���������ݵķ��࣬��knn��������
size_t determineType(Vect *A, size_t nTypes, size_t k) {
	size_t typ;
	int *typeCntArr = new int[nTypes];
	for (size_t i = 0; i < nTypes; i++) {
		typeCntArr[i] = 0;
	}
	for (size_t i = 0; i < k; i++) {
		(typeCntArr[A[i].vtype])++;
	}
	typ = findMax(typeCntArr, nTypes);
	delete[] typeCntArr;
	return typ;
}

// �жϴ�������testData�ķ��࣬����size_t���͵ķ������
// nDims��ѵ�����ݡ���������������ά����
// nTypes�������ռ�ķ������������м������
// k�ǽ�������Ĭ��ȡ1
size_t knn(Vect trainData[], size_t numTrainData , Vect *testData,
	         size_t nDims, size_t nTypes, size_t k=1) {
	size_t testDataType;
	assert(k >= 1);

	// �������
	for (size_t i = 0; i < numTrainData; i++) {
		trainData[i].tmpDistance = distanceCalc(trainData[i].arr, testData->arr, nDims);
	}
	Vect *A = new Vect[numTrainData];   // ֻ��A���򣬶�������ԭ����trainData�ռ�
	size_t bytesToCopy = (numTrainData * sizeof(Vect));
	memcpy_s(A, bytesToCopy, trainData, bytesToCopy);

	qsort(A, k, sizeof(Vect), compareByDistance);    // ��A�е�ǰk��Ԫ������
	double maxDistance = A[k - 1].tmpDistance;

	for (size_t i = k; i < numTrainData; i++) {
		if (A[i].tmpDistance < maxDistance) {
			memcpy_s((A + k - 1), sizeof(Vect), (A + i), sizeof(Vect));
			qsort(A, k, sizeof(Vect), compareByDistance);    // ��A�е�ǰk��Ԫ������
			maxDistance = A[k - 1].tmpDistance;
		}
	}
	testDataType = determineType(A, nTypes, k);
	delete[] A;
	testData->vtype = testDataType;
	return testDataType;
}