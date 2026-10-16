class Mixer {
  public:
    void Install(void*, int);
};
class Manager {
  public:
    char pad[4];
    Mixer* mixer;
};
extern Manager* gManager;
class CSoundCommand {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
class CSoundCommand_InstallMixer : public CSoundCommand {
  public:
    char pad[0x10 - 4];
    char data[0x20];
    float value;
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
void CSoundCommand_InstallMixer::vfunc_1(int, int) {
    gManager->mixer->Install(data, (int)value);
}