class Inner_246a60 {
  public:
    unsigned int Size();
    void Change(unsigned int);
};
class Outer_246a60 {
  public:
    char pad[0x1c];
    Inner_246a60* inner;
};
bool target(Outer_246a60* self, unsigned int value) {
    unsigned int n = self->inner->Size();
    if (value >= n) {
        self->inner->Change(value - n);
        return true;
    }
    return false;
}