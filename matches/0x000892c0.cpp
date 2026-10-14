typedef unsigned int u32_892c0;
class Callee_892c0 {
  public:
    void Run(int a, int b);
};
class Obj_892c0 {
  public:
    char pad[0xac4];
    Callee_892c0* mArg;
    char* mBase;
    void Target(int param2, int index);
};
void Obj_892c0::Target(int param2, int index) {
    char* p = mBase + index * 0xbe8;
    for (int i = 0; i < 0x2fa; ++i)
        ((u32_892c0*)p)[i] = 0;
    p[4] = 0;
    mArg->Run(param2, index);
}