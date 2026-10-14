class Base_62cd0 {
  public:
    Base_62cd0();
    virtual void A();
};

class CPropActorSetStateTrack : public Base_62cd0 {
  public:
    CPropActorSetStateTrack();
    virtual void A();
    char pad[4];
    int m8;
    int mC;
    int m10;
};

CPropActorSetStateTrack::CPropActorSetStateTrack() : Base_62cd0() {
    mC = 0;
    m10 = 0;
    m8 = 1;
}
