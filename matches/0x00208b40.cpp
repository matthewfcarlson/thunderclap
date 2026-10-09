class A {
  public:
    char pad[4];
    signed char count;
    void F(unsigned short x);
};
void A::F(unsigned short x) {
    *(unsigned short*)(pad + 6 + count * 2) = x;
    ++count;
}