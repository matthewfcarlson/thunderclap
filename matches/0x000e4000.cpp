class A_e4000 {
  public:
    char pad[0x298];
    unsigned int x;
    unsigned int target();
};
unsigned int A_e4000::target() {
    return x;
}