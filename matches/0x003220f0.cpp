struct Block_3220f0 {
    unsigned int x[16];
};
class d3dExtGlobalProjectedTexture {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual bool vfunc_2(int, Block_3220f0*, int*);
    char pad[4];
    Block_3220f0 blocks[16];
};
bool d3dExtGlobalProjectedTexture::vfunc_2(int index, Block_3220f0* output, int* value) {
    *output = *(Block_3220f0*)((char*)this + index * 0x40 + 0x44);
    int v = *(int*)((char*)this + index * 4 + 4);
    *value = v;
    return v != 0;
}