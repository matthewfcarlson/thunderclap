class CompletionEventRequest { public: virtual void f0(); virtual int vfunc_1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); int pad; int value; };
int __cdecl DoThing(int);
int CompletionEventRequest::vfunc_1() { DoThing(value); return 1; }