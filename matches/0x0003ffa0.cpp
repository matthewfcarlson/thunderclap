class Ref {
  public:
    virtual void Use();
    virtual void Release();
};
class Thing {
  public:
    char pad[0x328];
    Ref* member;
    char pad2[0x1b48 - 0x32c];
    unsigned char state;
    void Set(Ref*, unsigned char);
};
void Missing();
void Thing::Set(Ref* value, unsigned char flag) {
    if (value == 0) {
        Missing();
        return;
    }
    state = flag;
    value->Use();
    if (member)
        member->Release();
    member = value;
}