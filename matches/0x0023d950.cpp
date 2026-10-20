// Same code shape as 0x0011c270 (propagated; names are from that function)
void __cdecl Cleanup(int);
class CommentTrack_23d950 {
  public:
    int a, b;
    virtual ~CommentTrack_23d950();
    int d;
    virtual void hulk_slot_F(); void F();
};
CommentTrack_23d950::~CommentTrack_23d950() {
    Cleanup(d);
    F();
}