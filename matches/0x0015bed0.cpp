struct Sub { int a; int b; void Clear(); };
class LocomotionSteerTrack {
public:
    virtual ~LocomotionSteerTrack();
    void BaseDtor();
    char pad0[0x24];
    Sub m28;
    Sub m30;
    Sub m38;
    Sub m40;
    char pad1[0x8];
    Sub m50;
};
LocomotionSteerTrack::~LocomotionSteerTrack() {
    m50.Clear();
    m40.Clear();
    m38.Clear();
    m30.Clear();
    m28.Clear();
    BaseDtor();
}
