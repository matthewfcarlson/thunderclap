typedef unsigned int u32;
extern u32 g_unknown;
void FUN_002705f0();
class MemoryPool {
  public:
    MemoryPool();
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v7;
    u32 v8;
    u32 v9;
    u32 v10;
    u32 v11;
    u32 v12;
};
MemoryPool::MemoryPool() {
    v0 = 0x42b5f4;
    v1 = 0x42afa8;
    v2 = g_unknown;
    FUN_002705f0();
    v1 = 0x42b3a4;
    v3 = 0;
    FUN_002705f0();
    v0 = 0x42b5b4;
    v1 = 0x42b5ac;
    v6 = 0;
    v12 = 0;
    FUN_002705f0();
}