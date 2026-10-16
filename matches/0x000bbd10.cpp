class Inner {
  public:
    void Run(int);
};
class Outer {
  public:
    char pad[0x3c];
    Inner* inner;
    inline void Do(int n) {
        if (inner)
            inner->Run(n);
    }
};
class Host {
  public:
    char pad[4];
    Outer* outer;
    void Do(int);
};
void Host::Do(int n) {
    outer->Do(n);
}