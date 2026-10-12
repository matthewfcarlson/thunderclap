// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 52/52)
// FUN_002c7340 @ 0x002c7340
struct V3 {
    float x, y, z;
    void FUN_00011090();
};

void *FUN_0008d6d0(unsigned int size);
void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (V3::*ctor)());

class MeshBuffers {
public:
    char pad0[0x14];
    unsigned short *indices;    // 0x14
    V3 *vec18;                  // 0x18
    V3 *vec1c;                  // 0x1c
    float *raw20;               // 0x20
    float *raw24;               // 0x24
    V3 *vec28;                  // 0x28
    float *raw2c;               // 0x2c
    V3 *vec30;                  // 0x30
    float *raw34;               // 0x34
    float *uv[4];               // 0x38
    float *color[2];            // 0x48
    float *raw50;               // 0x50
    V3 *vec54;                  // 0x54

    void FUN_002c7340(unsigned int flags, unsigned int n, unsigned int indexCount);
};

void MeshBuffers::FUN_002c7340(unsigned int flags, unsigned int n, unsigned int indexCount)
{
    if (indexCount != 0)
        indices = (unsigned short *)FUN_0008d6d0(indexCount * 2);

    if (flags & 0x2000) {
        V3 *p = (V3 *)FUN_0008d6d0(n * 12);
        if (p)
            FUN_00011520(p, 12, n, &V3::FUN_00011090);
        else
            p = 0;
        vec18 = p;
    }
    if (flags & 0x10) {
        V3 *p = (V3 *)FUN_0008d6d0(n * 12);
        if (p)
            FUN_00011520(p, 12, n, &V3::FUN_00011090);
        else
            p = 0;
        vec1c = p;
    }
    if (flags & 0x800) {
        V3 *p = (V3 *)FUN_0008d6d0(n * 12);
        if (p)
            FUN_00011520(p, 12, n, &V3::FUN_00011090);
        else
            p = 0;
        vec28 = p;
    }
    if (flags & 0x1000) {
        V3 *p = (V3 *)FUN_0008d6d0(n * 12);
        if (p)
            FUN_00011520(p, 12, n, &V3::FUN_00011090);
        else
            p = 0;
        vec30 = p;
    }

    unsigned int uvCount = flags & 0xf;
    for (unsigned int k = 0; k < 4; k++) {
        uv[k] = 0;
        if (k < uvCount)
            uv[k] = (float *)FUN_0008d6d0(n * 8);
    }

    unsigned int colorCount = (flags >> 15) & 7;
    for (unsigned int k = 0; k < 2; k++) {
        color[k] = 0;
        if (k < colorCount)
            color[k] = (float *)FUN_0008d6d0(n * 4);
    }
    if (color[0] == 0 && (flags & 0x20))
        color[0] = (float *)FUN_0008d6d0(n * 4);

    if (flags & 0x80)
        raw50 = (float *)FUN_0008d6d0(n * 4);

    if (flags & 0x100) {
        vec54 = (V3 *)FUN_0008d6d0(n * 12);
        for (unsigned int i = 0; i < n; i++) {
            vec54[i].x = 1.0f;
            vec54[i].y = 0.0f;
            vec54[i].z = 0.0f;
        }
    }

    if ((flags & 0x80) || (flags & 0x100)) {
        raw20 = (float *)FUN_0008d6d0(n * 12);
        if (flags & 0x10)
            raw24 = (float *)FUN_0008d6d0(n * 12);
        if (flags & 0x800)
            raw2c = (float *)FUN_0008d6d0(n * 12);
        if (flags & 0x1000)
            raw34 = (float *)FUN_0008d6d0(n * 12);
    }
}
