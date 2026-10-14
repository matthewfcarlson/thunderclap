// Same code shape as 0x00030040 (propagated; names are from that function)
class Actor_1ce300 {
  public:
    void fn(unsigned char);
};
class Closure1 {
  public:
    char pad[0x1c];
    void (Actor_1ce300::*mFn)(unsigned char);
    Actor_1ce300* mObject;
    void vfunc_2(void*, unsigned char*, void*);
};
void Closure1::vfunc_2(void*, unsigned char* arg, void*) {
    (mObject->*mFn)(*arg);
}