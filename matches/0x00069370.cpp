class Obj_69370 {
  public:
    char pad[0x30];
    int a;
    int b;
    int c;
    int d;
    void f(int);
};
void callee(int, int, int, int, int);
void Obj_69370::f(int x) {
    callee(b, a, d, c, x);
}