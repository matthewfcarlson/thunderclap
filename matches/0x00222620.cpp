extern "C" char DAT_004272b8[];
typedef unsigned int u32_222620;
typedef unsigned char u8;
struct Arg_222620 {
    virtual void F();
};
struct Sub_222620 {
    char x[4];
    void Init();
};
struct Puppet {
    char pad[0x2ec];
    void BaseInit();
    Puppet* Init(Arg_222620*);
};
Puppet* Puppet::Init(Arg_222620* param) {
    BaseInit();
    *(u32_222620*)this = ((int)DAT_004272b8);
    ((Sub_222620*)((char*)this + 0x10))->Init();
    *(u32_222620*)((char*)this + 0x68) = 0;
    *(u8*)((char*)this + 0x2ec) = 0;
    *(Arg_222620**)((char*)this + 0x64) = param;
    param->F();
    return this;
}