class Ref {
  public:
    virtual void f0();
    virtual void f1();
};
struct Block {
    unsigned int x[16];
};
class pure3d_d3dExtGlobalProjectedTexture {
  public:
    virtual void v0();
    virtual void v1(int index, Block* data, Ref* ref);
    virtual void v2();
    unsigned int slots[16];
};
void pure3d_d3dExtGlobalProjectedTexture::v1(int index, Block* data, Ref* ref) {
    Block* dest = (Block*)((char*)this + index * 0x40 + 0x44);
    *dest = *data;
    if (ref)
        ref->f0();
    Ref** p = (Ref**)((char*)this + index * 4 + 4);
    if (*p)
        (*p)->f1();
    *p = ref;
}