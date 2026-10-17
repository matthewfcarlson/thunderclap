// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/9)
// FUN_00035e70 @ 0x00035e70
// equiv-conv: FUN_00035e70 eax stack
struct Status { char padding[12]; int mode; };
int __cdecl FUN_00044560(Status *);
extern float DAT_003f5c48;
extern float DAT_003f5c44;
extern float DAT_003f3f08;

unsigned int FUN_00035e70(Status *status, float value)
{
    if (status->mode != 1)
        return ((unsigned int)status & ~255u) | 1u;
    int category = FUN_00044560(status);
    float limit = 0.0f;
    switch (category) {
    case 0: limit = DAT_003f5c48; break;
    case 1: case 4: case 5: limit = DAT_003f5c44; break;
    case 2: case 3: limit = DAT_003f3f08; break;
    }
    return value > limit ? 1 : 0;
}
