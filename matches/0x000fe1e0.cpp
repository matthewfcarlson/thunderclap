extern int golemVtable;
extern int memoryVtable;
extern int refVtable;
class IRefCount {
  public:
    virtual void f0();
    virtual void Release();
};
class CGolem {
  public:
    int vf;
    char pad04[8];
    IRefCount* items[16];
    char pad4c[12];
    int memory;
    void destroy();
};
void CGolem::destroy() {
    int i;
    vf = (int)&golemVtable;
    for (i = 0; i < 16; ++i) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
    }
    memory = (int)&memoryVtable;
    vf = (int)&refVtable;
}