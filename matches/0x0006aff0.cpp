class CTrack_6aff0 {
  public:
    CTrack_6aff0();
    virtual void f();
    char pad[8];
};
class CClearCollisionStun : public CTrack_6aff0 {
  public:
    CClearCollisionStun();
    virtual void f();
    int a;
    float b;
};
CClearCollisionStun::CClearCollisionStun() {
    a = 0;
    b = -1.0f;
    *(int*)((char*)this + 8) = 1;
}