/* Remastered traversal moves (wtrav1, D242; port_settings.c `remaster_moves`, Gameplay Options > Traversal Moves;
 * docs/traversal.md "What was built"; HULK_WASM_GFX=1 builds only).
 *
 * Three moves, as entry hooks on the original's code (tools/wasm_port.py GFX_APP_HOOKS), bought in the game's own
 * moves store:
 *
 * - Charging sprint (Charge Sprint I-III). While the sprint trigger is held during a sprint the charge builds from 0
 *   to 1 over CHARGE_TIME seconds; the sprint's speed is lerp(1, top, charge) times the track's (top by level), the
 *   turning rate falls with the speed, and Hulk's hits while charged deal lerp(1, damage top, charge) times the damage
 *   and push their target further. Releasing the trigger with some charge keeps the sprint going at the speed and
 *   heading it has (the input block shows the trigger still held and, with the stick centred, the last stick sample;
 *   his intention points along his velocity) until he hits something or someone, is stopped by a wall, starts another
 *   move (the sprint node ends) or presses the trigger again (charging resumes). Hooks: LocomotionSprintAction begin
 *   0x00163ed0 (charge 0), per frame 0x0015e250 (charge, turn, speed), end 0x0015c540; CControllerAgent::vfunc_4
 *   0x000fd0f0 (the input block, after the original copies the pad into it); the collision damage formula
 *   0x00013f20 (damage, push-back, the hit that ends a coast).
 * - Higher leaps (Mega Leap I-III): every jump's launch speed and gravity scale by 1 + 0.1 level (the arc is
 *   10% higher per level and takes the same time) and its forward speed by the same factor; CJumpAction::vfunc_6
 *   0x00013b90 after the original computed them.
 * - Landing bounce: a jump that starts within BOUNCE_WINDOW seconds of touching down (the main actor's motion state
 *   leaving Air, followed in UpdateSimulation) is a bounce: chain n gives (1 + BOUNCE_STEP n) times the height and
 *   forward speed, at least CARRY times the landing's horizontal speed; the chain grows by one per timed bounce up to
 *   1 + leap level and breaks on a jump outside the window. (The original already lets a jump released in the landing
 *   node start at once, and such a re-jump keeps some jump charge: its height grows by about half over a few re-jumps;
 *   the bounce multiplies on top of that.) Free with the setting (its cap grows with the leap upgrades). Off in the
 *   two precision-landing challenges (c10m24, c10m27), where the original turns its own landing re-jump off.
 *
 * - Wall fling (Wall Fling I-III, wtrav2): a jump off a wall run (WallJumpAction::vfunc_3 0x00140650) launches with
 *   k_fling_xz times the horizontal speed (at least FLING_CARRY of the wall run's speed) and k_fling_y the vertical;
 *   leaving a wall going up (WallExitAction::vfunc_3 0x0013f1d0: off the top of a wall run) with k_exit.
 * - Air control (Air Control I-III, wtrav2): jumps (CJumpAction::vfunc_7 0x00018d40) and falls (FallAction::vfunc_5
 *   0x00134ee0) turn k_air_turn faster, the jump drifts k_air_drift further, and the stick strafes him (sideways in a
 *   jump, whose own drift moves him along his facing; any way in a fall) at k_air_strafe units/s.
 * - The camera at speed (wtrav2, no purchase): while a move of ours is under way (a charging or coasting sprint, a
 *   scaled jump or fling until it lands) the picture's camera eases back, up and wider with the Hulk's speed; the
 *   logic view is changed after the update and put back before the next, so the simulation never sees it.
 * - The charge-sprint glow (wtrav2, no purchase): ember trails from the feet, heel blooms and a ring per charge stage,
 *   drawn after World::Render through the game's pddi, from state kept per update.
 *
 * The store: twelve CUnlockableMove slots the shipped init.lua leaves empty (k_slot) are set up with the
 * original's setup (0x00092ef0: our own string keys, a cost, the picture of an existing move), placed in the store's
 * order (0x00092f70) right after the shipped moves the story has unlocked, and chained (0x00092e20: level n needs level
 * n-1), so the store lists, prices and buys them like its own and the save keeps the purchase in the original's bits
 * (an old save reads them as not bought). They are set up from UpdateSimulation and from the store's list 0x000c21b0
 * (the computer interface's refresh, also in the front end). The strings are fe_options.c's (appended to the string
 * table, our own text). With the setting off nothing is set up (the store is the original's; turned off in a session,
 * ours leave the store's order) and every hook passes straight through.
 *
 * Game state: the charge, the coast, the landing clock and the chain live in hulk_game_state; the track parameters
 * the damage hook scales are put back at the end of UpdateSimulation. Everything is computed from game state and the
 * game's dt, so the same input gives the same game and HULK_ROLLTEST holds. The setting is per session (netplay peers
 * must share it); replays and tests pin it off.
 *
 * HULK_TRAV_LOG=1 logs the store set-up, charges, coasts, hits and bounces (2: the unlockable moves table, 3: every
 * sprint frame). HULK_TRAV_FORCE=C,J[,W,A] (tests) treats charge level C, leap J, wall fling W and air control A as bought;
 * HULK_TRAV_CAM=0 / HULK_TRAV_GLOW=0 (tests) turn the camera pull-back / the glow off; HULK_TRAV_TEST_XP=N
 * (tests) gives N smash points when the moves are set up.
 *
 * Developer forces (wdev1; port_settings.c's developer rows, developer mode only): Force Charge Sprint / Force Mega
 * Leap set the level the hooks above use (as HULK_TRAV_FORCE does; the store still shows the real purchases), and
 * Force Original Moves makes every shipped store move (slots 0x266..FIRST_OURS-1 with a name) count as unlocked and
 * bought where the game asks: the fight script's `unlockable` condition (UnlockableCondition::vfunc_6 0x0012f110,
 * answered by the hook), the C++ readers of a move's purchase (0x00092940: health upgrades 0x401a0 and the health bar
 * 0xd2c30; answered by the hook except while the save is captured, 0x0008b560, which reads every bit through it) and
 * the missile deflection (ProjectileMissile::vfunc_4 0x0019e910 reads move 0x2b9's bytes itself: they are set for the
 * call and put back after it). No purchase bit, locked bit or smash point is changed, so a save made with the forces on
 * holds only real purchases; Lua (um_* through 0x00092de0, inside the defining TU, which no entry hook sees) and the
 * store's own screens see the real state. HULK_DEV_TEST_FROM=N (tests) starts Force Original Moves at frame N. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../host/hulk_host.h"
#include "../host/sim.h"
#include "port_settings.h"

#define GAME_STATE __attribute__((section("hulk_game_state")))

/* ---------------------------------------------------------------------------------------------- tuning */
#define CHARGE_TIME 3.0f                /* seconds of held trigger from no charge to full */
#define COAST_MIN 0.10f                 /* the charge a release needs to coast */
#define TURN_LOSS 0.55f                 /* at the top speed the turn rate and acceleration keep 1 - this */
static const float k_speed_top[4] = {1.0f, 1.3f, 1.5f, 1.7f};     /* by charge level: speed at full charge */
static const float k_damage_top[4] = {1.0f, 3.0f, 5.0f, 8.0f};    /* damage at full charge */
static const float k_push_top[4] = {1.0f, 1.5f, 2.0f, 2.5f};      /* push-back distance at full charge */
#define LEAP_STEP 0.10f                 /* per leap level */
#define BOUNCE_WINDOW 0.25f             /* seconds after touching down (motion state Air -> another) */
#define BOUNCE_STEP 0.12f               /* per chain step */
#define CARRY 0.8f                      /* a bounce keeps at least this much of the landing's horizontal speed */
#define STALL_FRAC 0.35f                /* a coast below this fraction of its speed ... */
#define STALL_FRAMES 4                  /* ... this many sprint frames in a row has hit a wall */
/* wall fling (wtrav2): a jump off a wall run, and the launch off the top of a wall, by level */
static const float k_fling_xz[4] = {1.0f, 1.3f, 1.6f, 1.9f};     /* the jump's horizontal launch speed */
static const float k_fling_y[4] = {1.0f, 1.12f, 1.24f, 1.36f};   /* its vertical launch speed (height ~ square) */
static const float k_exit[4] = {1.0f, 1.15f, 1.3f, 1.45f};       /* a wall exit's launch (going up: off the top) */
#define FLING_CARRY 0.6f                /* at least this share of the wall run's speed carries into the fling */
/* air control (wtrav2): jumps and falls turn faster, drift further and strafe towards the stick */
static const float k_air_turn[4] = {1.0f, 1.6f, 2.2f, 2.8f};     /* the tracks' turning rates */
static const float k_air_drift[4] = {1.0f, 1.4f, 1.8f, 2.2f};    /* the jump's drift (stick along the facing) */
static const float k_air_strafe[4] = {0.0f, 5.0f, 8.0f, 11.0f};  /* units/s of stick-relative strafe */
/* the camera at speed (wtrav2): pulled back and widened with the speed of a traversal move, render-side */
#define CAM_SPEED0 20.0f                /* no pull-back at or below this speed (the original sprint) */
#define CAM_SPEED1 36.0f                /* full pull-back at this speed */
#define CAM_PULL 2.0f                   /* units back along the view at full */
#define CAM_LIFT 0.4f                   /* units up at full */
#define CAM_WIDEN 0.10f                 /* the field of view widens by this share at full */
#define CAM_RISE 0.55f                  /* seconds to ease in fully */
#define CAM_FALL 0.9f                   /* seconds to ease out */
/* the charge-sprint glow (wtrav2): ember ribbons trailing from the feet, a ring at each charge stage */
#define TRAIL_N 20                      /* positions kept (one per update) */
#define GLOW_RISE 0.15f
#define GLOW_FALL 0.45f
#define GLOW_START (1.0f / 3.0f)       /* the charge it shows from: the first stage, 1 s of held trigger (user, 11-24) */

/* the store */
/* twelve spare CUnlockableMove slots (the shipped init.lua sets up none of 0x2bb..0x2c9): the first six (wtrav1) at
 * 0x2c4..0x2c9, the wall fling and air control (wtrav2) at 0x2be..0x2c3. A slot is a save bit: never move one. */
#define FIRST_OURS 0x2be                /* the lowest of ours; the shipped moves are below it (0x266..0x2ba) */
enum { M_CHARGE1, M_CHARGE2, M_CHARGE3, M_LEAP1, M_LEAP2, M_LEAP3, M_FLING1, M_FLING2, M_FLING3, M_AIR1, M_AIR2,
       M_AIR3, N_MOVES };
static const int k_slot[N_MOVES] = {0x2c4, 0x2c5, 0x2c6, 0x2c7, 0x2c8, 0x2c9, 0x2be, 0x2bf, 0x2c0, 0x2c1, 0x2c2, 0x2c3};
/* priced like the original's upgrade lines (Air Dash 12,000 / Super 25,000 / Double 60,000 / Double Super 150,000) */
static const int k_cost[N_MOVES] = {20000, 50000, 100000, 10000, 25000, 60000, 15000, 35000, 75000, 8000, 20000, 45000};
/* the shipped moves whose pictures (+0x48) ours show: Dashing Straight, Air Dash, Super Air Dash and Air Recovery
 * (slots 0x267 / 0x26f / 0x29b / 0x269) */
static const int k_picture_from[N_MOVES] = {0x267, 0x267, 0x267, 0x26f, 0x26f, 0x26f, 0x29b, 0x29b, 0x29b,
                                            0x269, 0x269, 0x269};
static int ours(uint32_t index) {      /* index -> our move, -1 */
    for (int m = 0; m < N_MOVES; m++)
        if ((uint32_t)k_slot[m] == index) return m;
    return -1;
}

/* ---------------------------------------------------------------------------------------------- the game */
#define WORLD_PTR 0x004dd700u           /* +0x54 CGame (its unlockables: 0x00086340) */
#define FN_OWNER_CTX 0x000592a0u        /* an action's owner -> its context */
#define FN_CTX_CHAR 0x00059a30u         /* context -> the character */
#define FN_UNLOCKS 0x00086340u
#define FN_IS_ON 0x00092940u            /* unlockable index -> on (a move: bought) */
#define FN_SETUP_MOVE 0x00092ef0u       /* (index, name, combo, description, picture, cost) */
#define FN_FE_ORDER 0x00092f70u         /* (index, position, flag) */
#define FN_DEPENDENCY 0x00092e20u       /* (index, needs) */
#define CH_VELOCITY 0x80                /* the character's velocity */
#define CH_SLOT 0x20a8                  /* its controller slot (-1: none) */
#define CH_MOTION 0x140                 /* its motion state */
#define MOTION_AIR 3
#define CH_INPUT 0x1f58                 /* its input block: 13 buttons of 12 bytes (state, held, value), 2 sticks */
#define IN_STICK 0x9c                   /* stick 0: state, held, x, y, magnitude, angle, ... (0x38 bytes) */
#define IN_INTENT 0x10c                 /* the intention (world vector) and its magnitude at +0x118 */
#define TRIGGER 5                       /* the sprint button (Free Look, the right trigger) */

static int g_on;
static int g_force_charge = -1, g_force_leap = -1, g_force_fling = -1, g_force_air = -1;
static int g_dev_charge, g_dev_leap, g_dev_moves;   /* developer forces (wdev1): 0 off */
static int g_dev_fling, g_dev_air;                   /* (wtrav2) */
static int g_saving;                                 /* inside the save's capture 0x0008b560 */
static int log_level(void) {
    static int l = -1;
    if (l < 0) l = getenv("HULK_TRAV_LOG") ? atoi(getenv("HULK_TRAV_LOG")) : 0;
    return l;
}

static struct {
    uint32_t ch;                /* the controlled character whose sprint is charging (0: none) */
    uint32_t act;               /* its LocomotionSprintAction */
    float charge;               /* 0..1 */
    float hold;                 /* the trigger's held time the input block shows while coasting */
    int32_t coast;              /* 1: released, keeping speed and heading */
    int32_t trig;               /* the real trigger was down at the last input copy */
    int32_t stall;
    float speed;                /* the sprint's last target speed */
    uint32_t stick[14];         /* the last deflected stick-0 sample */
    int32_t have_stick;
    float clock;                /* game seconds (UpdateSimulation's dt) */
    uint32_t land_ch;           /* the character that landed last */
    float land_time, land_speed;
    uint32_t motion_ch;         /* the main actor whose motion state is followed, its state and horizontal speed */
    uint32_t motion;
    float motion_speed;
    int32_t chain;
    int32_t nmod;               /* collision tracks scaled this update, and their originals */
    uint32_t mod_track[8];
    float mod_val[8][4];
    uint32_t setup_mgr;         /* the unlockables manager our moves were set up in */
    int32_t setup_ok;
    /* (wtrav2) */
    int32_t air_boost;          /* the controlled Hulk is in the air from a jump or wall launch a move of ours scaled */
    float cam_amt;              /* the camera's pull-back, 0..1 (eased) */
    int32_t cam_on;             /* the logic view holds our pulled-back camera (put back before the next update) */
    uint32_t cam_view;
    float cam_base[16], cam_base_fov, cam_mod[16], cam_mod_fov;
    float glow;                 /* the charge glow's strength, 0..1 (eased) */
    float glow_charge;          /* the charge it shows */
    uint32_t glow_ch, glow_ticks;
    int32_t trail_n, trail_head;
    float trail[TRAIL_N][3];    /* the glowing Hulk's positions, newest at trail_head */
    int32_t ring_stage;         /* the charge stage last reached (0..3) and the seconds since its ring */
    float ring_t;
    uint32_t sh_add;            /* the glow's pddi shader (the device's "simple", additive), kept */
} g_tv GAME_STATE;

void hulk_wasm_traversal_apply(int value) {
    g_on = value != 0;
    const char* f = getenv("HULK_TRAV_FORCE");
    if (f && *f) {                              /* C,J[,W,A]: charge, leap, wall fling, air control levels */
        int* lv[4] = {&g_force_charge, &g_force_leap, &g_force_fling, &g_force_air};
        const char* c = f;
        for (int i = 0; i < 4; i++) {
            *lv[i] = c ? atoi(c) : 0;
            if (c) c = strchr(c, ',');
            if (c) c++;
        }
    }
}

void hulk_wasm_traversal_force_charge(int value) { g_dev_charge = value > 0 && value <= 3 ? value : 0; }
void hulk_wasm_traversal_force_leap(int value) { g_dev_leap = value > 0 && value <= 3 ? value : 0; }
void hulk_wasm_traversal_force_moves(int value) { g_dev_moves = value != 0; }
void hulk_wasm_traversal_force_fling(int value) { g_dev_fling = value > 0 && value <= 3 ? value : 0; }
void hulk_wasm_traversal_force_air(int value) { g_dev_air = value > 0 && value <= 3 ? value : 0; }

static uint32_t rd(uint32_t a) { return a ? *(uint32_t*)PTR(a) : 0; }
static float rf(uint32_t a) { return *(float*)PTR(a); }
static void wf(uint32_t a, float v) { *(float*)PTR(a) = v; }

static uint32_t char_of_owner(uint32_t owner) {
    if (!owner) return 0;
    uint32_t ctx = ff_call_this(FN_OWNER_CTX, owner, 0);
    return ctx ? ff_call_this(FN_CTX_CHAR, ctx, 0) : 0;
}
static int controlled(uint32_t ch) { return ch && (int32_t)rd(ch + CH_SLOT) >= 0 && (int32_t)rd(ch + CH_SLOT) < 4; }
static float hspeed(uint32_t ch) {
    float x = rf(ch + CH_VELOCITY), z = rf(ch + CH_VELOCITY + 8);
    return sqrtf(x * x + z * z);
}

/* the original turns its own landing re-jump off in the two precision-landing challenges (c10m24, c10m27: hulk.fig's
 * landing branch carries NOT chapterMission(10, 24) / (10, 27)); the bounce follows it */
static int bounce_allowed(void) {
    uint32_t game = rd(0x004dd6ecu), fm = game ? rd(game + 0x38) : 0;
    if (!fm || rd(fm + 0x80) != 10) return 1;
    uint32_t m = rd(fm + 0x84);
    return m != 24 && m != 27;
}

static uint32_t unlocks(void) {
    uint32_t w = rd(WORLD_PTR), game = w ? rd(w + 0x54) : 0;
    return game ? ff_call_this(FN_UNLOCKS, game, 0) : 0;
}
static int bought(uint32_t mgr, int m) { return mgr && (ff_call_this(FN_IS_ON, mgr, 1, (uint32_t)k_slot[m]) & 0xff); }
static int level_of(int first, int forced) {
    if (forced >= 0) return forced > 3 ? 3 : forced;
    uint32_t mgr = unlocks();
    int l = 0;
    while (l < 3 && bought(mgr, first + l)) l++;
    return l;
}
static int charge_level(void) { return level_of(M_CHARGE1, g_dev_charge ? g_dev_charge : g_force_charge); }
static int leap_level(void) { return level_of(M_LEAP1, g_dev_leap ? g_dev_leap : g_force_leap); }
static int fling_level(void) { return level_of(M_FLING1, g_dev_fling ? g_dev_fling : g_force_fling); }
static int air_level(void) { return level_of(M_AIR1, g_dev_air ? g_dev_air : g_force_air); }

static void end_charge(const char* why) {
    if (g_tv.ch && log_level())
        fprintf(stderr, "hulk: traversal: frame %u: sprint ends (%s), charge %.2f%s\n", SIM->frame, why,
                (double)g_tv.charge, g_tv.coast ? " coasting" : "");
    g_tv.ch = g_tv.act = 0;
    g_tv.charge = 0;
    g_tv.coast = g_tv.stall = g_tv.have_stick = 0;
}

/* ---------------------------------------------------------------------------------------------- the sprint */
void ffgo_00163ed0(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_sprint_begin(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_00163ed0(ecx, edx, st, rb);
    if (!g_on || !(*(uint32_t*)rb & 0xff)) return;
    uint32_t ch = char_of_owner(rd(ecx + 0x20));
    if (!controlled(ch) || !charge_level()) return;
    if (g_tv.ch && g_tv.ch != ch) return;          /* (one charging Hulk at a time) */
    g_tv.ch = ch;
    g_tv.act = ecx;
    g_tv.charge = 0;
    g_tv.coast = g_tv.stall = 0;
    g_tv.hold = 0;
    if (log_level()) fprintf(stderr, "hulk: traversal: frame %u: sprint begins (charge level %d)\n", SIM->frame, charge_level());
}

void ffgo_0015c540(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_sprint_end(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_0015c540(ecx, edx, st, rb);
    if (g_tv.act == ecx) end_charge("node ended");
}

void ffgo_0015e250(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_sprint_frame(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    if (!g_on || ecx != g_tv.act || ARG(0) != 0) {
        ffgo_0015e250(ecx, edx, st, rb);
        return;
    }
    int lvl = charge_level();
    float dt = ARGF(1);
    if (!(dt > 0 && dt < 1)) dt = 0;
    if (g_tv.trig && !g_tv.coast) {
        g_tv.charge += dt / CHARGE_TIME;
        if (g_tv.charge > 1) g_tv.charge = 1;
    }
    g_tv.hold += dt;
    float c = g_tv.charge, top = k_speed_top[lvl];
    float sm = 1 + (top - 1) * c;
    float heavy = 1 - TURN_LOSS * (sm - 1) / (k_speed_top[3] - 1);
    uint32_t cfg = rd(ecx + 0x1c);
    float t18 = rf(cfg + 0x18), t1c = rf(cfg + 0x1c);
    wf(cfg + 0x18, t18 * heavy);
    wf(cfg + 0x1c, t1c * heavy);
    ffgo_0015e250(ecx, edx, st, rb);
    wf(cfg + 0x18, t18);
    wf(cfg + 0x1c, t1c);
    uint32_t drv = rd(ecx + 0x24);
    if (drv) {
        float v = rf(drv + 0x8b0) * sm;
        wf(drv + 0x8b0, v);
        g_tv.speed = v;
    }
    if (g_tv.coast && g_tv.speed > 1) {         /* stopped by a wall: a coast that cannot keep its speed */
        g_tv.stall = hspeed(g_tv.ch) < STALL_FRAC * g_tv.speed ? g_tv.stall + 1 : 0;
        if (g_tv.stall >= STALL_FRAMES) {
            if (log_level()) fprintf(stderr, "hulk: traversal: frame %u: coast stopped by a wall\n", SIM->frame);
            g_tv.coast = 0;
        }
    }
    if (log_level() >= 3)
        fprintf(stderr, "hulk: traversal: frame %u: sprint dt %.4f charge %.3f x%.2f target %.2f speed %.2f trig %d coast %d\n",
                SIM->frame, (double)dt, (double)c, (double)sm, (double)g_tv.speed, (double)hspeed(g_tv.ch), g_tv.trig,
                g_tv.coast);
}

/* the input block, after the original copied the pad into it: whether the trigger is down; while coasting, the trigger
 * shown held and (stick centred) the last stick sample with the intention along the velocity */
void ffgo_000fd0f0(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_ctrl_agent(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_000fd0f0(ecx, edx, st, rb);
    if (!g_on || !g_tv.ch) return;
    uint32_t obj = rd(ecx + 0x58);
    uint32_t ch = obj ? ff_call_this(rd(rd(obj) + 6 * 4), obj, 0) : 0;
    if (ch != g_tv.ch) return;
    uint32_t in = ch + CH_INPUT, b = in + TRIGGER * 12, s = in + IN_STICK;
    uint32_t state = rd(b);
    int down = state == 1 || state == 2;
    float mag = rf(s + 0x10);
    if (down && mag >= 0.5f) {
        memcpy(g_tv.stick, PTR(s), sizeof g_tv.stick);
        g_tv.have_stick = 1;
    }
    if (down) {
        if (g_tv.coast && log_level()) fprintf(stderr, "hulk: traversal: frame %u: trigger again, charging\n", SIM->frame);
        g_tv.coast = 0;
        g_tv.hold = rf(b + 4);
    } else if (g_tv.trig && g_tv.charge >= COAST_MIN && !g_tv.coast) {
        g_tv.coast = 1;
        g_tv.stall = 0;
        if (log_level())
            fprintf(stderr, "hulk: traversal: frame %u: released at charge %.2f, coasting at %.2f\n", SIM->frame,
                    (double)g_tv.charge, (double)g_tv.speed);
    }
    g_tv.trig = down;
    if (!g_tv.coast || down) return;
    *(uint32_t*)PTR(b) = 2;
    wf(b + 4, g_tv.hold);
    wf(b + 8, 1.0f);
    if (mag < 0.25f && g_tv.have_stick) {
        memcpy(PTR(s), g_tv.stick, sizeof g_tv.stick);
        *(uint32_t*)PTR(s) = 2;
        float vx = rf(ch + CH_VELOCITY), vz = rf(ch + CH_VELOCITY + 8), l = sqrtf(vx * vx + vz * vz);
        if (l > 1e-3f) {
            wf(in + IN_INTENT, vx / l);
            wf(in + IN_INTENT + 4, 0);
            wf(in + IN_INTENT + 8, vz / l);
            wf(in + IN_INTENT + 12, 1.0f);
        }
    }
}

/* the collision damage formula (this: a CCollisionAction, +0x1c its owner, +0x20 its track; (k, target, &damage,
 * &force)): Hulk's hits while charged */
void ffgo_00013f20(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_hit_damage(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_00013f20(ecx, edx, st, rb);
    if (!g_on || !g_tv.ch || g_tv.charge <= 0) return;
    if (char_of_owner(rd(ecx + 0x1c)) != g_tv.ch) return;
    int lvl = charge_level();
    float c = g_tv.charge;
    float dm = 1 + (k_damage_top[lvl] - 1) * c, pm = 1 + (k_push_top[lvl] - 1) * c;
    float* dmg = (float*)PTR(ARG(2));
    float* force = (float*)PTR(ARG(3));
    float d0 = *dmg;
    *dmg *= dm;
    if (*force < c) *force = c;
    uint32_t tr = rd(ecx + 0x20);
    int k;
    for (k = 0; k < g_tv.nmod && g_tv.mod_track[k] != tr; k++) {}
    if (tr && k == g_tv.nmod && k < 8) {        /* push-back: small and large targets' distance and height */
        static const uint32_t off[4] = {0xf8, 0x100, 0x110, 0x118};
        g_tv.mod_track[k] = tr;
        for (int i = 0; i < 4; i++) {
            g_tv.mod_val[k][i] = rf(tr + off[i]);
            wf(tr + off[i], g_tv.mod_val[k][i] * (i & 1 ? sqrtf(pm) : pm));
        }
        g_tv.nmod++;
    }
    if (log_level())
        fprintf(stderr, "hulk: traversal: frame %u: charged hit, charge %.2f: damage %.1f -> %.1f, push x%.2f%s\n",
                SIM->frame, (double)c, (double)d0, (double)*dmg, (double)pm, g_tv.coast ? ", coast ends" : "");
    g_tv.coast = 0;
}

/* ---------------------------------------------------------------------------------------------- jumps */
void ffgo_00013b90(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_jump_begin(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_00013b90(ecx, edx, st, rb);
    if (!g_on || !(*(uint32_t*)rb & 0xff)) return;
    uint32_t ch = char_of_owner(rd(ecx + 0x1c));
    if (!controlled(ch)) return;
    int lvl = leap_level();
    float k = 1 + LEAP_STEP * (float)lvl, b = 0;
    float since = g_tv.land_ch == ch ? g_tv.clock - g_tv.land_time : -1;
    if (g_tv.land_ch == ch && since >= 0 && since <= BOUNCE_WINDOW && bounce_allowed()) {
        int cap = 1 + lvl;
        g_tv.chain = g_tv.chain < cap ? g_tv.chain + 1 : cap;
        b = BOUNCE_STEP * (float)g_tv.chain;
    } else {
        g_tv.chain = 0;
    }
    g_tv.land_ch = 0;
    float h = k * (1 + b);
    if (h == 1) {
        if (log_level() >= 2)
            fprintf(stderr, "hulk: traversal: frame %u: jump (%.2f s after landing), up %.2f forward %.2f\n", SIM->frame,
                    (double)since, (double)rf(ecx + 0x28), (double)rf(ecx + 0x2c));
        return;
    }
    float vy = rf(ecx + 0x28), fwd = rf(ecx + 0x2c), g = rf(ecx + 0x30);
    float nf = fwd * h;
    if (b > 0 && nf < CARRY * g_tv.land_speed) nf = CARRY * g_tv.land_speed;
    wf(ecx + 0x28, vy * h);
    wf(ecx + 0x30, g * h);
    wf(ecx + 0x2c, nf);
    g_tv.air_boost = 1;
    if (log_level())
        fprintf(stderr, "hulk: traversal: frame %u: jump x%.2f (leap %d%s chain %d, %.2f s after landing): up %.2f -> %.2f, "
                "forward %.2f -> %.2f\n", SIM->frame, (double)h, lvl, b > 0 ? ", bounce" : "", g_tv.chain, (double)since,
                (double)vy, (double)(vy * h),
                (double)fwd, (double)nf);
}

/* ---------------------------------------------------------------------------------------------- wall fling */
/* WallJumpAction::vfunc_3 0x00140650 (begin; this +0x1c the track, +0x20 the owner, +0x40 "from a wall run" (the
 * character's motion state 4), +0x44 the launch velocity the per-frame 0x00141040 integrates with the track's gravity):
 * off a wall run the launch is flung further: horizontal x k_fling_xz, vertical x k_fling_y, and at least FLING_CARRY of
 * the wall run's speed horizontally (the track's velocityXZMax cap applied before stays below that) */
void ffgo_00140650(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_wall_jump(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    uint32_t ch = g_on ? char_of_owner(rd(ecx + 0x20)) : 0;
    float run[3] = {0, 0, 0};
    if (ch) memcpy(run, PTR(ch + CH_VELOCITY), sizeof run);
    ffgo_00140650(ecx, edx, st, rb);
    if (!ch || !(*(uint32_t*)rb & 0xff) || !controlled(ch) || !*(uint8_t*)PTR(ecx + 0x40)) return;
    int lvl = fling_level();
    if (!lvl) return;
    float vx = rf(ecx + 0x44), vy = rf(ecx + 0x48), vz = rf(ecx + 0x4c);
    float h = sqrtf(vx * vx + vz * vz), rs = sqrtf(run[0] * run[0] + run[1] * run[1] + run[2] * run[2]);
    float nh = h * k_fling_xz[lvl], floor = FLING_CARRY * rs * k_fling_xz[lvl];
    if (nh < floor) nh = floor;
    float k = h > 1e-3f ? nh / h : 1.0f;
    wf(ecx + 0x44, vx * k);
    wf(ecx + 0x4c, vz * k);
    if (vy > 0) wf(ecx + 0x48, vy * k_fling_y[lvl]);
    g_tv.air_boost = 1;
    if (log_level())
        fprintf(stderr, "hulk: traversal: frame %u: wall fling (level %d, wall run %.1f u/s): launch (%.1f, %.1f) -> "
                "(%.1f, %.1f) horizontal, vertical\n", SIM->frame, lvl, (double)rs, (double)h, (double)vy, (double)nh,
                (double)rf(ecx + 0x48));
}

/* WallExitAction::vfunc_3 0x0013f1d0 (begin; +0x20 the owner, +0x40 the launch velocity: the wall run's, turned by the
 * track's up angle and clamped to its velocity range): leaving a wall going up (off the top of a wall run) launches
 * x k_exit */
void ffgo_0013f1d0(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_wall_exit(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_0013f1d0(ecx, edx, st, rb);
    if (!g_on || !(*(uint32_t*)rb & 0xff)) return;
    uint32_t ch = char_of_owner(rd(ecx + 0x20));
    int lvl = controlled(ch) ? fling_level() : 0;
    if (!lvl || !(rf(ecx + 0x44) > 1.0f)) return;
    float v0[3] = {rf(ecx + 0x40), rf(ecx + 0x44), rf(ecx + 0x48)};
    for (int i = 0; i < 3; i++) wf(ecx + 0x40 + 4u * (uint32_t)i, v0[i] * k_exit[lvl]);
    g_tv.air_boost = 1;
    if (log_level())
        fprintf(stderr, "hulk: traversal: frame %u: wall exit flung (level %d): (%.1f, %.1f, %.1f) x%.2f\n", SIM->frame,
                lvl, (double)v0[0], (double)v0[1], (double)v0[2], (double)k_exit[lvl]);
}

/* ---------------------------------------------------------------------------------------------- air control */
/* the character's facing in the world (its scene node's matrix: the z row), (0, 0) when unknown */
static void facing(uint32_t ch, float f[2]) {
    uint32_t node = rd(ch + 0x10), m = node ? rd(node + 0x18) : 0;
    f[0] = m ? rf(m + 0x30) : 0;
    f[1] = m ? rf(m + 0x38) : 0;
}

/* the stick's pull in the air: the intention (world, unit; +0x2070 its magnitude) times the strafe speed; along: the
 * share along `fwd` kept (1) or dropped (0: the jump's own drift moves him along his facing) */
static void air_strafe(uint32_t ch, int lvl, float dt, float fx, float fz, int along) {
    float mag = rf(ch + 0x2070);
    if (!(mag > 0.1f) || !(dt > 0 && dt < 1)) return;
    if (mag > 1) mag = 1;
    float ix = rf(ch + 0x2064), iz = rf(ch + 0x206c), fl = sqrtf(fx * fx + fz * fz);
    if (!along && fl > 1e-3f) {
        fx /= fl, fz /= fl;
        float d = ix * fx + iz * fz;
        ix -= d * fx, iz -= d * fz;
    }
    float s = k_air_strafe[lvl] * mag * dt;
    float v[3] = {ix * s, 0, iz * s};
    ff_call_this(0x000357a0u, ch, 1, (uint32_t)(uintptr_t)v);     /* the character's displacement add */
}

/* CJumpAction::vfunc_7 0x00018d40 (per frame, (dt); +0x1c the owner, +0x20 the CJumpTrack: +0x2c drift, +0x30 / +0x38
 * the turning rates (radians/s) at the low / high forward speed): faster turns and more drift during the call, then a
 * sideways strafe */
void ffgo_00018d40(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_jump_frame(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    uint32_t ch = g_on ? char_of_owner(rd(ecx + 0x1c)) : 0;
    int lvl = controlled(ch) ? air_level() : 0;
    uint32_t tr = rd(ecx + 0x20);
    if (!lvl || !tr) {
        ffgo_00018d40(ecx, edx, st, rb);
        return;
    }
    float d0 = rf(tr + 0x2c), t0 = rf(tr + 0x30), t1 = rf(tr + 0x38);
    wf(tr + 0x2c, d0 * k_air_drift[lvl]);
    wf(tr + 0x30, t0 * k_air_turn[lvl]);
    wf(tr + 0x38, t1 * k_air_turn[lvl]);
    ffgo_00018d40(ecx, edx, st, rb);
    wf(tr + 0x2c, d0);
    wf(tr + 0x30, t0);
    wf(tr + 0x38, t1);
    float f[2];
    facing(ch, f);
    air_strafe(ch, lvl, ARGF(0), f[0], f[1], 0);
}

/* FallAction::vfunc_5 0x00134ee0 (per frame, (event, dt); +0x1c the FallTrack: +0x14 / +0x1c the turning rates; +0x20
 * the owner; +0x28 the fall's velocity): faster turns, then a strafe towards the stick (all of it: a fall has no drift) */
void ffgo_00134ee0(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_fall_frame(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    uint32_t ch = g_on && ARG(0) == 0 ? char_of_owner(rd(ecx + 0x20)) : 0;
    int lvl = controlled(ch) ? air_level() : 0;
    uint32_t tr = rd(ecx + 0x1c);
    if (!lvl || !tr) {
        ffgo_00134ee0(ecx, edx, st, rb);
        return;
    }
    float t0 = rf(tr + 0x14), t1 = rf(tr + 0x1c);
    wf(tr + 0x14, t0 * k_air_turn[lvl]);
    wf(tr + 0x1c, t1 * k_air_turn[lvl]);
    ffgo_00134ee0(ecx, edx, st, rb);
    wf(tr + 0x14, t0);
    wf(tr + 0x1c, t1);
    air_strafe(ch, lvl, ARGF(1), rf(ecx + 0x28), rf(ecx + 0x30), 1);
}

/* ---------------------------------------------------------------------------------------------- the store */
static void dump_moves(uint32_t mgr) {
    for (int i = 0x266; i <= 0x2c9; i++) {
        uint32_t it = rd(mgr + 4u * (uint32_t)i);
        if (!it) continue;
        fprintf(stderr, "hulk: traversal: move 0x%x: locked %u name %08x%08x cost %d on %u needs %d tut %u pic '%.16s'\n", i,
                *(uint8_t*)PTR(it + 8), rd(it + 0x14), rd(it + 0x10), (int32_t)rd(it + 0x24), *(uint8_t*)PTR(it + 0x20),
                (int32_t)rd(it + 0x28), *(uint8_t*)PTR(it + 0x2c), (const char*)PTR(it + 0x48));
    }
    for (int p = 0; p < 100; p++) fprintf(stderr, "%s%d:%x", p ? " " : "hulk: traversal: order ", p, rd(mgr + 0xbf8 + 4u * (uint32_t)p));
    fprintf(stderr, "\n");
}

static const char* const k_keys[N_MOVES][3] = {
    {"TBS_PORT_MV_CHARGE1", "TBS_PORT_MV_CHARGE_COMBO", "TBS_PORT_MV_CHARGE1_DESC"},
    {"TBS_PORT_MV_CHARGE2", "TBS_PORT_MV_CHARGE_COMBO", "TBS_PORT_MV_CHARGE2_DESC"},
    {"TBS_PORT_MV_CHARGE3", "TBS_PORT_MV_CHARGE_COMBO", "TBS_PORT_MV_CHARGE3_DESC"},
    {"TBS_PORT_MV_LEAP1", "TBS_PORT_MV_LEAP_COMBO", "TBS_PORT_MV_LEAP1_DESC"},
    {"TBS_PORT_MV_LEAP2", "TBS_PORT_MV_LEAP_COMBO", "TBS_PORT_MV_LEAP2_DESC"},
    {"TBS_PORT_MV_LEAP3", "TBS_PORT_MV_LEAP_COMBO", "TBS_PORT_MV_LEAP3_DESC"},
    {"TBS_PORT_MV_FLING1", "TBS_PORT_MV_FLING_COMBO", "TBS_PORT_MV_FLING1_DESC"},
    {"TBS_PORT_MV_FLING2", "TBS_PORT_MV_FLING_COMBO", "TBS_PORT_MV_FLING2_DESC"},
    {"TBS_PORT_MV_FLING3", "TBS_PORT_MV_FLING_COMBO", "TBS_PORT_MV_FLING3_DESC"},
    {"TBS_PORT_MV_AIR1", "TBS_PORT_MV_AIR_COMBO", "TBS_PORT_MV_AIR1_DESC"},
    {"TBS_PORT_MV_AIR2", "TBS_PORT_MV_AIR_COMBO", "TBS_PORT_MV_AIR2_DESC"},
    {"TBS_PORT_MV_AIR3", "TBS_PORT_MV_AIR_COMBO", "TBS_PORT_MV_AIR3_DESC"},
};

/* Our moves in the manager: set up once per manager whose shipped moves are (init.lua ran: the first move has a
 * name), then kept listed (unlocked, +8) and placed in the store's order every update (below). */
#define FN_STATS 0x00086370u            /* CGame -> its stats (the smash points are "xp") */
#define FN_ADD_XP 0x000900a0u
#define FN_STRINGS 0x000fc1b0u          /* the front end's string table */
#define FN_STRING_ID 0x000f7240u        /* (64-bit name key) -> string id, -1 when missing */
static void store_setup(void) {
    uint32_t mgr = unlocks();
    if (!mgr) return;
    if (mgr != g_tv.setup_mgr) {
        uint32_t first = rd(mgr + 4u * 0x266);
        if (!first || !(rd(first + 0x10) | rd(first + 0x14))) return;
        g_tv.setup_mgr = mgr;
        g_tv.setup_ok = 0;
        if (log_level() >= 2) dump_moves(mgr);
        for (int m = 0; m < N_MOVES; m++) {      /* (spare: no move set up there) */
            uint32_t it = rd(mgr + 4u * (uint32_t)k_slot[m]);
            if (!it || rd(it + 0x10) | rd(it + 0x14)) {
                fprintf(stderr, "hulk: traversal: move slot 0x%x is not spare; no remaster moves in the store\n", k_slot[m]);
                return;
            }
        }
        static char pic[N_MOVES][0x41];
        for (int m = 0; m < N_MOVES; m++) {
            int idx = k_slot[m];
            uint32_t src = rd(mgr + 4u * (uint32_t)k_picture_from[m]);
            if (src) memcpy(pic[m], PTR(src + 0x48), 0x40);
            ff_call_this(FN_SETUP_MOVE, mgr, 6, (uint32_t)idx, (uint32_t)(uintptr_t)k_keys[m][0],
                         (uint32_t)(uintptr_t)k_keys[m][1], (uint32_t)(uintptr_t)k_keys[m][2],
                         (uint32_t)(uintptr_t)pic[m], (uint32_t)k_cost[m]);
            if (m % 3) ff_call_this(FN_DEPENDENCY, mgr, 2, (uint32_t)idx, (uint32_t)k_slot[m - 1]);   /* (level n needs n-1) */
        }
        g_tv.setup_ok = 1;
        const char* xp = getenv("HULK_TRAV_TEST_XP");    /* (tests: smash points to buy with, once a manager) */
        uint32_t w = rd(WORLD_PTR), game = w ? rd(w + 0x54) : 0, stats = game ? ff_call_this(FN_STATS, game, 0) : 0;
        if (xp && *xp && stats) ff_call_this(FN_ADD_XP, stats, 1, (uint32_t)atoi(xp));
        if (log_level()) {
            uint32_t strings = ff_call(FN_STRINGS, 0);
            uint32_t it = rd(mgr + 4u * (uint32_t)k_slot[0]);
            int sid = strings && it ? (int32_t)ff_call_this(FN_STRING_ID, strings, 2, rd(it + 0x10), rd(it + 0x14)) : -2;
            fprintf(stderr, "hulk: traversal: frame %u: %d moves set up (slots 0x%x..0x%x; name string %d)\n",
                    SIM->frame, N_MOVES, FIRST_OURS, k_slot[M_CHARGE3 + 3], sid);
        }
    }
    if (!g_tv.setup_ok) return;
    /* the store's rows are its order positions from 0 (the detail screen 0x000c2c20 takes row n as position n), and
     * init.lua gives a shipped move the next position when the story unlocks it, so the shown moves are always a prefix:
     * ours go right after it, and move on when a newly unlocked shipped move takes one of their positions */
    uint32_t ord = mgr + 0xbf8;
    int start = 0;
    while (start < 100) {
        uint32_t v = rd(ord + 4u * (uint32_t)start);
        if (v == 0xffffffffu || ours(v) >= 0) break;
        start++;
    }
    if (start > 100 - N_MOVES) start = 100 - N_MOVES;
    for (int p = 0; p < 100; p++) {             /* ours anywhere else: taken out */
        uint32_t v = rd(ord + 4u * (uint32_t)p);
        if (ours(v) >= 0 && (p < start || p >= start + N_MOVES || ours(v) != p - start))
            *(uint32_t*)PTR(ord + 4u * (uint32_t)p) = 0xffffffffu;
    }
    for (int m = 0; m < N_MOVES; m++) {
        uint32_t idx = (uint32_t)k_slot[m], pos = (uint32_t)(start + m);
        if (rd(ord + 4 * pos) != idx) {
            ff_call_this(FN_FE_ORDER, mgr, 3, idx, pos, 0u);
            if (log_level()) fprintf(stderr, "hulk: traversal: frame %u: move 0x%x at store position %u\n", SIM->frame, idx, pos);
        }
        uint32_t it = rd(mgr + 4 * idx);
        if (it && *(uint8_t*)PTR(it + 8)) *(uint8_t*)PTR(it + 8) = 0;      /* unlocked: listed */
    }
    if (log_level() >= 2 && SIM->frame % 3000 == 0) dump_moves(mgr);
}

/* the store's list (UnlockMenu 0x000c21b0, (unlockable index)): CFEManager's refresh of the computer interface calls
 * it before the Buy Menu shows, also in the front end before any update ran (Continue Game), so our moves are set up
 * there too */
void ffgo_000c21b0(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_store_list(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    if (g_on) store_setup();
    ffgo_000c21b0(ecx, edx, st, rb);
}

/* every update (tutorial_skip.c's UpdateSimulation hook, after the original): the clock, the scaled tracks put back,
 * the store */
static void update_moves(int kind, float dt) {
    for (int k = 0; k < g_tv.nmod; k++) {
        static const uint32_t off[4] = {0xf8, 0x100, 0x110, 0x118};
        for (int i = 0; i < 4; i++) wf(g_tv.mod_track[k] + off[i], g_tv.mod_val[k][i]);
    }
    g_tv.nmod = 0;
    if (!g_on) {                                 /* turned off in this session: ours leave the store again */
        uint32_t mgr = g_tv.setup_ok ? unlocks() : 0;
        if (mgr && mgr == g_tv.setup_mgr) {
            for (int m = 0; m < N_MOVES; m++) {
                uint32_t it = rd(mgr + 4u * (uint32_t)k_slot[m]);
                if (it) *(uint8_t*)PTR(it + 8) = 1;
            }
            for (int p = 0; p < 100; p++) {
                uint32_t a = mgr + 0xbf8 + 4u * (uint32_t)p, v = rd(a);
                if (ours(v) >= 0) *(uint32_t*)PTR(a) = 0xffffffffu;
            }
        }
        return;
    }
    if (kind == 6 || kind == 7) return;
    if (dt > 0 && dt < 1) g_tv.clock += dt;
    store_setup();
    /* landings: the main actor's motion state (+0x140: 0 none, 1 standing, 2 prone, 3 air, 4 climbing) leaving air */
    uint32_t w = rd(WORLD_PTR), am = w ? rd(w + 0x20) : 0, ch = am ? rd(am + 0x124) : 0;
    if (!controlled(ch)) {
        g_tv.motion_ch = 0;
        return;
    }
    uint32_t m = rd(ch + CH_MOTION);
    if (ch == g_tv.motion_ch && m != g_tv.motion) {
        if (g_tv.motion == MOTION_AIR && m != MOTION_AIR) {
            g_tv.air_boost = 0;
            g_tv.land_ch = ch;
            g_tv.land_time = g_tv.clock;
            g_tv.land_speed = g_tv.motion_speed;
        }
        if (log_level() >= 2) {
            float p[3] = {0, 0, 0};
            uint32_t node = rd(ch + 0x10);
            if (node) ff_call_this(0x00059a50u, node, 1, (uint32_t)(uintptr_t)p);
            fprintf(stderr, "hulk: traversal: frame %u: motion %u -> %u at %.2f units/s, at (%.1f, %.1f, %.1f)\n",
                    SIM->frame, g_tv.motion, m, (double)g_tv.motion_speed, (double)p[0], (double)p[1], (double)p[2]);
        }
    }
    g_tv.motion_ch = ch;
    g_tv.motion = m;
    g_tv.motion_speed = hspeed(ch);
}

/* ---------------------------------------------------------------------------------------------- the camera at speed */
/* The logic view (0x004e231c: the camera-to-world matrix at +0x1c, rows right / up / forward / position, the field of
 * view at +0x5c, a "derived values stale" flag at +0x6c that 0 asks to recompute) is what World::Render draws and culls
 * with; CCameraManager (0x0009bb50, near the end of UpdateSimulation) copies the game camera into it every update. After
 * the update, with a traversal move under way, it is pulled back along the view, lifted and widened by an eased amount
 * that follows the Hulk's speed; before the next update (hulk_wasm_traversal_pre_update) the original values are put
 * back, so the simulation (the audio listener the update fed, ambient despawn, object streaming, the scripts) sees the
 * game's camera and only the picture moves. */
#define VIEW_PTR 0x004e231cu
#define LV_MATRIX 0x1c
#define LV_FOV 0x5c
#define LV_STALE 0x6c

void hulk_wasm_traversal_pre_update(void) {
    if (!g_tv.cam_on) return;
    g_tv.cam_on = 0;
    uint32_t v = rd(VIEW_PTR);
    if (!v || v != g_tv.cam_view || memcmp(PTR(v + LV_MATRIX), g_tv.cam_mod, 64) || rf(v + LV_FOV) != g_tv.cam_mod_fov)
        return;                                 /* (the game wrote it since: nothing of ours left to put back) */
    memcpy(PTR(v + LV_MATRIX), g_tv.cam_base, 64);
    wf(v + LV_FOV, g_tv.cam_base_fov);
    *(uint8_t*)PTR(v + LV_STALE) = 0;
}

/* in play: the game camera (the camera manager's flags, none of 0x5e) and no letterbox (tutorial_skip.c's test) */
static int game_camera(uint32_t view) {
    uint32_t w = rd(WORLD_PTR), cmgr = w ? rd(w + 8) : 0, lb = view ? rd(view + 0x14) : 0;
    int letterbox = lb && rf(lb + 0x28) != rf(0x003f32e0u) && rf(lb + 0x18) != rf(0x003f32e0u);
    return cmgr && (rd(cmgr + 4) & 0x5e) == 0 && !letterbox;
}

static void camera_update(int advance, float dt, uint32_t ch) {
    uint32_t view = rd(VIEW_PTR);
    if (advance) {
        float target = 0;
        if (g_on && controlled(ch) && view && game_camera(view) &&
            ((g_tv.ch == ch && (g_tv.charge > 0 || g_tv.coast)) || g_tv.air_boost)) {
            float vx = rf(ch + CH_VELOCITY), vy = rf(ch + CH_VELOCITY + 4), vz = rf(ch + CH_VELOCITY + 8);
            float sp = sqrtf(vx * vx + vy * vy + vz * vz);
            target = (sp - CAM_SPEED0) / (CAM_SPEED1 - CAM_SPEED0);
            target = target < 0 ? 0 : target > 1 ? 1 : target;
        }
        if (!(dt > 0 && dt < 1)) dt = 0;
        if (g_tv.cam_amt < target) {
            g_tv.cam_amt += dt / CAM_RISE;
            if (g_tv.cam_amt > target) g_tv.cam_amt = target;
        } else if (g_tv.cam_amt > target) {
            g_tv.cam_amt -= dt / CAM_FALL;
            if (g_tv.cam_amt < target) g_tv.cam_amt = target;
        }
    }
    static int knob = -1;                       /* HULK_TRAV_CAM=0 (tests): no pull-back, to compare pictures */
    if (knob < 0) knob = !getenv("HULK_TRAV_CAM") || atoi(getenv("HULK_TRAV_CAM")) != 0;
    if (!g_on || !knob || !(g_tv.cam_amt > 1e-4f) || !view || !game_camera(view)) return;
    float a = g_tv.cam_amt, e = a * a * (3 - 2 * a);       /* (smoothstep) */
    memcpy(g_tv.cam_base, PTR(view + LV_MATRIX), 64);
    g_tv.cam_base_fov = rf(view + LV_FOV);
    float* m = (float*)PTR(view + LV_MATRIX);
    float fx = m[8], fy = m[9], fz = m[10], fl = sqrtf(fx * fx + fy * fy + fz * fz);
    if (!(fl > 1e-3f) || !(g_tv.cam_base_fov > 0.1f && g_tv.cam_base_fov < 2.6f)) return;
    m[12] -= fx / fl * CAM_PULL * e;
    m[13] -= fy / fl * CAM_PULL * e - CAM_LIFT * e;
    m[14] -= fz / fl * CAM_PULL * e;
    wf(view + LV_FOV, g_tv.cam_base_fov * (1 + CAM_WIDEN * e));
    *(uint8_t*)PTR(view + LV_STALE) = 0;
    memcpy(g_tv.cam_mod, m, 64);
    g_tv.cam_mod_fov = rf(view + LV_FOV);
    g_tv.cam_view = view;
    g_tv.cam_on = 1;
    if (log_level() >= 3 && advance)
        fprintf(stderr, "hulk: traversal: frame %u: camera pull-back %.2f (fov %.3f -> %.3f)\n", SIM->frame, (double)a,
                (double)g_tv.cam_base_fov, (double)g_tv.cam_mod_fov);
}

/* ---------------------------------------------------------------------------------------------- the charge glow */
/* The charge-sprint glow: while the sprint charges (and while it coasts on the charge) ember ribbons trail from the
 * Hulk's feet along the path he ran, longer, hotter and faster-pulsing with the charge (white-hot at his heels, orange,
 * fading to red), with fainter ones from the hips past half charge; each charge stage (a third, two thirds, full) sends
 * a ring of heat out along the ground. It is the opposite of the game's jump charge in every way that shows when both
 * are on: that one is a pale green-white aura on the body and gold shafts below him at take-off; this one is warm,
 * horizontal, low and behind him. The state (positions, strength, the stage ring) is kept here per update from game
 * state alone (hulk_game_state); the drawing (hulk_wasm_traversal_draw, after World::Render) reads it, through the
 * game's own pddi context as tutorial_skip.c's star does. */
static int actor_pos(uint32_t ch, float out[3]) {
    uint32_t node = rd(ch + 0x10);
    uint32_t p[3] = {0, 0, 0};
    if (!node || !(ff_call_this(0x00059a50u, node, 1, (uint32_t)(uintptr_t)p) & 0xff)) return 0;
    memcpy(out, p, sizeof p);
    return 1;
}

static void glow_update(float dt) {
    if (!(dt > 0 && dt < 1)) dt = 0;
    uint32_t ch = g_tv.ch ? g_tv.ch : g_tv.glow_ch;
    float target = g_on && g_tv.ch && controlled(g_tv.ch) && g_tv.charge >= GLOW_START ? g_tv.charge : 0;
    if (target > 0) g_tv.glow_charge = target;
    if (g_tv.glow < (target > 0 ? 1.0f : 0.0f)) {
        g_tv.glow += dt / GLOW_RISE;
        if (g_tv.glow > 1) g_tv.glow = 1;
    } else if (target <= 0) {
        g_tv.glow -= dt / GLOW_FALL;
        if (g_tv.glow < 0) g_tv.glow = 0;
    }
    int stage = target >= 1.0f ? 3 : target >= 0.6667f ? 2 : target >= 0.3333f ? 1 : 0;
    if (stage > g_tv.ring_stage) g_tv.ring_t = 0;
    g_tv.ring_stage = target > 0 ? stage : 0;
    g_tv.ring_t += dt;
    g_tv.glow_ticks++;
    float p[3];
    if (!(g_tv.glow > 0) || !ch || !actor_pos(ch, p)) {
        g_tv.trail_n = 0;
        if (!(g_tv.glow > 0)) g_tv.glow_ch = 0;
        return;
    }
    if (ch != g_tv.glow_ch) g_tv.trail_n = 0;
    g_tv.glow_ch = ch;
    if (g_tv.trail_n) {                         /* (standing still: one point) */
        float* q = g_tv.trail[g_tv.trail_head];
        float dx = p[0] - q[0], dy = p[1] - q[1], dz = p[2] - q[2];
        if (dx * dx + dy * dy + dz * dz < 0.0025f) return;
        if (dx * dx + dy * dy + dz * dz > 400.0f) g_tv.trail_n = 0;     /* (a teleport) */
    }
    g_tv.trail_head = (g_tv.trail_head + 1) % TRAIL_N;
    memcpy(g_tv.trail[g_tv.trail_head], p, sizeof p);
    if (g_tv.trail_n < TRAIL_N) g_tv.trail_n++;
}

void hulk_wasm_traversal_update(int kind, float dt) {
    update_moves(kind, dt);
    int advance = kind != 6 && kind != 7;
    uint32_t w = rd(WORLD_PTR), am = w ? rd(w + 0x20) : 0, ch = am ? rd(am + 0x124) : 0;
    camera_update(advance, dt, ch);
    if (advance) glow_update(dt);
}

/* drawing: tutorial_skip.c's pddi use (the device's "simple" shader, one-colour prim streams, z write off) */
#define DEVICE_PTR 0x0052c2a0u         /* pure3d's pddi device */
#define CONTEXT_PTR 0x0052c2a8u        /* pure3d's pddi context */
#define FN_VERTEX 0x0008ef00u          /* the prim stream's next vertex */
#define FN_CAM_POS 0x001c1300u         /* the render context's camera position */
static uint32_t vslot(uint32_t obj, int i) { return rd(rd(obj) + 4u * (uint32_t)i); }
static uint32_t K4(const char* s) {
    return (uint32_t)(uint8_t)s[0] | (uint32_t)(uint8_t)s[1] << 8 | (uint32_t)(uint8_t)s[2] << 16 |
           (s[2] ? (uint32_t)(uint8_t)s[3] << 24 : 0u);
}
static uint32_t make_shader(int blend) {
    static const char simple[] = "simple";
    uint32_t dev = rd(DEVICE_PTR);
    if (!dev) return 0;
    uint32_t sh = ff_call_this(vslot(dev, 11), dev, 2, (uint32_t)(uintptr_t)simple, 0u);
    if (!sh) return 0;
    ff_call_this(vslot(sh, 0), sh, 0);                       /* AddRef: kept */
    ff_call_this(vslot(sh, 6), sh, 2, K4("BLMD"), (uint32_t)blend);
    ff_call_this(vslot(sh, 6), sh, 2, K4("LIT"), 0u);
    ff_call_this(vslot(sh, 6), sh, 2, K4("2SID"), 1u);
    return sh;
}
typedef struct { float p[3]; uint32_t c; } tvert;
static void draw_tris(uint32_t ctx, uint32_t shader, const tvert* v, int n) {
    for (int at = 0; at + 3 <= n; at += 240) {      /* (streams of at most 80 triangles) */
        int k = n - at < 240 ? n - at : 240;
        uint32_t s = ff_call_this(vslot(ctx, 30), ctx, 5, shader, 0u, 0x20u, (uint32_t)k, 0u);
        if (!s) return;
        for (int i = at; i < at + k; i++) {
            memcpy(PTR(rd(s + 8)), v[i].p, 12);
            *(uint32_t*)PTR(rd(s + 0x10)) = v[i].c;
            ff_call_this(FN_VERTEX, s, 0);
        }
        ff_call_this(vslot(ctx, 31), ctx, 1, s);
    }
}
/* an added colour at strength k (the additive blend takes the colour; alpha follows for the blend modes that use it) */
static uint32_t hot(float k, float r, float g, float b) {
    #define B8(x) ((uint32_t)((x) <= 0 ? 0 : (x) >= 1 ? 255 : (int)((x) * 255.0f + 0.5f)))
    return B8(k) << 24 | B8(r * k) << 16 | B8(g * k) << 8 | B8(b * k);
    #undef B8
}
/* the ember colour along a ribbon: t 0 at the Hulk (white-hot) to 1 at the tail (deep red) */
static void ember(float t, float c[3]) {
    static const float k[3][3] = {{1.0f, 0.78f, 0.5f}, {1.0f, 0.3f, 0.04f}, {0.6f, 0.02f, 0.0f}};
    int i = t < 0.5f ? 0 : 1;
    float u = t < 0.5f ? t * 2 : (t - 0.5f) * 2;
    for (int j = 0; j < 3; j++) c[j] = k[i][j] + (k[i + 1][j] - k[i][j]) * u;
}

enum { RIB_MAX = TRAIL_N + 2, RING_SEG = 28, DISC_SEG = 16 };
/* a soft disc facing the camera (centre colour cc fading to nothing at radius r) */
static int disc(tvert* out, const float o[3], const float cam[3], float r, uint32_t cc) {
    float f[3] = {cam[0] - o[0], cam[1] - o[1], cam[2] - o[2]};
    float fl = sqrtf(f[0] * f[0] + f[1] * f[1] + f[2] * f[2]);
    if (fl < 1e-3f) return 0;
    f[0] /= fl, f[1] /= fl, f[2] /= fl;
    float ux[3] = {f[2], 0, -f[0]}, ul = sqrtf(ux[0] * ux[0] + ux[2] * ux[2]);
    if (ul < 1e-3f) ux[0] = 1, ux[2] = 0, ul = 1;
    ux[0] /= ul, ux[2] /= ul;
    float uy[3] = {f[1] * ux[2], f[2] * ux[0] - f[0] * ux[2], -f[1] * ux[0]};
    float c[3] = {o[0] + f[0] * 0.4f, o[1] + f[1] * 0.4f, o[2] + f[2] * 0.4f};     /* (in front of his legs) */
    uint32_t none = 0;
    int m = 0;
    for (int i = 0; i < DISC_SEG; i++) {
        float a0 = 6.2831853f * (float)i / DISC_SEG, a1 = 6.2831853f * (float)(i + 1) / DISC_SEG;
        float c0 = cosf(a0) * r, s0 = sinf(a0) * r, c1 = cosf(a1) * r, s1 = sinf(a1) * r;
        out[m++] = (tvert){{c[0], c[1], c[2]}, cc};
        out[m++] = (tvert){{c[0] + ux[0] * c0 + uy[0] * s0, c[1] + uy[1] * s0, c[2] + ux[2] * c0 + uy[2] * s0}, none};
        out[m++] = (tvert){{c[0] + ux[0] * c1 + uy[0] * s1, c[1] + uy[1] * s1, c[2] + ux[2] * c1 + uy[2] * s1}, none};
    }
    return m;
}
/* one ribbon facing the camera along the trail points pts[0..n-1] (pts[0] at the Hulk), each lifted by `h` and moved
 * sideways by `side` (left of the path for side > 0); width w0 at the Hulk to w1 at the tail; strength k */
static int ribbon(tvert* out, float (*pts)[3], const float (*dir)[2], const float* along, int n, float total,
                  const float cam[3], float h, float side, float w0, float w1, float k) {
    float c[RIB_MAX][3];
    for (int i = 0; i < n; i++) {
        c[i][0] = pts[i][0] - dir[i][1] * side;      /* (left of the travel direction (x, z): (-z, x)) */
        c[i][1] = pts[i][1] + h;
        c[i][2] = pts[i][2] + dir[i][0] * side;
    }
    int m = 0;
    float prev[2][3];
    uint32_t pc = 0;
    for (int i = 0; i < n; i++) {
        float tx = i + 1 < n ? c[i][0] - c[i + 1][0] : c[i - 1][0] - c[i][0];
        float ty = i + 1 < n ? c[i][1] - c[i + 1][1] : c[i - 1][1] - c[i][1];
        float tz = i + 1 < n ? c[i][2] - c[i + 1][2] : c[i - 1][2] - c[i][2];
        float vx = cam[0] - c[i][0], vy = cam[1] - c[i][1], vz = cam[2] - c[i][2];
        float nx = ty * vz - tz * vy, ny = tz * vx - tx * vz, nz = tx * vy - ty * vx;
        float nl = sqrtf(nx * nx + ny * ny + nz * nz);
        if (nl < 1e-5f) nx = 0, ny = 1, nz = 0, nl = 1;
        float t = total > 0 ? along[i] / total : 0;
        float w = 0.5f * (w0 + (w1 - w0) * t) / nl;
        float col[3];
        ember(t, col);
        float fade = (1 - t) * (1 - t);
        uint32_t cc = hot(k * (0.35f + 0.65f * fade) * (i == n - 1 ? 0 : 1), col[0], col[1], col[2]);
        float e[2][3] = {{c[i][0] + nx * w, c[i][1] + ny * w, c[i][2] + nz * w},
                         {c[i][0] - nx * w, c[i][1] - ny * w, c[i][2] - nz * w}};
        if (i) {
            out[m++] = (tvert){{prev[0][0], prev[0][1], prev[0][2]}, pc};
            out[m++] = (tvert){{prev[1][0], prev[1][1], prev[1][2]}, pc};
            out[m++] = (tvert){{e[1][0], e[1][1], e[1][2]}, cc};
            out[m++] = (tvert){{prev[0][0], prev[0][1], prev[0][2]}, pc};
            out[m++] = (tvert){{e[1][0], e[1][1], e[1][2]}, cc};
            out[m++] = (tvert){{e[0][0], e[0][1], e[0][2]}, cc};
        }
        memcpy(prev, e, sizeof prev);
        pc = cc;
    }
    return m;
}

void hulk_wasm_traversal_draw(uint32_t rctx) {
    static int knob = -1;                       /* HULK_TRAV_GLOW=0 (tests): no glow drawn */
    if (knob < 0) knob = !getenv("HULK_TRAV_GLOW") || atoi(getenv("HULK_TRAV_GLOW")) != 0;
    if (!g_on || !knob || !(g_tv.glow > 0.01f) || g_tv.trail_n < 1 || !g_tv.glow_ch) return;
    uint32_t ctx = rd(CONTEXT_PTR);
    if (!ctx) return;
    if (!g_tv.sh_add) g_tv.sh_add = make_shader(2);
    if (!g_tv.sh_add) return;
    float cam[3] = {0, 0, 0};
    uint32_t cp = rctx ? ff_call_this(FN_CAM_POS, rctx, 0) : 0;
    if (!cp) return;
    cam[0] = rf(cp), cam[1] = rf(cp + 4), cam[2] = rf(cp + 8);

    float c = g_tv.glow_charge, g = g_tv.glow, t = (float)g_tv.glow_ticks / 30.0f;
    float pulse = 0.78f + 0.22f * sinf(t * (7.0f + 11.0f * c));     /* (faster as the charge builds) */
    float len = 2.5f + 7.5f * c;                                   /* the trail's length, units */
    /* the trail: newest first, cut at len; the travel direction at each point */
    float pts[RIB_MAX][3], dir[RIB_MAX][2], along[RIB_MAX];
    int n = 0;
    float total = 0;
    for (int i = 0; i < g_tv.trail_n && n < RIB_MAX - 1; i++) {
        const float* q = g_tv.trail[(g_tv.trail_head - i + TRAIL_N) % TRAIL_N];
        if (n) {
            float dx = q[0] - pts[n - 1][0], dy = q[1] - pts[n - 1][1], dz = q[2] - pts[n - 1][2];
            float d = sqrtf(dx * dx + dy * dy + dz * dz);
            if (total + d > len) {                  /* (the last piece cut to length) */
                float u = (len - total) / d;
                pts[n][0] = pts[n - 1][0] + dx * u, pts[n][1] = pts[n - 1][1] + dy * u, pts[n][2] = pts[n - 1][2] + dz * u;
                along[n++] = total = len;
                break;
            }
            total += d;
        }
        memcpy(pts[n], q, sizeof pts[n]);
        along[n++] = total;
    }
    if (n < 2) {                                    /* (just started: a short stub behind his facing) */
        float f[2];
        facing(g_tv.glow_ch, f);
        float fl = sqrtf(f[0] * f[0] + f[1] * f[1]);
        if (fl < 1e-3f) return;
        pts[1][0] = pts[0][0] - f[0] / fl * 1.0f, pts[1][1] = pts[0][1], pts[1][2] = pts[0][2] - f[1] / fl * 1.0f;
        along[1] = total = 1.0f;
        n = 2;
    }
    for (int i = 0; i < n; i++) {
        int a = i ? i - 1 : 0, b = i ? i : 1;      /* (from the older point to the newer) */
        float dx = pts[a][0] - pts[b][0], dz = pts[a][2] - pts[b][2], dl = sqrtf(dx * dx + dz * dz);
        dir[i][0] = dl > 1e-4f ? dx / dl : 0;
        dir[i][1] = dl > 1e-4f ? dz / dl : 1;
    }
    static tvert v[4 * 6 * RIB_MAX + 6 * 2 * RING_SEG + 2 * 3 * DISC_SEG];
    int m = 0;
    float k = g * pulse * (0.45f + 0.55f * c);
    m += ribbon(v + m, pts, (const float (*)[2])dir, along, n, total, cam, 0.30f, 0.42f, 0.5f, 0.08f, k);
    m += ribbon(v + m, pts, (const float (*)[2])dir, along, n, total, cam, 0.30f, -0.42f, 0.5f, 0.08f, k);
    for (int side = -1; side <= 1; side += 2) {     /* the heels: a pulsing ember bloom on each foot */
        float o[3] = {pts[0][0] - dir[0][1] * 0.42f * (float)side, pts[0][1] + 0.35f, pts[0][2] + dir[0][0] * 0.42f * (float)side};
        m += disc(v + m, o, cam, 0.6f + 0.6f * c * pulse, hot(k, 1.0f, 0.42f, 0.1f));
    }
    if (c > 0.5f) {                                 /* the hips' fainter pair, past half charge */
        float kh = k * (c - 0.5f) * 1.2f;
        m += ribbon(v + m, pts, (const float (*)[2])dir, along, n, total * 0.8f, cam, 1.45f, 0.62f, 0.18f, 0.04f, kh);
        m += ribbon(v + m, pts, (const float (*)[2])dir, along, n, total * 0.8f, cam, 1.45f, -0.62f, 0.18f, 0.04f, kh);
    }
    /* the stage ring: out from the feet over 0.45 s, fading */
    float rt = g_tv.ring_t / 0.45f;
    if (g_tv.ring_stage > 0 && rt < 1) {
        float r = 0.8f + 3.2f * rt, kr = g * (1 - rt) * (0.5f + 0.25f * (float)g_tv.ring_stage), w = 0.35f;
        float y = pts[0][1] + 0.08f;
        uint32_t mid = hot(kr, 1.0f, 0.55f, 0.12f), none = hot(0, 0, 0, 0);
        for (int i = 0; i < RING_SEG; i++) {
            float a0 = 6.2831853f * (float)i / RING_SEG, a1 = 6.2831853f * (float)(i + 1) / RING_SEG;
            float c0 = cosf(a0), s0 = sinf(a0), c1 = cosf(a1), s1 = sinf(a1);
            for (int band = 0; band < 2; band++) {      /* (inner edge to the bright middle, the middle to the outer) */
                float ri = band ? r : r - w, ro = band ? r + w : r;
                uint32_t ci = band ? mid : none, co = band ? none : mid;
                tvert q[4] = {{{pts[0][0] + c0 * ri, y, pts[0][2] + s0 * ri}, ci}, {{pts[0][0] + c1 * ri, y, pts[0][2] + s1 * ri}, ci},
                              {{pts[0][0] + c1 * ro, y, pts[0][2] + s1 * ro}, co}, {{pts[0][0] + c0 * ro, y, pts[0][2] + s0 * ro}, co}};
                v[m++] = q[0], v[m++] = q[1], v[m++] = q[2];
                v[m++] = q[0], v[m++] = q[2], v[m++] = q[3];
            }
        }
    }
    uint32_t zw = ff_call_this(vslot(ctx, 63), ctx, 0) & 0xff;
    ff_call_this(vslot(ctx, 62), ctx, 1, 0u);
    draw_tris(ctx, g_tv.sh_add, v, m);
    ff_call_this(vslot(ctx, 62), ctx, 1, zw);
}

/* ---------------------------------------------------------------------------------------------- developer forces */
/* Force Original Moves (wdev1): a shipped store move: an index of the moves' range below ours, set up (a name key) and a
 * CUnlockableMove (dynamic_cast 0x00344e74 CUnlockable 0x0049dab8 -> CUnlockableMove 0x0049db1c, as the readers do) */
#define FIRST_MOVE 0x266
static int forced_move(uint32_t mgr, uint32_t index) {
    static int from = -1;               /* HULK_DEV_TEST_FROM=N (tests): no force before frame N (a replay stays in step) */
    if (from < 0) from = getenv("HULK_DEV_TEST_FROM") ? atoi(getenv("HULK_DEV_TEST_FROM")) : 0;
    if (!g_dev_moves || !mgr || index < FIRST_MOVE || index >= FIRST_OURS || SIM->frame < (uint32_t)from) return 0;
    uint32_t it = rd(mgr + 4u * index);
    if (!it || !(rd(it + 0x10) | rd(it + 0x14))) return 0;
    return ff_call(0x00344e74u, 5, it, 0, 0x0049dab8u, 0x0049db1cu, 0) != 0;
}

/* the fight script's `unlockable` condition (this +0xc the index, +0x10 the locked value it wants; true when the move's
 * locked byte is that and its purchase the opposite): a forced move is unlocked and bought */
void ffgo_0012f110(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_unlock_cond(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    uint32_t id = rd(ecx + 0xc);
    if (g_dev_moves && forced_move(unlocks(), id)) {
        int want = *(uint8_t*)PTR(ecx + 0x10) == 0;
        if (log_level()) {                       /* (the first time a forced answer differs from the real one, per move) */
            static uint8_t seen[FIRST_OURS - FIRST_MOVE];
            ffgo_0012f110(ecx, edx, st, rb);
            int real = *(uint8_t*)rb != 0;
            if (real != want && !seen[id - FIRST_MOVE]) {
                seen[id - FIRST_MOVE] = 1;
                fprintf(stderr, "hulk: traversal: frame %u: forced move 0x%x: unlockable condition %d (real %d)\n",
                        SIM->frame, id, want, real);
            }
        }
        RET(want);
        return;
    }
    ffgo_0012f110(ecx, edx, st, rb);
}

/* the manager's on/purchased read (index): a forced move reads bought, except for the save's capture */
void ffgo_00092940(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_unlock_on(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    if (g_dev_moves && !g_saving && forced_move(ecx, ARG(0))) {
        static uint8_t seen[FIRST_OURS - FIRST_MOVE];
        uint32_t id = ARG(0);
        if (log_level() && !seen[id - FIRST_MOVE] && !*(uint8_t*)PTR(rd(ecx + 4 * id) + 0x20)) {
            seen[id - FIRST_MOVE] = 1;
            fprintf(stderr, "hulk: traversal: frame %u: forced move 0x%x: purchase read 1 (real 0)\n", SIM->frame, id);
        }
        RET(1);
        return;
    }
    ffgo_00092940(ecx, edx, st, rb);
}

/* the save's capture (CGameFlowManager: the slot record from the managers, then written, (a1, slot, game)): the real
 * bits. With the forces on, the record's purchase bits (+0xb8, one per index) are checked against the moves' own
 * purchase bytes (+0x20) afterwards (HULK_TRAV_LOG=1). */
void ffgo_0008b560(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_save_capture(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    uint32_t slot = ARG(1);
    g_saving++;
    ffgo_0008b560(ecx, edx, st, rb);
    g_saving--;
    uint32_t mgr = g_dev_moves && log_level() ? unlocks() : 0, rec = rd(ecx + 0xac8);
    if (!mgr || !rec || slot > 8) return;
    rec += slot * 0xbe8u;
    int forced = 0, bought_n = 0, bad = 0;
    for (uint32_t i = FIRST_MOVE; i < FIRST_OURS; i++) {
        if (!forced_move(mgr, i)) continue;
        int bit = (rd(rec + 0xb8 + 4 * (i / 32)) >> (i % 32)) & 1, real = *(uint8_t*)PTR(rd(mgr + 4 * i) + 0x20) != 0;
        forced++;
        bought_n += real;
        bad += bit != real;
    }
    fprintf(stderr, "hulk: traversal: frame %u: save captured (slot %u): %d forced moves, %d really bought, %d bits differ "
            "from the real purchases\n", SIM->frame, slot, forced, bought_n, bad);
}

/* the missile's update: the player's deflection reads move 0x2b9's locked (+8) and purchased (+0x20) bytes itself */
#define MOVE_DEFLECT 0x2b9
void ffgo_0019e910(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_missile(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    uint32_t mgr = g_dev_moves ? unlocks() : 0;
    uint32_t it = forced_move(mgr, MOVE_DEFLECT) ? rd(mgr + 4u * MOVE_DEFLECT) : 0;
    if (!it) {
        ffgo_0019e910(ecx, edx, st, rb);
        return;
    }
    uint8_t* locked = (uint8_t*)PTR(it + 8);
    uint8_t* on = (uint8_t*)PTR(it + 0x20);
    uint8_t l0 = *locked, o0 = *on;
    *locked = 0;
    *on = 1;
    ffgo_0019e910(ecx, edx, st, rb);
    *locked = l0;
    *on = o0;
}
