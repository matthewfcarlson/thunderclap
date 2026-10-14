struct Obj_2c3690 {
    char pad[0x26];
    short count;
};
void __cdecl thunk_FUN_0035a740(void*);
void __fastcall FUN_002c3690(Obj_2c3690* self) {
    if (self->count > 0) {
        if (self->count == 1)
            thunk_FUN_0035a740((char*)self + 0x10);
        --self->count;
    }
}