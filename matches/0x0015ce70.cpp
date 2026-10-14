extern "C" char DAT_00415aa0[];

struct Track {
  public:
    virtual void vfunc_3();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual ~Track();
    char pad[0x2c];
};

struct Elem_15ce70 {
    ~Elem_15ce70();
    char data[8];
};

class LocomotionSprintTrack : public Track {
  public:
    virtual void vfunc_0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot4();
    virtual void slot6();
    virtual void slot7();
    virtual void slot10();
    LocomotionSprintTrack* vfunc_5(unsigned char flag);
    Elem_15ce70 m_elems[5];
};

void operator delete(void* p);

LocomotionSprintTrack* LocomotionSprintTrack::vfunc_5(unsigned char flag) {
    *(int*)this = ((int)DAT_00415aa0);
    this->m_elems[4].~Elem_15ce70();
    this->m_elems[3].~Elem_15ce70();
    this->m_elems[2].~Elem_15ce70();
    this->m_elems[1].~Elem_15ce70();
    this->m_elems[0].~Elem_15ce70();
    this->Track::~Track();
    if (flag & 1) {
        operator delete(this);
    }
    return this;
}
