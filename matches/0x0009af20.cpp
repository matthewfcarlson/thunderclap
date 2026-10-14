struct B_9af20 {
    unsigned char v;
};
struct Obj_9af20 {
    void invoke(B_9af20, B_9af20, B_9af20, B_9af20, B_9af20, unsigned char, int);
};
typedef void (Obj_9af20::*CB)(B_9af20, B_9af20, B_9af20, B_9af20, B_9af20, unsigned char, int);
struct Rec_9af20 {
    B_9af20 a;
    char p[3];
};
void f(Obj_9af20* obj, Rec_9af20* r, int unused2, CB cb) {
    B_9af20 a = (r++)->a, b = (r++)->a, c = (r++)->a, d = (r++)->a, e = (r++)->a;
    (obj->*cb)(a, b, c, d, e, r->a.v, *(int*)(r + 1));
}