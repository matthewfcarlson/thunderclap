class Base {
  public:
    Base();
    virtual void f();
    int x;
};
namespace hulkfight {
class DialogueTrack : public Base {
  public:
    DialogueTrack();
    virtual void f();
    int unknown, a, b, c, d, e, g;
    char flag;
};
} // namespace hulkfight
hulkfight::DialogueTrack::DialogueTrack() : Base(), a(0), b(0), c(0), d(0), e(0), g(0), flag(0) {
    unknown = 1;
}