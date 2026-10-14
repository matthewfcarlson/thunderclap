struct Obj_b8c90 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual const char* Name();
};
Obj_b8c90* GetObj();
extern "C" int strcmp(const char*, const char*);
struct Foo_b8c90 {
    char pad[0x1cfc];
    float v;
    bool Check();
};
bool Foo_b8c90::Check() {
    if (GetObj()) {
        const char* s = GetObj()->Name();
        if (s) {
            if (strcmp("fullscreen_message", s) == 0 || strcmp("mission_accept", s) == 0) {
                if (v < 2.0f)
                    return true;
            }
        }
    }
    return false;
}