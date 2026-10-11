extern "C" char DAT_004272b8[];
typedef unsigned int u32;
typedef unsigned char u8;
struct Arg {
    virtual void F();
};
struct Sub {
    char x[4];
    void Init();
};
struct Puppet {
    char pad[0x2ec];
    void BaseInit();
    Puppet* Init(Arg*);
};
Puppet* Puppet::Init(Arg* param) {
    BaseInit();
    *(u32*)this = ((int)DAT_004272b8);
    ((Sub*)((char*)this + 0x10))->Init();
    *(u32*)((char*)this + 0x68) = 0;
    *(u8*)((char*)this + 0x2ec) = 0;
    *(Arg**)((char*)this + 0x64) = param;
    param->F();
    return this;
}