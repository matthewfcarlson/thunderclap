/* Co-op Hulks in one instance (wcoop1, D246; port_settings.c `dev_coop_local`, developer mode; docs/multiplayer.md
 * §17 "What was built"; HULK_WASM_GFX=1 builds only).
 *
 * With dev_coop_local = N (2 or 3) the game runs N Hulks: the main actor (P0, pad port 0) and N-1 more (P1, P2) the
 * game's own actor spawner makes from the Hulk template, each driven by its own pad port (1, 2). In an online session
 * (wnet2) the Hulks follow the players: Hulk k exists while slot k is in the session's set (netplay.c hulk_net_mask:
 * game state, the same on every peer at every update), so a guest's Hulk is made after he joins and removed (the
 * game's KillActorByName 0x0002b830) when he leaves; a host alone has none. dev_coop_local stays the developer knob. Every instance of a
 * session simulates every Hulk; which one this instance's picture follows (the local view) is host state that never
 * reaches the simulation. No network here: lane wnet1 puts a remote player's pad in SIM->pads[k] (input.c serves it
 * as XInput port k) and calls hulk_wasm_coop_set_local_view(k).
 *
 * Input. The game reads all four pad ports through one CController (0x000ae4b0 makes four CPhysicalControllers, one
 * per port; 0x000ae130 sums them into its sample blocks), one CSimController (0x000b3b80) that turns those samples into
 * button/stick state each update (0x000b3bc0, called by 0x000b3d80 from UpdateSimulation), and a list of one sim
 * controller (0x000b3d20, `i < 1`) that CControllerAgent::vfunc_4 0x000fd0f0 indexes with the character's controller
 * slot (+0x20a8) to copy the state into his input block. In co-op (entry hooks, tools/wasm_port.py GFX_APP_HOOKS):
 *   0x000ae130  the main CController sums only port 0; for each extra player k a CController of ours (game-state
 *               memory, the game's vftable) holding only the physical controller of port k is summed by the original
 *   0x000b3d80  after the original, each extra CSimController (built by the game's constructor 0x000b3b80 over ours)
 *               is updated as the original updates its own
 *   0x000b3d20  index k (1..N-1) answers player k's sim controller
 * Sticks are camera-relative (0x000fd0f0 reads the camera's matrix, the logic view 0x004e231c +0x1c). Each extra
 * player has a simulated camera of his own: a yaw that the right stick turns and that eases behind him as he runs
 * (game state, from his input block and velocity); while his controller agent runs, the logic view's matrix is that
 * camera's (the game camera's orientation turned about the vertical to his yaw), and put back right after.
 *
 * Spawning: in play (the main actor holds controller slot 0, the game camera is up, no letterbox) for SETTLE updates,
 * each missing player is made at the main actor's side by the actor spawner 0x0002b970 (as am_CreateActorAtPosition:
 * the "hulk" template, team "player", named coop_p1 / coop_p2), then given controller slot k. When the main actor's
 * slot goes to -1 (a cutscene, a script taking control) the extras' slots do too, and come back with it. A player who
 * strays more than LEASH units from the main actor, falls below the world or stands where the rooms cannot be kept
 * resident (stream.c) is put back beside him. Extra Hulks are never expendable (+0x1d78), or the game removes one who
 * is out of resident rooms and 238 units from the main actor (0x0002a960).
 *
 * Down and respawn (first version of docs/multiplayer.md §8.2): an extra player whose life state leaves 0 (the
 * engine's death: he is removed 1.5 s later by 0x0002ae80) is down; he is made again behind the main actor once he has
 * been down RESPAWN_MIN seconds and the main actor has taken no damage for CALM seconds, or after RESPAWN_MAX seconds
 * whatever happens. The main actor's death is the original's (the mission fails as in single player).
 *
 * Enemies: an AI actor choosing a target (AcquireTargetCondition::vfunc_6 0x001245b0) takes the nearest living Hulk
 * instead of the main actor (see ffh_hulk_app_coop_acquire). The rest of the AI's single-player notions (attack tokens,
 * scripts' known-player positions) still mean the main actor.
 *
 * The local view (picture only): after UpdateSimulation, with the local view on player k > 0, the logic view's matrix
 * becomes player k's camera (the game camera's framing of the main actor, turned to k's yaw and moved to k); the
 * view's 0x7c bytes are put back exactly as the update left them when World::Render returns (draw_distance.c's hook;
 * before the next GameClock::Update and its checkpoint), at the frame's end and before the next update, so the
 * simulation, the checkpoint records and the snapshots see the game camera only. With co-op on the save and restore
 * happen whatever the local view. Checked: two runs with local views 0 and 1 give byte-identical checkpoint records
 * (6,000 frames, the second Hulk running); the game hash differs (render bookkeeping, as for Draw Distance).
 *
 * Game state (players, cameras, timers, our controller objects) lives in hulk_game_state; everything is computed from
 * game state and the update's dt, so the same pads give the same game on every instance and HULK_ROLLTEST holds.
 * With N = 1 every hook passes straight through.
 *
 * Knobs: HULK_COOP_VIEW=k (the local view at start), HULK_COOP_LOG=1 (spawns, downs, respawns, leashes; 2: every 30
 * updates each player's place). Measurements only (wstream1): HULK_COOP_FROM=F (the developer's Hulks from frame F,
 * e.g. inside a replay of play3), HULK_COOP_SPREAD=D[:EVERY] (the extras put D units out every EVERY updates),
 * HULK_COOP_LEASH=U. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../host/hulk_host.h"
#include "../host/sim.h"

#define GAME_STATE __attribute__((section("hulk_game_state")))

#define MAXP 3                          /* the user's limit (D246): the host's Hulk and two guests */
#define SETTLE 30                       /* updates in play before the extras are made */
#define SIDE 2.5f                       /* units to the main actor's side per player at a spawn */
#define BEHIND 5.0f                     /* units behind the main actor at a respawn */
#define LEASH 300.0f                    /* farther from the main actor than this: put back beside him (wstream1; 80 at
                                           * first, 200 after the user's 11-24 note). Downtown night (128 rooms, room
                                           * sets of 5..19 of the 20 room slots): within 300 units an extra Hulk stands
                                           * in the main actor's own resident set or in rooms stream.c can add (95% of
                                           * placements, 99.9% at 250; teleport runs at 250 and 300: every target room
                                           * resident); at 400 the slots run out (16 of 70 placements in rooms that were
                                           * not resident, 6 put back). docs/multiplayer.md 19 */
#define FALL_Y -45.0f                   /* below this: put back (the engine's own limit for the main actor is -50) */
#define RESPAWN_MIN 5.0f                /* seconds down before a respawn */
#define CALM 5.0f                       /* seconds without damage to the main actor before a respawn */
#define RESPAWN_MAX 30.0f               /* respawn after this many seconds down whatever happens */
#define TURN_RATE 2.6f                  /* radians/s of camera yaw at full right stick */
#define FOLLOW 1.6f                     /* 1/s: the camera eases behind a running player */
#define FOLLOW_SPEED 3.0f               /* units/s: below this the camera does not follow */

/* the game */
#define WORLD_PTR 0x004dd700u           /* +0x20 the actor manager (+0x124 the main actor), +0x08 the camera manager */
#define VIEW_PTR 0x004e231cu            /* the logic view (0x7c bytes): +0x1c camera-to-world, +0x5c field of view */
#define VIEW_SIZE 0x7c
#define LV_MATRIX 0x1c
#define LV_STALE 0x6c
#define FN_SPAWN 0x0002b970u            /* CActorManager: (template, x, y, z, angle, team, anim, flag, name, ground) */
#define FN_FIND 0x00024280u             /* CActorManager: (name hash lo, hi) -> the actor */
#define FN_HASH 0x0027b020u             /* name -> 64-bit hash (cdecl) */
#define FN_SET_POS 0x0003f400u          /* CCharacter: (vec3*) */
#define FN_NODE_POS 0x00059a50u         /* a scene node's position */
#define FN_SIMCTL_CTOR 0x000b3b80u      /* CSimController(source) */
#define FN_SIMCTL_UPDATE 0x000b3bc0u    /* CSimController update (arg) */
#define FN_SIMCTL_RESET 0x000b3b50u     /* CSimController reset (1) */
#define FN_KILL_BY_NAME 0x0002b830u     /* CActorManager: KillActorByName (name): removes the actor (am_KillActorByName) */
#define CH_VELOCITY 0x80
#define CH_HEALTH 0x1b0c
#define CH_SLOT 0x20a8
#define CH_NEVER_EXPENDABLE 0x1d78
#define CH_LIFE 0x20b0
#define CH_INPUT 0x1f58
#define IN_STICK1 (0x9c + 0x38)         /* the right stick: state, held, x, y, magnitude, angle */
#define CC_SIZE 0x138                   /* CController: +0x10 count, +0x14 items */
#define SC_SIZE 0x224                   /* CSimController */
#define FLAG_4E222C 0x004e222cu         /* input held off after a menu (0x000ae130 clears it) */

static int g_n = 1;                     /* the setting: Hulks in the session (1: off) */
uint32_t hulk_net_mask(void);           /* netplay.c: the online session's players (bit k: slot k), 0 without one */
/* (wnet2) Hulk k is wanted: the developer setting's, or slot k is in the online session */
static int want(int k) { return k == 0 || k < g_n || (hulk_net_mask() >> k & 1); }
/* the Hulks the hooks look at: 1 + the highest wanted extra (1: every hook passes straight through) */
static int coop_from(void) {             /* HULK_COOP_FROM=F: the developer's Hulks from frame F (tests in a replay) */
    static int f = -1;
    if (f < 0) f = getenv("HULK_COOP_FROM") ? atoi(getenv("HULK_COOP_FROM")) : 0;
    return f;
}
static int coop_n(void) {
    uint32_t m = hulk_net_mask() & ((1u << MAXP) - 1);
    int n = (int)SIM->frame >= coop_from() ? g_n : 1;
    for (int k = 1; k < MAXP; k++)
        if (m >> k & 1 && k + 1 > n) n = k + 1;
    return n;
}
int hulk_wasm_stream_room_state(const float pos[3], int* room);
int hulk_wasm_stream_put_back(int k);   /* stream.c (wstream1): player k's room could not be kept resident */
/* the leash (HULK_COOP_LEASH=U overrides it: measurements only) */
static float leash_units(void) {
    static float l = -1;
    if (l < 0) {
        const char* e = getenv("HULK_COOP_LEASH");
        l = e && atof(e) > 10 ? (float)atof(e) : LEASH;
    }
    return l;
}
static int g_view;                      /* the local view (host state, never game state) */
static int log_level(void) {
    static int l = -1;
    if (l < 0) l = getenv("HULK_COOP_LOG") ? atoi(getenv("HULK_COOP_LOG")) : 0;
    return l;
}

typedef struct {
    uint32_t ch;                        /* his character (0: none) */
    int32_t down;                       /* 1: down (dead or removed), waiting to respawn */
    float down_t;                       /* the clock when he went down */
    float yaw;                          /* his camera's yaw (radians; atan2 of the forward row's x, z) */
    int32_t spawned;                    /* made at least once in this level */
} player;

static struct {
    uint32_t main;                      /* the main actor the extras were made for */
    int32_t settle;
    float clock;                        /* game seconds (UpdateSimulation's dt) */
    float main_health, calm_t;          /* the main actor's health at the last update, the clock of his last damage */
    player p[MAXP];
    int32_t ready;                      /* our controller objects are built */
    uint8_t cc[MAXP][CC_SIZE] __attribute__((aligned(8)));     /* CControllers holding one port each */
    uint32_t items[MAXP][1];
    uint8_t sc[MAXP][SC_SIZE] __attribute__((aligned(8)));     /* their CSimControllers */
    /* the local view's picture camera */
    int32_t view_on;
    uint32_t view_obj;
    uint8_t view_base[VIEW_SIZE];
} g_co GAME_STATE;

void hulk_wasm_coop_apply(int value) {
    g_n = value >= 2 && value <= MAXP ? value : 1;
    if (g_n > 1) SIM->pads_in |= (1u << g_n) - 1;              /* gamepads in ports 1..N-1 */
    static int once;
    if (!once) {
        once = 1;
        const char* v = getenv("HULK_COOP_VIEW");
        if (v && *v) g_view = atoi(v);
    }
}
int hulk_wasm_coop_players(void) { return coop_n(); }
/* wnet1: which Hulk this instance's camera follows (0: the host's, the main actor) */
void hulk_wasm_coop_set_local_view(int k) { g_view = k; }
int hulk_wasm_coop_local_view(void) { return g_view; }
/* player k's character (0: none), for the HUD and the net layer */
uint32_t hulk_wasm_coop_player(int k) {
    if (k == 0) {
        uint32_t w = *(uint32_t*)PTR(WORLD_PTR), am = w ? *(uint32_t*)PTR(w + 0x20) : 0;
        return am ? *(uint32_t*)PTR(am + 0x124) : 0;
    }
    return k > 0 && k < coop_n() && want(k) && !g_co.p[k].down ? g_co.p[k].ch : 0;
}

static uint32_t rd(uint32_t a) { return a ? *(uint32_t*)PTR(a) : 0; }
static float rf(uint32_t a) { return *(float*)PTR(a); }
static void wf(uint32_t a, float v) { *(float*)PTR(a) = v; }
static uint32_t actor_mgr(void) {
    uint32_t w = rd(WORLD_PTR);
    return w ? rd(w + 0x20) : 0;
}
static uint32_t A(const void* p) { return (uint32_t)(uintptr_t)p; }

static int actor_pos(uint32_t ch, float out[3]) {
    uint32_t node = rd(ch + 0x10);
    uint32_t p[3] = {0, 0, 0};
    if (!node || !(ff_call_this(FN_NODE_POS, node, 1, A(p)) & 0xff)) return 0;
    memcpy(out, p, sizeof p);
    return 1;
}
static uint32_t find_actor(const char* name) {
    uint32_t am = actor_mgr();
    if (!am) return 0;
    uint32_t st[1] = {A(name)};
    uint64_t rb[2] = {0, 0};
    ff_dispatch(FN_HASH, 0, 0, st, rb);
    return ff_call_this(FN_FIND, am, 2, (uint32_t)rb[0], (uint32_t)(rb[0] >> 32));
}
static const char* name_of(int k) { return k == 1 ? "coop_p1" : "coop_p2"; }

/* in play: the game camera (the camera manager's flags, none of 0x5e) and no letterbox (tutorial_skip.c's test) */
static int game_camera(void) {
    uint32_t view = rd(VIEW_PTR), w = rd(WORLD_PTR), cmgr = w ? rd(w + 8) : 0, lb = view ? rd(view + 0x14) : 0;
    int letterbox = lb && rf(lb + 0x28) != rf(0x003f32e0u) && rf(lb + 0x18) != rf(0x003f32e0u);
    return view && cmgr && (rd(cmgr + 4) & 0x5e) == 0 && !letterbox;
}
static float wrap(float a) {
    while (a > 3.14159265f) a -= 6.28318531f;
    while (a < -3.14159265f) a += 6.28318531f;
    return a;
}

/* ---------------------------------------------------------------------------------------------- input */
void ffgo_000ae130(uint32_t, uint32_t, void*, void*);
void ffgo_000b3d80(uint32_t, uint32_t, void*, void*);
void ffgo_000b3d20(uint32_t, uint32_t, void*, void*);

static int ours_cc(uint32_t c) {
    for (int k = 1; k < MAXP; k++)
        if (c == A(g_co.cc[k])) return 1;
    return 0;
}
/* CController sum (0x000ae130): the main one sums port 0 only, ours each sum their own port */
void ffh_hulk_app_coop_accum(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    int n = coop_n();
    if (n < 2 || ours_cc(ecx) || rd(ecx + 0x10) != 4) {
        ffgo_000ae130(ecx, edx, st, rb);
        return;
    }
    uint8_t flag0 = *(uint8_t*)PTR(FLAG_4E222C);
    *(uint32_t*)PTR(ecx + 0x10) = 1;
    ffgo_000ae130(ecx, edx, st, rb);
    *(uint32_t*)PTR(ecx + 0x10) = 4;
    uint8_t flag1 = *(uint8_t*)PTR(FLAG_4E222C);
    uint32_t items = rd(ecx + 0x14);
    for (int k = 1; k < n; k++) {
        uint32_t c = A(g_co.cc[k]);
        if (!rd(c)) {                                           /* built once: the game's vftable, one item */
            memcpy(PTR(c), PTR(ecx), CC_SIZE);
            *(uint32_t*)PTR(c + 0x04) = 1;                      /* (a reference: never released) */
            *(uint32_t*)PTR(c + 0x10) = 1;
            *(uint32_t*)PTR(c + 0x14) = A(g_co.items[k]);
        }
        g_co.items[k][0] = items ? rd(items + 4u * (uint32_t)k) : 0;
        *(uint8_t*)PTR(FLAG_4E222C) = flag0;
        uint64_t r[2];
        ffgo_000ae130(c, 0, st, r);
        /* the physical controllers of ports 1..3 carry the flag that sums them into the C/D blocks (0xac, 0xf0), which
         * a sim controller reads as its second sample; player k's are his first: move them to A/B (0x18, 0x5c) */
        uint32_t any = 0;
        for (uint32_t w = 0; w < 0x44; w += 4) any |= rd(c + 0xac + w) | rd(c + 0xf0 + w);
        if (any) {                                              /* (one item: A/B are empty then) */
            memcpy(PTR(c + 0x18), PTR(c + 0xac), 0x44);
            memcpy(PTR(c + 0x5c), PTR(c + 0xf0), 0x44);
            memset(PTR(c + 0xac), 0, 0x44);
            memset(PTR(c + 0xf0), 0, 0x44);
        }
    }
    *(uint8_t*)PTR(FLAG_4E222C) = flag1;
}

/* the sim controllers' update (0x000b3d80, UpdateSimulation): ours after the original's */
void ffh_hulk_app_coop_simctl(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_000b3d80(ecx, edx, st, rb);
    int n = coop_n();
    if (n < 2 || !ecx) return;
    uint32_t arg = ARG(0);
    for (int k = 1; k < n; k++) {
        uint32_t c = A(g_co.cc[k]), s = A(g_co.sc[k]);
        if (!rd(c)) continue;                                   /* (the CController sum has not run yet) */
        if (!rd(s)) {
            ff_call_this(FN_SIMCTL_CTOR, s, 1, c);
            ff_call_this(rd(rd(s)), s, 0);                      /* AddRef, as 0x000b3c90 does: kept */
        }
        if (*(uint8_t*)PTR(ecx + 8))
            ff_call_this(FN_SIMCTL_UPDATE, s, 1, arg);
        else
            ff_call_this(FN_SIMCTL_RESET, s, 1, 1u);
    }
}

/* the sim controller list (0x000b3d20): index k answers player k's */
void ffh_hulk_app_coop_simget(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    int32_t i = (int32_t)ARG(0);
    int n = coop_n();
    if (n >= 2 && i >= 1 && i < n && rd(A(g_co.sc[i]))) {
        RET(A(g_co.sc[i]));
        return;
    }
    ffgo_000b3d20(ecx, edx, st, rb);
}

/* player k's camera matrix: the logic view's (the game camera's) turned about the vertical to k's yaw and, when POS,
 * moved to frame k as the game camera frames the main actor */
static int player_camera(int k, float out[16], int pos) {
    uint32_t v = rd(VIEW_PTR), ch = g_co.p[k].ch, mainch = hulk_wasm_coop_player(0);
    if (!v || !ch) return 0;
    const float* m = (const float*)PTR(v + LV_MATRIX);
    float d = g_co.p[k].yaw - atan2f(m[8], m[10]), c = cosf(d), s = sinf(d);
    memcpy(out, m, 64);
    for (int r = 0; r < 3; r++) {
        float x = m[4 * r], z = m[4 * r + 2];
        out[4 * r] = x * c + z * s;
        out[4 * r + 2] = -x * s + z * c;
    }
    if (pos) {
        float pk[3], p0[3];
        if (!actor_pos(ch, pk) || !mainch || !actor_pos(mainch, p0)) return 0;
        float ox = m[12] - p0[0], oy = m[13] - p0[1], oz = m[14] - p0[2];
        out[12] = pk[0] + ox * c + oz * s;
        out[13] = pk[1] + oy;
        out[14] = pk[2] - ox * s + oz * c;
    }
    return 1;
}

/* CControllerAgent::vfunc_4 0x000fd0f0 (traversal.c's hook calls this for the original): for an extra player's
 * character the logic view's matrix is his camera's while it runs */
void ffgo_000fd0f0(uint32_t, uint32_t, void*, void*);
void hulk_wasm_coop_ctrl_agent(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    int k = 0, n = coop_n();
    if (n >= 2) {
        uint32_t obj = rd(ecx + 0x58);
        uint32_t ch = obj ? ff_call_this(rd(rd(obj) + 6 * 4), obj, 0) : 0;
        for (int j = 1; j < n; j++)
            if (ch && ch == g_co.p[j].ch && !g_co.p[j].down) k = j;
    }
    float cam[16], keep[16];
    uint32_t v = rd(VIEW_PTR);
    if (!k || !v || !player_camera(k, cam, 0)) {
        ffgo_000fd0f0(ecx, edx, st, rb);
        return;
    }
    memcpy(keep, PTR(v + LV_MATRIX), 64);
    memcpy(PTR(v + LV_MATRIX), cam, 64);
    ffgo_000fd0f0(ecx, edx, st, rb);
    memcpy(PTR(v + LV_MATRIX), keep, 64);
}

/* ---------------------------------------------------------------------------------------------- enemies */
/* AcquireTargetCondition::vfunc_6 0x001245b0: an AI actor with no target on another team than the main actor's takes
 * the main actor's target object (+0x12c). In co-op it takes the nearest living Hulk's: the main actor slot of the
 * actor manager holds that Hulk while the original runs (it reads no other main-actor state), then the main actor
 * again. Once an enemy has a target the original keeps it (the condition's other branches), so this is the
 * engagement's choice with the game's own hysteresis. */
#define FN_OWNER_CTX 0x000592a0u
#define FN_CTX_CHAR 0x00059a30u
void ffgo_001245b0(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_coop_acquire(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    uint32_t am = actor_mgr(), mainch = am ? rd(am + 0x124) : 0, owner = ARG(1);
    int n = coop_n();
    if (n < 2 || !mainch || !owner) {
        ffgo_001245b0(ecx, edx, st, rb);
        return;
    }
    uint32_t ctx = ff_call_this(FN_OWNER_CTX, owner, 0), self = ctx ? ff_call_this(FN_CTX_CHAR, ctx, 0) : 0;
    uint32_t best = mainch;
    float ps[3], q[3];
    int is_player = self == mainch;
    for (int k = 1; k < n; k++)
        if (self && self == g_co.p[k].ch) is_player = 1;
    if (self && !is_player && !rd(self + 0x328) && actor_pos(self, ps)) {
        float bd = 1e30f;
        for (int k = 0; k < n; k++) {
            uint32_t ch = k ? (g_co.p[k].down ? 0 : g_co.p[k].ch) : mainch;
            if (!ch || rd(ch + CH_LIFE) != 0 || !actor_pos(ch, q)) continue;
            float dx = q[0] - ps[0], dy = q[1] - ps[1], dz = q[2] - ps[2], d = dx * dx + dy * dy + dz * dz;
            if (d < bd) bd = d, best = ch;
        }
    }
    if (best == mainch) {
        ffgo_001245b0(ecx, edx, st, rb);
        return;
    }
    *(uint32_t*)PTR(am + 0x124) = best;
    ffgo_001245b0(ecx, edx, st, rb);
    *(uint32_t*)PTR(am + 0x124) = mainch;
    if (log_level() && rd(self + 0x328))
        fprintf(stderr, "hulk: coop: frame %u: an enemy (0x%08x) takes player %s's target\n", SIM->frame, self,
                best == g_co.p[1].ch ? "1" : "2");
}

/* ---------------------------------------------------------------------------------------------- the players */
static int spawn(int k, int respawn) {
    uint32_t am = actor_mgr(), mainch = hulk_wasm_coop_player(0);
    float p0[3];
    uint32_t v = rd(VIEW_PTR);
    if (!am || !mainch || !v || !actor_pos(mainch, p0)) return 0;
    const float* m = (const float*)PTR(v + LV_MATRIX);
    float rx = m[0], rz = m[2], fx = m[8], fz = m[10];
    float rl = sqrtf(rx * rx + rz * rz), fl = sqrtf(fx * fx + fz * fz);
    if (!(rl > 1e-3f) || !(fl > 1e-3f)) return 0;
    rx /= rl, rz /= rl, fx /= fl, fz /= fl;
    float pos[3];
    if (respawn) {
        float side = k == 1 ? -1.5f : 1.5f;
        pos[0] = p0[0] - fx * BEHIND + rx * side, pos[1] = p0[1] + 1.0f, pos[2] = p0[2] - fz * BEHIND + rz * side;
    } else {
        float side = (k == 1 ? -1.0f : 1.0f) * SIDE;
        pos[0] = p0[0] + rx * side, pos[1] = p0[1] + 1.0f, pos[2] = p0[2] + rz * side;
    }
    float yaw = atan2f(fx, fz), deg = yaw * 57.2957795f;
    uint32_t angle;
    memcpy(&angle, &deg, 4);
    uint32_t x, y, z;
    memcpy(&x, &pos[0], 4), memcpy(&y, &pos[1], 4), memcpy(&z, &pos[2], 4);
    uint32_t ok = ff_call_this(FN_SPAWN, am, 10, A("hulk"), x, y, z, angle, A("player"), A("none"), 0u, A(name_of(k)),
                               1u) & 0xff;
    uint32_t ch = ok ? find_actor(name_of(k)) : 0;
    if (log_level())
        fprintf(stderr, "hulk: coop: frame %u: %s player %d at (%.1f, %.1f, %.1f): %s (0x%08x)\n", SIM->frame,
                respawn ? "respawn" : "spawn", k, (double)pos[0], (double)pos[1], (double)pos[2],
                ch ? "ok" : "FAILED", ch);
    if (!ch) return 0;
    *(int32_t*)PTR(ch + CH_SLOT) = k;
    /* never expendable (am_SetNeverExpendable 0x00026ab0's byte): each update 0x0002a960 removes an actor whose room is
     * not resident and who is more than sqrt(56700) = 238 units from the main actor, unless the actor has this byte
     * (wstream1); a Hulk out of resident rooms is coop.c's business (fell, stream, leash) */
    *(uint8_t*)PTR(ch + CH_NEVER_EXPENDABLE) = 1;
    g_co.p[k].ch = ch;
    g_co.p[k].down = 0;
    g_co.p[k].yaw = yaw;
    g_co.p[k].spawned = 1;
    return 1;
}

static void put_back(int k, uint32_t ch, const char* why) {
    uint32_t mainch = hulk_wasm_coop_player(0), v = rd(VIEW_PTR);
    float p0[3];
    if (!mainch || !v || !actor_pos(mainch, p0)) return;
    const float* m = (const float*)PTR(v + LV_MATRIX);
    float fx = m[8], fz = m[10], fl = sqrtf(fx * fx + fz * fz);
    if (!(fl > 1e-3f)) return;
    float pos[3] = {p0[0] - fx / fl * BEHIND, p0[1] + 1.0f, p0[2] - fz / fl * BEHIND};
    ff_call_this(FN_SET_POS, ch, 1, A(pos));
    wf(ch + CH_VELOCITY, 0), wf(ch + CH_VELOCITY + 4, 0), wf(ch + CH_VELOCITY + 8, 0);
    if (log_level())
        fprintf(stderr, "hulk: coop: frame %u: player %d put back (%s)\n", SIM->frame, k, why);
}

/* HULK_COOP_SPREAD=D[:EVERY] (measurements only): every EVERY updates (300) player k is put D units from the main
 * actor, each player in another direction, turning a little each time (streaming and memory under load) */
static void spread_test(int k, uint32_t ch, const float p0[3], int ok) {
    static float d = -1;
    static int every = 300;
    if (d < 0) {
        const char* e = getenv("HULK_COOP_SPREAD");
        d = e ? (float)atof(e) : 0;
        const char* c = e ? strchr(e, ':') : 0;
        if (c && atoi(c + 1) > 0) every = atoi(c + 1);
    }
    if (!(d > 0) || !ok || SIM->frame % (uint32_t)every) return;
    float a = (float)k * 2.0943951f + (float)(SIM->frame / (uint32_t)every) * 0.7f;
    float pos[3] = {p0[0] + d * sinf(a), p0[1] + 3.0f, p0[2] + d * cosf(a)};
    ff_call_this(FN_SET_POS, ch, 1, A(pos));
    wf(ch + CH_VELOCITY, 0), wf(ch + CH_VELOCITY + 4, 0), wf(ch + CH_VELOCITY + 8, 0);
    if (log_level()) {
        int room = 0, rs = hulk_wasm_stream_room_state(pos, &room);
        fprintf(stderr, "hulk: coop: frame %u: player %d spread to (%.1f, %.1f, %.1f): room %d state %d\n", SIM->frame, k,
                (double)pos[0], (double)pos[1], (double)pos[2], room, rs);
    }
}

/* (wnet2) Hulk k's player has left the session: the game removes his actor (as a script's am_KillActorByName) */
static void remove_player(int k) {
    player* p = &g_co.p[k];
    if (p->ch && find_actor(name_of(k)) == p->ch) {
        uint32_t am = actor_mgr();
        if (am) ff_call_this(FN_KILL_BY_NAME, am, 1, A(name_of(k)));
        if (log_level()) fprintf(stderr, "hulk: coop: frame %u: player %d removed (left the session)\n", SIM->frame, k);
    }
    p->ch = 0, p->down = 0, p->spawned = 0;
}

static void update_camera(int k, uint32_t ch, float dt) {
    player* p = &g_co.p[k];
    uint32_t in = ch + CH_INPUT + IN_STICK1;
    float sx = rf(in + 8);
    if (sx > 0.2f || sx < -0.2f) p->yaw = wrap(p->yaw + sx * TURN_RATE * dt);
    else {
        float vx = rf(ch + CH_VELOCITY), vz = rf(ch + CH_VELOCITY + 8), sp = sqrtf(vx * vx + vz * vz);
        if (sp > FOLLOW_SPEED) {
            float d = wrap(atan2f(vx, vz) - p->yaw), a = dt * FOLLOW;
            if (a > 1) a = 1;
            if (d < 2.6f && d > -2.6f) p->yaw = wrap(p->yaw + d * a);   /* (not towards the camera: running at it) */
        }
    }
}

static void players_update(float dt) {
    uint32_t mainch = hulk_wasm_coop_player(0);
    if (!mainch) {
        g_co.settle = 0;
        return;
    }
    if (mainch != g_co.main) {                                  /* a new level (or the first): the extras are gone */
        g_co.main = mainch;
        g_co.settle = 0;
        for (int k = 1; k < MAXP; k++) g_co.p[k].ch = 0, g_co.p[k].down = 0, g_co.p[k].spawned = 0;
        g_co.main_health = rf(mainch + CH_HEALTH);
        g_co.calm_t = g_co.clock;
    }
    float h = rf(mainch + CH_HEALTH);
    if (h < g_co.main_health) g_co.calm_t = g_co.clock;
    g_co.main_health = h;
    int32_t slot0 = (int32_t)rd(mainch + CH_SLOT);
    int in_play = slot0 == 0 && game_camera() && rd(mainch + CH_LIFE) == 0;
    g_co.settle = in_play ? g_co.settle + 1 : 0;
    float p0[3];
    int have0 = actor_pos(mainch, p0);
    int n = coop_n();
    for (int k = 1; k < n; k++) {
        player* p = &g_co.p[k];
        if (!want(k)) {                                         /* (wnet2) his player left the session: no Hulk */
            remove_player(k);
            continue;
        }
        if (p->ch && !p->down) {
            uint32_t found = find_actor(name_of(k));
            if (found != p->ch || rd(p->ch + CH_LIFE) != 0) {   /* dead, removed */
                p->down = 1;
                p->down_t = g_co.clock;
                if (log_level()) {
                    float q[3] = {0, 0, 0};
                    int room = 0, rs = found == p->ch && actor_pos(p->ch, q) ? hulk_wasm_stream_room_state(q, &room) : -2;
                    fprintf(stderr, "hulk: coop: frame %u: player %d down (%s, life %d; room %d state %d at %.1f %.1f %.1f)\n",
                            SIM->frame, k, found != p->ch ? "removed" : "dead",
                            found == p->ch ? (int)rd(p->ch + CH_LIFE) : -1, room, rs, (double)q[0], (double)q[1], (double)q[2]);
                }
                if (found != p->ch) p->ch = 0;
            }
        }
        if (p->down && p->ch && find_actor(name_of(k)) != p->ch) p->ch = 0;     /* (removed while down) */
        if (!p->ch || p->down) {
            if (g_co.settle < SETTLE || p->ch) continue;        /* (a dying body still in the world: wait) */
            if (!p->spawned) spawn(k, 0);
            else if (p->down) {
                float t = g_co.clock - p->down_t;
                if ((t >= RESPAWN_MIN && g_co.clock - g_co.calm_t >= CALM) || t >= RESPAWN_MAX) spawn(k, 1);
            } else
                spawn(k, 1);
            continue;
        }
        uint32_t ch = p->ch;
        int32_t want = slot0 >= 0 ? k : -1;                     /* a cutscene takes every Hulk's control */
        if ((int32_t)rd(ch + CH_SLOT) != want) *(int32_t*)PTR(ch + CH_SLOT) = want;
        float pk[3];
        if (in_play && have0 && actor_pos(ch, pk)) {
            float dx = pk[0] - p0[0], dz = pk[2] - p0[2], leash = leash_units();
            if (pk[1] < FALL_Y) put_back(k, ch, "fell");
            else if (dx * dx + dz * dz > leash * leash) put_back(k, ch, "leash");
            else if (hulk_wasm_stream_put_back(k)) put_back(k, ch, "stream");
        }
        spread_test(k, ch, p0, have0 && in_play);
        update_camera(k, ch, dt);
        if (log_level() >= 2 && SIM->frame % 30 == 0 && actor_pos(ch, pk))
            fprintf(stderr, "hulk: coop: frame %u: player %d at (%.1f, %.1f, %.1f) health %.0f yaw %.2f slot %d\n",
                    SIM->frame, k, (double)pk[0], (double)pk[1], (double)pk[2], (double)rf(ch + CH_HEALTH),
                    (double)p->yaw, (int)(int32_t)rd(ch + CH_SLOT));
    }
}

/* ---------------------------------------------------------------------------------------------- the local view */
/* put the logic view back as the update left it (the frame's end, and before the next update) */
void hulk_wasm_coop_view_restore(void) {
    if (!g_co.view_on) return;
    g_co.view_on = 0;
    uint32_t v = rd(VIEW_PTR);
    if (v && v == g_co.view_obj) memcpy(PTR(v), g_co.view_base, VIEW_SIZE);
}
static void view_apply(void) {
    uint32_t v = rd(VIEW_PTR);
    if (!v) return;
    memcpy(g_co.view_base, PTR(v), VIEW_SIZE);                  /* (whatever the view: the same bytes come back) */
    g_co.view_obj = v;
    g_co.view_on = 1;
    int k = g_view;
    float cam[16];
    if (k <= 0 || k >= coop_n() || !want(k) || !g_co.p[k].ch || g_co.p[k].down || !game_camera() || !player_camera(k, cam, 1)) return;
    memcpy(PTR(v + LV_MATRIX), cam, 64);
    *(uint8_t*)PTR(v + LV_STALE) = 0;
}

void hulk_wasm_coop_pre_update(void) { hulk_wasm_coop_view_restore(); }
void hulk_wasm_coop_update(int kind, float dt) {
    if (coop_n() < 2) {                                         /* (the last guest left: his Hulk goes too) */
        for (int k = 1; k < MAXP; k++)
            if (g_co.p[k].ch && kind != 6 && kind != 7) remove_player(k);
        return;
    }
    int advance = kind != 6 && kind != 7;
    if (advance && dt > 0 && dt < 1) g_co.clock += dt;
    if (advance) players_update(dt > 0 && dt < 1 ? dt : 0);
    view_apply();
}
