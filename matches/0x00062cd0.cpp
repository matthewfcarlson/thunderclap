class Base {
  public:
    Base();
    virtual void A();
};

class CPropActorSetStateTrack : public Base {
  public:
    CPropActorSetStateTrack();
    virtual void A();
    char pad[4];
    int m8;
    int mC;
    int m10;
};

CPropActorSetStateTrack::CPropActorSetStateTrack() : Base() {
    mC = 0;
    m10 = 0;
    m8 = 1;
}
