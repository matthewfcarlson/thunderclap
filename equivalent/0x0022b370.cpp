// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/10, incomplete)
// FUN_0022b370 @ 0x0022b370
extern "C" double sqrt(double);

struct Quat {
    float x, y, z, w;
    void FUN_0022b370(const float *m);
};

// Rotation matrix (row-major 4x4) to quaternion; the result has its w negated.
void Quat::FUN_0022b370(const float *m)
{
    int next[3];
    float q[4];
    next[0] = 1;
    next[1] = 2;
    next[2] = 0;

    float trace = m[5] + m[0] + m[10];
    if (trace > 0.0f) {
        double s = sqrt((double)(trace + 1.0f));
        w = (float)(-0.5f * s);
        double inv = (s != 0.0f) ? 0.5f / s : s;
        x = (float)((m[9] - m[6]) * inv);
        y = (float)((m[2] - m[8]) * inv);
        z = (float)((m[4] - m[1]) * inv);
        return;
    }

    int i = 0;
    if (m[5] > m[0])
        i = 1;
    if (m[10] > m[i * 5])
        i = 2;
    int j = next[i];
    int k = next[j];

    double s = sqrt((double)(m[i * 5] - (m[k * 5] + m[j * 5]) + 1.0f));
    q[i] = (float)(0.5f * s);
    double inv = (s != 0.0f) ? 0.5f / s : s;
    q[3] = (float)((m[j + 4 * k] - m[k + 4 * j]) * inv);
    q[j] = (float)((m[i + 4 * j] + m[j + 4 * i]) * inv);
    q[k] = (float)((m[i + 4 * k] + m[k + 4 * i]) * inv);
    x = q[0];
    y = q[1];
    z = q[2];
    w = -q[3];
}
