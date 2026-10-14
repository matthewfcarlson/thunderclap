// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00261bb0 @ 0x00261bb0
extern "C" double fmod(double x, double y);
extern float DAT_004cd470;
double FUN_00261bb0(float a1, const int* length, int a3, int a4, float a5) {
    float pos;
    float len;
    len = (float)*length;
    pos = (float)(((double)a3 + (double)DAT_004cd470 * a4 * 0.001f) / ((double)a4 * 60.0f / a1) + a5);
    if (!(((double)a3 + (double)DAT_004cd470 * a4 * 0.001f) < 0.0))
        return fmod(pos, len);
    return len - fmod(-pos, len);
}
