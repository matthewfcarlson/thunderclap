class C {
  public:
    int value;
    C* Set(int x);
};
C* C::Set(int x) {
    value = x;
    return this;
}
