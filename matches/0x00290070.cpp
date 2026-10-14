extern void __cdecl ReleaseThing(int);
extern void __cdecl ReleaseSelf(void*);
class Obj_290070 {
  public:
    char pad[8];
    int ptr;
    void Reset();
    Obj_290070* Run(unsigned char flag);
};
Obj_290070* Obj_290070::Run(unsigned char flag) {
    if (ptr != 0) {
        ReleaseThing(ptr);
        ptr = 0;
    }
    Reset();
    if (flag & 1) {
        ReleaseSelf((void*)this);
    }
    return this;
}
