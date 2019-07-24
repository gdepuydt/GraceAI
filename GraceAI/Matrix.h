#pragma once

namespace GraceAI {

	class Matrix {
		double* data;
		int rows, columns;
		int total;

	public:
		Matrix(int rows, int columns) {
			this->rows = rows;
			this->columns = columns;
			this->total = rows * columns;
			//align alloc to 64 bytes for cach line and AVX: performance reasons 
			data = (double*)_aligned_malloc(sizeof(double) * total, 64);
		}

		~Matrix() {
			_aligned_free(data);
		}
	};
}