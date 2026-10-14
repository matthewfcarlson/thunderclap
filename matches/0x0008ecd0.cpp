extern "C" void __cdecl Init();
extern "C" unsigned char gFlag_8ecd0;
extern "C" int gWidth;
extern "C" int gHeight;

struct Obj_8ecd0 {
    int a, b, c, pad, mode;
    char gap[0x0b];
    char f2;
    char f1;
    char f3;
    int x, y;
};
void __cdecl FUN_0008ecd0(Obj_8ecd0* p) {
    Init();
    if (gFlag_8ecd0) {
        gWidth = 0x280;
        gHeight = 0x240;
    }
    p->mode = 7;
    *((char*)p + 0x2f) = 1;
    *((char*)p + 0x30) = 1;
    p->a = gWidth;
    p->b = gHeight;
    p->c = 0x20;
    *((char*)p + 0x2c) = 0;
    p->x = 0x11;
    p->y = 0;
    *((char*)p + 0x2e) = 1;
}