class Base {
  public:
    virtual void Fn();
    Base();
    char pad[0x0c];
};

class Member {
  public:
    Member();
    char pad[8];
};

class CKeyPoseTrack : public Base {
  public:
    virtual ~CKeyPoseTrack() throw();
    Member m10;
    float arr[16];
    char m58;
    char pad1[7];
    Member m60;
    int m68;
    float m6c;
    float m70;
    CKeyPoseTrack();
};

CKeyPoseTrack::CKeyPoseTrack() : Base(), m10(), m58(1), m60() {
    {
        int* q = &m68;
        *q = 0;
    }
    m6c = 0.1f;
    m70 = 0.1f;
    arr[0] = -1.0f;
    arr[8] = -1.0f;
    arr[1] = -1.0f;
    arr[9] = -1.0f;
    arr[2] = -1.0f;
    arr[10] = -1.0f;
    arr[3] = -1.0f;
    arr[11] = -1.0f;
    arr[4] = -1.0f;
    arr[12] = -1.0f;
    arr[5] = -1.0f;
    arr[13] = -1.0f;
    arr[6] = -1.0f;
    arr[14] = -1.0f;
    arr[7] = -1.0f;
    arr[15] = -1.0f;
}
