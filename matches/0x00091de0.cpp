extern int vtBase_91de0;
extern int vtCheat_91de0;
struct Sub_91de0 {
    void Init();
    char pad[8];
};
struct UnlockCheat {
    int* vptr;
    char p4[4];
    unsigned char flag;
    char p9[7];
    Sub_91de0 sub;
    int field18;
    char p1c[4];
    unsigned char field20;
    char p21[7];
    UnlockCheat* ctor(const char* arg);
};
void Format(void*, int, const char*, const char*);
UnlockCheat* UnlockCheat::ctor(const char* arg) {
    vptr = (int*)&vtBase_91de0;
    flag = 1;
    sub.Init();
    field18 = 0;
    field20 = 0;
    vptr = (int*)&vtCheat_91de0;
    Format((char*)this + 0x28, 8, "%s", arg);
    return this;
}
