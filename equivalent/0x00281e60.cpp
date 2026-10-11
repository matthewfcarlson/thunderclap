// STATUS: equivalent (tools/equiv.py level 3: 43 inputs, branch coverage 4/4)
// FUN_00281e60 @ 0x00281e60
struct Plane {
    float nx, ny, nz, d;
};

struct Vtx {
    unsigned int f[6];
};

struct Frame {
    int count;
    Vtx outBuf[10];
    Vtx bufC[10];
    Vtx bufB[10];
    Vtx bufA[10];
};

void __cdecl FUN_00280be0(const Plane* plane, const Vtx* in, int inCount, Vtx* out, int* outCount);

void __cdecl FUN_00281e60(const Plane* planes, const Vtx* tri, Vtx* out, int* outCount)
{
    Frame f;

    FUN_00280be0(&planes[0], tri, 3, f.bufC, &f.count);
    FUN_00280be0(&planes[1], f.bufC, f.count, f.bufB, &f.count);
    FUN_00280be0(&planes[2], f.bufB, f.count, f.bufA, &f.count);
    FUN_00280be0(&planes[3], f.bufA, f.count, f.outBuf, &f.count);

    int n = f.count;
    *outCount = 0;
    if (n > 2) {
        for (int i = 1; i <= n - 2; i++) {
            int idx;
            idx = (*outCount)++;
            out[idx] = f.outBuf[0];
            idx = (*outCount)++;
            out[idx] = f.outBuf[i];
            idx = (*outCount)++;
            out[idx] = f.outBuf[i + 1];
        }
    }
}
