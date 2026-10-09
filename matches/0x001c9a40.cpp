class C {
  public:
    C* helper(int, int, unsigned);
    C* target(unsigned);
};
C* C::target(unsigned p) {
    helper(3, 0xb0, p);
    return this;
}
