typedef unsigned char u8;
typedef unsigned int u32;
extern u32 g_flag;
extern char g_buffer[];
class Obj {
  public:
    char pad[16];
    u32 mPtr;
};
char* __fastcall target(Obj* self) {
    if (self->mPtr)
        return (char*)(self->mPtr + 0x2c);
    if ((((u8*)&g_flag)[0] & 1) == 0)
        g_flag |= 1;
    return g_buffer;
}