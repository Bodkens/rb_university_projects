#include "UI.hpp"
Image::Image(int x, int y,string p, bool v){
    this->pos.first = x;
    this->pos.second = y;
    this->path = p;
    this->visible = v;
}

bool Image::isVisible(){
    return this->visible;
}

void Image::setVisible(bool v){
    this->visible = v;
}

void Image::toggleVisible(){
    this->visible = !this->visible;
}

string Image::getPath(){
    return this->path;
}

void Image::setPath(string p){
    this->path = p;
}

void Image::setPosition(int x, int y){
    this->pos.first = x;
    this->pos.second = y;
}
pair<int, int> Image::getPosition(){
    return this->pos;
}   

void Image::display(){
    std::cout << "Image appeared!" << std::endl;
    std::cout << "X position: " <<  this->pos.first << std::endl;
    std::cout << "Y position: " << this->pos.second << std::endl;
    std::cout <<  "Visible: " << ((this->visible) ? "True" : "False") << std::endl;
    std::cout <<  "Path " << this->path << std::endl;
}
void Image::destroy(){
    std::cout << "Image destryed!" << std::endl;
}