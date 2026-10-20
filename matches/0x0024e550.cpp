struct Inner_24e550 {
    void Init(const char*, int);
};
class Base_24e550 {
  public:
    Base_24e550();
    virtual void g();
};
class SeqEventNestTrack_24e550 : public Base_24e550 {
  public:
    SeqEventNestTrack_24e550();
    virtual void g();
    char pad[4];
    Inner_24e550 in;
};
SeqEventNestTrack_24e550::SeqEventNestTrack_24e550() {
    in.Init("MySeqTrack", 2);
}
