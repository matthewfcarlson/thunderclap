struct Vec3_adb10 {
    int x, y, z;
};
struct Obj_adb10 {
    char pad[0xa0];
    Vec3_adb10 v;
    void Get(Vec3_adb10* out);
};
void Obj_adb10::Get(Vec3_adb10* out) {
    *out = v;
}
