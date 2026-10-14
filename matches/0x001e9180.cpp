class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual ~IRefCount();
};
class CSoundSequence : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual CSoundSequence* f2(unsigned char);
    char pad[0x18];
    void* member;
};
extern int seq_vftable_1e9180, base_vftable;
extern void thunk(void*);
CSoundSequence* CSoundSequence::f2(unsigned char flag) {
    *(unsigned long*)this = (unsigned long)&seq_vftable_1e9180;
    if (member) {
        struct X {
            virtual void a();
            virtual void b();
        };
        ((X*)member)->b();
        member = 0;
    }
    *(unsigned long*)this = (unsigned long)&base_vftable;
    if (flag & 1)
        thunk(this);
    return this;
}