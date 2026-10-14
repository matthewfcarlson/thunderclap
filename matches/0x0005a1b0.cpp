struct Vec3 {
    int x;
    int y;
    int z;
};

class Obj {
  public:
    char pad[0x48];
    int m48;
    int m4c;
    int m50;
    bool Set(const Vec3* v);
};

bool Obj::Set(const Vec3* v) {
    m48 = v->x;
    m4c = v->y;
    m50 = v->z;
    return true;
}
