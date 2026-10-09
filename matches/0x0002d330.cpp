struct Vec { unsigned x, y, z; };
class CActorManager { public: int Act(Vec v); };
typedef int (CActorManager::*ActFn)(Vec);
class Function { public: virtual void vfunc_0(); virtual void vfunc_1(); };
class Method1 : public Function {
public:
    virtual void vfunc_2(CActorManager* obj, Vec* v, unsigned* out);
    char pad[0x1c - 4];
    ActFn mFn;
};
void Method1::vfunc_2(CActorManager* obj, Vec* v, unsigned* out) {
    ActFn fn = mFn;
    int r = (obj->*fn)(*v);
    if (out) *out = r;
}
