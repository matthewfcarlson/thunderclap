// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 22/22)
// FUN_00282a10 @ 0x00282a10
union Word_282a10 {
    float f;
    unsigned int u;
};

// Both the destination (this) and the source are the same buffer type, so the compiler
// must treat them as possibly overlapping, as the original does.
struct VertexBuf_282a10 {
    Word_282a10 w[0x31];          // 12 xyz triples at 0, copied words at 0x12 + 3*i, reference point at 0x24..0x26, color at 0x30

    void Blend(VertexBuf_282a10 *src, int count, float a3, float a4, float a5, float a6, float a7, float a8);
};

void VertexBuf_282a10::Blend(VertexBuf_282a10 *src, int count, float a3, float a4, float a5, float a6, float a7, float a8)
{
    double t = 1.0f - (double)a3 * a6;
    if (!(t > 0.0f))
        t = 0.0f;

    for (int i = 0; i < count; i++) {
        for (int k = 0; k < 3; k++)
            w[i * 3 + k].f = (float)((src->w[i * 3 + k].f - src->w[0x24 + k].f) * t + src->w[0x24 + k].f);
        w[0x12 + i * 3 + 0].u = src->w[0x12 + i * 3 + 0].u;
        w[0x12 + i * 3 + 1].u = src->w[0x12 + i * 3 + 1].u;
        w[0x12 + i * 3 + 2].u = src->w[0x12 + i * 3 + 2].u;
    }

    double y = 1.0f - (double)a3 * a7;
    if (!(y > 0.0f))
        y = 0.0f;
    if (a4 < 0.0f) {
        double s = (double)a4 * a5 + 1.0f;
        if (!(s > 0.0f))
            s = 0.0f;
        y = y * s;
    }
    int v = (int)(y * 255.0f);
    w[0x30].u = ((((0xffffff00u | v) << 8) | v) << 8) | v;

    double z = 1.0f - (double)a3 * a8;
    if (!(z > 0.0f))
        z = 0.0f;
    for (int k = 0; k < count; k++)
        w[0x24 + k * 2].f = (float)z;
}
