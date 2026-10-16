class Base {
  public:
    Base();
    virtual void f();
};
class IntentionClearTrack : public Base {
  public:
    IntentionClearTrack();
    char pad[4];
    volatile int a;
    int b;
    float c;
};
IntentionClearTrack::IntentionClearTrack() : Base() {
    b = 0;
    c = -1.0f;
    a = 1;
}