// Same code shape as 0x00083d60 (propagated; names are from that function)
class Target {
    char pad[0x24];
    int value;

  public:
    void Set(int v);
};
void Target::Set(int v) {
    value = v;
}