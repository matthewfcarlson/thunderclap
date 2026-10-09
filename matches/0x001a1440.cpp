typedef unsigned int u32;
extern void* LuaTrack_vft;
void __cdecl cleanup(u32);
struct LuaTrack { void* vft; char pad[0x10]; u32 field14; void Tail(); void Run(); };
void LuaTrack::Run() { vft = &LuaTrack_vft; cleanup(field14); Tail(); }