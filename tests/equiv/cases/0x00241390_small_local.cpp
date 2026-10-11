// FUN_00241390 @ 0x00241390
struct SoundState { unsigned int values[44]; };
struct Config { unsigned int first; unsigned int second; };
extern SoundState *DAT_004e5ce0;
extern unsigned int DAT_004e5ce8[4];
extern volatile unsigned int DAT_004e5cb0, DAT_004e5cb4, DAT_004e5cb8, DAT_004e5cbc, DAT_004e5cc0, DAT_004e5cc4, DAT_004e5cc8, DAT_004e5ccc, DAT_004e5cd0, DAT_004e5cd4, DAT_004e5cd8, DAT_004e5cdc;
int __cdecl FUN_0026fd50(unsigned int, unsigned int);
struct Temporary { char data[32]; void *FUN_002584d0(unsigned int *, unsigned int *, unsigned int *, int); void FUN_002580e0(); };
SoundState * __cdecl FUN_00247530(void *);
namespace DSOUND { int __stdcall DirectSoundCreate(void *, void *, void *); }
void __cdecl FUN_002411b0(); void __cdecl FUN_0024c9c0(); void __cdecl FUN_0024c7f0(int);
unsigned int __stdcall FUN_0020c731(unsigned int, unsigned int, unsigned int);
unsigned int __cdecl FUN_00267f80(); void __cdecl FUN_00257dd0(void *);
struct Message { unsigned int FUN_0023fe50(const char *); };
bool __cdecl FUN_00241390(Config *config, Message *showMessage)
{
    unsigned int *initial = (unsigned int *)(FUN_0026fd50(config->second, 0x1000) + 0xb0);
    unsigned int first[2] = { DAT_004e5ce8[0], DAT_004e5ce8[1] };
    unsigned int second[2] = { DAT_004e5ce8[2], DAT_004e5ce8[3] };
    Temporary temp;
    DAT_004e5ce0 = FUN_00247530(temp.FUN_002584d0(second, first, initial, 4));
    temp.FUN_002580e0();
    SoundState *state = DAT_004e5ce0;
    for (int i = 0; i < 44; ++i) state->values[i] = 0;
    DAT_004e5ce0->values[43] = (unsigned int)initial;
    DSOUND::DirectSoundCreate(0, &DAT_004e5ce0->values[13], 0);
    FUN_002411b0(); FUN_0024c9c0(); FUN_0024c7f0(1);
    DAT_004e5ce0->values[11] = FUN_0026fd50(config->first, 0x1000);
    DAT_004e5ce0->values[12] = 0;
    DAT_004e5ce0->values[10] = FUN_0020c731(0, DAT_004e5ce0->values[11], 0);
    DAT_004e5ce0->values[1] = FUN_0026fd50(config->second, 0x1000);
    state = DAT_004e5ce0;
    state->values[3] = state->values[1] ? (unsigned int)&state->values[44] : 0;
    DAT_004e5ce0->values[4] = 0;
    DAT_004e5ce0->values[9] = FUN_00267f80();
    FUN_00257dd0(&DAT_004e5ce0->values[7]); FUN_00257dd0(&DAT_004e5ce0->values[5]);
    DAT_004e5ce0->values[38] = 0x3f800000;
    DAT_004e5ce0->values[39] = 0x3f800000;
    DAT_004e5ce0->values[40] = 0;
    DAT_004e5ce0->values[41] = 0;
    ((unsigned char *)DAT_004e5ce0)[0xa8] = 0;
    DAT_004e5cb0 = 0xffffd8f0; DAT_004e5cb4 = 0xffffd8f0;
    DAT_004e5cb8 = 0; DAT_004e5cbc = 0x3dcccccd;
    DAT_004e5cc0 = 0x3dcccccd; DAT_004e5cc4 = 0xffffd8f0;
    DAT_004e5cc8 = 0; DAT_004e5ccc = 0xffffd8f0;
    DAT_004e5cd0 = 0; DAT_004e5cd4 = 0;
    DAT_004e5cd8 = 0; DAT_004e5cdc = 0x41a00000;
    state = DAT_004e5ce0;
    state->values[26] = DAT_004e5cb0; state->values[27] = DAT_004e5cb4;
    state->values[28] = DAT_004e5cb8; state->values[29] = DAT_004e5cbc;
    state->values[30] = DAT_004e5cc0; state->values[31] = DAT_004e5cc4;
    state->values[32] = DAT_004e5cc8; state->values[33] = DAT_004e5ccc;
    state->values[34] = DAT_004e5cd0; state->values[35] = DAT_004e5cd4;
    state->values[36] = DAT_004e5cd8; state->values[37] = DAT_004e5cdc;
    if (showMessage)
        showMessage->FUN_0023fe50("Ok");
    return true;
}
