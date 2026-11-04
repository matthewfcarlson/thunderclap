// Host main of tests/native_host/replay_native_test.py: the replay's start-up as entry_posix.cpp runs it, the stand-in
// game loop, the checkpoint statistics. Host side.
#include <stdio.h>
#include <stdlib.h>

#include "replay/hulk_replay.h"

extern "C" {
int hulk_test_game_loop(int frames);     // replay_native_world.cpp (game side)
void hulk_replay_startup(void);          // replay_native.cpp
void hulk_native_log(const char* line) { printf("trace: gfx %s\n", line); }
void hulk_native_missing(const char* name) {
    printf("missing %s\n", name);
    exit(3);
}
}

int main(int argc, char** argv) {
    int frames = argc > 1 ? atoi(argv[1]) : 91;
    hulk_replay_startup();
    int boot = hulk_test_game_loop(frames);
    HulkCkptStats s;
    hulk_ckpt_stats(&s);
    printf("boot step %d\n", boot);
    printf("stats frames %u checked %u matched %u mismatched %u first_bad %d\n", s.frame, s.checked, s.matched,
           s.mismatched, s.first_bad_frame == 0xffffffffu ? -1 : (int)s.first_bad_frame);
    return 0;
}
