typedef unsigned char u8_2d7f70;
typedef unsigned int u32_2d7f70;
extern "C" u8_2d7f70 FUN_002d7f70(u32_2d7f70 handle, u8_2d7f70* object) {
    if (handle != 0 && object != 0)
        return object[0x1c];
    return 0;
}