struct Obj_d8150 {
    char pad[0x258];
};
void __fastcall FUN_000d8150(Obj_d8150* p) {
    char* q = p->pad + 0x258;
    for (int i = 5; i != 0; --i) {
        q[-8] = 0;
        *q = 0;
        q += 0x3c;
    }
}