class Thing_1c3950 {
    char pad[0x64];

  public:
    int a;
    int b;
    void Get(int* x, int* y);
};
void Thing_1c3950::Get(int* x, int* y) {
    *x = a;
    *y = b;
}