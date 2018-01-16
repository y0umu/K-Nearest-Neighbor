// stdafx.cpp : 只包括标准包含文件的源文件
// K-Nearest Neighbor.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用


// 使qsort成为升序排序的比较函数
int compareByDistance(const void *vect1, const void *vect2) {
	double a = ((Vect *)vect1)->tmpDistance;
	double b = ((Vect *)vect2)->tmpDistance;
	return a > b ? 1 : (a < b ? -1 : 0);
}

// 距离计算函数
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

// 数组找最大值
size_t findMax(const int *a, size_t nLen) {
	size_t indexOfMax = 0;  // 最大值所在的下标
	for (size_t i = 1; i < nLen; i++) {
		if (a[i] > a[indexOfMax]) {
			indexOfMax = i;
		}
	}
	return indexOfMax;
}

// 确定测试数据的分类，由knn函数调用
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

// 判断待测数据testData的分类，返回size_t类型的分类代号
// nDims是训练数据、测试数据向量的维度数
// nTypes是样本空间的分类数总数（有几种类别）
// k是近邻数，默认取1
size_t knn(Vect trainData[], size_t numTrainData , Vect *testData,
	         size_t nDims, size_t nTypes, size_t k=1) {
	size_t testDataType;
	assert(k >= 1);

	// 计算距离
	for (size_t i = 0; i < numTrainData; i++) {
		trainData[i].tmpDistance = distanceCalc(trainData[i].arr, testData->arr, nDims);
	}
	Vect *A = new Vect[numTrainData];   // 只对A排序，而不打乱原来的trainData空间
	size_t bytesToCopy = (numTrainData * sizeof(Vect));
	memcpy_s(A, bytesToCopy, trainData, bytesToCopy);

	qsort(A, k, sizeof(Vect), compareByDistance);    // 对A中的前k个元素排序
	double maxDistance = A[k - 1].tmpDistance;

	for (size_t i = k; i < numTrainData; i++) {
		if (A[i].tmpDistance < maxDistance) {
			memcpy_s((A + k - 1), sizeof(Vect), (A + i), sizeof(Vect));
			qsort(A, k, sizeof(Vect), compareByDistance);    // 对A中的前k个元素排序
			maxDistance = A[k - 1].tmpDistance;
		}
	}
	testDataType = determineType(A, nTypes, k);
	delete[] A;
	testData->vtype = testDataType;
	return testDataType;
}