extern int FUN_00249b40(int);
struct Obj_1f3550 {
    int pad;
    int member;
};
unsigned char __fastcall FUN_001f3550(Obj_1f3550* self) {
    if (self->member)
        return (unsigned char)FUN_00249b40(self->member);
    return 1;
}