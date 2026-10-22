class Track_181420 {
  public:
    virtual void f();
    int x;
    Track_181420();
};
namespace hulkfight {
namespace motion {
class PropAddToCollisionTrack : public Track_181420 {
  public:
    int a;
    int b;
    int c;
    char d;
    PropAddToCollisionTrack();
    virtual void f();
};
PropAddToCollisionTrack::PropAddToCollisionTrack() : Track_181420() {
    b = 0;
    c = 0;
    d = 1;
    a = 1;
}
} // namespace motion
} // namespace hulkfight