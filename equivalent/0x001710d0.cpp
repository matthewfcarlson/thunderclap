// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 6/6)
// hulkfight::motion::JointTrackerAction::vfunc_3 @ 0x001710d0
struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat4 {
    V3 r0;
    float w0;
    V3 r1;
    float w1;
    V3 r2;
    float w2;
    float t[4];
    void FUN_0022b980();
    void FUN_0022c0b0();
};

struct Name {
    char data[8];
    void FUN_0027b040(const char *s);
};

class JointDriver {
public:
    virtual void v0();
    char pad04[4];
    Name name;
    int f10;
    int f14;
    char pad18[0x70 - 0x18];
    JointDriver *FUN_002248a0();
};

void *__cdecl FUN_00263ea0(unsigned int size);

struct JointFinder {
    unsigned int FUN_0027b200(int a, int b);
};

struct SceneCtl {
    char pad0[8];
    JointFinder *finder;
};

struct Stats {
    char pad0[0x120];
    SceneCtl *scene;
};

struct Fighter { char pad[4]; };
Fighter *__fastcall FUN_000592a0(void *owner);
Stats *__fastcall FUN_00059a30(Fighter *f);

struct TrackerData {
    char pad0[0x18];
    int jointA;
    int jointB;
    V3 axisSrc;
    V3 refSrc;
};

class JointTrackerAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    TrackerData *data;
    void *owner;
    JointDriver *driver;
    V3 axis;
    Mat4 mat;
};

bool JointTrackerAction::vfunc_3(int a, int b)
{
    Stats *stats = FUN_00059a30(FUN_000592a0(owner));
    SceneCtl *scene = stats->scene;
    int ja = data->jointA;
    int jb = data->jointB;
    unsigned int id = 0;
    if ((ja | jb) != 0) {
        id = scene->finder->FUN_0027b200(ja, jb);
        if (id == 0xffff)
            id = 0;
    }

    JointDriver *d = (JointDriver *)FUN_00263ea0(0x70);
    if (d)
        d = d->FUN_002248a0();
    driver = d;
    driver->name.FUN_0027b040("jointTracker");
    driver->v0();
    driver->f14 = 2;
    driver->f10 = id;

    V3 src = data->axisSrc;
    axis = src;
    axis.FUN_0022d110();

    V3 ref = data->refSrc;
    ref.FUN_0022d110();

    V3 c;
    c.x = ref.z * axis.y - ref.y * axis.z;
    c.y = ref.x * axis.z - ref.z * axis.x;
    c.z = ref.y * axis.x - ref.x * axis.y;
    c.FUN_0022d110();

    V3 e;
    e.x = c.y * axis.z - c.z * axis.y;
    e.y = c.z * axis.x - c.x * axis.z;
    e.z = c.x * axis.y - c.y * axis.x;
    e.FUN_0022d110();

    mat.FUN_0022b980();
    mat.r0 = e;
    mat.r1 = c;
    mat.r2 = axis;
    mat.FUN_0022c0b0();
    return true;
}
