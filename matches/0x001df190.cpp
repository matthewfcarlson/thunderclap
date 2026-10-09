struct Vec3 { unsigned int x,y,z; };
class Thing { public: int Find(int arg); Vec3* Get(int index); Vec3* Target(Vec3* out, int arg); };
Vec3* Thing::Target(Vec3* out, int arg) {
    int i = Find(arg);
    if (i < 0) {
        out->x = 0x7f7fffff;
        out->y = 0x7f7fffff;
        out->z = 0x7f7fffff;
        return out;
    }
    Vec3* p = Get(i);
    *out = *p;
    return out;
}