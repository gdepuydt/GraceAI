#include <iostream>
#include "NeuralNet.h"

int main() {
	
	GraceAI::NeuralNet* n = new GraceAI::NeuralNet();

	n->AddInputLayer(10, 5);
	n->AddHiddenLayer(10);
	n->AddHiddenLayer(3);
	n->AddOutputLayer(4);

	delete n;

	return 0;
}