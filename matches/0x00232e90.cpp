typedef unsigned int u32;
struct Base { void Init(); };
struct Inner { void Init(); };
class Branch { public: virtual void v0(); char pad04[12]; u32 arg; u32 field14; Inner inner; u32 field1c; u32 field20; Branch* Build(u32); };
Branch* Branch::Build(u32 param) {
    ((Base*)this)->Init();
    *((u32*)this) = 0x427898;
    arg = param;
    field14 = 0;
    inner.Init();
    field1c = 0;
    field20 = 0;
    return this;
}