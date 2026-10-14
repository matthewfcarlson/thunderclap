class A_13ed0 {
  public:
    char pad[0x1c];
    void* p1;
    void* p2;
    char pad2[0x10];
    int m34;
    int m38;
};
struct B_13ed0 {
    char pad[0x10];
    unsigned char flag;
};
struct C_13ed0 {
    char pad[0x11c];
    B_13ed0* b;
};
struct D {
    char pad[0x30];
    int x;
    int y;
};
class X_13ed0 {
  public:
    C_13ed0* f();
};
class Y_13ed0 {
  public:
    C_13ed0* f();
};
bool __fastcall FUN_00013ed0(A_13ed0* self) {
    C_13ed0* c = ((X_13ed0*)self->p1)->f();
    c = ((Y_13ed0*)c)->f();
    if (!c || !c->b || !c->b->flag) {
        D* d = (D*)self->p2;
        if (d->x > 0 && self->m34 >= d->x && d->y > 0 && self->m38 >= d->y)
            return true;
    }
    return false;
}