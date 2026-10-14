extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
struct Vec4_22b170 {
    float x, y, z, w;
    void Set(float angle, float* v);
};
void Vec4_22b170::Set(float angle, float* v) {
    float a = angle * 0.5f;
    float s = (float)sin((double)a);
    w = (float)cos((double)a);
    x = s * v[0];
    y = s * v[1];
    z = s * v[2];
}
