struct Obj_2c3670 {
    char pad[0x26];
    short count;
};
void thunk_FUN_0035a720(void*);
void __fastcall FUN_002c3670(Obj_2c3670* self) {
    if (self->count == 0)
        thunk_FUN_0035a720((char*)self + 0x10);
    ++self->count;
}