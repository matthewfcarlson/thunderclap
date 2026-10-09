class A {
  public:
    virtual void f0();
    virtual void* f1();
    virtual void* f2();
};
extern void* __cdecl helper(A*);
void* __cdecl target(A* p) {
    void* q = p->f2();
    if ((*(unsigned int*)q & 15) == 4)
        return helper(p);
    return p;
}