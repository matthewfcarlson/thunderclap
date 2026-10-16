class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class CClearCollisionStun : public Base {
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