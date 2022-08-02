#include "UI.hpp"

Cell::Cell(int c){
    this->elements = new IRenderable* [c];
    this->elementsCount = 0;
    this->maxElementsCount = c;
}

Cell::~Cell(){
    for(int i = 0; i < this->elementsCount; i++){
        delete this->elements[i];
    }
    delete[] elements;
}

IRenderable* Cell::addElement(IRenderable* e){
    
    this->elements[this->elementsCount] = e;
    this->elementsCount++;
    return this->elements[this->elementsCount - 1];
}

IRenderable* Cell::getElement(int id){

    if(elements[id] != nullptr){
        return this->elements[id];
    }
    
    return nullptr;
}

void Cell::removeElement(int id){
    
    if(elements[id] != nullptr){
        this->elementsCount--;
        for(int o = id; o < this->elementsCount; o++){
            this->elements[o] = this->elements[o+1];
        }
    }
    
}

void Cell::display(){
    cout << "Cell displayed!" << endl;
    for(int i = 0; i < this->elementsCount; i++){
        this->elements[i]->display();
    }
}

void Cell::destroy(){
    cout << "Cell destroyed!" << endl;
}