struct State_2e6e50 {
    char pad[12];
    int raw;
    int bits;
    void* table;
};
struct Stream;
typedef void*(__cdecl* Alloc_2e6e50)(void*, unsigned, unsigned);
typedef void(__cdecl* Free)(void*, void*);
typedef unsigned(__cdecl* Lookup_2e6e50)(unsigned);
extern void* __cdecl FUN_002eb120(void*, unsigned, unsigned);
extern void __cdecl FUN_002eb140(void*, void*);
extern unsigned __cdecl FUN_002eafc0(unsigned);
struct Stream {
    char pad[24];
    int status;
    State_2e6e50* state;
    Alloc_2e6e50 allocate;
    Free release;
    void* context;
};
extern void* __cdecl FUN_002ea320(Stream*, Lookup_2e6e50, unsigned);
extern "C" int __cdecl FUN_002e6e00(void *);
extern int __cdecl FUN_002e6db0(Stream*);
extern "C" int __cdecl FUN_002e6e50(void * s, int bits, const char* version, int size) {
    if (!version || version[0] != '1' || size != 56)
        return -6;
    if (!((Stream *)s))
        return -2;
    ((Stream *)s)->status = 0;
    if (!((Stream *)s)->allocate) {
        ((Stream *)s)->allocate = FUN_002eb120;
        ((Stream *)s)->context = 0;
    }
    if (!((Stream *)s)->release)
        ((Stream *)s)->release = FUN_002eb140;
    ((Stream *)s)->state = (State_2e6e50*)((Stream *)s)->allocate(((Stream *)s)->context, 1, 24);
    if (!((Stream *)s)->state)
        return -4;
    ((Stream *)s)->state->table = 0;
    ((Stream *)s)->state->raw = 0;
    if (bits < 0) {
        bits = -bits;
        ((Stream *)s)->state->raw = 1;
    }
    if (bits < 8 || bits > 15) {
        FUN_002e6e00((Stream *)((Stream *)s));
        return -2;
    }
    ((Stream *)s)->state->bits = bits;
    ((Stream *)s)->state->table = FUN_002ea320(((Stream *)s), ((Stream *)s)->state->raw ? 0 : FUN_002eafc0, 1u << bits);
    if (!((Stream *)s)->state->table) {
        FUN_002e6e00((Stream *)((Stream *)s));
        return -4;
    }
    FUN_002e6db0(((Stream *)s));
    return 0;
}