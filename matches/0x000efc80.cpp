extern void* __stdcall FUN_000e7620(void*);
struct Obj {
    char pad[0x9ac];
    void* value;
};
void* __stdcall FUN_000efc80(void* arg) {
    return ((Obj*)FUN_000e7620(arg))->value;
}
