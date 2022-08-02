#include <iostream>
#include "UI.hpp"

int main(){
    Label * l = new Label(1,2, true, "Hello World!", "Magenta");
    Row * row = new Row(3, 10);
    Image * im = new Image(1,1,"image.txt", true);
    row->addCell(1)->addElement(new Label(0,0, true, "FirstLabel", "Black"));
    row->addCell(1)->addElement(new Button(0,0, true, "Button", "Black"));
    row->addCell(1)->addElement(im);
    vector<IRenderable*> window;
    window.push_back(l);
    window.push_back(row);

    for(IRenderable* renderer : window){
        renderer->display();
        renderer->destroy();
    }
    //delete im;
    delete l;
    delete row;
    
}