struct Pair {
    float x, y;
};
class Obj {
  public:
    void Get(int, Pair*);
};
void F(Pair* out, Obj* a, Obj* b, float t, int n) {
    Pair p, q;
    a->Get(n, &p);
    b->Get(n, &q);
    p.x = (q.x - p.x) * t + p.x;
    p.y = (q.y - p.y) * t + p.y;
    *out = p;
}