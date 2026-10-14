class Inner_2729c0 {
  public:
    virtual void First();
    virtual void Second();
};
class Target_2729c0 {
  public:
    char pad[0x0c];
    Inner_2729c0 inner;
    char pad2[0x30];
    int value40;
    int value44;
    void run(int);
};
void Target_2729c0::run(int x) {
    inner.First();
    value44 = x;
    value40 = 0;
    inner.Second();
}