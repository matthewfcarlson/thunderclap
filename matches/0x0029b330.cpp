struct Obj_29b330 {
    char pad[0x48];
    int value;
    char pad2[4];
    unsigned char flag;
};
void cleanup(int);
void __fastcall FUN_0029b330(Obj_29b330* self, void*, int param2, unsigned char param3) {
    if (self->flag)
        cleanup(self->value);
    self->value = param2;
    self->flag = param3;
}