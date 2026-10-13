// cl-flags: /O2
class Obj {
  public:
    char pad[0x4c];
    int* FUN_00012ee0();
};
int* Obj::FUN_00012ee0() {
    return (int*)((char*)this + 0x4c);
}