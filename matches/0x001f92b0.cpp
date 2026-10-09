typedef unsigned int uint;
struct Thing {
    char pad[0x10];
    bool Check(Thing*);
};
uint FUN_001f92b0(Thing* a, Thing* b) {
    Thing* x = (Thing*)((char*)b + 0x10);
    Thing* y = (Thing*)((char*)a + 0x10);
    if (y->Check(x))
        return 0xffffffff;
    return x->Check(y) != 0;
}