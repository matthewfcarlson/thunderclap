struct Pair_28b190 {
    float x, y;
};
class Obj_28b190 {
  public:
    void Get(int, Pair_28b190*);
};
void F(Pair_28b190* out, Obj_28b190* a, Obj_28b190* b, float t, int n) {
    Pair_28b190 p, q;
    a->Get(n, &p);
    b->Get(n, &q);
    p.x = (q.x - p.x) * t + p.x;
    p.y = (q.y - p.y) * t + p.y;
    *out = p;
}