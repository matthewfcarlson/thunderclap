typedef unsigned int size_t;
void* operator new(size_t) throw();
namespace pure3d {
class Shadow {
  public:
    virtual void f0();
    Shadow(Shadow*) throw();
};
class ShadowMeshBuffer : public Shadow {
    char pad[0x58 - sizeof(Shadow)];

  public:
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual ShadowMeshBuffer* vfunc_4();
    ShadowMeshBuffer(ShadowMeshBuffer* p) throw() : Shadow(p) {}
};
ShadowMeshBuffer* ShadowMeshBuffer::vfunc_4() {
    return new ShadowMeshBuffer(this);
}
} // namespace pure3d