class Obj_1c1750 {
  public:
    char pad[0xd0];
    int a;
    int b;
    void Get(int* x, int* y);
};
void Obj_1c1750::Get(int* x, int* y) {
    if (x)
        *x = a;
    if (y)
        *y = b;
}