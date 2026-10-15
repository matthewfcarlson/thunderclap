struct Pair {
    int a, b;
};
Pair __cdecl Lookup(int);
class Obj {
  public:
    int Find(int, int);
    unsigned char Do(int);
    unsigned char Run(int);
};
unsigned char Obj::Run(int x) {
    unsigned char r = 0;
    Pair p = Lookup(x);
    int i = Find(p.a, p.b);
    if (i != -1)
        r = Do(i);
    return r;
}