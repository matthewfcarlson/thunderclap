// Same code shape as 0x001ef6d0 (propagated; names are from that function)
class Singleton_1ef720 {
  public:
    void Run();
};
extern Singleton_1ef720** gSingleton_1ef720;
class CSoundCommand_PlayCuedNISEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
void CSoundCommand_PlayCuedNISEvent::vfunc_1(int, int) {
    (*gSingleton_1ef720)->Run();
}