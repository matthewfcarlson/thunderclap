// Same code shape as 0x00090470 (propagated; names are from that function)
class C_1dbc60 {
    char pad[8];

  public:
    void f();
};
class S_1dbc60 {
  public:
    void h();
};
void C_1dbc60::f() {
    ((S_1dbc60*)((char*)this + 8))->h();
    ((S_1dbc60*)this)->h();
}