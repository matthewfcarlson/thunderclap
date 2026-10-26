#include "decls/data/game/unknown.h"
// data: gManager = DAT_004e370c

class Mixer {
  public:
    void Install(void*, int);
};
class Manager {
  public:
    char pad[4];
    Mixer* mixer;
};
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
    (*(Manager**)&DAT_004e370c)->mixer->Install(data, (int)(__int64)value);
}