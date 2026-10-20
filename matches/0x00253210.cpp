struct Stm_253210 {
    char pad[0x24];
    int depth;
};
extern bool Match(Stm_253210*, const char*);
extern bool ReadTrack_002530b0(Stm_253210**, const char*, void*);
extern const char sOpen[];
extern const char sName_0042a108[];
extern const char sClose[];
class SeqEvent {
  public:
    virtual void v0();
    virtual bool v1(Stm_253210**);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventVarPosDist_253210 : public SeqEvent {
    char pad[8];

  public:
    int vfunc_1(Stm_253210**);
};
int SeqEventVarPosDist_253210::vfunc_1(Stm_253210** p) {
    if (SeqEvent::v1(p)) {
        if (Match(*p, sOpen)) {
            (*p)->depth++;
            if (ReadTrack_002530b0(p, sName_0042a108, (char*)this + 8)) {
                (*p)->depth--;
                Stm_253210* s = *p;
                if (Match(s, sClose))
                    return 1;
            }
        }
    }
    return 0;
}
