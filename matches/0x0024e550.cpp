struct Inner_24e550 {
    void Init(const char*, int);
};
class Base_24e550 {
  public:
    Base_24e550();
    virtual void g();
};
class Track : public Base_24e550 {
  public:
    Track();
    virtual void g();
    char pad[4];
    Inner_24e550 in;
};
Track::Track() {
    in.Init("MySeqTrack", 2);
}
