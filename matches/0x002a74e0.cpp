namespace pure3d {
extern void Free(void*) throw();
class Ref_2a74e0 {
  public:
    virtual void f0() throw();
    virtual void Release() throw();
};
template <class T> struct Vec_2a74e0 {
    T* b;
    T* e;
    T* c;
    unsigned size() const { return (unsigned)(e - b); }
    T& operator[](unsigned i) { return b[i]; }
    ~Vec_2a74e0() throw() {
        if (b)
            Free(b);
    }
};
class SimpleFrameController {
  public:
    virtual ~SimpleFrameController() throw();
    char p[0x4c];
};
class ParticleController : public SimpleFrameController {
  public:
    Vec_2a74e0<Ref_2a74e0*> v;
    virtual ~ParticleController() throw();
};
ParticleController::~ParticleController() throw() {
    for (unsigned i = 0; i < v.size(); i++) {
        Ref_2a74e0*& r = v[i];
        if (r) {
            r->Release();
            r = 0;
        }
    }
}
} // namespace pure3d
