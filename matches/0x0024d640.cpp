class MetaEntity { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual bool vfunc_4(int); };
class ListenerEffectXBox : public MetaEntity { char pad[0x24]; public: bool vfunc_4(int); };
void helper(void*, int, int);
bool ListenerEffectXBox::vfunc_4(int x) { MetaEntity::vfunc_4(x); helper((char*)this+0x28,0,0); return true; }