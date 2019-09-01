#pragma once

#include "Matrix.h"

namespace GraceAI {
	class Layer {
		Matrix* activations;
		Matrix* sums;
		Matrix* weights;
		Matrix* bias;

		Matrix* deltaActivations;
		Matrix* deltaSums;
		Matrix* deltaWeights;
		Matrix* deltaBias;

		int neuronCount;

		Layer* previousLayer;
		Layer* nextLayer;

	public:
		Layer(int neuronCount) {
			this->neuronCount = neuronCount;
		}

		~Layer() {
			delete activations;
			delete deltaActivations;
			delete sums;
			delete deltaSums;
			delete weights;
			delete deltaWeights;
			delete bias;
			delete deltaBias;
		}

		void SetInputLayerActivationMatrix(int batchSize) {
			activations = new Matrix(this->neuronCount, batchSize);
		}

		void SetPreviousLayer(Layer* previousLayer, int batchSize) {
			
			activations = new Matrix(this->neuronCount, batchSize);
			deltaActivations = new Matrix(this->neuronCount, batchSize);
			
			sums = new Matrix(this->neuronCount, batchSize);
			deltaSums = new Matrix(this->neuronCount, batchSize);
			
			weights = new Matrix(this->neuronCount, previousLayer->neuronCount);
			weights->Randomize();
			deltaWeights = new Matrix(this->neuronCount, previousLayer->neuronCount);
			
			bias = new Matrix(this->neuronCount, 1);
			bias->Randomize();
			deltaBias = new Matrix(this->neuronCount, 1);

			this->previousLayer = previousLayer;
			previousLayer->nextLayer = this;
		}

		void FeedForward() {
			sums->MUL(*weights, *previousLayer->activations);
			sums->ADD_COLUMN_VECTOR(bias);

			if (nextLayer != nullptr) {
				
				//TODO: Perform the activation function
				
				nextLayer->FeedForward();
			}
		}

		void Backprop() {

		}

	};
}