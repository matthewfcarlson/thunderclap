class Base {
  public:
    Base();
    virtual void A();
    char pad[4];
    int m8;
};

class TargetClearTrack : public Base {
  public:
    TargetClearTrack();
    int m_c;
    char m_10;
};

TargetClearTrack::TargetClearTrack() {
    *(volatile int*)((char*)this + 0xc) = 0;
    *(volatile char*)((char*)this + 0x10) = 0;
    *(volatile int*)((char*)this + 8) = 1;
}
