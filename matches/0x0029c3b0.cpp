class Thing { public: virtual void F(int); };
extern Thing* gThing;
void FUN_0029c3b0() { if (gThing) gThing->F(1); gThing = 0; }