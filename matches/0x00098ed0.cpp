class H {
  public:
    void A(void*);
    void B(void*);
};
class Obj {
  public:
    char pad[0xb0];
    H* a;
    H* b;
    H* f;
    H* c;
    H* d;
    H* e;
    void Run(void*);
};
void Obj::Run(void* arg) {
    if (a)
        a->A(arg);
    if (b)
        b->A(arg);
    if (c)
        c->A(arg);
    if (d)
        d->A(arg);
    if (e)
        e->A(arg);
    if (f)
        f->B(arg);
}