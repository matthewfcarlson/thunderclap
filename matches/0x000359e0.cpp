// FUN_000359e0 @ 0x000359e0
// FUN_000359e0 @ 0x000359e0: fetches the current orientation of a character (own or its parent's) and applies it
struct Quat_359e0 {
    unsigned x, y, z, w;
    void FUN_00034ca0(Quat_359e0 *src);
};

struct Pose {
    char pad00[0x2c];
    Quat_359e0 orientation;
};

class Source_359e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Pose *GetPose();
};

struct Link_359e0 {
    char pad00[8];
    Pose *pose;
};

struct Target_359e0 {
    void FUN_00059a50(Quat_359e0 *q);
};

class Character_359e0 {
public:
    char pad00[0x10];
    Target_359e0 *target;
    char pad14[0x11c - 0x14];
    Link_359e0 *link;
    char pad120[8];
    Character_359e0 *parent;
    bool FUN_000352b0(Quat_359e0 *q);
    bool FUN_000359e0(Quat_359e0 *out);
};

struct ParentLink {
    char pad00[0x11c];
    Source_359e0 *source;
};

bool Character_359e0::FUN_000359e0(Quat_359e0 *out)
{
    if (link == 0)
        return false;
    Pose *pose = link->pose;
    if (pose != 0) {
        out->x = pose->orientation.x;
        out->y = pose->orientation.y;
        out->z = pose->orientation.z;
        out->w = pose->orientation.w;
        if (!FUN_000352b0(out))
            target->FUN_00059a50(out);
        return true;
    }
    if (parent != 0) {
        Source_359e0 *source = ((ParentLink *)parent)->source;
        if (source != 0) {
            Pose *p = source->GetPose();
            if (p != 0) {
                out->FUN_00034ca0(&p->orientation);
                if (!FUN_000352b0(out))
                    target->FUN_00059a50(out);
                return true;
            }
        }
    }
    return false;
}
