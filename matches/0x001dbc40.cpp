// Same code shape as 0x00090450 (propagated; names are from that function)
class X {
  public:
    char pad[8];
    void f();
    X* target();
};
X* X::target() {
    f();
    ((X*)((char*)this + 8))->f();
    return this;
}