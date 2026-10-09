typedef unsigned int u32;
extern u32 g;
extern void finish();
void __fastcall target(u32* self) {
    *self = 0x43359c;
    if (g == (u32)self)
        g = 0;
    *self = 0x433568;
    finish();
}
