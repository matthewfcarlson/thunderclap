typedef unsigned int uint;
extern unsigned long long hash(const char*);
extern uint gHi, gLo;
void FUN_0035dfc0() {
    unsigned long long r = hash("$MACRO_INSERT");
    gHi = (uint)r;
    gLo = (uint)(r >> 32);
}
