struct Obj {
    void Init(const char*, int);
};
extern Obj gObj;
int atexit(void (*)(void));
extern "C" void FUN_00363c50();

void Reg() {
    gObj.Init("sound/rsd", 0);
    atexit(FUN_00363c50);
}
