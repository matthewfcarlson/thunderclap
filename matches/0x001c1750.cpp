class Obj {
  public:
    char pad[0xd0];
    int a;
    int b;
    void Get(int* x, int* y);
};
void Obj::Get(int* x, int* y) {
    if (x)
        *x = a;
    if (y)
        *y = b;
}