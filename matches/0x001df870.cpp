// Same code shape as 0x0002c510 (propagated; names are from that function)
class Function { public: virtual void f0(); virtual void f1(); };
class CActorManager { public: bool (CActorManager::*m)(const char *, bool); };
struct Pair { const char *p; bool b; };
class Method2 : public Function { public: char pad[0x1c - 4]; bool (CActorManager::*mFn)(const char *, bool); virtual void f0(); virtual void f1(); virtual void f2(CActorManager *obj, Pair *p, bool *out); };
void Method2::f2(CActorManager *obj, Pair *p, bool *out) { bool (CActorManager::*fn)(const char *, bool) = mFn; const char *s = p->p; bool b = p->b; bool r = (obj->*fn)(s, b); if (out) *out = r; }
