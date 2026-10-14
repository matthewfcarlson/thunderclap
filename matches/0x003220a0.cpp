class Ref_3220a0 {
  public:
    virtual void f0();
    virtual void f1();
};
struct Block_3220a0 {
    unsigned int x[16];
};
class pure3d_d3dExtGlobalProjectedTexture {
  public:
    virtual void v0();
    virtual void v1(int index, Block_3220a0* data, Ref_3220a0* ref);
    virtual void v2();
    unsigned int slots[16];
};
void pure3d_d3dExtGlobalProjectedTexture::v1(int index, Block_3220a0* data, Ref_3220a0* ref) {
    Block_3220a0* dest = (Block_3220a0*)((char*)this + index * 0x40 + 0x44);
    *dest = *data;
    if (ref)
        ref->f0();
    Ref_3220a0** p = (Ref_3220a0**)((char*)this + index * 4 + 4);
    if (*p)
        (*p)->f1();
    *p = ref;
}