class Thing_2665c0 {
  public:
    void First();
    void Second();
    Thing_2665c0* Target(unsigned char);
};
void __cdecl Third(Thing_2665c0*);
Thing_2665c0* Thing_2665c0::Target(unsigned char flags) {
    First();
    Second();
    if (flags & 1)
        Third(this);
    return this;
}