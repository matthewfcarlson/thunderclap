class A {
  public:
    char pad[0x298];
    unsigned int x;
    unsigned int target();
};
unsigned int A::target() {
    return x;
}