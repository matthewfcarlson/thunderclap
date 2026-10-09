// Same code shape as 0x000fc4b0 (propagated; names are from that function)
class CAgent {
  public:
    char pad[8];
    int field;
    void vfunc_6(int);
};
void CAgent::vfunc_6(int value) {
    field = value;
}