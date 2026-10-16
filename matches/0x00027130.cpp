struct Pair {
    int a, b;
};
Pair __cdecl other(int, int, int);
class Obj {
  public:
    void use(int, int);
    void fn(int x, int y);
};
void Obj::fn(int x, int y) {
    Pair p = other(x, 0, 0);
    use(p.a, p.b);
}