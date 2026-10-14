class Base_170080 {
  public:
    Base_170080();
    virtual void a();
    virtual void b();
    int x, y;
};
class Sub_170080 {
  public:
    Sub_170080();
    int a, b;
};
class SyncToLocatorTrack : public Base_170080 {
  public:
    SyncToLocatorTrack();
    virtual void a();
    virtual void b();
    int m0;
    float f0, f1, f2;
    char pad[4];
    Sub_170080 sub;
    int fields[10];
};
SyncToLocatorTrack::SyncToLocatorTrack() : m0(0), f0(1.0f), f1(-1.0f), f2(-1.0f) {
    fields[0] = 0;
    fields[1] = 0;
    fields[2] = 0;
    fields[3] = 0;
    fields[4] = 0;
    fields[5] = 0;
    fields[6] = 0;
    fields[8] = 0;
    fields[9] = 0;
    fields[7] = -5;
    y = 1;
}