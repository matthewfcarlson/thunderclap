typedef unsigned char byte;
struct Alloc { void f(void*, unsigned int); };
extern Alloc g_4e2210;
class ProjectileMissile { public: void tick(); virtual void a(); virtual void b(); virtual ProjectileMissile* vfunc_2(byte); virtual void d(); virtual void e(); virtual void f(); virtual void g(); };
ProjectileMissile* ProjectileMissile::vfunc_2(byte param_2) {
    tick();
    if (param_2 & 1) g_4e2210.f(this, 0xdc);
    return this;
}