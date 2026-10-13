struct Obj {
    char pad[0x58];
    char m[1];
};
void* __fastcall FUN_00012720(Obj* self) {
    return self->m;
}