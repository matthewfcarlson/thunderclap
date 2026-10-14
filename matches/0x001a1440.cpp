typedef unsigned int u32_1a1440;
extern void* LuaTrack_vft;
void __cdecl cleanup(u32_1a1440);
struct LuaTrack {
    void* vft;
    char pad[0x10];
    u32_1a1440 field14;
    void Tail();
    void Run();
};
void LuaTrack::Run() {
    vft = &LuaTrack_vft;
    cleanup(field14);
    Tail();
}