extern "C" int atexit(void (*)());
extern "C" void cleanup();
extern "C" unsigned int flag;
struct Obj {
    void init();
};
extern Obj object;
extern "C" Obj* target() {
    if ((flag & 1) == 0) {
        flag = flag | 1;
        object.init();
        atexit(cleanup);
    }
    return &object;
}