class C {
    char pad[0x17c];
    float a;
    char pad2[0x30];
    float b;

  public:
    int f(int);
};
int C::f(int x) {
    return a >= b;
}