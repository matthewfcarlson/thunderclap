struct Entry {
    int a, b, c, d;
    Entry() : a(0), b(0), c(0), d(-1) {}
};
class Obj {
    char pad[8];
    Entry x, y;

  public:
    void reset();
};
void Obj::reset() {
    x = Entry();
    y = Entry();
}