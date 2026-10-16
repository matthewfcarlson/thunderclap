struct Vec {
    float x, y, z;
};
class Obj {
    char pad[0x34];
    float x, y, z;

  public:
    unsigned char Set(const Vec* v);
};
unsigned char Obj::Set(const Vec* v) {
    x = v->x * 0.017453292f;
    y = v->y * 0.017453292f;
    z = v->z * 0.017453292f;
    return 1;
}