class Source {
  public:
    int Get();
};
extern Source gSource;
struct Pair {
    int a, b;
};
extern Pair gPair;
extern Pair __cdecl Make(int, int, int);
void FUN_0035eeb0() {
    int n = gSource.Get();
    Pair p = Make(n, 0, 0);
    gPair = p;
}