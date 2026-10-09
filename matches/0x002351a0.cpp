class Helper { public: void Process(int); };
class ParamValueBranch { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void vfunc_3(int, int); virtual void f4(); virtual void f5(); virtual int Query(int); virtual void f7(); };
void ParamValueBranch::vfunc_3(int a, int b) { int x = Query(a); if (x) ((Helper*)x)->Process(b); }