class Obj_69370 {
  public:
    char pad[0x30];
    int a;
    int b;
    int c;
    int d;
    float f(int);
};
float callee(int, int, int, int, int);
float Obj_69370::f(int x) {
    return callee(b, a, d, c, x);
}