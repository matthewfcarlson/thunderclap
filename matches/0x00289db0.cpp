float __cdecl work(int, int, int, float, int, int, unsigned char, int);
class Obj {
    char pad[0x14];
    float factor;
    unsigned char mode;

  public:
    float Run(int a, int b, int c, float value, int d, int e, unsigned char m, int p);
};
float Obj::Run(int a, int b, int c, float value, int d, int e, unsigned char m, int p) {
    return work(a, b, c, value * factor * 0.001f, d, e, p == 0 ? mode : m, p);
}