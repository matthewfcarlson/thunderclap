extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2bf9f0[];
void operator delete[](void*);
class Ref_2bf9f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_2bf9f0 {
  public:
    void* vptr;
    void Fin();
};
class ImageFont_2bf9f0 : public Entity_2bf9f0 {
  public:
    char pad4[0x24];
    Ref_2bf9f0* m28;
    char pad2c[8];
    char* m34;
    ~ImageFont_2bf9f0() throw();
};
ImageFont_2bf9f0::~ImageFont_2bf9f0() throw() {
    vptr = g_vftable_2bf9f0;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m34)
        operator delete[](m34 - 4);
    Fin();
}
