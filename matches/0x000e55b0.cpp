class X_e55b0 {
    char pad[0xab4];
    unsigned int value;

  public:
    void f(unsigned int a, unsigned int b, unsigned int c);
};
void X_e55b0::f(unsigned int a, unsigned int b, unsigned int c) {
    value = ((a | 0xffffff00) << 8 | b) << 8 | c;
}