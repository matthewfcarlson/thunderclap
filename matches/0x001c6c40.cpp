class Part_1c6c40 {
  public:
    void Cleanup();
};
class Thing_1c6c40 {
  public:
    int v;
    Part_1c6c40 part;
    Thing_1c6c40* Run(unsigned char flags);
};
void DeleteThing(Thing_1c6c40*);
Thing_1c6c40* Thing_1c6c40::Run(unsigned char flags) {
    part.Cleanup();
    if (flags & 1)
        DeleteThing(this);
    return this;
}