extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042b3a4[];
extern "C" char DAT_0042b5ac[];
extern "C" char DAT_0042b5b4[];
extern "C" char DAT_0042b5f4[];
typedef unsigned int u32_270170;
extern u32_270170 g_unknown_270170;
void FUN_002705f0();
class MemoryPool {
  public:
    MemoryPool();
    u32_270170 v0;
    u32_270170 v1;
    u32_270170 v2;
    u32_270170 v3;
    u32_270170 v4;
    u32_270170 v5;
    u32_270170 v6;
    u32_270170 v7;
    u32_270170 v8;
    u32_270170 v9;
    u32_270170 v10;
    u32_270170 v11;
    u32_270170 v12;
};
MemoryPool::MemoryPool() {
    v0 = ((int)DAT_0042b5f4);
    v1 = ((int)DAT_0042afa8);
    v2 = g_unknown_270170;
    FUN_002705f0();
    v1 = ((int)DAT_0042b3a4);
    v3 = 0;
    FUN_002705f0();
    v0 = ((int)DAT_0042b5b4);
    v1 = ((int)DAT_0042b5ac);
    v6 = 0;
    v12 = 0;
    FUN_002705f0();
}