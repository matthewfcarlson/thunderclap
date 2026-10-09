typedef unsigned char byte;
extern int vftable;
void __cdecl FreeMem(void*);
struct Sub { void Clean(); char pad[8]; };
class CGrappleSwapTrack {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CGrappleSwapTrack* vfunc_5(byte);
    void BaseClean();
    char pad[0xc];
    Sub a;
    Sub b;
};
CGrappleSwapTrack* CGrappleSwapTrack::vfunc_5(byte param_2) {
    *(int*)this = (int)&vftable;
    this->b.Clean();
    this->a.Clean();
    this->BaseClean();
    if (param_2 & 1) FreeMem(this);
    return this;
}
