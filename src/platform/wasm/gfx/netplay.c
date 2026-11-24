/* Online co-op, the module's side (wnet1, D246; docs/multiplayer.md section 18; HULK_WASM_GFX=1 builds only). The
 * network is the runner's (run/app/netplay.cpp); this file is where the game meets it.
 *
 * Lockstep keyed by presented frames: every peer runs the whole game, and at each frame end the pads in effect for the
 * next frame are the session's set for it, the same on every peer (the runner waits for it: the host's pad and each
 * guest's, sent a few frames ahead; see ff_coop_frame_end): every poll within a frame reads the same pads. Slot k's pad (the host 0, the guests 1 and 2)
 * goes into SIM->pads[k], where the co-op Hulks read it (coop.c, wcoop1: dev_coop_local Hulks, pad port k drives Hulk
 * k); a peer's own controller is its pad 0 locally (the runner's, or HULK_INPUT's) and its slot's pad in the session.
 * Each guest's picture follows its own Hulk (hulk_wasm_coop_set_local_view: host state, never sent).
 *
 * A guest joins mid-game: at a frame end (every fiber suspended) the host writes its state (sched.c ff_snap_write, the
 * playthrough snapshot; free blocks zeroed first), the runner sends it with the host's save folder and settings, and
 * the guest puts it back at one of its own frame ends (ff_snap_read), its saves going to a throwaway folder. Both then
 * run on from the frame after the snapshot.
 *
 * What lives where: the session's shared state (the pads in effect, the mask of peers, the flags) is game state, the
 * same on every peer, in the hulk_game_state section (snapshots carry it, the module hash covers it); this peer's own
 * (its role, a pending command, host paths) is host state in plain statics, never on the game's stacks. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../host/hulk_host.h"
#include "../host/sim.h"
#include "port_settings.h"

#define GI(name) __attribute__((import_module("hulk"), import_name(#name)))
#define GAME_STATE __attribute__((section("hulk_game_state")))
#define STATE_DATA_LO 0x0048ca80u         /* (frame.c's: the image's data) */

/* the runner's (run/app/netplay.cpp) */
typedef struct {
    uint32_t mask;              /* the peers in the session (bit k: slot k; bit 0 the host) */
    uint32_t flags;             /* COOP_F_* (the host's, the same for every peer) */
    uint32_t hash_every;        /* report the state hash every so many updates (0: never) */
    uint32_t spare;
    uint8_t pads[3][20];        /* XINPUT_GAMEPAD (18 bytes) per slot */
} coop_set;
GI(net_frame) int32_t gi_net_frame(const uint8_t* local18, uint32_t update);
GI(net_update) int32_t gi_net_update(uint32_t update, coop_set* out);
GI(net_host_snap) int32_t gi_net_host_snap(char* path, uint32_t cap);
GI(net_host_ready) void gi_net_host_ready(int32_t ok, uint32_t next_update, const char* settings,
                                          const uint8_t* pad18);
GI(net_guest_snap) int32_t gi_net_guest_snap(char* path, uint32_t cap, char* save_dir, uint32_t cap2, char* settings,
                                             uint32_t cap3);
GI(net_guest_ready) void gi_net_guest_ready(int32_t ok, uint32_t next_update);
GI(net_hash) void gi_net_hash(uint32_t update, uint64_t hash);
GI(net_menu) void gi_net_menu(uint32_t what, const char* code);
GI(net_status) uint32_t gi_net_status(char* buf, uint32_t cap);

int ff_snap_write(const char* path);
int ff_snap_read(const char* path);
uint32_t ff_replay_frame(void);
uint32_t ff_arena_scrub(void);
void ff_gfx_foreign_restore(void);
void ff_audio_restored(void) __attribute__((weak));
int ff_replay_active(void);
int ff_stack_ranges(uint32_t* out, int cap);
void hulk_wasm_coop_set_local_view(int k);         /* coop.c (wcoop1) */
uint32_t hulk_wasm_net_status(char* buf, uint32_t cap);
void hulk_wasm_net_label(const char* text);        /* fe_options.c */

/* ------------------------------------------------------------------------------------------- the session's state */
static struct {
    uint32_t active;            /* a session's set is in effect */
    uint32_t mask, flags;
    uint8_t pads[3][20];        /* the last set's pads (slots not in the session: zeros) */
    uint64_t digest;            /* the probe's digest at the last update (ff_coop_update) */
    uint32_t digest_frame;
} G GAME_STATE;

/* this peer's */
static int g_cmd;               /* the runner's command at the last frame end: 1 snapshot (host), 2 restore (guest) */
static char g_path[1024], g_save[1024], g_settings[2048];

/* wcoop1's view: slot 0..2's pad in the session's last set (null: no session, or the slot is empty) */
const uint8_t* hulk_net_pad(int slot) {
    if (!G.active || slot < 0 || slot > 2 || !(G.mask & (1u << slot))) return 0;
    return G.pads[slot];
}
uint32_t hulk_net_mask(void) { return G.active ? G.mask : 0; }

/* the state hash compared between peers: ff_game_hash's ranges (the image's data, the sim block, the arena without
 * the stacks), word-wise (faster than its FNV: ~40 MB every couple of seconds) */
static uint64_t mixw(uint64_t h, uint64_t w) {
    h ^= w * 0x9e3779b97f4a7c15ull;
    h = (h << 27 | h >> 37) * 0xbf58476d1ce4e5b9ull;
    return h;
}
static uint64_t hash_range(uint64_t h, uint32_t lo, uint32_t hi) {
    if (hi <= lo) return h;
    const uint8_t* p = PTR(lo);
    uint32_t n = hi - lo, i = 0;
    for (; i + 8 <= n; i += 8) {
        uint64_t w;
        memcpy(&w, p + i, 8);
        h = mixw(h, w);
    }
    for (; i < n; i++) h = mixw(h, p[i]);
    return mixw(h, n);
}
static int by_lo(const void* a, const void* b) {
    uint32_t x = *(const uint32_t*)a, y = *(const uint32_t*)b;
    return x < y ? -1 : x > y;
}
uint32_t ff_arena_top(void);
static uint64_t coop_hash(void) {
    static uint32_t r[2 * 512];
    int n = ff_stack_ranges(r, 512);
    qsort(r, (size_t)n, 8, by_lo);
    uint64_t h = 0x484b4f4f50ull;       /* "HKOOP" */
    h = hash_range(h, STATE_DATA_LO, XBE_END);
    h = hash_range(h, 0x00F00000u, 0x00F00000u + (uint32_t)sizeof(hulk_sim));
    uint32_t at = ARENA_LO, top = ff_arena_top();
    for (int i = 0; i < n; i++) {
        if (r[2 * i] > at) h = hash_range(h, at, r[2 * i] < top ? r[2 * i] : top);
        if (r[2 * i + 1] > at) at = r[2 * i + 1];
    }
    return hash_range(h, at, top);
}

static int whole_state(void) {
    static int on = -1;
    if (on < 0) on = getenv("HULK_COOP_HASH") && !strcmp(getenv("HULK_COOP_HASH"), "state");
    return on;
}

/* ------------------------------------------------------------------------------------------- the hooks */
/* Each frame end (sched.c pt_frame_end, on the host's stack; SIM->frame is the frame just ended, F). The frame end
 * has written this peer's own pad into SIM->pads[0] (the runner's, or HULK_INPUT's): that is the sample the runner
 * publishes for frame F+1+D. In a session the pads in effect for frame F+1 are the session's set for F+1 (the
 * runner waits for it), in every slot. Frames, not GameClock updates: the pause menu and the front end read the pad
 * with no update running (a session keyed by updates froze in the pause menu, its pads no longer moving). Presents
 * are the same count on every peer with the same renderer (the pddi front end, or every peer null): the runners
 * check it at the hello. */
static void session_end(uint32_t f) {
    fprintf(stderr, "hulk: co-op: the session ends at frame %u\n", f);
    memset(&G, 0, sizeof G);
    memset(SIM->pads[1], 0, 18), memset(SIM->pads[2], 0, 18);
    hulk_wasm_coop_set_local_view(0);
}
int ff_coop_frame_end(void) {
    if (ff_replay_active()) return 0;           /* (recordings and playthroughs: never a session) */
    static uint8_t local[18];
    static coop_set s;
    uint32_t f = SIM->frame;
    memcpy(local, SIM->pads[0], 18);
    if (G.active)                               /* (frame F's pads again: the state hash covers the sim block) */
        for (int k = 0; k < 3; k++) memcpy(SIM->pads[k], G.pads[k], 18);
    g_cmd = gi_net_frame(local, f);
    if (g_cmd != 2) {
        if (gi_net_update(f + 1, &s)) {
            /* (the digest of the simulation, not coop_hash's whole state: peers whose pictures follow different
             * Hulks differ in render bookkeeping, wcoop1; HULK_COOP_HASH=state compares the whole state) */
            if (s.hash_every && f % s.hash_every == 0 && G.active)
                gi_net_hash(f, whole_state() ? coop_hash() : G.digest ^ G.digest_frame);
            G.active = 1;
            G.mask = s.mask | 1u;
            G.flags = s.flags;
            memcpy(G.pads, s.pads, sizeof G.pads);
            for (int k = 0; k < 3; k++)
                if (!(G.mask >> k & 1)) memset(G.pads[k], 0, sizeof G.pads[k]);
        } else if (G.active) {
            session_end(f);                     /* (this peer plays on alone) */
        }
    }
    if (G.active)
        for (int k = 0; k < 3; k++) memcpy(SIM->pads[k], G.pads[k], 18);
    return g_cmd == 1 || g_cmd == 2;
}

/* the scheduler with every fiber suspended (sched.c, after the frame end asked for it) */
void ff_coop_switch(void) {
    int cmd = g_cmd;
    g_cmd = 0;
    uint32_t f = SIM->frame;
    if (cmd == 1) {                             /* host: a guest is joining */
        int slot = gi_net_host_snap(g_path, sizeof g_path);
        if (!G.active && slot > 0) {            /* the first guest: the session starts with frame F+1, whose set
                                                   is the pads in effect now (the runner stores the same) */
            G.active = 1;
            G.mask = 1u | 1u << slot;
            memcpy(G.pads[0], SIM->pads[0], 18);
            memset(G.pads[1], 0, sizeof G.pads[1]), memset(G.pads[2], 0, sizeof G.pads[2]);
            memset(SIM->pads[1], 0, 18), memset(SIM->pads[2], 0, 18);
        }
        uint32_t scrubbed = ff_arena_scrub();
        int ok = slot > 0 && ff_snap_write(g_path);
        hulk_settings_line(g_settings, sizeof g_settings);
        fprintf(stderr, "hulk: co-op: snapshot for player %d at frame %u (%u free bytes zeroed): %s\n", slot + 1, f,
                scrubbed, ok ? "written" : "FAILED");
        gi_net_host_ready(ok, f + 1, g_settings, SIM->pads[0]);
        if (!ok && G.mask == (1u | 1u << slot)) memset(&G, 0, sizeof G);
    } else if (cmd == 2) {                      /* guest: the host's state has arrived */
        int slot = gi_net_guest_snap(g_path, sizeof g_path, g_save, sizeof g_save, g_settings, sizeof g_settings);
        int ok = slot > 0;
        if (ok) {
            setenv("HULK_SAVE_DIR", g_save, 1);         /* (xapi.c and the settings read it at every use) */
            hulk_settings_session(g_settings);
            ff_gfx_foreign_restore();
            ok = ff_snap_read(g_path);
            if (ok && ff_audio_restored) ff_audio_restored();
            if (ok) hulk_wasm_coop_set_local_view(slot);       /* (this instance's picture: its own Hulk) */
        }
        fprintf(stderr, "hulk: co-op: the host's state %s at frame %u\n", ok ? "restored" : "NOT restored", SIM->frame);
        gi_net_guest_ready(ok, SIM->frame + 1);
    }
}

/* GameClock::Update's entry (replay.cpp), on the game's stack: the session's digest of the simulation (the replay
 * probe's tags: the frame ends report the latest), and the Online Co-op row's label (game code: the menu's) */
uint64_t ff_probe_digest(uint32_t clock);       /* replay.cpp */
void ff_coop_update(uint32_t clock) {
    if (ff_replay_active()) return;
    if (G.active) {
        G.digest = ff_probe_digest(clock) ^ (uint64_t)ff_replay_frame() << 40;
        G.digest_frame = SIM->frame;
    }
    static char t[96];
    hulk_wasm_net_status(t, sizeof t);
    hulk_wasm_net_label(t);
}

/* ------------------------------------------------------------------------------------------- the menu
 * Gameplay Options' rows (port_settings.c): "Join Code 1".."Join Code 8" (a digit each) and "Online Co-op" (Off, Host
 * a Game, Join a Game). Choosing Host makes a room; Join joins the room the digits name; Off leaves or ends it. In a
 * session every peer's menus follow the host's pad, so every peer's runner hears the host's choice: a guest ignores
 * Host / Join while it is in a game and leaves on Off, which is what the host's Off means for it anyway. */
void hulk_wasm_net_apply(int value) {
    static char code[16];
    int n = 0;
    for (int k = 1; k <= 8; k++) {
        char key[16];
        snprintf(key, sizeof key, "coop_d%d", k);
        code[n++] = (char)('0' + hulk_setting(key) % 10);
    }
    code[n] = 0;
    if (ff_replay_active()) return;
    gi_net_menu((uint32_t)value, code);
}
/* the Online Co-op row's label while co-op is on (fe_options.c hulk_wasm_net_label, at every update): in a session
 * only what every peer knows alike (the room's code, how many play), so the menu's text, which is game state, stays
 * equal; before one (a host alone, a guest not yet in) the runner's own state */
uint32_t hulk_wasm_net_status(char* buf, uint32_t cap) {
    static char t[160];
    enum { ST_IDLE, ST_WORKING, ST_HOSTING, ST_JOINING, ST_IN, ST_FAILED };
    uint32_t st = ff_replay_active() ? ST_IDLE : gi_net_status(t, sizeof t);
    char code[24];
    snprintf(code, sizeof code, "%.4s %.4s", t, strlen(t) > 4 ? t + 4 : "");
    int players = 0;
    for (int k = 0; k < 3; k++) players += (G.active && (G.mask >> k & 1)) ? 1 : 0;
    if (G.active) snprintf(buf, cap, "Co-op: room %s, %d players", code, players);
    else if (st == ST_WORKING) snprintf(buf, cap, "Co-op: making a room...");
    else if (st == ST_HOSTING || st == ST_IN) snprintf(buf, cap, "Co-op: room %s, waiting for players", code);
    else if (st == ST_JOINING) snprintf(buf, cap, "Co-op: joining %s...", code);
    else if (st == ST_FAILED) snprintf(buf, cap, "Co-op: %s", t);
    else buf[0] = 0;
    return (uint32_t)strlen(buf);
}
