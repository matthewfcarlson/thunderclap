class Obj {
  public:
    char pad[0x18];
    int a;
    int b;
    int c;
    void Get(int* x, int* y, int* z);
};
void Obj::Get(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}