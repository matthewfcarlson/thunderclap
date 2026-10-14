// Same code shape as 0x001c3990 (propagated; names are from that function)
struct X_1c39a0 {
    char pad[0x1c];
};
void* __fastcall target(X_1c39a0* p) {
    return p->pad + 0x1c;
}