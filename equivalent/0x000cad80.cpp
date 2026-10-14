// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000cad80 @ 0x000cad80
extern "C" char *__cdecl strncpy(char *dst, const char *src, unsigned int n);

struct Label_cad80 {
    char pad0[0xbc];
    char text[0x80];
    int f13c;
    int f140;
    int f144;
    unsigned int color;
    void FUN_000cad80(const char *src, int a, int b, float r, float g, float bl);
};

void Label_cad80::FUN_000cad80(const char *src, int a, int b, float r, float g, float bl)
{
    strncpy(text, src, 0x80);
    f13c = a;
    f140 = b;
    f144 = 0;
    unsigned int c = (int)r | 0xffffff00;
    c = (c << 8) | (int)g;
    c = (c << 8) | (int)bl;
    color = c;
}
