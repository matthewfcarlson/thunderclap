class Base {
  public:
    virtual void BaseFn();
    char pad[0x3c];
};

class Obj : public Base {
  public:
    virtual ~Obj() throw();
    bool Set(int v);
    int m40;
};

bool Obj::Set(int v) {
    m40 = v;
    return true;
}
