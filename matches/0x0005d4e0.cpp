struct Vec3 {
    int x, y, z;
};

class Obj {
  public:
    char pad[0x20];
    Vec3 mVec;
    char Set(const Vec3* v);
};

char Obj::Set(const Vec3* v) {
    mVec.x = v->x;
    mVec.y = v->y;
    mVec.z = v->z;
    return 1;
}
