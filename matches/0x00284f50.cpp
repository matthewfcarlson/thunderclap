// Same code shape as 0x000862a0 (propagated; names are from that function)
class Target {
  public:
    char pad[0x28];
    unsigned int value;
    unsigned int Get();
};
unsigned int Target::Get() {
    return value;
}