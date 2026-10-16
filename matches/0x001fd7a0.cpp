struct Pair {
    int a, b;
};
Pair __cdecl convert(int);
class Obj {
  public:
    int check(int, int);
    char run(int);
};
char Obj::run(int x) {
    Pair p = convert(x);
    return check(p.a, p.b) != 0;
}