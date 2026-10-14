struct Vec3 {
    int x;
    int y;
    int z;
};

class Obj {
  public:
    char pad[0x40];
    int m40;
    int m44;
    int m48;
    bool Set(const Vec3* v);
};

bool Obj::Set(const Vec3* v) {
    m40 = v->x;
    m44 = v->y;
    m48 = v->z;
    return true;
}
