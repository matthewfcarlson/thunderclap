typedef unsigned int u32;
struct Obj18 {
    char pad[0x18];
    u32 val;
};
struct Obj1c {
    char pad[0x1c];
    u32 val;
};
extern void* Cast(void*, int, const void*, const void*, int);
extern int TypeA;
extern int TypeB;
class C {
  public:
    char pad[0x70];
    void* source;
    Obj1c* cached;
};
u32 __fastcall Target(C* self) {
    if (self->cached)
        return self->cached->val;
    if (self->source) {
        if (Cast(self->source, 0, &TypeA, &TypeB, 0)) {
            return ((Obj18*)Cast(self->source, 0, &TypeA, &TypeB, 0))->val;
        }
    }
    return 0;
}
