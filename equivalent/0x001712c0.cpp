// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 6/6)
// hulkfight::motion::JointPivotTrackerAction::vfunc_3 @ 0x001712c0
struct V3_1712c0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat4_1712c0 {
    V3_1712c0 r0;
    float w0;
    V3_1712c0 r1;
    float w1;
    V3_1712c0 r2;
    float w2;
    float t[4];
    void FUN_0022b980();
    void FUN_0022c0b0();
};

struct Name_1712c0 {
    char data[8];
    void FUN_0027b040(const char *s);
};

class JointDriver {
public:
    virtual void v0();
    char pad04[4];
    Name_1712c0 name;
    int f10;
    int f14;
    char pad18[0x70 - 0x18];
    JointDriver *FUN_002248a0();
};

void *__cdecl FUN_00263ea0(unsigned int size);

struct JointFinder_1712c0 {
    unsigned int FUN_0027b200(int a, int b);
};

struct SceneCtl_1712c0 {
    char pad0[8];
    JointFinder_1712c0 *finder;
};

struct Stats_1712c0 {
    char pad0[0x120];
    SceneCtl_1712c0 *scene;
};

struct Fighter_1712c0 { char pad[4]; };
Fighter_1712c0 *__fastcall FUN_000592a0(void *owner);
Stats_1712c0 *__fastcall FUN_00059a30(Fighter_1712c0 *f);

struct TrackerData_1712c0 {
    char pad0[0x18];
    int jointA;
    int jointB;
    V3_1712c0 vecB;
    V3_1712c0 axisSrc;
};

class JointPivotTrackerAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    TrackerData_1712c0 *data;
    void *owner;
    JointDriver *driver;
    V3_1712c0 side;
    V3_1712c0 axis;
    Mat4_1712c0 mat;
};

bool JointPivotTrackerAction::vfunc_3(int a, int b)
{
    Stats_1712c0 *stats = FUN_00059a30(FUN_000592a0(owner));
    SceneCtl_1712c0 *scene = stats->scene;
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
    driver->name.FUN_0027b040("jointPivotTracker");
    driver->v0();
    driver->f14 = 2;
    driver->f10 = id;

    V3_1712c0 src = data->axisSrc;
    axis = src;
    axis.FUN_0022d110();

    V3_1712c0 b3 = data->vecB;
    b3.FUN_0022d110();

    V3_1712c0 c;
    c.x = b3.z * axis.y - b3.y * axis.z;
    c.y = b3.x * axis.z - b3.z * axis.x;
    c.z = b3.y * axis.x - b3.x * axis.y;
    c.FUN_0022d110();

    side.x = c.y * axis.z - c.z * axis.y;
    side.y = c.z * axis.x - c.x * axis.z;
    side.z = c.x * axis.y - c.y * axis.x;
    side.FUN_0022d110();

    mat.FUN_0022b980();
    mat.r0 = c;
    mat.r1 = axis;
    mat.r2 = side;
    mat.FUN_0022c0b0();
    return true;
}
