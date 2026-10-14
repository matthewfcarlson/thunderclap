class Elem_1f93e0 {
  public:
    char Test(int, int, int, int, int, int, int, int, int, int);
};
class Obj_1f93e0 {
  public:
    char pad[0x6e0];
    int count;
    int Run(int, int, int, int, int, int, int, int, int, int);
};
int Obj_1f93e0::Run(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    int r = -1;
    if (count < 16) {
        if (((Elem_1f93e0*)((char*)this + (count * 5 + 0x8c) * 8))->Test(a, b, c, d, e, f, g, h, i, j)) {
            r = count;
            count = r + 1;
        }
    }
    return r;
}