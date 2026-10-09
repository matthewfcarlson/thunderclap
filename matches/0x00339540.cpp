extern void __cdecl CopyThing(int, void*, int);
extern void __cdecl FinishThing(int, int);
struct Thing {
    int base;
    int count;
    int value;
};
void __cdecl FUN_00339540(Thing* p) {
    int diff = p->base - (int)p - 12;
    if (diff != 0) {
        char* dst = (char*)p + 12;
        CopyThing(p->value, dst, diff);
        p->base = (int)dst;
        p->count = p->count + 1;
    }
    FinishThing(p->value, p->count);
    p->count = 1;
}