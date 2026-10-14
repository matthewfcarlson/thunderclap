typedef unsigned int u32_2ef4a0;
struct Obj18_2ef4a0 {
    char pad[0x18];
    u32_2ef4a0 val;
};
struct Obj1c {
    char pad[0x1c];
    u32_2ef4a0 val;
};
extern void* Cast(void*, int, const void*, const void*, int);
extern int TypeA_2ef4a0;
extern int TypeB_2ef4a0;
class C_2ef4a0 {
  public:
    char pad[0x70];
    void* source;
    Obj1c* cached;
};
u32_2ef4a0 __fastcall Target(C_2ef4a0* self) {
    if (self->cached)
        return self->cached->val;
    if (self->source) {
        if (Cast(self->source, 0, &TypeA_2ef4a0, &TypeB_2ef4a0, 0)) {
            return ((Obj18_2ef4a0*)Cast(self->source, 0, &TypeA_2ef4a0, &TypeB_2ef4a0, 0))->val;
        }
    }
    return 0;
}
