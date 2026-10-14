typedef unsigned int u32_213380;
struct Context {
    char pad0[8];
    u32_213380* output;
    char pad0c[4];
    u32_213380* state;
};
void __cdecl Ensure(Context*);
u32_213380 __cdecl Build(Context*, u32_213380, u32_213380);
void __cdecl target(Context* self, u32_213380 a, u32_213380 b) {
    u32_213380* state = self->state;
    if (state[19] >= state[18])
        Ensure(self);
    u32_213380* out = self->output;
    u32_213380 value = Build(self, a, b);
    out[1] = value;
    out[0] = 4;
    self->output += 2;
}
