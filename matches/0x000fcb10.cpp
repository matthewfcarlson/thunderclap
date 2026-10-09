typedef unsigned int u32;
struct Base { void InitBase(u32); };
struct CChaseAgent : Base {
    char pad0[8]; u32 a; char padc[0x68-0x0c]; float f; char b; char pad70[3]; u32 c;
    CChaseAgent* Init(u32);
};
extern char CChaseAgent_vftable;
CChaseAgent* CChaseAgent::Init(u32 x) {
    ((Base*)this)->InitBase(x);
    a=0; c=0; b=0;
    *(u32*)this=(u32)&CChaseAgent_vftable;
    f=-1.0f;
    return this;
}