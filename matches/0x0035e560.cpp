extern "C" int __cdecl atexit(void (*)());

struct Reg {
    void RegFunc(const char* name, int v);
};

extern Reg gReg;

void Target() {
    gReg.RegFunc("sound/rsd", 0);
    atexit((void (*)())0x363fc0);
}
