extern "C" char DAT_00555b9c[];
extern "C" char DAT_00555ba4[];
class Obj_333ef0 {
  public:
    void Fn();
};
void FUN_00333ef0() {
    if (*(volatile unsigned char*)((int)DAT_00555b9c)) {
        Obj_333ef0* p = *(Obj_333ef0* volatile*)((int)DAT_00555ba4);
        if (p)
            p->Fn();
    }
}
