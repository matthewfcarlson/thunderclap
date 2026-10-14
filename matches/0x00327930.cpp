extern "C" char DAT_00433568[];
extern "C" char DAT_0043359c[];
typedef unsigned int u32_327930;
extern u32_327930 g_327930;
extern void finish();
void __fastcall target(u32_327930* self) {
    *self = ((int)DAT_0043359c);
    if (g_327930 == (u32_327930)self)
        g_327930 = 0;
    *self = ((int)DAT_00433568);
    finish();
}
