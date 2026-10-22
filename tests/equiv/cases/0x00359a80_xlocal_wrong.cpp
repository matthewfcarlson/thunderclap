// STATUS: equivalent (tools/equiv.py level 3: 1859 inputs, branch coverage 66/72, incomplete)
// FUN_00359a80 @ 0x00359a80
#include "compat/ptr.h"
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct V3 {
    float x, y, z;
};

union FBits {
    float f;
    unsigned int u;
};

// a + (b - a) * t, with t = da / (da - db), written out so the FPU keeps t and the differences unrounded
#define LERP(dst, a, b, da, db)                                  \
    do {                                                         \
        float *pa_ = (a);                                        \
        float *pb_ = (b);                                        \
        volatile float tx_, ty_, dz_;                            \
        hulk_freg t_ = (hulk_freg)(da) / ((hulk_freg)(da) - (db)); \
        dz_ = pb_[2] - pa_[2];                                   \
        tx_ = ((hulk_freg)pb_[0] - pa_[0]) * t_;                 \
        ty_ = ((hulk_freg)pb_[1] - pa_[1]) * t_;                 \
        (dst)[2] = (hulk_freg)dz_ * t_ + pb_[2];                 \
        (dst)[0] = tx_ + pa_[0];                                 \
        (dst)[1] = ty_ + pa_[1];                                 \
    } while (0)

void FUN_00359a80(const V3 *plane, float d, int *pcount, V3 *v)
{
    struct Frame {
        char padA[0x1c];
        float dist[12];
        char padB[12];
        V3 out[12];
    } F;
    int n = *pcount;
    int pos = 0;
    int neg = 0;
    int first = -1;
    int i;
    FBits a;
    a.f = d;
    a.u &= 0x7fffffff;
    for (i = 0; i < n; i++) {
        F.dist[i] = (hulk_freg)v[i].x * plane->x + (hulk_freg)v[i].z * plane->z + (hulk_freg)v[i].y * plane->y - d +
                    (hulk_freg)a.f * 1e-5f;
        if (F.dist[i] >= 0.0f) {
            pos++;
            if (first < 0)
                first = i;
        } else {
            neg++;
        }
    }
    int k = 0;
    if (n == 2) {
        if (pos <= 0) {
            *pcount = 0;
            return;
        }
        if (neg <= 0)
            return;
        int other = (first == 0);
        LERP((float *)&v[other], (float *)&v[first], (float *)&v[other], F.dist[first], F.dist[other]);
        return;
    }
    if (pos <= 0) {
        *pcount = 0;
        return;
    }
    if (neg <= 0) {
        *pcount = n;
        return;
    }
    int c = first;
    if (c > 0) {
        LERP((float *)&F.out[0], (float *)&v[c], (float *)&v[c - 1], F.dist[c], F.dist[c - 1]);
        k = 1;
        while (c < n && F.dist[c] >= 0.0f) {
            F.out[k++] = v[c];
            c++;
        }
        if (c < n) {
            LERP((float *)&F.out[k], (float *)&v[c], (float *)&v[c - 1], F.dist[c], F.dist[c - 1]);
        } else {
            LERP((float *)&F.out[k], (float *)&v[0], (float *)&v[n - 1], F.dist[0], F.dist[n - 1]);
        }
        k++;
    } else {
        c = 0;
        while (c < n && F.dist[c] >= 0.0f) {
            F.out[k++] = v[c];
            c++;
        }
        LERP((float *)&F.out[k], (float *)&v[c], (float *)&v[c - 1], F.dist[c], F.dist[c - 1]);
        k++;
        bool entered = false;
        if (c < n) {
            while (c < n) {
                if (!(F.dist[c] < 0.0f)) {
                    entered = true;
                    break;
                }
                c++;
            }
        }
        if (entered && c < n) {
            LERP((float *)&F.out[k], (float *)&v[c], (float *)&v[c - 1], F.dist[c], F.dist[c - 1]);
            k++;
            while (c < n && F.dist[c] >= 0.0f) {
                F.out[k++] = v[c];
                c++;
            }
        } else {
            LERP((float *)&F.out[k], (float *)&v[0], (float *)&v[n - 1], F.dist[0], F.dist[n - 1]);
            k++;
        }
    }
    memcpy(v, F.out, k * sizeof(V3));
    *pcount = k;
}
