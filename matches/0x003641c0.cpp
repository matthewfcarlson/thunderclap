extern "C" char DAT_00423f20[];
class Stream {
  public:
    virtual void Fn();
};
Stream* gStream;
void Init() {
    gStream = (Stream*)((int)DAT_00423f20);
}