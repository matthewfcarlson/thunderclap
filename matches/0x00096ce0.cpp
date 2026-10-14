struct Vec3_96ce0 {
    int x, y, z;
};
class Provider_96ce0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual Vec3_96ce0* Get();
};
struct Holder_96ce0 {
    char pad[0x20];
    Provider_96ce0* p;
};
class Obj_96ce0 {
  public:
    char pad0[0x40];
    int x, y, z;
    char pad1[0x28];
    Holder_96ce0* h;
};
bool FUN_00096ce0(Obj_96ce0* self, Vec3_96ce0* out, int* scalar) {
    bool r = false;
    Holder_96ce0* h = self->h;
    if (h && h->p) {
        Provider_96ce0* p = h->p;
        Vec3_96ce0* v = p->Get();
        out->x = v->x;
        out->y = v->y;
        out->z = v->z;
        *scalar = *(int*)((char*)p + 0x34);
        r = true;
    } else {
        out->x = self->x;
        out->y = self->y;
        out->z = self->z;
        *scalar = 0x3f800000;
    }
    return r;
}
