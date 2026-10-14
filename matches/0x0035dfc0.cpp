typedef unsigned int uint;
extern unsigned long long hash(const char*);
extern uint gHi_35dfc0, gLo;
void FUN_0035dfc0() {
    unsigned long long r = hash("$MACRO_INSERT");
    gHi_35dfc0 = (uint)r;
    gLo = (uint)(r >> 32);
}
