extern const int Expression_vftable;
void __cdecl operator delete[](void*);
class Expression {
  public:
    virtual void f0();
    virtual void f1();
    virtual Expression* f2(int);
    virtual void f3();
    virtual void f4();
    int pad[4];
    void* a;
    void* b;
    void Do();
};
extern void __cdecl FreeObj(void*);
Expression* Expression::f2(int x) {
    Expression* p = this;
    void* q = p->a;
    *(const int**)p = &Expression_vftable;
    operator delete[](q);
    q = p->b;
    operator delete[](q);
    p->Do();
    if (x & 1)
        FreeObj(p);
    return p;
}
