class Obj {
  public:
    void init27();
    void init23();
};
class TrackPart {
  public:
    void init36();
};
class FireBeamTrack {
  public:
    int vptr;
    char pad[0xbc];
    FireBeamTrack* vfunc_5(unsigned char);
};
void destroy(FireBeamTrack*);
extern int fireVtable;
FireBeamTrack* FireBeamTrack::vfunc_5(unsigned char flag) {
    vptr = (int)&fireVtable;
    ((Obj*)((char*)this + 0xc0))->init27();
    ((Obj*)((char*)this + 0xb0))->init23();
    ((Obj*)((char*)this + 0x84))->init23();
    ((Obj*)((char*)this + 0x70))->init27();
    ((Obj*)((char*)this + 0x30))->init27();
    ((Obj*)((char*)this + 0x18))->init27();
    ((TrackPart*)this)->init36();
    if (flag & 1)
        destroy(this);
    return this;
}
