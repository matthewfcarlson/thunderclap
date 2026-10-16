class Track {
  public:
    Track();
    virtual void Fn();
    int pad;
};
class PropAddToMissileCountTrack : public Track {
  public:
    PropAddToMissileCountTrack();
    virtual void Fn();
    int count;
    int a;
    int b;
    int c;
};
PropAddToMissileCountTrack::PropAddToMissileCountTrack() {
    a = 0;
    b = 0;
    c = 0;
    count = 1;
}