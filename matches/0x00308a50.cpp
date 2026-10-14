// Same code shape as 0x001c3990 (propagated; names are from that function)
struct X_308a50 {
    char pad[0x1c];
};
void* __fastcall target(X_308a50* p) {
    return p->pad + 0x1c;
}