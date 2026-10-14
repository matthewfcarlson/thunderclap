struct Vec_2d330 {
    unsigned x, y, z;
};
class CActorManager {
  public:
    int Act(Vec_2d330 v);
};
typedef int (CActorManager::*ActFn_2d330)(Vec_2d330);
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method1 : public Function {
  public:
    virtual void vfunc_2(CActorManager* obj, Vec_2d330* v, unsigned* out);
    char pad[0x1c - 4];
    ActFn_2d330 mFn;
};
void Method1::vfunc_2(CActorManager* obj, Vec_2d330* v, unsigned* out) {
    ActFn_2d330 fn = mFn;
    int r = (obj->*fn)(*v);
    if (out)
        *out = r;
}
