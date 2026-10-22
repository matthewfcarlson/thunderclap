class Track_12eb30 {
  public:
    Track_12eb30();
    virtual void f();
    int x;
};
namespace hulkfight {
class DialogueTrack : public Track_12eb30 {
  public:
    DialogueTrack();
    virtual void f();
    int unknown, a, b, c, d, e, g;
    char flag;
};
} // namespace hulkfight
hulkfight::DialogueTrack::DialogueTrack() : Track_12eb30(), a(0), b(0), c(0), d(0), e(0), g(0), flag(0) {
    unknown = 1;
}