struct Inner_1c5e40 {
    void run();
};
Inner_1c5e40* __stdcall FUN_001c3d90(void*, unsigned int);
struct Obj_1c5e40 {
    char pad[8];
    void target(unsigned int);
};
void Obj_1c5e40::target(unsigned int arg) {
    Inner_1c5e40* p = FUN_001c3d90((char*)this + 8, arg);
    p->run();
}