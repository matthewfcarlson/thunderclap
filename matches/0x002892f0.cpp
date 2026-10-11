void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
extern char gAMBVftable[];
extern char gIRefCountVftable[];

class AnimationMemoryBlock {
  public:
    void** mVftable;
    char pad[0x14];
    void* mField18;
    void* mField1C;
    AnimationMemoryBlock* vfunc_2(unsigned char flag);
};

AnimationMemoryBlock* AnimationMemoryBlock::vfunc_2(unsigned char flag) {
    void* p18 = mField18;
    mVftable = (void**)&gAMBVftable;
    operator delete[](p18);
    operator delete[](mField1C);
    mVftable = (void**)&gIRefCountVftable;
    if (flag & 1) {
        operator delete((void*)this);
    }
    return this;
}
