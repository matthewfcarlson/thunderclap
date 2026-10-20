extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
struct Vec3 {
    float x, y, z;
};
extern "C" void __cdecl FUN_00224d70(float angle, Vec3* v) {
    double s = sin(angle);
    double c = cos(angle);
    float x = v->x;
    float z = v->z;
    double zs = z * s;
    v->x = (float)(zs + x * c);
    double negxs = -(x * s);
    v->z = (float)(negxs + z * c);
}