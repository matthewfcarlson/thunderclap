extern int gVtable;
class Base {
  public:
    virtual void V();
    Base(int);
};
class Obj : public Base {
  public:
    Obj(int a, int b);
    char pad[0xc];
    int m10;
};
Obj::Obj(int a, int b) : Base(a) {
    *(int*)this = (int)&gVtable;
    m10 = b;
}
