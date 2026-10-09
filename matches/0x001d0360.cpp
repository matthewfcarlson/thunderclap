extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct DataInit { void Init(); };
struct CScenarioParams { unsigned int vf; unsigned int pad4; unsigned int id; unsigned int padc; DataInit data; void InitBase(); CScenarioParams* target(const unsigned int* src); };
extern unsigned int g_counter;
CScenarioParams* CScenarioParams::target(const unsigned int* src) {
    InitBase();
    vf = 0x422370;
    data.Init();
    unsigned int n = *src;
    memcpy(&data, src, n);
    ++g_counter;
    id = g_counter;
    return this;
}