// FUN_001c3d90 is the 0-argument singleton getter; the two pushed values are arguments of the method call.
struct Registry {
    void FUN_001c3bb0(void*, unsigned int);
};
Registry* FUN_001c3d90();
struct Obj_1c5e40 {
    char pad[8];
    void target(unsigned int);
};
void Obj_1c5e40::target(unsigned int arg) {
    FUN_001c3d90()->FUN_001c3bb0((char*)this + 8, arg);
}
