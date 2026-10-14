// Same code shape as 0x001c6c40 (propagated; names are from that function)
class Part_2e5280 {
  public:
    void Cleanup();
};
class Thing_2e5280 {
  public:
    int v;
    Part_2e5280 part;
    Thing_2e5280* Run(unsigned char flags);
};
void DeleteThing(Thing_2e5280*);
Thing_2e5280* Thing_2e5280::Run(unsigned char flags) {
    part.Cleanup();
    if (flags & 1)
        DeleteThing(this);
    return this;
}