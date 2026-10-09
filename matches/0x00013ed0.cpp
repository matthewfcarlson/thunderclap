class A {
  public:
    char pad[0x1c];
    void* p1;
    void* p2;
    char pad2[0x10];
    int m34;
    int m38;
};
struct B {
    char pad[0x10];
    unsigned char flag;
};
struct C {
    char pad[0x11c];
    B* b;
};
struct D {
    char pad[0x30];
    int x;
    int y;
};
class X {
  public:
    C* f();
};
class Y {
  public:
    C* f();
};
bool __fastcall FUN_00013ed0(A* self) {
    C* c = ((X*)self->p1)->f();
    c = ((Y*)c)->f();
    if (!c || !c->b || !c->b->flag) {
        D* d = (D*)self->p2;
        if (d->x > 0 && self->m34 >= d->x && d->y > 0 && self->m38 >= d->y)
            return true;
    }
    return false;
}