// Same code shape as 0x00080ba0 (propagated; names are from that function)
class Obj {
  public:
    void method(unsigned int, unsigned int);
};
extern Obj* gObject;
extern "C" void FUN_00080ba0(unsigned int param_1, unsigned int param_2) {
    gObject->method(param_1, param_2);
}