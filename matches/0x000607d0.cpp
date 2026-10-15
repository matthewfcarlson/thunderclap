extern "C" void _ReadWriteBarrier();
struct Vec {
    float x, y, z;
};
class Obj {
    char pad[0x44];
    float x, y, z;

  public:
    unsigned char SetAngles(const Vec* v);
};
unsigned char Obj::SetAngles(const Vec* v) {
    x = v->x;
    y = v->y;
    z = v->z;
    _ReadWriteBarrier();
    x *= 0.017453292f;
    y *= 0.017453292f;
    z *= 0.017453292f;
    return 1;
}