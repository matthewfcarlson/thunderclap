struct MissionProgressCondition {
    void* vf;
    char pad4[8];
    volatile void* a;
    char pad10[4];
    volatile void* b;
    void Init();
    void Tail();
};
extern char missionVftable;
void __cdecl thunk(void*);
void MissionProgressCondition::Init() {
    vf = &missionVftable;
    thunk((void*)a);
    thunk((void*)b);
    Tail();
}
