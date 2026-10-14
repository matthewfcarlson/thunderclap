class C_90470 {
    char pad[8];

  public:
    void f();
};
class S_90470 {
  public:
    void h();
};
void C_90470::f() {
    ((S_90470*)((char*)this + 8))->h();
    ((S_90470*)this)->h();
}