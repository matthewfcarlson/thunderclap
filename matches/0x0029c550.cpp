class C {
    char pad[0x24];
    int value;

  public:
    int f(int x);
};
int C::f(int x) {
    return x * 0x40 + value;
}