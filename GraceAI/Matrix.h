#pragma once

#include <malloc.h>

namespace GraceAI {

	class Matrix {
		float* data;
		int rows, columns;
		int total;

	public:
		Matrix(int rows, int columns) {
			this->rows = rows;
			this->columns = columns;
			this->total = rows * columns;
			//align alloc to 64 bytes for cache line size and AVX: performance reasons 
			data = (float*)_aligned_malloc(sizeof(float) * total, 64);
		}

		~Matrix() {
			_aligned_free(data);
		}

		float& operator() (int row, int col) {
			//check!
			return data[row * columns + col];
		}

		//Matrix dot product
		void MUL(Matrix& a, Matrix& b) {
			if (a.columns != b.rows) {
				throw "Columns of matrix A must equal rows of matrix B";
			}

			if (this == &a || this == &b) {
				throw "Destination matrix must be distinct from matrices A and B";
			}

			int sharedDim = a.columns;

			for (int r = 0; r < a.rows; r++) {
				for (int c = 0; c < b.columns; c++) {
					float total = 0.0f;
					for (int d = 0; d < sharedDim; d++) {

						total += a(r, d) * b(d, c);
					}

					this->operator()(r, c) = total;
				}
			}
		}

		void Hadamard(Matrix& a) {
			if (this->rows != a.rows || this->columns != a.columns) {
				throw "Matrixes must be of same dimension to Hadamard!";
			}
			for (int i = 0; i < this->total; i++) {
				data[i] *= a.data[i];
			}
		}

		void ADD(Matrix& a) {
			if (this->rows != a.rows || this->columns != a.columns) {
				throw "Matrixes must be of same dimension to Add!";
			}
			for (int i = 0; i < this->total; i++) {
				data[i] += a.data[i];
			}
		}

		void SUB(Matrix& a) {
			if (this->rows != a.rows || this->columns != a.columns) {
				throw "Matrixes must be of same dimension to Sub!";
			}
			for (int i = 0; i < this->total; i++) {
				data[i] -= a.data[i];
			}
		}

		void Randomize() {
			for (int i = 0; i < total; i++) {
				data[i] = (float)rand() / (float)RAND_MAX;
			}
		}

		void ADD_COLUMN_VECTOR(Matrix* colVec) {
			if (this.rows != colVec->rows || colvec->columns != 1) {
				throw("Column vector must have the same number of rows, and a single column.");
			}

			for (int c = 0; c < this->columns; c++) {
				for (int r = 0; r < this->rows; r++) {
					this->operator()(r, c) += colVec->operator()(r, 0);
				}
			}
		}
	};
}