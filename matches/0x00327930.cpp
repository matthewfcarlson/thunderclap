extern "C" char DAT_00433568[];
extern "C" char DAT_0043359c[];
typedef unsigned int u32;
extern u32 g;
extern void finish();
void __fastcall target(u32* self) {
    *self = ((int)DAT_0043359c);
    if (g == (u32)self)
        g = 0;
    *self = ((int)DAT_00433568);
    finish();
}
