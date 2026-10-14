class A_187d0 {
  public:
    virtual void f();
    virtual void g();
};
void FUN_000187d0(A_187d0** p) {
    if (*p) {
        (*p)->g();
        *p = 0;
    }
}