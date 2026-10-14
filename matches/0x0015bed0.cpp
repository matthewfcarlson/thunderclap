struct Sub_15bed0 {
    int a;
    int b;
    void Clear();
};
class LocomotionSteerTrack {
  public:
    virtual ~LocomotionSteerTrack();
    void BaseDtor();
    char pad0[0x24];
    Sub_15bed0 m28;
    Sub_15bed0 m30;
    Sub_15bed0 m38;
    Sub_15bed0 m40;
    char pad1[0x8];
    Sub_15bed0 m50;
};
LocomotionSteerTrack::~LocomotionSteerTrack() {
    m50.Clear();
    m40.Clear();
    m38.Clear();
    m30.Clear();
    m28.Clear();
    BaseDtor();
}
