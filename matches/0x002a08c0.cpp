extern "C" double sin(double);
extern "C" double cos(double);
class Obj {
    char pad[0x48];
    float s, c;

  public:
    void Set(float x);
};
void Obj::Set(float x) {
    s = (float)sin(x);
    c = (float)cos(x);
}