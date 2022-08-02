#include "UI.hpp"
Button::Button(int x, int y, bool v) : Label(x,y,v){
    
}
Button::Button(int x, int y, bool v, string t): Label(x,y,v,t){
   
}
Button::Button(int x, int y, bool v, string t, string bgc) : Label(x,y,v,t,bgc){
    
}
void Button::display(){
    std::cout << "Button appeared!" << std::endl;
    std::cout << "X position: " <<  this->getPosition().first << std::endl;
    std::cout << "Y position: " << this->getPosition().second << std::endl;
    std::cout <<  "Visible: " << ((this->isVisible()) ? "True" : "False") << std::endl;
    std::cout <<  "Background Color: " << this->getBackgroundColor() << std::endl;
}
void Button::destroy(){
    std::cout << "Button destroyed!" << std::endl;
}