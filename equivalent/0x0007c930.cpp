// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 13/14, incomplete)
// FUN_0007c930 @ 0x0007c930
struct V3 {
    float x, y, z;
    void FUN_0022d180();
};
struct Mat {
    float m[16];
    void FUN_0022c3b0(V3* in, V3* out);
};
struct Body {
    char pad0[0x34];
    int id;
};
struct Lookup {
    void FUN_001dd520(int id, Mat* out);
};
struct Env {
    char pad0[0xc];
    Lookup* lookup;
};
class Group {
public:
    char pad0[0x374c];
    Body* bodies[20];
    int count;
    char pad37a0[0x382c - 0x37a0];
    Env* env;
    bool FUN_0007c930(V3 pos, int skip);
};

bool Group::FUN_0007c930(V3 pos, int skip)
{
    V3 ref;
    if (skip != -1) {
        Mat basis;
        env->lookup->FUN_001dd520(bodies[skip]->id, &basis);
        V3 axis;
        axis.x = -1.0f;
        axis.y = 0.0f;
        axis.z = 0.0f;
        basis.FUN_0022c3b0(&axis, &ref);
    }
    for (int i = 0; i < count; i++) {
        if (i == skip)
            continue;
        Mat m;
        env->lookup->FUN_001dd520(bodies[i]->id, &m);
        V3 d;
        float dx = m.m[12] - pos.x;
        float dy = m.m[13] - pos.y;
        float dz = m.m[14] - pos.z;
        d.x = dx;
        d.y = dy;
        d.z = dz;
        if (!(dz * dz + dy * dy + dx * dx < 100.0f))
            continue;
        if (skip == -1)
            return true;
        d.FUN_0022d180();
        float dot = ref.z * d.z + ref.y * d.y + ref.x * d.x - 1.0f;
        float a = dot < 0.0f ? -dot : dot;
        if (a <= 1e-5f)
            return true;
    }
    return false;
}
