struct Pair {
    unsigned a, b;
};
Pair __cdecl FUN_002672f0(int, int, int);
class Obj {
  public:
    void Fn(int);
    void Next(Pair);
};
void Obj::Fn(int x) {
    Pair p = FUN_002672f0(x, 0, 0);
    Next(p);
}