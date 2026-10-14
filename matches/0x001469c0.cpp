struct Vec3_1469c0 {
    int x;
    int y;
    int z;
};
class Obj_1469c0 {
  public:
    char m[0x10];
    Vec3_1469c0 mVec;
    char Set(const Vec3_1469c0* src);
};

char Obj_1469c0::Set(const Vec3_1469c0* src) {
    mVec.x = src->x;
    mVec.y = src->y;
    mVec.z = src->z;
    return 1;
}