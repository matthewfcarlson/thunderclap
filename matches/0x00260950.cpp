extern void* gSource;
extern int gCount;
void InitSeq(void*, void*);
void DestroySeq(void*);
class Sub {
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
    Sub sub;
    void Finish();
    SeqEventType* vfunc2(unsigned int flags);
};
SeqEventType* SeqEventType::vfunc2(unsigned int flags) {
    void* p = gSource;
    *(void**)this = (void*)0x42aa7c;
    InitSeq(p, this);
    --gCount;
    sub.Clean();
    Finish();
    if (flags & 1)
        DestroySeq(this);
    return this;
}
