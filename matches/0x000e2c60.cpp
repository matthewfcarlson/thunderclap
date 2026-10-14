class C_e2c60 {
    char pad[0x118];
    int slots[10];

  public:
    void f(int x);
};
void C_e2c60::f(int x) {
    int i = 0;
    while (i < 10 && slots[i] != 0)
        ++i;
    if (i != 10)
        slots[i] = x;
}