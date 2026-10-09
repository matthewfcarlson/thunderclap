class CSubtitleManager {
  public:
    void V0();
    void V1();
    void V2();
    void V3();
    void V4();
    void V5();
    void V6();
    void V7(int, int);
};
class Function {
  public:
    virtual void V0();
    virtual void V1();
};
class Method2 : public Function {
  public:
    char pad[0x18];
    void (CSubtitleManager::*fn)(int, int);
    void vfunc_2(int, int*, int);
};
void Method2::vfunc_2(int manager, int* pair, int a) {
    int x = pair[0];
    int y = pair[1];
    CSubtitleManager* m = (CSubtitleManager*)manager;
    (m->*fn)(x, y);
}