// STATUS: equivalent (tools/equiv.py level 3: 60 inputs, branch coverage 38/38)
// FUN_002d5640 @ 0x002d5640
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);

class Channel {
public:
    void FUN_0028a1c0(float t, float *out);
    void FUN_0028a0b0(float t, float *out);
    void FUN_0028ad20(float t, float *out);
};

class ChannelSet_2d5640 {
public:
    Channel *FUN_00288960(unsigned int tagLo, unsigned int tagHi);
};

class Source_2d5640 {
public:
    char pad0[0x10];
    float length;
    ChannelSet_2d5640 *FUN_00288a10(int index);
};

namespace pure3d {
class SpriteParticleEmitter {
public:
    class OverLifeAttributes {
    public:
        virtual void v0();
        int f04;
        int count;                  // 0x08
        int f0c;
        float *times;               // 0x10
        float *tbl14;
        float *tbl18;
        float *tbl1c;
        float *tbl20;
        float *tbl24;
        unsigned char *bytes28;
        unsigned char *bytes2c;
        OverLifeAttributes(Source_2d5640 *src, int n, int arg);
    };
};

SpriteParticleEmitter::OverLifeAttributes::OverLifeAttributes(Source_2d5640 *src, int n, int arg)
{
    f04 = 0;
    count = n;
    f0c = arg;
    times = 0;
    tbl14 = 0;
    tbl18 = 0;
    tbl1c = 0;
    tbl20 = 0;
    tbl24 = 0;
    bytes28 = 0;
    bytes2c = 0;
    times = (float *)FUN_0008d6d0(n * 4 + 4);
    volatile float inv = 1.0f / (float)count;
    volatile int idx = 0;
    while (idx < count + 1) {
        int i = idx;
        idx = i + 1;
        times[i] = (float)i * inv;
    }
    if (src == 0)
        return;

    ChannelSet_2d5640 *cs = src->FUN_00288a10(0);
    int life = (int)src->length;
    Channel *ch;

    ch = cs->FUN_00288960(0x4c4f5053, 0x31544c46);
    if (ch != 0) {
        float *a = (float *)FUN_0008d6d0(0x54);
        tbl14 = a;
        volatile float step = (float)life * 0.05f;
        volatile float t = 0.0f;
        for (int k = 0; k < 20; k++) {
            ch->FUN_0028a1c0(t, a + k);
            t = step + t;
        }
        tbl14[20] = tbl14[19];
    }

    ch = cs->FUN_00288960(0x4c4f5a53, 0x31544c46);
    if (ch != 0) {
        float *a = (float *)FUN_0008d6d0(0x54);
        tbl18 = a;
        volatile float step = (float)life * 0.05f;
        volatile float t = 0.0f;
        for (int k = 0; k < 20; k++) {
            ch->FUN_0028a1c0(t, a + k);
            t = step + t;
        }
        tbl18[20] = tbl18[19];
    }

    ch = cs->FUN_00288960(0x4c4f4e53, 0x31544c46);
    if (ch != 0) {
        float *a = (float *)FUN_0008d6d0(0x54);
        tbl1c = a;
        volatile float step = (float)life * 0.05f;
        volatile float t = 0.0f;
        for (int k = 0; k < 20; k++) {
            ch->FUN_0028a1c0(t, a + k);
            t = step + t;
        }
        tbl1c[20] = tbl1c[19];
    }

    ch = cs->FUN_00288960(0x4c4f4557, 0x31544c46);
    if (ch != 0) {
        float *a = (float *)FUN_0008d6d0(0x54);
        tbl20 = a;
        volatile float step = (float)life * 0.05f;
        volatile float t = 0.0f;
        for (int k = 0; k < 20; k++) {
            ch->FUN_0028a1c0(t, a + k);
            t = step + t;
        }
        tbl20[20] = tbl20[19];
    }

    ch = cs->FUN_00288960(0x4c4f4f43, 0x524c43);
    if (ch != 0) {
        float *a = (float *)FUN_0008d6d0(0x54);
        tbl24 = a;
        volatile float step = (float)life * 0.05f;
        volatile float t = 0.0f;
        for (int k = 0; k < 20; k++) {
            ch->FUN_0028ad20(t, a + k);
            t = step + t;
        }
        tbl24[20] = tbl24[19];
    }

    float tmp[21];

    ch = cs->FUN_00288960(0x4c4f4c41, 0x544e49);
    if (ch != 0) {
        volatile float step = (float)life * 0.05f;
        volatile float t = 0.0f;
        for (int k = 0; k < 20; k++) {
            ch->FUN_0028a0b0(t, tmp + k);
            t = step + t;
        }
        bytes28 = (unsigned char *)FUN_0008d6d0(0x15);
        const unsigned char *src8 = (const unsigned char *)tmp;
        unsigned int i = 0;
        do {
            bytes28[i] = src8[i * 4];
            bytes28[i + 1] = src8[(i + 1) * 4];
            bytes28[i + 2] = src8[(i + 2) * 4];
            i += 3;
        } while (i <= 0x14);
    }

    ch = cs->FUN_00288960(0x4c4f4554, 0x544e49);
    if (ch != 0) {
        volatile float step = (float)life * 0.05f;
        volatile float t = 0.0f;
        for (int k = 0; k < 20; k++) {
            ch->FUN_0028a0b0(t, tmp + k);
            t = step + t;
        }
        bytes2c = (unsigned char *)FUN_0008d6d0(0x15);
        const unsigned char *src8 = (const unsigned char *)tmp;
        unsigned int i = 0;
        do {
            bytes2c[i] = src8[i * 4];
            bytes2c[i + 1] = src8[(i + 1) * 4];
            bytes2c[i + 2] = src8[(i + 2) * 4];
            bytes2c[i + 3] = src8[(i + 3) * 4];
            bytes2c[i + 4] = src8[(i + 4) * 4];
            i += 5;
        } while (i < 0x14);
    }
}
}
