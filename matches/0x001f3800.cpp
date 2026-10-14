// Same code shape as 0x00090470 (propagated; names are from that function)
class C_1f3800 {
    char pad[8];

  public:
    void f();
};
class S_1f3800 {
  public:
    void h();
};
void C_1f3800::f() {
    ((S_1f3800*)((char*)this + 8))->h();
    ((S_1f3800*)this)->h();
}