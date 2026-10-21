// STATUS: equivalent (tools/equiv.py level 3: 20029 inputs, branch coverage 8/10, incomplete)
// FUN_0022b370 @ 0x0022b370
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct Quat_22b370 {
    float x, y, z, w;
    void FUN_0022b370(const float *m);
};

// Rotation matrix (row-major 4x4) to quaternion; the result has its w negated.
// x87: the trace, the sums and the differences stay in registers (53 bits) until they are stored
void Quat_22b370::FUN_0022b370(const float *m)
{
    int next[3];
    float q[4];
    next[0] = 1;
    next[1] = 2;
    next[2] = 0;

    hulk_freg trace = (hulk_freg)m[5] + m[0] + m[10];
    if (trace > 0.0f) {
        double s = sqrt((double)(trace + 1.0f));
        w = (float)(-0.5f * s);
        double inv = (s != 0.0f) ? 0.5f / s : s;
        x = (float)(((hulk_freg)m[9] - m[6]) * inv);
        y = (float)(((hulk_freg)m[2] - m[8]) * inv);
        z = (float)(((hulk_freg)m[4] - m[1]) * inv);
        return;
    }

    int i = 0;
    if (m[5] > m[0])
        i = 1;
    if (m[10] > m[i * 5])
        i = 2;
    int j = next[i];
    int k = next[j];

    double s = sqrt((double)((hulk_freg)m[i * 5] - ((hulk_freg)m[k * 5] + m[j * 5]) + 1.0f));
    q[i] = (float)(0.5f * s);
    double inv = (s != 0.0f) ? 0.5f / s : s;
    q[3] = (float)(((hulk_freg)m[j + 4 * k] - m[k + 4 * j]) * inv);
    q[j] = (float)(((hulk_freg)m[i + 4 * j] + m[j + 4 * i]) * inv);
    q[k] = (float)(((hulk_freg)m[i + 4 * k] + m[k + 4 * i]) * inv);
    x = q[0];
    y = q[1];
    z = q[2];
    w = -q[3];
}
