struct O_bbb00 {
    char pad[0x88];
    int m;
};
void __fastcall FUN_000bbb00(O_bbb00* self, void*) {
    if (self->m > 0)
        --self->m;
}
