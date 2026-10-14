class Base_1a2180 {
  public:
    Base_1a2180() {}
    virtual ~Base_1a2180() {}
};

class Obj_1a2180 {
  public:
    char pad[0x20];
    int mValue;
    bool Set(int v);
};

bool Obj_1a2180::Set(int v) {
    mValue = v;
    return true;
}
