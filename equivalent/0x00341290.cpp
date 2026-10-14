// STATUS: equivalent (tools/equiv.py level 3: 202 inputs, branch coverage 4/4)
// FUN_00341290 @ 0x00341290
// equiv-conv: FUN_00341290 eax stack stack
void FUN_00341290(float *a, int n, float *w)
{
    int h = n >> 3;
    int o1 = h * 2;
    int o2 = o1 * 2;
    int o3 = o1 * 3;
    int o4 = o1 * 4;

    {
        float x0r = a[o2] + a[0];
        float x0i = a[o2 + 1] + a[1];
        float x1r = a[0] - a[o2];
        float x1i = a[1] - a[o2 + 1];
        float x2r = a[o3] + a[o1];
        float x2i = a[o3 + 1] + a[o1 + 1];
        float x3r = a[o1] - a[o3];
        float x3i = a[o1 + 1] - a[o3 + 1];
        a[0] = x2r + x0r;
        a[1] = x2i + x0i;
        a[o1] = x0r - x2r;
        a[o1 + 1] = x0i - x2i;
        a[o2] = x1r - x3i;
        a[o2 + 1] = x3r + x1i;
        a[o3] = x3i + x1r;
        a[o3 + 1] = x1i - x3r;
    }

    float wn4r = w[1];

    if (h > 2) {
        int j = 2;
        int k = 2;
        do {
            float W1 = w[k + 2];
            float W2 = w[k + 3];
            float W3 = w[k + 4];
            float W4 = -w[k + 5];
            k += 4;

            {
                float x0r = a[j] + a[o2 + j];
                float x0i = a[j + 1] + a[o2 + j + 1];
                float x1r = a[j] - a[o2 + j];
                float x1i = a[j + 1] - a[o2 + j + 1];
                float x2r = a[o3 + j] + a[o1 + j];
                float x2i = a[o1 + j + 1] + a[o3 + j + 1];
                float x3r = a[o1 + j] - a[o3 + j];
                float x3i = a[o1 + j + 1] - a[o3 + j + 1];
                a[j] = x2r + x0r;
                a[j + 1] = x2i + x0i;
                a[o1 + j] = x0r - x2r;
                a[o1 + j + 1] = x0i - x2i;
                float t1 = x1r - x3i;
                float t2 = x3r + x1i;
                a[o2 + j] = W1 * t1 - W2 * t2;
                a[o2 + j + 1] = W1 * t2 + W2 * t1;
                float u1 = x3i + x1r;
                float u2 = x1i - x3r;
                a[o3 + j] = W4 * u2 + W3 * u1;
                a[o3 + j + 1] = W3 * u2 - W4 * u1;
            }
            {
                float y0r = a[o1 - j] + a[o3 - j];
                float y0i = a[o1 - j + 1] + a[o3 - j + 1];
                float y1r = a[o1 - j] - a[o3 - j];
                float y1i = a[o1 - j + 1] - a[o3 - j + 1];
                float y2r = a[o2 - j] + a[o4 - j];
                float y2i = a[o2 - j + 1] + a[o4 - j + 1];
                float y3r = a[o2 - j] - a[o4 - j];
                float y3i = a[o2 - j + 1] - a[o4 - j + 1];
                a[o1 - j] = y2r + y0r;
                a[o1 - j + 1] = y2i + y0i;
                a[o2 - j] = y0r - y2r;
                a[o2 - j + 1] = y0i - y2i;
                float v1 = y1r - y3i;
                float v2 = y3r + y1i;
                a[o3 - j] = W2 * v1 - W1 * v2;
                a[o3 - j + 1] = W2 * v2 + W1 * v1;
                float s1 = y3i + y1r;
                float s2 = y1i - y3r;
                a[o4 - j] = W3 * s2 + W4 * s1;
                a[o4 - j + 1] = W4 * s2 - W3 * s1;
            }
            j += 2;
        } while (j < h);
    }

    int p1 = h;
    int p3 = 3 * h;
    int p5 = 5 * h;
    int p7 = 7 * h;
    float z0r = a[p5] + a[p1];
    float z0i = a[p5 + 1] + a[p1 + 1];
    float z1r = a[p1] - a[p5];
    float z1i = a[p1 + 1] - a[p5 + 1];
    float z2r = a[p7] + a[p3];
    float z2i = a[p7 + 1] + a[p3 + 1];
    float z3r = a[p3] - a[p7];
    float z3i = a[p3 + 1] - a[p7 + 1];
    a[p1] = z2r + z0r;
    a[p1 + 1] = z2i + z0i;
    a[p3] = z0r - z2r;
    a[p3 + 1] = z0i - z2i;
    float s1 = z1r - z3i;
    float s2 = z3r + z1i;
    a[p5] = wn4r * (s1 - s2);
    a[p5 + 1] = wn4r * (s2 + s1);
    float r1 = z3i + z1r;
    float r2 = z1i - z3r;
    a[p7] = -(wn4r * (r2 + r1));
    a[p7 + 1] = -(wn4r * (r2 - r1));
}
