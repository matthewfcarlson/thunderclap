extern "C" char DAT_003f6098[];
class IRefCount {
  public:
    virtual void F();
};
IRefCount* gRefCount;
void FUN_00364780() {
    gRefCount = (IRefCount*)((int)DAT_003f6098);
}