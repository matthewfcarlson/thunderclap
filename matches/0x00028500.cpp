struct Pair {
    int a, b;
};
extern "C" Pair __cdecl Make(int, int, int);
class Obj {
  public:
    void* Find(int, int);
    unsigned char Test(int x);
};
unsigned char Obj::Test(int x) {
    Pair p = Make(x, 0, 0);
    unsigned char* q = (unsigned char*)Find(p.a, p.b);
    if (!q)
        return 0;
    return q[0x1b34];
}