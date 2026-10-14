// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 6/6)
// hulkfight::motion::JointTrackerAction::vfunc_3 @ 0x001710d0
struct V3_1710d0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat4_1710d0 {
    V3_1710d0 r0;
    float w0;
    V3_1710d0 r1;
    float w1;
    V3_1710d0 r2;
    float w2;
    float t[4];
    void FUN_0022b980();
    void FUN_0022c0b0();
};

struct Name_1710d0 {
    char data[8];
    void FUN_0027b040(const char *s);
};

class JointDriver {
public:
    virtual void v0();
    char pad04[4];
    Name_1710d0 name;
    int f10;
    int f14;
    char pad18[0x70 - 0x18];
    JointDriver *FUN_002248a0();
};

void *__cdecl FUN_00263ea0(unsigned int size);

struct JointFinder_1710d0 {
    unsigned int FUN_0027b200(int a, int b);
};

struct SceneCtl_1710d0 {
    char pad0[8];
    JointFinder_1710d0 *finder;
};

struct Stats_1710d0 {
    char pad0[0x120];
    SceneCtl_1710d0 *scene;
};

struct Fighter_1710d0 { char pad[4]; };
Fighter_1710d0 *__fastcall FUN_000592a0(void *owner);
Stats_1710d0 *__fastcall FUN_00059a30(Fighter_1710d0 *f);

struct TrackerData_1710d0 {
    char pad0[0x18];
    int jointA;
    int jointB;
    V3_1710d0 axisSrc;
    V3_1710d0 refSrc;
};

class JointTrackerAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    TrackerData_1710d0 *data;
    void *owner;
    JointDriver *driver;
    V3_1710d0 axis;
    Mat4_1710d0 mat;
};

bool JointTrackerAction::vfunc_3(int a, int b)
{
    Stats_1710d0 *stats = FUN_00059a30(FUN_000592a0(owner));
    SceneCtl_1710d0 *scene = stats->scene;
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

    V3_1710d0 src = data->axisSrc;
    axis = src;
    axis.FUN_0022d110();

    V3_1710d0 ref = data->refSrc;
    ref.FUN_0022d110();

    V3_1710d0 c;
    c.x = ref.z * axis.y - ref.y * axis.z;
    c.y = ref.x * axis.z - ref.z * axis.x;
    c.z = ref.y * axis.x - ref.x * axis.y;
    c.FUN_0022d110();

    V3_1710d0 e;
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
