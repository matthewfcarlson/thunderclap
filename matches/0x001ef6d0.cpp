class Singleton {
  public:
    void Run();
};
extern Singleton** gSingleton;
class CSoundCommand_PlayCuedNISEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
void CSoundCommand_PlayCuedNISEvent::vfunc_1(int, int) {
    (*gSingleton)->Run();
}