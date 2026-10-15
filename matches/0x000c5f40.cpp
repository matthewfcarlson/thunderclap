struct Vec {
    int x, y, z;
    inline void set(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
    }
};
class Obj {
  public:
    char pad[8];
    Vec* v;
    char pad2[4];
    int* p;
    void update();
};
void fun(Obj* o, int a, int b, int c, int d, int e, int f, int g, int h) {
    o->v->set(a, b, c);
    *o->p = g;
    o->update();
    o->v->set(d, e, f);
    *o->p = h;
    o->update();
}