class Thing_1c38f0 {
    char pad[0x5c];
    int a;
    int b;

  public:
    void Get(int* x, int* y);
};
void Thing_1c38f0::Get(int* x, int* y) {
    *x = a;
    *y = b;
}