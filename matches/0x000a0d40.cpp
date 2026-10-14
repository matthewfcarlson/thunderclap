// Same code shape as 0x000187d0 (propagated; names are from that function)
class A_a0d40 {
  public:
    virtual void f();
    virtual void g();
};
void FUN_000187d0(A_a0d40** p) {
    if (*p) {
        (*p)->g();
        *p = 0;
    }
}