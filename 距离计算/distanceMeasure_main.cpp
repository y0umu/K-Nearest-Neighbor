#include <stdio.h>
#include <math.h>
#include <assert.h>

// dim ÊÇÎ¬¶È
double distance(double *a, double *b, size_t dim) {
	assert(dim > 0);
	double sum = 0.0;
	double diff;
	for (size_t i = 0; i < dim; i++) {
		diff = a[i] - b[i];
		sum += (diff * diff);
	}
	return sqrt(sum);
}

int main() {
#define LEN 3
	double trainData[LEN][2] = { 
		   { 0.6213, 0.7373 },
		   { 0.5226, 0.8939 },
		   { 0.9797, 0.6614 }
	};
	double testData[2] = { 0.9883, 0.4329 };
	for (int i = 0; i < LEN; i++) {
		printf("trainData_%d=(%f,%f)  %f\n",i, trainData[i][0], trainData[i][1], distance(trainData[i], testData, 2));
	}

	return 0;
}