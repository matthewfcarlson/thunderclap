extern int gData_3646d0;
class Obj_3646d0 {
  public:
    void Run();
};
void __stdcall Wrapper() {
    Obj_3646d0* p = (Obj_3646d0*)&gData_3646d0;
    p->Run();
}
