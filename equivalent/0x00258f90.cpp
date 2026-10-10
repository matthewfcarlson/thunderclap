// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 58/64, incomplete)
// FUN_00258f90 @ 0x00258f90
extern "C" unsigned char FUN_00354c8f();
extern "C" int FUN_00262270(float db);
extern "C" int FUN_00262230(float pitch, unsigned int rate);
extern "C" double log10(double);
namespace DSOUND {
extern "C" int __stdcall IDirectSoundBuffer_SetMixBinVolumes_8(void* buf, void* vols);
extern "C" int __stdcall IDirectSoundBuffer_SetFrequency(void* buf, int freq);
}
struct Global { char pad[0x98]; float volA; float volB; };
extern Global* DAT_004e5ce0;
extern void* DAT_004e6200;
extern float DAT_003f32dc, DAT_003f32e0, DAT_003f32f4, DAT_003f3db0, DAT_003fef48;

struct Emitter {
    char pad0[0x48];
    float att;      // 0x48
    float sec;      // 0x4c
    float special;  // 0x50
    float spatial;  // 0x54
    float pan;      // 0x58
    float fade;     // 0x5c
    float pitch;    // 0x60
};
struct Source {
    int kind[4];
    float amount[4];
    float base;           // 0x20
    char pad24[4];        // 0x24 (mix bin volumes)
    char pad28[0x34];
    int* out[7];          // 0x5c..0x74
    char pad78[4];
    void* buffer;         // 0x7c
};
struct State {
    char p0[0x10];
    float pitch;
    float scale;
    char p1[8];
    Source* sources[16];
    void* sample;
    Emitter* handles[8];
    void (__cdecl *callback)(void*, void*);
};

static float ToDb(float v)
{
    if (v == DAT_003f32e0)
        return -3.402823466e38f;
    if (v > DAT_003f32dc)
        return 0.0f;
    return (float)(log10((double)v) * DAT_003fef48);
}

void __cdecl FUN_00258f90(State* s)
{
    for (int i = 0; i < 8; i++)
        if (s->handles[i])
            s->callback(DAT_004e6200, s->handles[i]);

    unsigned int info = *(unsigned int*)((char*)s->sample + 0x14);
    unsigned int count = (info >> 4) & 0x1f;
    float pitch = s->pitch;
    float a = DAT_004e5ce0->volA;
    float master = a * a * a * a * DAT_004e5ce0->volB;
    float sc = s->scale;
    float scale4 = sc * sc * sc * sc;

    for (unsigned int n = 0; n < count; n++) {
        Source* src = s->sources[n];
        float b = src->base;
        float base4 = b * b * b * b;
        float v0 = 0, v1 = 0, v2 = 0, v3 = 0;
        float t4 = 0, t7 = 0, t3 = 0, special = 0;
        for (unsigned int j = 0; j < 4; j++) {
            int type = src->kind[j];
            if (type == 0)
                continue;
            float p = src->amount[j];
            float pp = p * p * p * p;
            if (type >= 8 && type <= 15) {
                Emitter* e = s->handles[type - 8];
                pitch = pitch * e->pitch;
                float att = DAT_003f32dc - e->att;
                float sec = DAT_003f32dc - e->sec;
                float sp = e->spatial * e->spatial * att * pp;
                float left = DAT_003f3db0 * e->pan + DAT_003f32f4;
                float right = e->pan * DAT_003f32f4 + DAT_003f32f4;
                float front = DAT_003f3db0 * e->fade + DAT_003f32f4;
                float back = e->fade * DAT_003f32f4 + DAT_003f32f4;
                float A, B, C, D;
                if (FUN_00354c8f() & 2) {
                    A = back * left * sp * sec;
                    B = back * right * sp * sec;
                    C = front * left * sp * sec;
                    D = front * right * sp * sec;
                } else {
                    A = left * sp * sec;
                    B = right * sp * sec;
                    C = 0;
                    D = 0;
                }
                v0 += A;
                v1 += B;
                v2 += C;
                v3 += D;
                float u = e->special;
                special += u * u * u * u * sp * att;
            } else if (type == 7) {
                t7 += pp;
            } else if (type == 1) {
                v0 += pp;
            } else if (type == 2) {
                v1 += pp;
            } else if (type == 5) {
                v2 += pp;
            } else if (type == 6) {
                v3 += pp;
            } else if (type == 4) {
                t4 += pp;
            } else if (type == 3) {
                t3 = pp;
            }
        }
        float factor = base4 * scale4;
        t4 *= factor;
        t3 *= factor;
        v0 *= factor;
        v1 *= factor;
        v2 *= factor;
        v3 *= factor;
        t7 = (t7 + special) * master * factor;

        src->out[0][1] = FUN_00262270(ToDb(v0));
        src->out[1][1] = FUN_00262270(ToDb(v1));
        src->out[2][1] = FUN_00262270(ToDb(v2));
        src->out[3][1] = FUN_00262270(ToDb(v3));
        src->out[5][1] = FUN_00262270(ToDb(t4));
        src->out[4][1] = FUN_00262270(ToDb(t3));
        src->out[6][1] = FUN_00262270(ToDb(t7));
        DSOUND::IDirectSoundBuffer_SetMixBinVolumes_8(src->buffer, (char*)src + 0x24);
    }

    int freq = FUN_00262230(pitch, (*(unsigned int*)((char*)s->sample + 0x14) >> 9) & 0x1ffff);
    for (unsigned int i = 0; i < count; i++)
        DSOUND::IDirectSoundBuffer_SetFrequency(s->sources[i]->buffer, freq);
}
