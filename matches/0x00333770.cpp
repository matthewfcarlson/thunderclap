// Same code shape as 0x0030a260 (propagated; names are from that function)
class C_333770 {
    char pad[0x18];
    int value;

  public:
    void set(int);
};
struct ThisCall_003335e0 {
    void called();
};
void C_333770::set(int x) {
    value = x;
    ((ThisCall_003335e0*)(this))->called();
}