extern "C" void __cdecl Init();
extern int gCount;
extern int gMax;
extern int vtable;
class Driver { public: int *mVtable; };
Driver * __fastcall Target(Driver *self) {
    Init();
    self->mVtable = &vtable;
    ++gCount;
    if (gCount <= gMax) return self;
    gMax = gCount;
    return self;
}
