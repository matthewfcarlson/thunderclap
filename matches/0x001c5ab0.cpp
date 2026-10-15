class Item {
  public:
    virtual void f();
    void g(int);
    char pad[4];
};
class Obj {
    char pad[8];

  public:
    void h(Item*, void*);
    void fn(Item*, int);
};
void Obj::fn(Item* p, int x) {
    if (p) {
        p->f();
        p->g(x);
        ((Obj*)((char*)this + 8))->h((Item*)((char*)p + 8), p);
    }
}