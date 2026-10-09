class ISoundManager {
  public:
    virtual void f0();
    virtual void f1(void*, void*);
    virtual void f2();
};
class CFESoundManager : public ISoundManager {
  public:
    void* p;
    virtual void vfunc_0();
    virtual void vfunc_1(void*, void*);
    virtual void vfunc_2();
};
class Helper {
  public:
    void run(void*, void*);
};
void CFESoundManager::vfunc_1(void* a, void* b) {
    if (p)
        ((Helper*)p)->run(a, b);
}