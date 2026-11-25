// The app's co-op runner side (src/platform/wasm/run/app/netplay.cpp) without the game: a toy game in its place that
// calls the same imports the module's netplay.c does. Most frames mix the pads in effect into its state; at frame
// ends it hands over its pad, takes the next frame's set and the runner's commands (a host writes its state for a joining guest, a guest restores the host's). Run one process per
// peer against a lobby server (net/worker/test/local_server.mjs); every peer prints its state hash at the last frame,
// and the hashes must agree (tests/net/coop_loop.sh).
//
//   build: tests/net/coop_loop.sh builds it (clang++, the runner's sources, libjuice)
//   run:   HULK_NET_WORKER=http://127.0.0.1:PORT HULK_COOP_HOST=1 ... coop_loop PEER FRAMES [MS_PER_FRAME]
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "game.h"

static uint8_t g_mem[1 << 20];
extern "C" uint8_t* hulk_run_memory(void) { return g_mem; }
extern "C" void hulk_coop_quit(void);
// run/disc.c's readers, as plain files (the toy has no disc images; wnet2's disc challenge reads a test folder)
extern "C" int hdisc_open(const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) return -1;
    return fileno(f);       // (never closed by fclose: hdisc_close closes the descriptor)
}
extern "C" int64_t hdisc_pread(int fd, void* p, size_t n, uint64_t off) { return pread(fd, p, n, (off_t)off); }
extern "C" uint64_t hdisc_size(int) { return 0; }   // (the XBE hash: every peer's identity alike)
extern "C" void hdisc_close(int fd) { close(fd); }
extern "C" const char* hulk_app_default_dir(void) { return ""; }     // (start.cpp's, in the app)

enum : u32 { A_LOCAL = 0x100, A_SET = 0x200, A_PATH = 0x1000, A_SAVE = 0x2000, A_SETTINGS = 0x3000, A_PAD = 0x4000 };

static uint64_t mixh(uint64_t h, const uint8_t* p, size_t n) {
    for (size_t i = 0; i < n; i++) h = (h ^ p[i]) * 0x100000001b3ull;
    return h;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: coop_loop PEER FRAMES [MS_PER_FRAME]\n");
        return 2;
    }
    int peer = atoi(argv[1]);
    unsigned frames = (unsigned)atoi(argv[2]);
    int ms = argc > 3 ? atoi(argv[3]) : 2;
    struct {
        uint64_t h;
        u32 frame, active, mask;
        uint8_t pads[3][18];        // the pads in effect (a session's set), as the module's G
    } st = {0xcbf29ce484222325ull, 0, 0, 0, {}};
    unsigned hashes = 0, set_frames = 0;
    uint8_t* local = g_mem + A_LOCAL;
    while (st.frame < frames) {
        // a frame of the toy game: its pads mixed into its state (a session's set, or this peer's own pad)
        if (st.frame % 7 != 3) st.h = mixh(st.h, st.active ? &st.pads[0][0] : local, st.active ? 54 : 18);
        st.frame++;
        // the frame end, as netplay.c's: this peer's pad (a script: peer and frame), the runner's command, the set
        memset(local, 0, 18);
        local[0] = (uint8_t)((st.frame / 40 + peer) & 0x3f);
        local[10] = (uint8_t)(st.frame * (peer + 1));
        u32 cmd = w2c_hulk_net_frame(nullptr, A_LOCAL, st.frame);
        if (cmd != 2) {
            uint8_t* set = g_mem + A_SET;
            if (w2c_hulk_net_update(nullptr, st.frame + 1, A_SET)) {
                u32 every;
                memcpy(&every, set + 8, 4);
                if (every && st.frame % every == 0 && st.active) {
                    w2c_hulk_net_hash(nullptr, st.frame, st.h);
                    hashes++;
                }
                st.active = 1;
                memcpy(&st.mask, set, 4);
                for (int k = 0; k < 3; k++) memcpy(st.pads[k], set + 16 + 20 * k, 18);
                set_frames++;
            } else if (st.active) {
                st.active = 0;
            }
        }
        if (cmd == 1) {
            u32 slot = w2c_hulk_net_host_snap(nullptr, A_PATH, 1024);
            if (!st.active && slot) {
                st.active = 1;
                st.mask = 1u | 1u << slot;
                memcpy(st.pads[0], local, 18);
                memset(st.pads[1], 0, 18), memset(st.pads[2], 0, 18);
            }
            FILE* f = fopen((const char*)g_mem + A_PATH, "wb");
            fwrite(&st, sizeof st, 1, f);
            static uint8_t pad[4 << 20];            // (a few MB of state, as a game's would be)
            for (size_t i = 0; i < sizeof pad; i++) pad[i] = (uint8_t)(i * 2654435761u >> 13 ^ st.h >> (i & 31));
            fwrite(pad, sizeof pad, 1, f);
            fclose(f);
            strcpy((char*)g_mem + A_SETTINGS, "toy=1");
            memcpy(g_mem + A_PAD, local, 18);
            w2c_hulk_net_host_ready(nullptr, 1, st.frame + 1, A_SETTINGS, A_PAD);
            fprintf(stderr, "coop_loop %d: snapshot for slot %u at frame %u\n", peer, slot, st.frame);
        } else if (cmd == 2) {
            int ok = (int)w2c_hulk_net_guest_snap(nullptr, A_PATH, 1024, A_SAVE, 1024, A_SETTINGS, 4096) > 0;
            FILE* f = ok ? fopen((const char*)g_mem + A_PATH, "rb") : nullptr;
            ok = f && fread(&st, sizeof st, 1, f) == 1;
            if (f) fclose(f);
            fprintf(stderr, "coop_loop %d: restored frame %u (save dir %s, settings %s)\n", peer, st.frame,
                    (const char*)g_mem + A_SAVE, (const char*)g_mem + A_SETTINGS);
            w2c_hulk_net_guest_ready(nullptr, (u32)ok, st.frame + 1);
        }
        if (ms) usleep((useconds_t)ms * 1000);
    }
    printf("coop_loop %d: frame %u mask %u state %016llx (%u frames in a session, %u hashes sent)\n", peer, st.frame,
           st.mask, (unsigned long long)st.h, set_frames, hashes);
    fflush(stdout);
    hulk_coop_quit();
    return 0;
}
