struct Helper_366d0 {
    void method(int);
};
struct Target_366d0 {
    unsigned char pad[0x118];
    unsigned char flag;
};
void __fastcall target(Target_366d0* self, void*, int a, int b) {
    if (self->flag == 0)
        ((Helper_366d0*)((char*)self + 0xdc))->method(1);
}