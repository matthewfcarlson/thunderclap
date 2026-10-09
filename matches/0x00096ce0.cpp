struct Vec3 { int x,y,z; };
class Provider { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual Vec3* Get(); };
struct Holder { char pad[0x20]; Provider* p; };
class Obj { public: char pad0[0x40]; int x,y,z; char pad1[0x28]; Holder* h; };
bool FUN_00096ce0(Obj* self, Vec3* out, int* scalar) {
    bool r = false;
    Holder* h = self->h;
    if (h && h->p) {
        Provider* p = h->p;
        Vec3* v = p->Get();
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
