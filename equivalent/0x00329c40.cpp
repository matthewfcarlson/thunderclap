// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00329c40 @ 0x00329c40
#include "decls/data/platform/xbox/pure3d.h"

struct Device_329c40 { char pad[0x28]; int texture[32]; void FUN_00329c40(int stage, int value); };
struct TextureState_329c40 { int first; int second; int third; char pad[0x74]; };
extern unsigned int DAT_0039db08;
extern TextureState_329c40 DAT_0039db10[];
void Device_329c40::FUN_00329c40(int stage, int value) {
    if (texture[stage] != value) {
        texture[stage] = value;
        int resolved = DAT_004d4efc[value];
        DAT_0039db10[stage].first = resolved;
        DAT_0039db10[stage].second = resolved;
        DAT_0039db08 |= 1u << (stage & 31);
        DAT_0039db10[stage].third = resolved;
    }
}