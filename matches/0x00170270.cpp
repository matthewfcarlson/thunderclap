extern char VT_004179e8[];
class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class LocomotionStateTrack : public Base {
  public:
    LocomotionStateTrack();
    virtual void f();
    int m8;
    int mc;
    int m10;
};
LocomotionStateTrack::LocomotionStateTrack() {
    mc = 0;
    m10 = 0;
    *(void**)this = (void*)((int)VT_004179e8);
    m8 = 1;
}
