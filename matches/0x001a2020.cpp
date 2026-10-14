struct Vec3 {
    int x, y, z;
};

class Obj {
  public:
    char pad[0x38];
    int v38, v3c, v40;
    bool Set(Vec3* v);
};

bool Obj::Set(Vec3* v) {
    v38 = v->x;
    v3c = v->y;
    v40 = v->z;
    return true;
}
