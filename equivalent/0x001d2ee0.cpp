// STATUS: equivalent (tools/equiv.py level 3: 13662 inputs, branch coverage 4/4)
// FUN_001d2ee0 @ 0x001d2ee0
// cl-flags: /GS

struct LuaState;
struct Vec3 {
    float x, y, z;
};

void __cdecl FUN_002133d0(LuaState *L, const char *s);
void __cdecl FUN_00213800(LuaState *L, int index);
void __cdecl FUN_00212d80(LuaState *L, int index);
void __cdecl FUN_001d0870(LuaState *L, Vec3 *v);

struct NodeName {
    void FUN_00233460(char *out, int size);
};

struct Node {
    char pad0[0x28];
    Vec3 pushback;
    char pad34[0x70 - 0x34];
    NodeName *sourceMotionNode;
};

class Actor {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Node *vfunc_3();
};

struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(Actor *actor);
struct Stats { char pad[4]; };
Stats *__fastcall FUN_00059a30(Context *ctx);
char *__fastcall FUN_00036d00(Stats *stats);

class ScriptTable {
public:
    char pad0[8];
    LuaState *L;
    void FUN_001d1cb0();
    void FUN_001d2ba0(const char *name, int a, int b);
    char FUN_001d2ee0(Actor *actor);
};

char ScriptTable::FUN_001d2ee0(Actor *actor)
{
    char *actorName = FUN_00036d00(FUN_00059a30(FUN_000592a0(actor)));
    FUN_001d1cb0();
    FUN_002133d0(L, "actor");
    FUN_002133d0(L, actorName);
    FUN_00213800(L, -3);

    Node *node = actor->vfunc_3();
    if (node != 0) {
        FUN_001d2ba0("collision", 0, 1);
        NodeName *src = node->sourceMotionNode;
        if (src != 0) {
            char name[0x100];
            for (int i = 0; i < 0x100; i++)
                name[i] = 0;
            src->FUN_00233460(name, 0x100);
            FUN_002133d0(L, "sourceMotionNode");
            FUN_002133d0(L, name);
            FUN_00213800(L, -3);
        }
        Vec3 v = node->pushback;
        FUN_002133d0(L, "pushbackVelocity");
        FUN_001d0870(L, &v);
        FUN_00213800(L, -3);
        FUN_00212d80(L, -2);
    }
    FUN_00212d80(L, -2);
    return 1;
}
