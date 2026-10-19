// Same code shape as 0x000679c0 (propagated; names are from that function)
struct C_1c7f70 {
    char pad[0x18];
};
struct Cache_1c7f70 { int FUN_0027af50(int); };
struct Mgr_1c7f70 { char pad[0x18]; Cache_1c7f70 cache; int FUN_001c7f70(int a); };
int Mgr_1c7f70::FUN_001c7f70(int a) {
    return cache.FUN_0027af50(a);
}