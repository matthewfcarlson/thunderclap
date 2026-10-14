class Base {
  public:
    Base();
    virtual void v0();
    int m4;
};

class CSoundTrack : public Base {
  public:
    CSoundTrack();
    virtual void v0();
    virtual void v1();
    int m8;
    int mC;
    char m10;
    char pad[0x3f];
    char m50;
};

CSoundTrack::CSoundTrack() {
    mC = 0;
    m10 = 0;
    m50 = 0;
    m8 = 1;
}
