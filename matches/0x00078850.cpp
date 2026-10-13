class X {
  public:
    X* f();
};
X* X::f() {
    return this;
}
