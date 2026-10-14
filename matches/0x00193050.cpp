struct Vec3_193050 {
    int x;
    int y;
    int z;
};

class Obj_193050 {
  public:
    char pad[0x40];
    int m40;
    int m44;
    int m48;
    bool Set(const Vec3_193050* v);
};

bool Obj_193050::Set(const Vec3_193050* v) {
    m40 = v->x;
    m44 = v->y;
    m48 = v->z;
    return true;
}
