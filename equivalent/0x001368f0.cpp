// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 43/44, incomplete)
// hulkfight::motion::AirToGroundTargetAction::vfunc_5 @ 0x001368f0
struct V3_1368f0 {
    float x, y, z;
};
extern V3_1368f0 DAT_004abf64;
extern "C" double sqrt(double);

class Prop_1368f0 {
  public:
    virtual void addRef();
    virtual void release();
};

struct Sub18_1368f0 {
    void FUN_00221d20(float v);
    void FUN_0022be40(V3_1368f0 *p);
};
struct Target_1368f0 {
    char pad[0x18];
    Sub18_1368f0 sub;
};

struct Mover_1368f0 {
    char pad0[0x328];
    Prop_1368f0 *prop;
    void FUN_000359c0(int n);
    float FUN_000354c0();
};

struct Pos_1368f0 {
    void FUN_00059a50(V3_1368f0 *out);
};
struct Inner_1368f0 {
    Mover_1368f0 *FUN_00059a30();
};
struct Source_1368f0 {
    Inner_1368f0 *FUN_000592a0();
};

struct Info_1368f0 {
    char pad0[0x14];
    float lo;
    float hi;
    float rate;
    float grav;
    float f24;
    float f28;
};

void FUN_00096a90(Prop_1368f0 *p, V3_1368f0 *out);
float FUN_00224f10(V3_1368f0 *v);
float FUN_00224fc0(float a, float b);
void FUN_00224d70(float a, V3_1368f0 *v);

struct Frame_1368f0 {
    float g;
    float t1;
    float t2;
    V3_1368f0 d;
    V3_1368f0 pos;
    V3_1368f0 w;
    V3_1368f0 pn;
    V3_1368f0 q;
};

union Arg1_1368f0 {
    int flag;
    float v;
};

class AirToGroundTargetAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char v5(Arg1_1368f0 a1, float dt);
    char pad04[0x1c - 4];
    Info_1368f0 *info;
    Source_1368f0 *source;
    Target_1368f0 *target;
    Prop_1368f0 *prop;
    float speed;
    float vy;
};

char AirToGroundTargetAction::v5(Arg1_1368f0 a1, float dt)
{
    if (a1.flag)
        return 1;
    if (!target)
        return 0;
    Frame_1368f0 f;
    Inner_1368f0 *inner = source->FUN_000592a0();
    Mover_1368f0 *mover = inner->FUN_00059a30();
    mover->FUN_000359c0(3);
    f.pos.x = 0;
    f.pos.y = 0;
    f.pos.z = 0;
    ((Pos_1368f0 *)inner)->FUN_00059a50(&f.pos);
    if (!prop) {
        Prop_1368f0 *np = mover->prop;
        if (np)
            np->addRef();
        if (prop)
            prop->release();
        prop = np;
    }
    a1.v = mover->FUN_000354c0();
    if (prop) {
        f.q.x = 0;
        f.q.y = 0;
        f.q.z = 0;
        FUN_00096a90(prop, &f.q);
        f.d.x = f.q.x - f.pos.x;
        f.d.y = f.q.y - f.pos.y;
        f.d.z = f.q.z - f.pos.z;
        f.t1 = FUN_00224f10(&f.d);
        f.t2 = info->f24;
        if (f.t2 <= 0.0f) {
            a1.v = f.t1;
        } else {
            float r = FUN_00224fc0(a1.v, f.t1);
            f.t2 = f.t2 * dt;
            f.g = r;
            union {
                float f;
                unsigned int u;
            } bits;
            bits.f = r;
            bits.u &= 0x7fffffff;
            if (bits.f <= f.t2) {
                a1.v = f.t1;
            } else if (r < 0.0f) {
                a1.v = a1.v - f.t2;
            } else {
                a1.v = f.t2 + a1.v;
            }
        }
    }
    float v1 = a1.v;
    target->sub.FUN_00221d20(v1);
    f.g = info->grav;
    a1.v = speed;
    if (prop) {
        f.q.x = 0;
        f.q.y = 0;
        f.q.z = 0;
        FUN_00096a90(prop, &f.q);
        f.d.x = f.q.x - f.pos.x;
        f.d.y = f.q.y - f.pos.y;
        f.d.z = f.q.z - f.pos.z;
        if (f.d.y < 0.0f && f.g > 0.0f) {
            double inv = 1.0f / (double)(-f.g);
            double vy2 = (double)vy * (double)vy;
            double tt = (double)(-f.d.y) * (double)(-f.g);
            double disc = vy2 - (tt + tt);
            f.t2 = (float)(sqrt(disc) * inv);
            double tc = (double)(-vy) * inv;
            f.t1 = (float)((double)f.t2 + tc);
            double t2v = tc - (double)f.t2;
            double cand = 0.0f;
            bool have = false;
            if (f.t1 > 0.0f) {
                cand = f.t1;
                have = true;
            } else if (t2v > 0.0f) {
                cand = t2v;
                have = true;
            }
            if (have && cand > 0.0f) {
                double hd = sqrt((double)f.d.z * (double)f.d.z + (double)f.d.x * (double)f.d.x) - (double)info->f28;
                if (hd > 0.0f)
                    a1.v = (float)(hd / cand);
            }
        }
    }
    Info_1368f0 *inf = info;
    f.t2 = inf->rate;
    if (f.t2 <= 0.0f) {
        speed = a1.v;
    } else {
        double diff = (double)a1.v - (double)speed;
        f.t1 = f.t2 * dt;
        union {
            float f;
            unsigned int u;
        } bits;
        bits.f = (float)diff;
        bits.u &= 0x7fffffff;
        f.t2 = bits.f;
        if (f.t2 < f.t1) {
            speed = a1.v;
        } else if (diff < 0.0f) {
            speed = speed - f.t1;
        } else {
            speed = f.t1 + speed;
        }
    }
    float lo = inf->lo;
    float hi = inf->hi;
    a1.v = lo;
    float c;
    if (speed >= lo && speed <= hi)
        c = speed;
    else if (hi < speed)
        c = hi;
    else
        c = lo;
    speed = c;
    double newvy = (double)vy - (double)f.g * (double)dt;
    vy = (float)newvy;
    double sc = (double)c * (double)dt;
    f.w = DAT_004abf64;
    f.w.x = (float)((double)f.w.x * sc);
    f.w.z = (float)((double)f.w.z * sc);
    f.w.y = (float)(newvy * (double)dt);
    FUN_00224d70(v1, &f.w);
    f.pn.x = f.pos.x + f.w.x;
    f.pn.y = f.pos.y + f.w.y;
    f.pn.z = f.pos.z + f.w.z;
    target->sub.FUN_0022be40(&f.pn);
    return 1;
}
