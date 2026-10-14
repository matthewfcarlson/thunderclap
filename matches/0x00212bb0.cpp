struct Item_212bb0 {
    char pad[7];
    unsigned char count;
    char more[8];
};
struct Obj_212bb0 {
    char pad[8];
    char* first;
    char* last;
    char* other;
    char pad2[44];
};
extern char zeroVal_212bb0;
extern "C" char* __fastcall FUN_00212bb0(int n, Obj_212bb0* o) {
    if (n > 0) {
        char* p = o->last + n * 8 - 8;
        if (p < o->first)
            return p;
        return &zeroVal_212bb0;
    }
    if (n > -10000)
        return o->first + n * 8;
    if (n != -10001) {
        if (n != -10000) {
            Item_212bb0* a = *(Item_212bb0**)(o->last - 4);
            int i = -10001 - n;
            char* p = (char*)a + i * 8 + 8;
            return i <= a->count ? p : &zeroVal_212bb0;
        }
        return o->other + 0x54;
    }
    return (char*)o + 0x40;
}