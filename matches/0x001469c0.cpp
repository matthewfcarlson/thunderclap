struct Vec3 {
    int x;
    int y;
    int z;
};
class Obj {
  public:
    char m[0x10];
    Vec3 mVec;
    char Set(const Vec3* src);
};

char Obj::Set(const Vec3* src) {
    mVec.x = src->x;
    mVec.y = src->y;
    mVec.z = src->z;
    return 1;
}