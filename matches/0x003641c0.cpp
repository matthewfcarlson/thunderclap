extern "C" char DAT_00423f20[];
class Stream {
  public:
    virtual void Fn();
};
extern "C" Stream* DAT_004cc0cc;
void Init() {
    DAT_004cc0cc = (Stream*)((int)DAT_00423f20);
}