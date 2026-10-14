// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 13/14, incomplete)
// FUN_0007c930 @ 0x0007c930
struct V3_7c930 {
    float x, y, z;
    void FUN_0022d180();
};
struct Mat_7c930 {
    float m[16];
    void FUN_0022c3b0(V3_7c930* in, V3_7c930* out);
};
struct Body_7c930 {
    char pad0[0x34];
    int id;
};
struct Lookup_7c930 {
    void FUN_001dd520(int id, Mat_7c930* out);
};
struct Env_7c930 {
    char pad0[0xc];
    Lookup_7c930* lookup;
};
class Group_7c930 {
public:
    char pad0[0x374c];
    Body_7c930* bodies[20];
    int count;
    char pad37a0[0x382c - 0x37a0];
    Env_7c930* env;
    bool FUN_0007c930(V3_7c930 pos, int skip);
};

bool Group_7c930::FUN_0007c930(V3_7c930 pos, int skip)
{
    V3_7c930 ref;
    if (skip != -1) {
        Mat_7c930 basis;
        env->lookup->FUN_001dd520(bodies[skip]->id, &basis);
        V3_7c930 axis;
        axis.x = -1.0f;
        axis.y = 0.0f;
        axis.z = 0.0f;
        basis.FUN_0022c3b0(&axis, &ref);
    }
    for (int i = 0; i < count; i++) {
        if (i == skip)
            continue;
        Mat_7c930 m;
        env->lookup->FUN_001dd520(bodies[i]->id, &m);
        V3_7c930 d;
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
