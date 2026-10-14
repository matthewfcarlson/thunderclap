// Same code shape as 0x00090450 (propagated; names are from that function)
class X_1dbc40 {
  public:
    char pad[8];
    void f();
    X_1dbc40* target();
};
X_1dbc40* X_1dbc40::target() {
    f();
    ((X_1dbc40*)((char*)this + 8))->f();
    return this;
}