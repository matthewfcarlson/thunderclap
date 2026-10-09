class Stream {
  public:
    virtual void Fn();
};
Stream* gStream;
void Init() {
    gStream = (Stream*)0x423f20;
}