struct S {
    char pad[0x28];
    int x;
};
char* __fastcall FUN_0015b6d0(S* self) {
    return (char*)&self->x;
}