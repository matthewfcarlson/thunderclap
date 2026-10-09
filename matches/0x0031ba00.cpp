typedef unsigned int u32;
struct Device {
    u32 vftable;
    char pad4[8];
    u32 fieldC;
    u32 field10;
    Device* Init(u32 value);
};
extern void FUN_0031bac0();
extern void FUN_00328130();
Device* Device::Init(u32 value) {
    FUN_0031bac0();
    vftable = 0x4324e4;
    field10 = value;
    fieldC = 0;
    FUN_00328130();
    return this;
}