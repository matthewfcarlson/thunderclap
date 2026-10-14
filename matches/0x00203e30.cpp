struct Manager_203e30 {
    int Get();
    void Set(int);
};
struct Waiter {
    bool Ready();
};
struct Target_203e30 {
    void Run(Waiter*);
};
extern Manager_203e30* gManager_203e30;
extern void __cdecl FUN_00087990();
void Target_203e30::Run(Waiter* w) {
    int old = gManager_203e30->Get();
    gManager_203e30->Set(250000);
    while (!w->Ready())
        FUN_00087990();
    gManager_203e30->Set(old);
}