struct Inner { void Init(const char*, int); };
class Base {
public:
    Base();
    virtual void g();
};
class Track : public Base {
public:
    Track();
    virtual void g();
    char pad[4];
    Inner in;
};
Track::Track() {
    in.Init("MySeqTrack", 2);
}
