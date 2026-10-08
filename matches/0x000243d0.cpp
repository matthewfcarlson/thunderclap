extern char zeroValue;
struct Obj { char pad[0x124]; void *member; void *go(); };
void * __fastcall FUN_000243d0(Obj *self) {
    Obj *p = (Obj *)self->member;
    if (!p) return &zeroValue;
    return p->go();
}