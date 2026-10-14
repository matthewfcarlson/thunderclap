// Same code shape as 0x00030040 (propagated; names are from that function)
class Actor_7e3e0 {
  public:
    void fn(unsigned char);
};
class Closure1 {
  public:
    char pad[0x1c];
    void (Actor_7e3e0::*mFn)(unsigned char);
    Actor_7e3e0* mObject;
    void vfunc_2(void*, unsigned char*, void*);
};
void Closure1::vfunc_2(void*, unsigned char* arg, void*) {
    (mObject->*mFn)(*arg);
}