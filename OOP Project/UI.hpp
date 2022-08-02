#include <string>
#include <vector>
#include <iostream>
using namespace std;


class IRenderable{
public:
    virtual void display() = 0;
    virtual void destroy() = 0;
    virtual ~IRenderable(){

    }

};
class Label : public IRenderable{
    private: 
    bool visible;
    string text;
    string backgroundColor;
    pair<int, int> pos;
    public:

    Label(int x, int y, bool v);
    Label(int x, int y, bool v, string t);
    Label(int x, int y, bool v, string t, string bgc);

    string getText();
    void setText(string t);
    string getBackgroundColor();
    void setBackgroundColor(string bt);
    
    void setPosition(int x, int y);
    pair<int, int> getPosition();

    bool isVisible();
    void setVisible(bool vis);
    void toggleVisible();
    
    void display();
    void destroy();
};
class Button : public Label{
    public:
    Button(int x, int y, bool v);
    Button(int x, int y, bool v, string t);
    Button(int x, int y, bool v, string t, string bgc);
    void onClick();
    void onHold();
    void display() override;
    void destroy();
};
class Image : public IRenderable{
    private:
    bool visible;
    string path;
    pair<int, int> pos;
    public:
    Image(int x, int y, string p, bool v);
    void onClick();
    void onHold();
    void display();
    void destroy();

    bool isVisible();
    void setVisible(bool vis);
    void toggleVisible();

    string getPath();
    void setPath(string p);

    void setPosition(int x, int y);
    pair<int, int> getPosition();
};
class Cell : public IRenderable{
    private:
    IRenderable** elements;
    int elementsCount;
    int maxElementsCount;
    public:
    Cell(int c);
    ~Cell();

    IRenderable* addElement(IRenderable* e);
    IRenderable* getElement(int id);
    void removeElement(int id);

    void display();
    void destroy();
};
class Row : public IRenderable {
    private:
    pair<int, int> cords;
    Cell** cells;
    int cellsCount;
    int maxCellsCount;
    int height;
    public:
    Row(int c, int h);
    ~Row();

    Cell* addCell(int c);
    void removeCell(int id);
    Cell* getCell(int id);
    
    void display();
    void destroy();
};