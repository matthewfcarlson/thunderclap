typedef unsigned int u32_2eb480;
typedef unsigned char u8_2eb480;
void target(int a, char* b, u32_2eb480 c, u32_2eb480 d, u8_2eb480 e) {
    if (a && b) {
        *(u32_2eb480*)(b + 0x70) = c;
        *(u32_2eb480*)(b + 0x74) = d;
        *(u8_2eb480*)(b + 0x78) = e;
        *(u32_2eb480*)(b + 8) |= 0x80;
    }
}
