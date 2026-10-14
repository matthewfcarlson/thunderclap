class Thing_2c4200 {
  public:
    char pad[0x74];
    int a;
    int b;
    int c;
    void Get(int* x, int* y, int* z);
};
void Thing_2c4200::Get(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}