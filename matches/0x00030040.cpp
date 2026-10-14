class Actor_30040 {
  public:
    void fn(unsigned char);
};
class Closure1 {
  public:
    char pad[0x1c];
    void (Actor_30040::*mFn)(unsigned char);
    Actor_30040* mObject;
    void vfunc_2(void*, unsigned char*, void*);
};
void Closure1::vfunc_2(void*, unsigned char* arg, void*) {
    (mObject->*mFn)(*arg);
}