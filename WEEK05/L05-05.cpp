// FACTORY METHOD
#include <iostream>
using namespace std;

class Button {
public:
    virtual void render() = 0;
};

class WindowsButton : public Button {
public:
    void render() override {
        cout << "Rendering Windows Button" << endl;
    }
};

class MacButton : public Button {
public:
    void render() override {
        cout << "Rendering Mac Button" << endl;
    }
};

// Factory Method interface
class Dialog {
public:
    virtual Button* createButton() = 0;

    void renderWindow() {
        Button* btn = createButton();
        btn->render();
        delete btn;
    }
};

// Subclasses implement factory method
class WindowsDialog : public Dialog {
public:
    Button* createButton() override {
        return new WindowsButton();
    }
};

class MacDialog : public Dialog {
public:
    Button* createButton() override {
        return new MacButton();
    }
};

int main() {
    Dialog* dialog = new WindowsDialog();
    dialog->renderWindow();

    delete dialog;

    dialog = new MacDialog();
    dialog->renderWindow();

    delete dialog;
}
