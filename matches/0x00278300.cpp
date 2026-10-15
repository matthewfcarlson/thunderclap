extern "C" void __stdcall FUN_00356611(int);
class Obj {
  public:
    char pad[0x2f4];
    struct Slot {
        int handle;
        char pad[0x204];
    } slots[1];
    int Do(int* idx);
};
int Obj::Do(int* idx) {
    int h = slots[*idx].handle;
    if (h != -1) {
        FUN_00356611(h);
        slots[*idx].handle = -1;
    }
    return 1;
}