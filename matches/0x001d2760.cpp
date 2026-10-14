typedef unsigned char u8;
typedef unsigned int u32_1d2760;
struct Object {
    char pad[8];
    u32_1d2760 member;
    char pad2[0x1064 - 12];
    u8 flag;
};
void ReleaseThing(u32_1d2760);
void __fastcall FUN_001d2760(Object* self) {
    if (self->flag) {
        if (self->member) {
            ReleaseThing(self->member);
            self->member = 0;
        }
        self->flag = 0;
    }
}