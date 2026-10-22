extern void* g_vt_6af70[];
extern void* g_vt2[];
struct Sub_6af70 {
    void Fin() throw();
};
class CTrack_6af70 {
  public:
    void* vptr;
    ~CTrack_6af70() throw();
};
class CAIHintTrack_6af70 : public CTrack_6af70 {
  public:
    char pad[0x18 - 4];
    Sub_6af70 sub;
    ~CAIHintTrack_6af70() throw();
};
CAIHintTrack_6af70::~CAIHintTrack_6af70() throw() {
    vptr = g_vt_6af70;
    sub.Fin();
    vptr = g_vt2;
}
