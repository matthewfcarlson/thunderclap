struct Obj {
    char pad[0x26];
    short count;
};
void thunk_FUN_0035a720(void*);
void __fastcall FUN_002c3670(Obj* self) {
    if (self->count == 0)
        thunk_FUN_0035a720((char*)self + 0x10);
    ++self->count;
}