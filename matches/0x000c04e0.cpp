class Inner {
  public:
    void action();
};
class Outer {
  public:
    char pad[4];
    Inner* inner;
    int run(void* arg, int unused);
};
int Outer::run(void* arg, int unused) {
    if (!inner)
        return -1;
    if (arg)
        return -1;
    inner->action();
    return 0;
}