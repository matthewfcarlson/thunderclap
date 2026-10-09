class CollisionSolverAgent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual int vfunc_6(void*, int, void*, int, int, int, int, int*, int*);
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    char pad[4];
    void* member;
};
class Obj {
  public:
    char pad[0x6c];
    int state;
    void helper(int);
};
class Ref {
  public:
    char pad[0x20];
    int state;
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void*, int, void*, int, int, int, int);
};
int CollisionSolverAgent::vfunc_6(void* a, int b, void* c, int d, int e, int f, int g, int* p, int* q) {
    if (*p && !((Ref*)*p)->state && !((Obj*)a)->state)
        ((Obj*)a)->helper(1);
    if (*q && !((Ref*)*q)->state && !((Obj*)c)->state)
        ((Obj*)c)->helper(1);
    if (member)
        ((Ref*)member)->f4(a, b, c, d, e, f, g);
    return 0;
}