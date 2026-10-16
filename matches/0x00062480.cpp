struct Vec {
    float x, y, z;
};
class Obj {
    char pad[0x38];
    float x, y, z;

  public:
    bool Set(const Vec* v);
};
bool Obj::Set(const Vec* v) {
    x = v->x * 0.017453292f;
    y = v->y * 0.017453292f;
    z = v->z * 0.017453292f;
    return true;
}