#pragma once

#include <vector>
#include "Layer.h"
#include "TrainingSet.h"

namespace GraceAI {
	class NeuralNet {
		std::vector<Layer*> layers;
		TrainingSet* trainingSet;

	public:
		NeuralNet() {

		}

		~NeuralNet() {

		}

		void Init(int inputNeuronCount, int trainingSetBatchSize, int outputNeuronCount) {

		}

		void AddLayer(int neuronCount) {

		}

		void ForwardProp() {

		}

		void BackProp() {

		}
	};
}