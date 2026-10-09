typedef unsigned int u32;
typedef unsigned char u8;
void target(int a, char* b, u32 c, u32 d, u8 e) {
    if (a && b) {
        *(u32*)(b + 0x70) = c;
        *(u32*)(b + 0x74) = d;
        *(u8*)(b + 0x78) = e;
        *(u32*)(b + 8) |= 0x80;
    }
}
