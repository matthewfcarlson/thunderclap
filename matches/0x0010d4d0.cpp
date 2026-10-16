class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class TokenTrack : public Base {
  public:
    TokenTrack();
    virtual void f();
    int a;
    int b;
    float c;
    char d;
};
TokenTrack::TokenTrack() : b(0), d(0) {
    c = -1.0f;
    a = 1;
}