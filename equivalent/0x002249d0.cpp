// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 12/12)
// choreo2::JointDriver::vfunc_10 @ 0x002249d0
struct V3_2249d0 {
    float x, y, z;
};

struct Quat_2249d0 {
    float x, y, z, w;
    void FUN_0022b750(const Quat_2249d0 *a, const Quat_2249d0 *b, float t);
};

struct Transform_2249d0 {
    char pad0[0x30];
    V3_2249d0 pos;
    Quat_2249d0 *FUN_00221cd0();
    void FUN_00221cf0(const Quat_2249d0 *q);
    void FUN_0022be40(const V3_2249d0 *p);
};

struct JointPose {
    char pad0[0x30];
    V3_2249d0 pos;
    char pad3c[4];
};

struct PoseSet_2249d0 {
    char pad0[0xc];
    unsigned int count;
    Quat_2249d0 *rotations;
    JointPose *poses;
};

class JointDriver {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10(int a, Transform_2249d0 *target, PoseSet_2249d0 *set, float t);
    char pad04[0x10 - 4];
    unsigned int index;
    unsigned char flags;
    char pad15[3];
    Transform_2249d0 goal;
};

void JointDriver::vfunc_10(int a, Transform_2249d0 *target, PoseSet_2249d0 *set, float t)
{
    if (index == 0) {
        if (flags & 1) {
            V3_2249d0 p = target->pos;
            p.x = (goal.pos.x - p.x) * t + p.x;
            p.y = (goal.pos.y - p.y) * t + p.y;
            p.z = (goal.pos.z - p.z) * t + p.z;
            target->FUN_0022be40(&p);
        }
        if (flags & 2) {
            Quat_2249d0 q = *target->FUN_00221cd0();
            q.FUN_0022b750(&q, goal.FUN_00221cd0(), t);
            target->FUN_00221cf0(&q);
        }
    } else {
        if (index >= set->count)
            return;
        if (flags & 1) {
            JointPose *jp = &set->poses[index];
            V3_2249d0 p = jp->pos;
            float x = (goal.pos.x - p.x) * t + p.x;
            float y = (goal.pos.y - p.y) * t + p.y;
            float z = (goal.pos.z - p.z) * t + p.z;
            jp->pos.z = z;
            jp->pos.x = x;
            jp->pos.y = y;
        }
        if (flags & 2) {
            Quat_2249d0 q = set->rotations[index];
            q.FUN_0022b750(&q, goal.FUN_00221cd0(), t);
            set->rotations[index] = q;
        }
    }
}
