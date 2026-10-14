class Singleton_1ef6d0 {
  public:
    void Run();
};
extern Singleton_1ef6d0** gSingleton_1ef6d0;
class CSoundCommand_PlayCuedNISEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
void CSoundCommand_PlayCuedNISEvent::vfunc_1(int, int) {
    (*gSingleton_1ef6d0)->Run();
}