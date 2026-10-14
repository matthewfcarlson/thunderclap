// Same code shape as 0x000862d0 (propagated; names are from that function)
struct X_2bf150 {
    char pad[0x14];
    unsigned value;
};
unsigned __fastcall target(X_2bf150* self) {
    return self->value;
}