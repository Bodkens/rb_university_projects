#include "UI.hpp"
Label::Label(int x, int y, bool v){
    this->pos.first = x;
    this->pos.second = y;
    this->visible = v;
}
Label::Label(int x, int y, bool v, string t){
    this->pos.first = x;
    this->pos.second = y;
    this->visible = v;
    this->text = t;
}
Label::Label(int x, int y, bool v, string t, string bgc){
    this->pos.first = x;
    this->pos.second = y;
    this->visible = v;
    this->text = t;
    this->backgroundColor = bgc;
}
void Label::display(){
    std::cout << "Label appeared!" << std::endl;
    std::cout << "X position: " <<  this->pos.first << std::endl;
    std::cout << "Y position: " << this->pos.second << std::endl;
    std::cout <<  "Visible: " << ((this->visible) ? "True" : "False") << std::endl;
    std::cout <<  "Background Color: " << this->backgroundColor << std::endl;
}
void Label::destroy(){
    std::cout << "Label destroyed!" << std::endl;
}
bool Label::isVisible(){
    return this->visible;
}
void Label::setVisible(bool vis){
    this->visible = vis;
}
void Label::toggleVisible(){
    this->visible = !this->visible;
}

string Label::getText(){
    return this->text;
}
void Label::setText(string t){
    this->text = t;
}
string Label::getBackgroundColor(){
    return this->backgroundColor;
}
void Label::setBackgroundColor(string bt){
    this->backgroundColor = bt;
}

void Label::setPosition(int x, int y){
    this->pos.first = x;
    this->pos.second = y;
}
pair<int, int> Label::getPosition(){
    return this->pos;
}
