struct Helper { void method(int); };
struct Target { unsigned char pad[0x118]; unsigned char flag; };
void __fastcall target(Target* self, void*, int a, int b) {
    if (self->flag == 0) ((Helper*)((char*)self + 0xdc))->method(1);
}