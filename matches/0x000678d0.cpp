extern "C" int atexit(void (*)());
extern "C" void cleanup();
extern "C" unsigned int flag_678d0;
struct Obj_678d0 {
    void init();
};
extern Obj_678d0 object_678d0;
extern "C" Obj_678d0* FUN_000678d0() {
    if ((flag_678d0 & 1) == 0) {
        flag_678d0 = flag_678d0 | 1;
        object_678d0.init();
        atexit(cleanup);
    }
    return &object_678d0;
}