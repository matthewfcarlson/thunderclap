struct O {
    char pad[0x88];
    int m;
};
void __fastcall FUN_000bbb00(O* self, void*) {
    if (self->m > 0)
        --self->m;
}
