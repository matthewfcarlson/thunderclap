extern "C" void* memset(void*, int, unsigned);
extern "C" int __cdecl format(char*, int, const char*, ...);
class Obj_1ca110 {
  public:
    volatile int a, b;
    char pad[8];
    int x;
    char text[64];
    volatile int p, q, r, s;
    Obj_1ca110(int u, int v, int w, int y, int z);
};
Obj_1ca110::Obj_1ca110(int u, int v, int w, int y, int z) {
    memset(this, 0, 0x64);
    a = 100;
    b = 16;
    p = w;
    q = y;
    r = z;
    s = 1;
    format(text, 64, "%s", v);
    x = u;
}