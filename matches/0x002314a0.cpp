class A {
  public:
    unsigned int x;
    unsigned int y;
    A(unsigned int);
};
A::A(unsigned int v) {
    x = v;
    y = 0;
}