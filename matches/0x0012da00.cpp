extern void* g_vftable_12da00[];
class Str_12da00 {
  public:
    void Init();
};
class Track_12da00 {
  public:
    void* vptr;
    char pad[12];
    Str_12da00 s;
    void Fin();
};
class PostEvent_StringTrack_12da00 : public Track_12da00 {
  public:
    ~PostEvent_StringTrack_12da00();
};
PostEvent_StringTrack_12da00::~PostEvent_StringTrack_12da00() {
    vptr = g_vftable_12da00;
    s.Init();
    Fin();
}
