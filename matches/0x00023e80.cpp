struct Pair {
    unsigned a, b;
};
Pair __cdecl FUN_002672f0(int, int, int);
class Obj {
  public:
    int Fn(int);
    int Next(Pair);
};
int Obj::Fn(int x) {
    Pair p = FUN_002672f0(x, 0, 0);
    return Next(p);
}