extern "C" float __cdecl calc(float, float);
class Obj {
  public:
    char pad[0x12e0];
    float a, b, c;
    float apply(float, float);
    void run(float);
};
void Obj::run(float x) {
    float aa = a;
    float bb = b;
    float y = calc(bb, aa);
    c = apply(x, y);
}