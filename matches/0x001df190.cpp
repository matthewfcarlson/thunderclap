struct Vec3_1df190 {
    unsigned int x, y, z;
};
class CSPManager_1df190 {
  public:
    int Find(int arg);
    Vec3_1df190* Get(int index);
    Vec3_1df190* Target(Vec3_1df190* out, int arg);
};
Vec3_1df190* CSPManager_1df190::Target(Vec3_1df190* out, int arg) {
    int i = Find(arg);
    if (i < 0) {
        out->x = 0x7f7fffff;
        out->y = 0x7f7fffff;
        out->z = 0x7f7fffff;
        return out;
    }
    Vec3_1df190* p = Get(i);
    *out = *p;
    return out;
}