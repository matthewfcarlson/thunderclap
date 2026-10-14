struct Vec3_5d4e0 {
    int x, y, z;
};

class Obj_5d4e0 {
  public:
    char pad[0x20];
    Vec3_5d4e0 mVec;
    char Set(const Vec3_5d4e0* v);
};

char Obj_5d4e0::Set(const Vec3_5d4e0* v) {
    mVec.x = v->x;
    mVec.y = v->y;
    mVec.z = v->z;
    return 1;
}
