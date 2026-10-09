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
    vftable = (void*)0x42afa8;
    mRef = g_unknown;
    Init();
    vftable = (void*)0x42b3a4;
    mParam = (void*)x;
    Init();
}