struct Ctx {
    char pad[0x24];
    void(__cdecl* fn)(int, int);
    int x28;
    char p2c[4];
    int m30;
};
extern void __cdecl FUN_002ebed0(int, Ctx*);
class Obj {
  public:
    int type;
    int a4;
    int a8;
    int aC;
    char p10[0x0c];
    int m1c;
    int m20;
    char p24[4];
    int m28;
    int m2c;
    int m30;
    int m34;
    int(__cdecl* m38)(int, int, int);
    int m3c;
};
void __cdecl FUN_002ea2a0(Obj* self, Ctx* ctx, int* out) {
    if (out)
        *out = self->m3c;
    if (self->type == 4 || self->type == 5) {
        int v = ctx->x28;
        int a = self->aC;
        ctx->fn(v, a);
    }
    if (self->type == 6)
        FUN_002ebed0(self->a4, ctx);
    self->m34 = self->m28;
    self->m30 = self->m28;
    int(__cdecl * f)(int, int, int) = self->m38;
    self->type = 0;
    self->m1c = 0;
    self->m20 = 0;
    if (f) {
        int r = f(0, 0, 0);
        self->m3c = r;
        ctx->m30 = r;
    }
}