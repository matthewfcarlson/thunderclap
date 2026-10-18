struct R {
    int a;
    int b;
};
R __cdecl FUN_002672f0(int a, int b, int c);
class Obj {
  public:
    int Fn(int a);
    int Sub(int x, int y);
};
int Obj::Fn(int a) {
    R r = FUN_002672f0(a, 0, 0);
    return Sub(r.a, r.b);
}
