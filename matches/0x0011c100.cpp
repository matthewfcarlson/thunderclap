struct S_11c100 {
    char pad[0x40];
    char* Get() { return (char*)this + 0x40; }
};
char* __fastcall FUN_0011c100(S_11c100* self) {
    return self->Get();
}
