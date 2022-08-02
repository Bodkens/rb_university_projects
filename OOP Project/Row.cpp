#include "UI.hpp"

Row::Row(int c, int h){
    this->cells = new Cell * [c];
    this->height = h;
    this->cellsCount = 0;
    this->maxCellsCount = c;
}

Row::~Row(){
    for(int i = 0; i < this->cellsCount; i++){
        delete this->cells[i];
    }
    
    delete[] cells;
}

void Row::display(){
    cout << "Row displayed!" << endl;
    cout << "Height:" << this->height <<  endl;
    for(int i = 0; i < this->cellsCount; i++){
        this->cells[i]->display();
    }
}

void Row::destroy(){
    cout << "Row destroyed!" << endl;
}

Cell* Row::addCell(int c){
    this->cells[this->cellsCount] = new Cell(c);
    this->cellsCount++;
    return this->cells[this->cellsCount - 1];
}
Cell* Row::getCell(int id){
    
    if(cells[id] != nullptr){
        return this->cells[id];
    }
    return nullptr;
}
void Row::removeCell(int id){
    if(cells[id] != nullptr){
        this->cellsCount--;
        for(int o = id; o < this->cellsCount; o++){
            this->cells[o] = this->cells[o+1];
        }
    }
}
