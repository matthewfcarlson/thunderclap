class A_25bec0 {
  public:
    virtual void f0();
    virtual void* f1();
    virtual void* f2();
};
extern void* __cdecl helper(A_25bec0*);
extern "C" void* __cdecl FUN_0025bec0(A_25bec0* p) {
    void* q = p->f2();
    if ((*(unsigned int*)q & 15) == 4)
        return helper(p);
    return p;
}