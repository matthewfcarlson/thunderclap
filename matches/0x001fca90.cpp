struct Info {
    char pad[0xc8];
    float value;
};
extern float DEFAULT_VALUE;
struct ThisWrap_001fca90 {
    Info* GetInfo(int);
    float FUN_001fca90(int arg);
};
float ThisWrap_001fca90::FUN_001fca90(int arg) {
    Info* p = this->GetInfo(arg);
    if (!p)
        return DEFAULT_VALUE;
    return p->value;
}
