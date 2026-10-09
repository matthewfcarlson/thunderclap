class C {
    char pad[0x118];
    int slots[10];

  public:
    void f(int x);
};
void C::f(int x) {
    int i = 0;
    while (i < 10 && slots[i] != 0)
        ++i;
    if (i != 10)
        slots[i] = x;
}