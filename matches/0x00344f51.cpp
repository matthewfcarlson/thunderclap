typedef void (__cdecl *Callback)();
extern Callback gCallback;
void __cdecl DoThing(int);
class DynamicCasterBase { public: virtual void Method(); };
void DynamicCasterBase::Method() { if (gCallback) gCallback(); DoThing(0x19); }