typedef unsigned int u32_12f9b0;
struct Action {
    char pad[0x1c];
};
struct Manager_12f9b0 {
    Manager_12f9b0* doA(u32_12f9b0, int);
    void doB();
};
struct StatAction : Action {
    int m1c;
    int m20;
    bool vfunc_3(int, int);
};
extern Manager_12f9b0* gManager_12f9b0;
bool StatAction::vfunc_3(int a, int b) {
    if (!m20)
        return false;
    u32_12f9b0 x = *(u32_12f9b0*)((char*)m1c + 0x10);
    Manager_12f9b0* p = gManager_12f9b0->doA(x, 1);
    p->doB();
    return true;
}