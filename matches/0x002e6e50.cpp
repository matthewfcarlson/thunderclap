struct State {
    char pad[12];
    int raw;
    int bits;
    void* table;
};
struct Stream;
typedef void*(__cdecl* Alloc)(void*, unsigned, unsigned);
typedef void(__cdecl* Free)(void*, void*);
typedef unsigned(__cdecl* Lookup)(unsigned);
extern void* __cdecl FUN_002eb120(void*, unsigned, unsigned);
extern void __cdecl FUN_002eb140(void*, void*);
extern unsigned __cdecl FUN_002eafc0(unsigned);
struct Stream {
    char pad[24];
    int status;
    State* state;
    Alloc allocate;
    Free release;
    void* context;
};
extern void* __cdecl FUN_002ea320(Stream*, Lookup, unsigned);
extern int __cdecl FUN_002e6e00(Stream*);
extern int __cdecl FUN_002e6db0(Stream*);
int __cdecl FUN_002e6e50(Stream* s, int bits, const char* version, int size) {
    if (!version || version[0] != '1' || size != 56)
        return -6;
    if (!s)
        return -2;
    s->status = 0;
    if (!s->allocate) {
        s->allocate = FUN_002eb120;
        s->context = 0;
    }
    if (!s->release)
        s->release = FUN_002eb140;
    s->state = (State*)s->allocate(s->context, 1, 24);
    if (!s->state)
        return -4;
    s->state->table = 0;
    s->state->raw = 0;
    if (bits < 0) {
        bits = -bits;
        s->state->raw = 1;
    }
    if (bits < 8 || bits > 15) {
        FUN_002e6e00(s);
        return -2;
    }
    s->state->bits = bits;
    s->state->table = FUN_002ea320(s, s->state->raw ? 0 : FUN_002eafc0, 1u << bits);
    if (!s->state->table) {
        FUN_002e6e00(s);
        return -4;
    }
    FUN_002e6db0(s);
    return 0;
}