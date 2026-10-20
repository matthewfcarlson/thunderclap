extern "C" char DAT_003f6098[];
class IRefCount {
  public:
    virtual void F();
};
extern "C" IRefCount* DAT_004cdb4c;
void FUN_00364780() {
    DAT_004cdb4c = (IRefCount*)((int)DAT_003f6098);
}