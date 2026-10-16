struct Count {
    int n;
    Count() : n(0) {}
};
struct Entry {
    unsigned int x;
    int a, b, c;
    Entry() : x(0xbf800000), a(0), b(0), c(0) {}
};
class Obj {
  public:
    Count count;
    Entry entries[80];
    Obj();
};
Obj::Obj() {}