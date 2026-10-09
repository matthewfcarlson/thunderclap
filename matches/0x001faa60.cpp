extern int gameVftable;
extern int creatorVftable;
class Ref {
  public:
    virtual void Release(int);
};
class Obj {
  public:
    int* vptr;
    Ref* mRef;
    void f();
};
void Obj::f() {
    vptr = &gameVftable;
    if (mRef)
        mRef->Release(1);
    vptr = &creatorVftable;
}