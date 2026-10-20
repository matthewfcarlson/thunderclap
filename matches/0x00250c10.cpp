struct Stm_250c10 {
    char pad[0x24];
    int depth;
};
extern bool Match(Stm_250c10*, const char*);
extern bool ReadTrack(Stm_250c10**, const char*, void*);
extern const char sOpen[];
extern const char sName_00429b00[];
extern const char sClose[];
class SeqEvent {
  public:
    virtual void v0();
    virtual bool v1(Stm_250c10**);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventExpression_250c10 : public SeqEvent {
    char pad[8];

  public:
    int vfunc_1(Stm_250c10**);
};
int SeqEventExpression_250c10::vfunc_1(Stm_250c10** p) {
    if (SeqEvent::v1(p)) {
        if (Match(*p, sOpen)) {
            (*p)->depth++;
            if (ReadTrack(p, sName_00429b00, (char*)this + 8)) {
                (*p)->depth--;
                Stm_250c10* s = *p;
                if (Match(s, sClose))
                    return 1;
            }
        }
    }
    return 0;
}
