class X {
  public:
    X* Fn();
};
X* X::Fn() {
    return this;
}
