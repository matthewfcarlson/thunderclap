// Same code shape as 0x00080ba0 (propagated; names are from that function)
class Obj_2f2750 {
  public:
    int method(unsigned int, unsigned int);
};
extern Obj_2f2750* gObject_2f2750;
extern "C" int FUN_002f2750(unsigned int param_1, unsigned int param_2) {
    return gObject_2f2750->method(param_1, param_2);
}