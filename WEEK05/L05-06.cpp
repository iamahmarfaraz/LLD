// ABSTRACT FACTORY
#include <iostream>
#include <vector>
using namespace std;

// -------- Abstract Products --------
class Button {
public:
  string type;
  virtual void render() = 0;
};

class Checkbox {
public:
  string type;
  virtual void render() = 0;
};

// -------- Concrete Products --------
class MacButton : public Button {
public:
  MacButton() { type = "MacButton"; }
  void render() override { cout << "Rendering Mac Button" << endl; }
};

class WinButton : public Button {
public:
  WinButton() { type = "WinButton"; }
  void render() override { cout << "Rendering Windows Button" << endl; }
};

class MacCheckbox : public Checkbox {
public:
  MacCheckbox() { type = "MacCheckbox"; }
  void render() override { cout << "Rendering Mac Checkbox" << endl; }
};

class WinCheckbox : public Checkbox {
public:
  WinCheckbox() { type = "WinCheckbox"; }
  void render() override { cout << "Rendering Windows Checkbox" << endl; }
};

// -------- Abstract Factory --------
class UIFactory {
public:
  virtual Button *createButton() = 0;
  virtual Checkbox *createCheckbox() = 0;
};

// -------- Concrete Factories --------
class MacFactory : public UIFactory {
public:
  Button *createButton() override { return new MacButton(); }

  Checkbox *createCheckbox() override { return new MacCheckbox(); }
};

class WindowsFactory : public UIFactory {
public:
  Button *createButton() override { return new WinButton(); }

  Checkbox *createCheckbox() override { return new WinCheckbox(); }
};

// -------- Client --------
class Application {
public:
  UIFactory *factory;
  Button *button;
  Checkbox *checkbox;

  Application(UIFactory *fact) {
    factory = fact;
    button = factory->createButton();
    checkbox = factory->createCheckbox();
  }

  void buildUI() {
    cout << "UI Elements for platform:" << endl;
    button->render();
    checkbox->render();
    cout << endl;
  }

  ~Application() {
    delete button;
    delete checkbox;
  }
};

int main() {
  UIFactory *macFactory = new MacFactory();
  UIFactory *winFactory = new WindowsFactory();

  Application app1(macFactory);
  Application app2(winFactory);

  vector<Application *> apps = {&app1, &app2};
  for (auto app : apps)

  {
    app->buildUI();
  }

  delete macFactory;
  delete winFactory;

  return 0;
}
