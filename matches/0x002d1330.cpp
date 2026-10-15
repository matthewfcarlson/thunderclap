struct Sub {
    char p[0x1c];
    float* samples;
};
struct Obj {
    char p[0x1bc];
    Sub* sub;
};
struct Out {
    char p[0x14];
    float accum;
    char q[4];
    float scale;
};
void __cdecl FUN_002d1330(float gain, int index, float interp, Obj* obj, Out* out) {
    float* s = obj->sub->samples;
    float a = s[index];
    float b = s[index + 1];
    out->accum += (a + (b - a) * interp) * out->scale * gain;
}