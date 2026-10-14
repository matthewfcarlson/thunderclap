typedef unsigned char u8;
typedef unsigned int u32_1c6af0;
extern u32_1c6af0 g_flag_1c6af0;
extern char g_buffer[];
class Obj_1c6af0 {
  public:
    char pad[16];
    u32_1c6af0 mPtr;
};
char* __fastcall target(Obj_1c6af0* self) {
    if (self->mPtr)
        return (char*)(self->mPtr + 0x2c);
    if ((((u8*)&g_flag_1c6af0)[0] & 1) == 0)
        g_flag_1c6af0 |= 1;
    return g_buffer;
}