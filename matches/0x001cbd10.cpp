typedef unsigned int u32_1cbd10;
struct Local_1cbd10 {
    char pad[32];
    void Init(u32_1cbd10);
};
struct CEventManager_1cbd10 {
    char pad[0x20];
    void Run(Local_1cbd10*);
    void Target(u32_1cbd10);
};
void CEventManager_1cbd10::Target(u32_1cbd10 arg) {
    Local_1cbd10 local;
    local.Init(arg);
    Run(&local);
}