class Elem {
  public:
    char Test(int, int, int, int, int, int, int, int, int, int);
};
class Obj {
  public:
    char pad[0x6e0];
    int count;
    int Run(int, int, int, int, int, int, int, int, int, int);
};
int Obj::Run(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    int r = -1;
    if (count < 16) {
        if (((Elem*)((char*)this + (count * 5 + 0x8c) * 8))->Test(a, b, c, d, e, f, g, h, i, j)) {
            r = count;
            count = r + 1;
        }
    }
    return r;
}