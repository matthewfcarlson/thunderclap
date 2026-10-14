typedef unsigned int uint_1f92b0;
struct Thing_1f92b0 {
    char pad[0x10];
    bool Check(Thing_1f92b0*);
};
uint_1f92b0 FUN_001f92b0(Thing_1f92b0* a, Thing_1f92b0* b) {
    Thing_1f92b0* x = (Thing_1f92b0*)((char*)b + 0x10);
    Thing_1f92b0* y = (Thing_1f92b0*)((char*)a + 0x10);
    if (y->Check(x))
        return 0xffffffff;
    return x->Check(y) != 0;
}