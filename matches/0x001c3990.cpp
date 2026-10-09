struct X {
    char pad[0x1c];
};
void* __fastcall target(X* p) {
    return p->pad + 0x1c;
}