extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042b3a4[];
extern int g_unknown;
void Init();
class RefCount {
  public:
    void* vftable;
    int mRef;
    void* mParam;
    RefCount(int x);
};
RefCount::RefCount(int x) {
    vftable = (void*)((int)DAT_0042afa8);
    mRef = g_unknown;
    Init();
    vftable = (void*)((int)DAT_0042b3a4);
    mParam = (void*)x;
    Init();
}