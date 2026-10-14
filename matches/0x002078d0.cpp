struct Obj_2078d0 {
    char pad[0xaec];
    void* field;
    bool FUN_00207410();
    bool FUN_002078d0();
};
extern "C" void __stdcall FUN_00203e30(void*);
bool Obj_2078d0::FUN_002078d0() {
    if (field) {
        FUN_00203e30(field);
        return FUN_00207410();
    }
    return false;
}