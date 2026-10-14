extern "C" char DAT_0042aa7c[];
extern void* gSource;
extern int gCount_260950;
void InitSeq(void*, void*);
void DestroySeq(void*);
class Sub_260950 {
  public:
    void Clean();
};
class Type {
  public:
    virtual void dtor(unsigned int);
    virtual void vfunc1();
    virtual Type* vfunc2(unsigned int);
    virtual void vfunc3();
};
class SeqEventType : public Type {
  public:
    char pad[0x54];
    Sub_260950 sub;
    void Finish();
    SeqEventType* vfunc2(unsigned int flags);
};
SeqEventType* SeqEventType::vfunc2(unsigned int flags) {
    void* p = gSource;
    *(void**)this = (void*)((int)DAT_0042aa7c);
    InitSeq(p, this);
    --gCount_260950;
    sub.Clean();
    Finish();
    if (flags & 1)
        DestroySeq(this);
    return this;
}
