#include "queue.h"
#include "element.h"
#include <iostream>
#include "element.h"


using namespace std;

void Queue::addElement(int newElement)
{
	size++;
	Element* elementsWithNewElement = new Element[size];
	for (int i = 0; i < size - 1; i++) {
		elementsWithNewElement[i] = elements[i];
	}
	elementsWithNewElement[size - 1].value = newElement;

	delete[] elements;
	elements = elementsWithNewElement;
}

void Queue::deleteElement()
{
	if (size == 0) { cout << "������� �����" << endl; return; }

	size--;
	Element* elementsWithoutLastElement = new Element[size];
	for (int i = 0; i < size; i++) {
		elementsWithoutLastElement[i] = elements[i + 1];
	}
	delete[] elements;
	elements = elementsWithoutLastElement;
}
void Queue::printQueue()
{
	if (size == 0) { cout << "Queue is empty. " << endl; return; }
	for (int i = 0; i < size; i++) {
		(size - 1 != i) ?
			cout << elements[i].value << ", " :
			cout << elements[i].value << ".";
	}
	cout << "\n";
}
Queue::Queue(){ // ������������� �������
	this->size = 0;
	elements = new Element[size];
}
Queue::Queue(const Queue &q) { // �������� ����� �������
	this->size = q.size;
	this->elements = new Element[size];
	for (int i = 0; i < size; i++) {
		elements[i].value = q.elements[i].value;
	}
}
// ����� ������ �� private
int Queue::getSize() { return this->size; }
int Queue::getElementValue(int numberElement) { return this->elements[numberElement].value; }
Element Queue::getElement(int numberElement) { return this->elements[numberElement]; }