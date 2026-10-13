struct Obj {
    char pad[0xc4];
    int value;
};
int __fastcall FUN_00012640(Obj* self) {
    return self->value;
}
