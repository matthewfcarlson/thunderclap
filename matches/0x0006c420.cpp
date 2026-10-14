class Base {
  public:
    Base(int a);
    virtual ~Base();
};

class CMoveTrack : public Base {
  public:
    CMoveTrack(int a, int b);
    virtual ~CMoveTrack();
    char pad[12];
    int mValue;
};

CMoveTrack::CMoveTrack(int a, int b) : Base(a) {
    mValue = b;
}
