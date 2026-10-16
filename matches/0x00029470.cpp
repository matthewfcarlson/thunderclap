struct Pair {
    unsigned a, b;
};
extern "C" Pair __cdecl lookup(int, int, int);
class Result {
  public:
    void finish();
};
class Obj {
  public:
    Result* get(unsigned, unsigned);
    void run(int);
};
void Obj::run(int x) {
    Pair p = lookup(x, 0, 0);
    Result* r = get(p.a, p.b);
    if (r)
        r->finish();
}