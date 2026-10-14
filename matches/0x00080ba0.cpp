class Obj_80ba0 {
  public:
    void method(unsigned int, unsigned int);
};
extern Obj_80ba0* gObject_80ba0;
extern "C" void FUN_00080ba0(unsigned int param_1, unsigned int param_2) {
    gObject_80ba0->method(param_1, param_2);
}