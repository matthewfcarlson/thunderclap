class ParamValue { public: char pad[12]; };
class ParamValueBool : public ParamValue {};
class CCollisionTrack;
class ParamBoolPtr : public ParamValueBool {
public:
 int offset;
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
 virtual bool vfunc_6(unsigned char* p, unsigned char v);
};
bool ParamBoolPtr::vfunc_6(unsigned char* p, unsigned char v) { p[offset] = v; return true; }