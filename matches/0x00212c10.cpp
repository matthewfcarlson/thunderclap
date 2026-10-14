typedef unsigned int u32_212c10;
struct Obj_212c10 {
    char pad0[8];
    u32_212c10* cur;
    char padc[12];
    u32_212c10* end;
};
extern void __cdecl Ensure(Obj_212c10*, int);
void __cdecl FUN_00212c10(Obj_212c10* self, u32_212c10* src) {
    u32_212c10* p = self->cur;
    p[0] = src[0];
    p[1] = src[1];
    if ((char*)self->end - (char*)self->cur <= 8)
        Ensure(self, 1);
    self->cur = (u32_212c10*)((char*)self->cur + 8);
}