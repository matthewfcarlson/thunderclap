extern "C" void _ReadWriteBarrier();
typedef unsigned int u32;
extern void __cdecl thunk_FUN_00267090(u32);
extern void __fastcall FUN_002c6aa0(void*);
struct TranslucentTraversal {
    u32 vptr;
    char pad04[0x18];
    u32 mSeven;
    char pad20[8];
    u32 mTen;
};
void __fastcall FUN_002a21c0(TranslucentTraversal* self) {
    *(volatile u32*)&self->vptr = 0x42d750;
    _ReadWriteBarrier();
    if (self->mTen)
        thunk_FUN_00267090(self->mTen);
    if (self->mSeven)
        thunk_FUN_00267090(self->mSeven);
    FUN_002c6aa0(self);
}
