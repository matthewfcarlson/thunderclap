extern "C" char DAT_004324e4[];
typedef unsigned int u32_31ba00;
struct Device_31ba00 {
    u32_31ba00 vftable;
    char pad4[8];
    u32_31ba00 fieldC;
    u32_31ba00 field10;
    Device_31ba00* Init(u32_31ba00 value);
};
extern void FUN_0031bac0();
extern void FUN_00328130();
Device_31ba00* Device_31ba00::Init(u32_31ba00 value) {
    FUN_0031bac0();
    vftable = ((int)DAT_004324e4);
    field10 = value;
    fieldC = 0;
    FUN_00328130();
    return this;
}