struct ThisCall_001d0480 {
    void Init();
};
extern int gCount_22a8e0;
extern int gMax_22a8e0;
extern int vtable_22a8e0;
class Driver {
  public:
    int* mVtable;
};
Driver* __fastcall Target(Driver* self) {
    ((ThisCall_001d0480*)(self))->Init();
    self->mVtable = &vtable_22a8e0;
    ++gCount_22a8e0;
    if (gCount_22a8e0 <= gMax_22a8e0)
        return self;
    gMax_22a8e0 = gCount_22a8e0;
    return self;
}
