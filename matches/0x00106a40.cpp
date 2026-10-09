class CPatrolPathManager { public: bool invoke(const char*, bool, int); };
struct Args { const char* s; bool b; int i; };
typedef bool (CPatrolPathManager::*Fn)(const char*, bool, int);
class Function { public: virtual void f0(); virtual void f1(); };
class Method3 : public Function {
public:
  virtual void f0();
  virtual void f1();
  virtual bool f2(int x, Args* a, bool* out);
  char pad[0x1c - 4];
  Fn fn;
};
bool Method3::f2(int x, Args* a, bool* out) {
  Fn f = fn;
  const char* s = a->s;
  bool b = a->b;
  int i = a->i;
  bool r = (((CPatrolPathManager*)x)->*f)(s, b, i);
  if (out) *out = r;
  return r;
}
