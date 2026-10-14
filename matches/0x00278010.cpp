class Obj_278010 {
  public:
    char pad[0x1c];
    int state;
    int A(int, int, int, int, int, int, int, int, int);
    int B(int, int, int, int, int, int, int, int, int);
    int Target(int a, int b, int c, int d, int e, int f, int g, int h, int i);
};
int Obj_278010::Target(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    switch (state) {
    case 0:
        return A(a, b, c, d, e, f, g, h, i);
    case 1:
        return B(a, b, c, d, e, f, g, h, i);
    default:
        return 0;
    }
}