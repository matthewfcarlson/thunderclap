// STATUS: equivalent (tools/equiv.py level 3: 867 inputs, branch coverage 36/36)
// FUN_0022a0d0 @ 0x0022a0d0
struct Shape {
    char pad[0x10];
    float f10;
    float f14;
};

struct Slot {
    char pad[0x34];
    Shape *shape;
    char pad2[0x208 - 0x38];
};

struct Elem {
    int idx;
    float w;
    float f;
};

float __cdecl FUN_0004af40(float lo, float hi, float x);
float __cdecl FUN_0015cf40(float x);
void __cdecl FUN_00229f40(Elem *first, Elem *last, int n);

class Spawner {
public:
    char pad0[0x20];
    float f20;
    float f24;
    unsigned n;
    unsigned m;
    char pad30[0x854 - 0x30];
    float tab[3];
    void *grid[16];
    float angle;
    float blend;
    char pad8a8[8];
    float t;
    unsigned k;
    Elem arr[1];

    void FUN_002287b0(void *g, float w, float tt);
    void FUN_0022a0d0(float dt);
};

void Spawner::FUN_0022a0d0(float dt)
{
    unsigned n0 = n;
    unsigned m1 = m - 1;
    unsigned stride = n0 + 1;
    unsigned row = m1;
    k = 0;
    float T0 = tab[row];
    while (!(t >= T0) && row != 0) {
        row--;
        T0 = tab[row];
    }
    float B = blend;
    if (B > 0.01f && n0 != 0) {
        angle = FUN_0004af40(0.0f, 6.28318548f, angle);
        unsigned n1 = n;
        float step = 6.28318548f / (float)n1;
        float inv = 1.0f / step;
        unsigned idx = (int)(angle * inv);
        unsigned i0 = idx % n1;
        unsigned i1 = (i0 + 1) % n1;
        float S = FUN_0015cf40((angle - (float)i0 * step) * inv);
        unsigned a0 = row * stride;
        if (row >= m - 1) {
            FUN_002287b0(grid[a0 + i0 + 1], (1.0f - S) * B, T0);
            FUN_002287b0(grid[a0 + i1 + 1], S * B, T0);
            FUN_002287b0(grid[a0], 1.0f - B, T0);
        } else {
            volatile float U = tab[row + 1];
            volatile float R = (t - T0) / (U - T0);
            volatile float Rm = 1.0f - R;
            volatile float Sm = 1.0f - S;
            FUN_002287b0(grid[a0 + i0 + 1], Rm * Sm * B, T0);
            FUN_002287b0(grid[a0 + i1 + 1], Rm * S * B, T0);
            volatile float Bm = 1.0f - B;
            FUN_002287b0(grid[a0], Rm * Bm, T0);
            unsigned a1 = a0 + stride;
            FUN_002287b0(grid[a1 + i0 + 1], Sm * R * B, U);
            FUN_002287b0(grid[a1 + i1 + 1], R * S * B, U);
            FUN_002287b0(grid[a1], Bm * R, U);
        }
    } else if (row >= m1) {
        FUN_002287b0(grid[row * stride], 1.0f, T0);
    } else {
        volatile float V = tab[row + 1];
        volatile float R = (t - T0) / (V - T0);
        FUN_002287b0(grid[row * stride], 1.0f - R, T0);
        FUN_002287b0(grid[(row + 1) * stride], R, V);
    }

    Elem *first = arr;
    Elem *last = &arr[k];
    FUN_00229f40(first, last, last - first);

    float sum = 0.0f;
    for (unsigned i = 0; i < k; i++) {
        if (arr[i].w < 0.01f) {
            k = i;
            break;
        }
        sum += arr[i].w;
    }

    f20 = 0.0f;
    float W = 0.0f;
    if (k != 0) {
        double inv2 = 1.0f / sum;
        for (unsigned i = 0; i < k; i++) {
            volatile float nw = inv2 * arr[i].w;
            arr[i].w = nw;
            W += nw * arr[i].f;
            Shape *sh = ((Slot *)this)[arr[i].idx].shape;
            if (sh) {
                float a = sh->f10 - 1.0f;
                float b = sh->f14;
                if (b < 0.0f)
                    b = 1.0f;
                f20 = a / b * nw + f20;
            }
        }
    }

    if (f20 > 0.0f) {
        double X;
        if (W > 0.0f && t > 0.0f)
            X = t / W * dt;
        else
            X = dt;
        float v = X / f20 + f24;
        f24 = v;
        f24 = FUN_0015cf40(v);
    }
}
