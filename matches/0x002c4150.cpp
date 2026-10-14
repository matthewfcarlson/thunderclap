// Same code shape as 0x002a2f20 (propagated; names are from that function)
class C_2c4150 {
    char pad[0x58];

  public:
    int a, b, c;
    void Get(int* x, int* y, int* z);
};
void C_2c4150::Get(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}