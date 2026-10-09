struct Block {
    unsigned int x[16];
};
class d3dExtGlobalProjectedTexture {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual bool vfunc_2(int, Block*, int*);
    char pad[4];
    Block blocks[16];
};
bool d3dExtGlobalProjectedTexture::vfunc_2(int index, Block* output, int* value) {
    *output = *(Block*)((char*)this + index * 0x40 + 0x44);
    int v = *(int*)((char*)this + index * 4 + 4);
    *value = v;
    return v != 0;
}