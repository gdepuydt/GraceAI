#pragma once

#include <vector>
#include "Layer.h"
#include "TrainingSet.h"

namespace GraceAI {
	class NeuralNet {
		std::vector<Layer*> layers;
		TrainingSet* trainingSet;
		int trainingSetBatchSize;

	public:
		NeuralNet() {

		}

		~NeuralNet() {
			for (Layer* l : layers) {
				delete l;
			}
			layers.clear();
		}

		void AddInputLayer(int inputNeuronCount, int trainingSetBatchSize) {
			if (layers.size() != 0) {
				throw "Error: Neural Net already has an input layer.";
			}

			this->trainingSetBatchSize = trainingSetBatchSize;
			Layer* inputLayer = new Layer(inputNeuronCount);
			inputLayer->SetInputLayerActivationMatrix(trainingSetBatchSize);
			layers.push_back(inputLayer);

		}

		void AddHiddenLayer(int neuronCount) {
			if (layers.size() < 1) {
				throw "Error: An input layer must be present prior to adding hidden layers, please call the AddInputLayer first.";
			}

			Layer* hiddenLayer = new Layer(neuronCount);
			//the back() function returns a pointer to the last element of the vector
			hiddenLayer->SetPreviousLayer(layers.back(), this->trainingSetBatchSize);
			layers.push_back(hiddenLayer);

		}

		void AddOutputLayer(int neuronCount) {
			AddHiddenLayer(neuronCount);
		}

		void ForwardProp() {
			if (layers.size() < 1) {
				throw "Net cannot feed forward, tehre are not enough layers.";
			}
			
			layers[0]->FeedForward();
		}

		void BackProp() {

		}
	};
}