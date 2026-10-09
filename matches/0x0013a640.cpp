class Base {
  public:
    Base();
    virtual void F();
};
class GrappleAnimationTrack : public Base {
  public:
    GrappleAnimationTrack();
};
GrappleAnimationTrack::GrappleAnimationTrack() : Base() {}
