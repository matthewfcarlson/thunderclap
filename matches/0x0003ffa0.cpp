class Ref_3ffa0 {
  public:
    virtual void Use();
    virtual void Release();
};
class Thing_3ffa0 {
  public:
    char pad[0x328];
    Ref_3ffa0* member;
    char pad2[0x1b48 - 0x32c];
    unsigned char state;
    void Set(Ref_3ffa0*, unsigned char);
};
struct ThisCall_000393c0 {
    void Missing();
};
void Thing_3ffa0::Set(Ref_3ffa0* value, unsigned char flag) {
    if (value == 0) {
        ((ThisCall_000393c0*)(this))->Missing();
        return;
    }
    state = flag;
    value->Use();
    if (member)
        member->Release();
    member = value;
}