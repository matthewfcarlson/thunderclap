typedef unsigned int u32;
typedef unsigned char u8;
extern void Parse(void*, u8*);
extern void Report(void*, const char*);
extern void Continue(void*, u32);
void Target(void* self, u32 param2, u32 param3) {
    u8* flag = (u8*)self + 0x114;
    Parse(self, flag);
    if ((*flag & 0x20) == 0 && (Report(self, "unknown critical chunk"), param2 == 0)) return;
    u32* state = (u32*)((char*)self + 0x60);
    if ((*state & 4) != 0) *state |= 8;
    Continue(self, param3);
}