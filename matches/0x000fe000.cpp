// Same code shape as 0x000187d0 (propagated; names are from that function)
class A_fe000 {
  public:
    virtual void f();
    virtual void g();
};
void FUN_000fe000(A_fe000** p) {
    if (*p) {
        (*p)->g();
        *p = 0;
    }
}