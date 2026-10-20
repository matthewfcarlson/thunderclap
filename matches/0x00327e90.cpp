void* FUN_0008d690(unsigned int);
class MyObj {
  public:
    MyObj* Init(void* arg);
};
MyObj* FUN_00327e90(void* arg) {
    MyObj* r = (MyObj*)FUN_0008d690(0x94);
    if (r)
        return r->Init(arg);
    return 0;
}
