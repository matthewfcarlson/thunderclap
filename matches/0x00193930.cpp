struct Vec3_193930 {
    int x, y, z;
};

class Obj_193930 {
  public:
    char pad[0x48];
    Vec3_193930 mVec;
    bool Set(const Vec3_193930* v);
};

bool Obj_193930::Set(const Vec3_193930* v) {
    mVec.x = v->x;
    mVec.y = v->y;
    mVec.z = v->z;
    return true;
}
