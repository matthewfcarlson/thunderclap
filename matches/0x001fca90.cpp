struct Info {
    char pad[0xc8];
    float value;
};
extern float DEFAULT_VALUE;
extern Info* __stdcall GetInfo(int);
float __stdcall FUN_001fca90(int arg) {
    Info* p = GetInfo(arg);
    if (!p)
        return DEFAULT_VALUE;
    return p->value;
}
