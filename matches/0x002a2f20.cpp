class C_2a2f20 {
    char pad[0x58];

  public:
    int a, b, c;
    void Get(int* x, int* y, int* z);
};
void C_2a2f20::Get(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}