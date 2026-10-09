class Inner {
  public:
    unsigned int Size();
    void Change(unsigned int);
};
class Outer {
  public:
    char pad[0x1c];
    Inner* inner;
};
bool target(Outer* self, unsigned int value) {
    unsigned int n = self->inner->Size();
    if (value >= n) {
        self->inner->Change(value - n);
        return true;
    }
    return false;
}