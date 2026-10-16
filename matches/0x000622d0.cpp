struct Vec {
    float x, y, z;
};
class Obj {
    char pad[0x38];
    float x, y, z;

  public:
    unsigned char Set(Vec const* v);
};
unsigned char Obj::Set(Vec const* v) {
    x = v->x * 0.017453292519943295f;
    y = v->y * 0.017453292519943295f;
    z = v->z * 0.017453292519943295f;
    return 1;
}