extern void* g_a_6acf0[];
extern void* g_b_6acf0[];
struct Sub_6acf0 {
    void Fin();
};
class CTrack_6acf0 {
  public:
    void* vptr;
    void Fin();
};
class CHeadTrackerTrack_6acf0 : public CTrack_6acf0 {
  public:
    char pad[0x14];
    Sub_6acf0 sub;
    void f();
};
void CHeadTrackerTrack_6acf0::f() {
    vptr = g_a_6acf0;
    sub.Fin();
    vptr = g_b_6acf0;
    Fin();
}
