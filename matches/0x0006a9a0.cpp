class CTrack_6a9a0 {
  public:
    virtual void BPlaceholder();
    CTrack_6a9a0();
};

class CInvulnerableTrack : public CTrack_6a9a0 {
  public:
    virtual void Placeholder();
    int m4;
    int m8;
    int mC;
    float m10;
    int m14;
    CInvulnerableTrack();
};
void CInvulnerableTrack::Placeholder() {}

CInvulnerableTrack::CInvulnerableTrack() {
    mC = 0;
    m14 = 0;
    m10 = -1.0f;
    m8 = 1;
}
