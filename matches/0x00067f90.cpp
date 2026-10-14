class Base_67f90 {
  public:
    virtual void BaseFn();
    char pad[0x3c];
};

class Obj_67f90 : public Base_67f90 {
  public:
    virtual ~Obj_67f90() throw();
    bool Set(int v);
    int m40;
};

bool Obj_67f90::Set(int v) {
    m40 = v;
    return true;
}
