typedef unsigned int u32_2e9fc0;
typedef unsigned char u8;
extern void Parse(void*, u8*);
extern void Report(void*, const char*);
extern void Continue(void*, u32_2e9fc0);
void Target(void* self, u32_2e9fc0 param2, u32_2e9fc0 param3) {
    u8* flag = (u8*)self + 0x114;
    Parse(self, flag);
    if ((*flag & 0x20) == 0 && (Report(self, "unknown critical chunk"), param2 == 0))
        return;
    u32_2e9fc0* state = (u32_2e9fc0*)((char*)self + 0x60);
    if ((*state & 4) != 0)
        *state |= 8;
    Continue(self, param3);
}