class Inner { public: virtual void a(); virtual void b(); };
void thunk(void*);
class Target { public: Inner* mObj; void* mArg; Target* run(unsigned char); };
Target* Target::run(unsigned char flags) { mObj->b(); thunk(mArg); if (flags & 1) thunk(this); return this; }