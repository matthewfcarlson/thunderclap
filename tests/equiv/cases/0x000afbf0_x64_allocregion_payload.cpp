// FUN_000afbf0 @ 0x000afbf0
// (integ3, allocty regions, rev5: one record and its payload, not an array) a cookie and its elements (sweep2's haptic controller, D149 lead item): the
// allocation is cast to int* (the count at +0), its elements are `(Elem*)(raw + 1)`. The record region from +4
// (k * sizeof(int) on both targets) is typed as `n * sizeof(Elem) + 4` records; their pointer field compares as a
// pointer, not as two int words of the int* allocation (a false `layout` before)
struct Ref { virtual void Release(); };
struct Elem { int f0; int words[10]; Ref* f2c; int tail; };
extern "C" void* __cdecl FUN_0008d690(unsigned);
struct Owner { const void* vftable; int count; Elem* items; void FUN_000afbf0(int n); };
void Owner::FUN_000afbf0(int n) {
    n &= 7;
    count = n;
    unsigned len = (unsigned)(n * 12);       // (a fuzzed payload length: multiples of the 32-bit sizeof(Elem) included)
    int* raw = (int*)FUN_0008d690((unsigned)sizeof(int) + (unsigned)sizeof(Elem) + len);
    if (!raw) {
        items = 0;
        return;
    }
    raw[0] = n;
    Elem* e = (Elem*)(raw + 1);
    e->f0 = 0;
    e->f2c = 0;
    count = len ? ((unsigned char*)(e + 1))[0] : 0;     // a payload byte read before written
    items = e;
}
