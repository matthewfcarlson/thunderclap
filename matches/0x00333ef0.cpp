class Obj {
  public:
    void Fn();
};
void FUN_00333ef0() {
    if (*(volatile unsigned char*)0x555b9c) {
        Obj* p = *(Obj* volatile*)0x555ba4;
        if (p)
            p->Fn();
    }
}
