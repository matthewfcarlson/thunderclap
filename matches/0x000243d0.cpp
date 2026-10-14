extern char zeroValue_243d0;
struct Obj_243d0 {
    char pad[0x124];
    void* member;
    void* go();
};
void* __fastcall FUN_000243d0(Obj_243d0* self) {
    Obj_243d0* p = (Obj_243d0*)self->member;
    if (!p)
        return &zeroValue_243d0;
    return p->go();
}