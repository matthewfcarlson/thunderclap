struct Vec3 {
    int x, y, z;
};
struct Obj {
    char pad[0xa0];
    Vec3 v;
    void Get(Vec3* out);
};
void Obj::Get(Vec3* out) {
    *out = v;
}
