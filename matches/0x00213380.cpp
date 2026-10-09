typedef unsigned int u32;
struct Context {
    char pad0[8];
    u32* output;
    char pad0c[4];
    u32* state;
};
void __cdecl Ensure(Context*);
u32 __cdecl Build(Context*, u32, u32);
void __cdecl target(Context* self, u32 a, u32 b) {
    u32* state = self->state;
    if (state[19] >= state[18])
        Ensure(self);
    u32* out = self->output;
    u32 value = Build(self, a, b);
    out[1] = value;
    out[0] = 4;
    self->output += 2;
}
