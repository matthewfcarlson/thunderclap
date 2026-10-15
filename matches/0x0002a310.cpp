struct Pair {
    unsigned a, b;
};
Pair __cdecl findPair(int, int, int);
class Obj {
  public:
    Obj* get(unsigned a, unsigned b);
    void act(int);
    void run(int x);
};
void Obj::run(int x) {
    Pair p = findPair(x, 0, 0);
    Obj* q = get(p.a, p.b);
    if (q)
        q->act(1);
}