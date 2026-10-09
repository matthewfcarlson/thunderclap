typedef unsigned int u32;
struct Local {
    char pad[32];
    void Init(u32);
};
struct Obj {
    char pad[0x20];
    void Run(Local*);
    void Target(u32);
};
void Obj::Target(u32 arg) {
    Local local;
    local.Init(arg);
    Run(&local);
}