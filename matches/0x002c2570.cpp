extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2c2570[];
void operator delete(void*);
class Ref_2c2570 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_2c2570 {
  public:
    void* vptr;
    void Fin();
};
class Texture_2c2570 : public Entity_2c2570 {
  public:
    char pad[0x10 - 4];
    Ref_2c2570* m;
    Texture_2c2570* f2(unsigned char flags);
};
Texture_2c2570* Texture_2c2570::f2(unsigned char flags) {
    vptr = g_vftable_2c2570;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
