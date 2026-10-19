// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c0be0 @ 0x000c0be0
// cl-flags: /GS
struct CFEManager;
struct Closure6 {
    const void* callbackTable;
    char data[0x1c];
    const char* arg2;
    void FUN_000be950(const char*, const char*);
    void FUN_001d04a0();
};
extern const void* DAT_00409300;
struct CFEManager {
    void FUN_001d26d0(const char*, Closure6*);
    void FUN_000c0be0(const char*, const char*, const char*);
};
void CFEManager::FUN_000c0be0(const char* first, const char* second, const char* third) {
    Closure6 closure;
    closure.FUN_000be950(first,third);
    closure.arg2=second;
    closure.callbackTable=&DAT_00409300;
    this->FUN_001d26d0(first,&closure);
    closure.FUN_001d04a0();
}
