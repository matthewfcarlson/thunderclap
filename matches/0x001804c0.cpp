struct Vec {
    float x, y, z;
};
class Obj {
    char pad[0x2c];
    volatile float x, y, z;

  public:
    char Set(const Vec* v);
};
char Obj::Set(const Vec* v) {
    float a = v->x * 0.017453292f;
    float b = v->y * 0.017453292f;
    volatile float c[3];
    c[2] = v->z * 0.017453292f;
    z = c[2];
    x = a;
    y = b;
    return 1;
}