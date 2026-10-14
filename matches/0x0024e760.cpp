struct Stm_24e760 {
    char pad[0x24];
    int depth;
};
extern bool Match(Stm_24e760*, const char*);
extern bool ReadTrack(Stm_24e760**, const char*, void*);
extern const char sOpen[];
extern const char sName[];
extern const char sClose[];
class SeqEvent {
  public:
    virtual void v0();
    virtual bool v1(Stm_24e760**);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventNestTrack : public SeqEvent {
    char pad[8];

  public:
    int vfunc_1(Stm_24e760**);
};
int SeqEventNestTrack::vfunc_1(Stm_24e760** p) {
    if (SeqEvent::v1(p)) {
        if (Match(*p, sOpen)) {
            (*p)->depth++;
            if (ReadTrack(p, sName, (char*)this + 8)) {
                (*p)->depth--;
                Stm_24e760* s = *p;
                if (Match(s, sClose))
                    return 1;
            }
        }
    }
    return 0;
}
