struct Vec3 {
    int x, y, z;
};

class Obj {
  public:
    char pad[0x48];
    Vec3 mVec;
    bool Set(const Vec3* v);
};

bool Obj::Set(const Vec3* v) {
    mVec.x = v->x;
    mVec.y = v->y;
    mVec.z = v->z;
    return true;
}
