struct Root {
    char pad[0x1c];
    void* sub;
};
extern Root* gRoot;
struct Sub {
    void Init(void*);
};
extern void __cdecl Ref(void*);
class CPathGraphAgent {
  public:
    void* vptr;
    char p1[0x58];
    char p2[0x34];
    void* mB;
    void* mBcopy;
    char p3[0x2c];
    void* mA;
    void* mAcopy;
};
extern void __fastcall Finish(CPathGraphAgent*);
void __fastcall FUN(CPathGraphAgent* self) {
    self->vptr = (void*)0x40d518;
    ((Sub*)gRoot->sub)->Init((char*)self + 0x5c);
    self->mAcopy = self->mA;
    if (self->mA)
        Ref(self->mA);
    self->mBcopy = self->mB;
    if (self->mB)
        Ref(self->mB);
    Finish(self);
}