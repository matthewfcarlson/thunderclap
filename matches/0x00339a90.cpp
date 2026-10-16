extern "C" void FUN_003479bc(void*);
extern "C" int FUN_00347d7a(void*, void*);
extern "C" int FUN_00339a90(int a, void* p, int b, void* q) {
    if (!q) {
        FUN_003479bc(p);
        return 0;
    }
    return FUN_00347d7a(p, q);
}