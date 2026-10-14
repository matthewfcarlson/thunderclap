void* __stdcall FUN_0027f250(void*);
struct Helper {
    void* Run();
};
void* __stdcall FUN_001b8ec0(void* arg) {
    void* p = FUN_0027f250(arg);
    return ((Helper*)p)->Run();
}
