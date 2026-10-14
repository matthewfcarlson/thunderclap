struct R {
    int a;
    int b;
};
R __cdecl FUN_002672f0(int a, int b, int c);
class Obj {
  public:
    void Fn(int a);
    void Sub(int x, int y);
};
void Obj::Fn(int a) {
    R r = FUN_002672f0(a, 0, 0);
    Sub(r.a, r.b);
}
