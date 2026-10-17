// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00095fa0 @ 0x00095fa0
extern float DAT_003f32b8;
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
void __cdecl FUN_00095fa0(float *v, float angle) {
    double radians = angle * DAT_003f32b8;
    double s = sin(radians);
    double c = cos(radians);
    float x = v[0], z = v[2];
    v[0] = (float)(x*c + z*s);
    v[2] = (float)(z*c - x*s);
}