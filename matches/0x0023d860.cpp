// Same code shape as 0x0011c270 (propagated; names are from that function)
void __cdecl Cleanup(int);
class CommentCondition_23d860 {
  public:
    int a, b;
    virtual ~CommentCondition_23d860();
    int d;
    virtual void hulk_slot_F(); void F();
};
CommentCondition_23d860::~CommentCondition_23d860() {
    Cleanup(d);
    F();
}