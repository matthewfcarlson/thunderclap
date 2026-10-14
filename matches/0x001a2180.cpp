class Base {
  public:
    Base() {}
    virtual ~Base() {}
};

class Obj {
  public:
    char pad[0x20];
    int mValue;
    bool Set(int v);
};

bool Obj::Set(int v) {
    mValue = v;
    return true;
}
