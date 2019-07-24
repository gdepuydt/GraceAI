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

		}

		void SetPreviousLayer(Layer* previousLayer) {

		}

		void FeedForward() {

		}

		void Backprop() {

		}

	};
}