namespace hulkfight {
namespace motion {
class BaseTrack {
  public:
    BaseTrack();
    virtual void f();
    char pad[8];
};
class PropActorToPropTrack : public BaseTrack {
  public:
    PropActorToPropTrack();
    virtual void f();
    int value;
    int state;
    char flag1;
    char flag2;
};
PropActorToPropTrack::PropActorToPropTrack() : value(0), state(-1), flag1(0), flag2(0) {}
} // namespace motion
} // namespace hulkfight