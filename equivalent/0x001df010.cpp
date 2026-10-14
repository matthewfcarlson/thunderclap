// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001df010 @ 0x001df010
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);
unsigned __int64 __cdecl FUN_0027b020(const char *name);

struct Mat4 {
    float m[12];
    int tx, ty, tz;
    float w;
    void FUN_0022b980();
    void FUN_0022bc20(float x, float y, float z);
};

struct Index {
    int FUN_0027b200(unsigned __int64 key);
};

struct Holder {
    char pad00[8];
    Index *index;
};

struct Part;

struct Actor {
    char pad00[0x120];
    Holder *holder;
    void FUN_0003acf0(int a, Part *part, int index, int c, int d, Mat4 *mat);
};

struct Registry {
    Actor *FUN_00024280(unsigned __int64 id);
};

struct Group {
    char pad00[0x20];
    Registry *registry;
};

class Owner {
public:
    char pad00[0x1e830];
    Group *group;
    Part *FUN_001def30(int a);
    void FUN_001df010(int a1, const char *actorName, int a3, const char *partName, int px, int py, int pz,
                      float rx, float ry, float rz);
};

void Owner::FUN_001df010(int a1, const char *actorName, int a3, const char *partName, int px, int py, int pz,
                         float rx, float ry, float rz)
{
    Registry *registry = group->registry;
    Actor *actor = registry->FUN_00024280(FUN_002672f0(actorName, 0, 0));
    Part *part = FUN_001def30(a1);
    if (!actor || !part)
        return;
    int index = 0xffff;
    if (actor->holder) {
        Index *table = actor->holder->index;
        index = table->FUN_0027b200(FUN_0027b020(partName));
    }
    Mat4 m;
    m.FUN_0022b980();
    m.FUN_0022bc20(rx * 0.01745329238474369f, ry * 0.01745329238474369f, rz * 0.01745329238474369f);
    m.tx = px;
    m.ty = py;
    m.tz = pz;
    actor->FUN_0003acf0(a3, part, index, 0, 0, &m);
}
