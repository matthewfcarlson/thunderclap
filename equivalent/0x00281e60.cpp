// STATUS: equivalent (tools/equiv.py level 3: 43 inputs, branch coverage 4/4)
// FUN_00281e60 @ 0x00281e60
struct Plane_281e60 {
    float nx, ny, nz, d;
};

struct Vtx_281e60 {
    unsigned int f[6];
};

struct Frame_281e60 {
    int count;
    Vtx_281e60 outBuf[10];
    Vtx_281e60 bufC[10];
    Vtx_281e60 bufB[10];
    Vtx_281e60 bufA[10];
};

void __cdecl FUN_00280be0(const Plane_281e60* plane, const Vtx_281e60* in, int inCount, Vtx_281e60* out, int* outCount);

void __cdecl FUN_00281e60(const Plane_281e60* planes, const Vtx_281e60* tri, Vtx_281e60* out, int* outCount)
{
    Frame_281e60 f;

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
