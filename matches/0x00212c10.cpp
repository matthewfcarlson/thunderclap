typedef unsigned int u32;
struct Obj {
    char pad0[8];
    u32* cur;
    char padc[12];
    u32* end;
};
extern void __cdecl Ensure(Obj*, int);
void __cdecl FUN_00212c10(Obj* self, u32* src) {
    u32* p = self->cur;
    p[0] = src[0];
    p[1] = src[1];
    if ((char*)self->end - (char*)self->cur <= 8)
        Ensure(self, 1);
    self->cur = (u32*)((char*)self->cur + 8);
}