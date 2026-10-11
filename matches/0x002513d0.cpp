extern "C" char DAT_00429dcc[];
class Base {
  public:
    void Init();
};
class Track {
  public:
    void Setup(const char*, int);
};
class SeqEventPlayTrack {
  public:
    int vptr;
    char pad4[4];
    int a;
    int b;
    unsigned char c;
    char pad11[3];
    Track track;
};
SeqEventPlayTrack* __fastcall Target(SeqEventPlayTrack* self) {
    ((Base*)self)->Init();
    self->vptr = ((int)DAT_00429dcc);
    self->a = 0;
    self->b = 0;
    self->c = 0;
    self->track.Setup("MySeqTrack", 2);
    return self;
}