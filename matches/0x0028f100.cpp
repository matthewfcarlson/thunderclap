extern "C" void _ReadWriteBarrier();
extern void* g_vftable_0042cb44[];
class Ref_28f100 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_28f100 {
  public:
    void* vptr;
    void Fin();
};
class Shader_28f100 : public Entity_28f100 {
  public:
    char pad[12];
    Ref_28f100* m;
    ~Shader_28f100();
};
Shader_28f100::~Shader_28f100() {
    vptr = g_vftable_0042cb44;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
