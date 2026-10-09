class IRefCount {
  public:
    virtual void F();
};
IRefCount* gRefCount;
void FUN_00364780() {
    gRefCount = (IRefCount*)0x003f6098;
}