// The stand-in game world of tests/native_host/replay_native_test.py: game side (the MS-ABI front end, as the tree's
// TUs). What matches/0x00086450.cpp (GameClock::Update) calls and reads, the data the replay checkpoint hashes, and a
// game loop that calls Update once per frame from this object (so the link's entry hook applies to the call).
typedef unsigned __int64 U64_86450;

// GameClock::Update's view of the debug menu and of the clock (the source's own declarations)
struct Debug_86450 { void FUN_0023f720(int*,const char*); bool FUN_0023f760(const char*,int,int); bool FUN_0023f770(const char*,int); int FUN_0023f790(const char*,int,int,int,int); void FUN_0023f740(); };
struct Timer { U64_86450 limit,last,total,scaledTotal,elapsed,step,scaledStep,rate; char pad[8]; unsigned char paused; void FUN_00086450(); };

void Debug_86450::FUN_0023f720(int*, const char*) {}
bool Debug_86450::FUN_0023f760(const char*, int, int) { return false; }    // "Paused": no
bool Debug_86450::FUN_0023f770(const char*, int) { return false; }
int Debug_86450::FUN_0023f790(const char*, int, int, int, int) { return 16; }  // "Debug time dilation": 16/16
void Debug_86450::FUN_0023f740() {}

// The view object 0x001c34c0 builds (seven ints, 0x40 bytes, floats): the camera position at +0x4c
struct View_1c34c0 { int a[7]; float pad[12]; float pos[3]; float f, g, h, j; };

static Debug_86450 g_debug;
static Timer g_clock;
static View_1c34c0 g_view;

extern "C" {
// the game's data items, named by XBE address (pointer items pointer-sized, as the 64-bit builds need them)
void* DAT_004dd6e8[1] = {&g_debug};
int DAT_0049c104;
unsigned char DAT_004e5ad0[20] = {0x34, 0x12, 0, 0, 0x78, 0x56, 0, 0};   // the gameplay RNG: 0x1234, 0x5678
int DAT_0049fb40 = 2;                                                     // g_BootSequenceStep (skip-intro sets 6)
void* DAT_004e231c[1];                                                    // the logic view singleton: null at first
void* DAT_004e5acc[1] = {DAT_004e5ad0};                                   // the game's pointer to its RNG
// core::GetMicroseconds64 0x00267f40: the hooked call in Update goes to the virtual clock instead (a zero here makes
// an unhooked run diverge)
U64_86450 FUN_00267f40() { return 0; }

// the game loop: the GameClock as its constructor leaves it under the virtual clock (last = 300 s - one step), then
// one Update per frame; the camera singleton appears at frame 30 and moves along x
int hulk_test_game_loop(int frames) {
    g_clock.limit = 100000;
    g_clock.last = 300000000ull - 33333;
    g_clock.rate = 0x10000;
    g_view.pos[1] = 2.0f;
    g_view.pos[2] = 3.0f;
    for (int i = 0; i < frames; i++) {
        if (i >= 30) {
            g_view.pos[0] = (float)i;
            DAT_004e231c[0] = &g_view;
        }
        g_clock.FUN_00086450();
    }
    return DAT_0049fb40;
}
}

static_assert(sizeof(void*) == 8 && __builtin_offsetof(View_1c34c0, pos) == 0x4c, "the view's position at +0x4c");
static_assert(__builtin_offsetof(Timer, total) == 0x10 && __builtin_offsetof(Timer, rate) == 0x38, "GameClock block");
