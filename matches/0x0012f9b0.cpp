typedef unsigned int u32;
struct Action { char pad[0x1c]; };
struct Manager { Manager* doA(u32, int); void doB(); };
struct StatAction : Action { int m1c; int m20; bool vfunc_3(int, int); };
extern Manager* gManager;
bool StatAction::vfunc_3(int a, int b) {
    if (!m20) return false;
    u32 x = *(u32*)((char*)m1c + 0x10);
    Manager* p = gManager->doA(x, 1);
    p->doB();
    return true;
}