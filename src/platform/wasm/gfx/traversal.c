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
 * The store: six CUnlockableMove slots the shipped init.lua leaves empty (MOVE_BASE..+5) are set up with the
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
 * sprint frame). HULK_TRAV_FORCE=C,J (tests) treats charge level C and leap level J as bought; HULK_TRAV_TEST_XP=N
 * (tests) gives N smash points when the moves are set up.
 *
 * Developer forces (wdev1; port_settings.c's developer rows, developer mode only): Force Charge Sprint / Force Mega
 * Leap set the level the hooks above use (as HULK_TRAV_FORCE does; the store still shows the real purchases), and
 * Force Original Moves makes every shipped store move (slots 0x266..MOVE_BASE-1 with a name) count as unlocked and
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

/* the store */
#define MOVE_BASE 0x2c4                 /* six spare CUnlockableMove slots: 0x2c4..0x2c9 */
enum { M_CHARGE1, M_CHARGE2, M_CHARGE3, M_LEAP1, M_LEAP2, M_LEAP3, N_MOVES };
/* priced like the original's upgrade lines (Air Dash 12,000 / Super 25,000 / Double 60,000 / Double Super 150,000) */
static const int k_cost[N_MOVES] = {20000, 50000, 100000, 10000, 25000, 60000};
/* the shipped moves whose pictures (+0x48) ours show: Dashing Straight and Air Dash (constants.unlockables.move_2 /
 * move_10, slots 0x267 / 0x26f) */
static const int k_picture_from[N_MOVES] = {0x267, 0x267, 0x267, 0x26f, 0x26f, 0x26f};

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
static int g_force_charge = -1, g_force_leap = -1;
static int g_dev_charge, g_dev_leap, g_dev_moves;   /* developer forces (wdev1): 0 off */
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
} g_tv GAME_STATE;

void hulk_wasm_traversal_apply(int value) {
    g_on = value != 0;
    const char* f = getenv("HULK_TRAV_FORCE");
    if (f && *f) {
        g_force_charge = atoi(f);
        const char* c = strchr(f, ',');
        g_force_leap = c ? atoi(c + 1) : 0;
    }
}

void hulk_wasm_traversal_force_charge(int value) { g_dev_charge = value > 0 && value <= 3 ? value : 0; }
void hulk_wasm_traversal_force_leap(int value) { g_dev_leap = value > 0 && value <= 3 ? value : 0; }
void hulk_wasm_traversal_force_moves(int value) { g_dev_moves = value != 0; }

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
static int bought(uint32_t mgr, int m) { return mgr && (ff_call_this(FN_IS_ON, mgr, 1, (uint32_t)(MOVE_BASE + m)) & 0xff); }
static int level_of(int first, int forced) {
    if (forced >= 0) return forced > 3 ? 3 : forced;
    uint32_t mgr = unlocks();
    int l = 0;
    while (l < 3 && bought(mgr, first + l)) l++;
    return l;
}
static int charge_level(void) { return level_of(M_CHARGE1, g_dev_charge ? g_dev_charge : g_force_charge); }
static int leap_level(void) { return level_of(M_LEAP1, g_dev_leap ? g_dev_leap : g_force_leap); }

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
    if (log_level())
        fprintf(stderr, "hulk: traversal: frame %u: jump x%.2f (leap %d%s chain %d, %.2f s after landing): up %.2f -> %.2f, "
                "forward %.2f -> %.2f\n", SIM->frame, (double)h, lvl, b > 0 ? ", bounce" : "", g_tv.chain, (double)since,
                (double)vy, (double)(vy * h),
                (double)fwd, (double)nf);
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
            uint32_t it = rd(mgr + 4u * (uint32_t)(MOVE_BASE + m));
            if (!it || rd(it + 0x10) | rd(it + 0x14)) {
                fprintf(stderr, "hulk: traversal: move slot 0x%x is not spare; no remaster moves in the store\n", MOVE_BASE + m);
                return;
            }
        }
        static char pic[N_MOVES][0x41];
        for (int m = 0; m < N_MOVES; m++) {
            int idx = MOVE_BASE + m;
            uint32_t src = rd(mgr + 4u * (uint32_t)k_picture_from[m]);
            if (src) memcpy(pic[m], PTR(src + 0x48), 0x40);
            ff_call_this(FN_SETUP_MOVE, mgr, 6, (uint32_t)idx, (uint32_t)(uintptr_t)k_keys[m][0],
                         (uint32_t)(uintptr_t)k_keys[m][1], (uint32_t)(uintptr_t)k_keys[m][2],
                         (uint32_t)(uintptr_t)pic[m], (uint32_t)k_cost[m]);
            if (m != M_CHARGE1 && m != M_LEAP1) ff_call_this(FN_DEPENDENCY, mgr, 2, (uint32_t)idx, (uint32_t)(idx - 1));
        }
        g_tv.setup_ok = 1;
        const char* xp = getenv("HULK_TRAV_TEST_XP");    /* (tests: smash points to buy with, once a manager) */
        uint32_t w = rd(WORLD_PTR), game = w ? rd(w + 0x54) : 0, stats = game ? ff_call_this(FN_STATS, game, 0) : 0;
        if (xp && *xp && stats) ff_call_this(FN_ADD_XP, stats, 1, (uint32_t)atoi(xp));
        if (log_level()) {
            uint32_t strings = ff_call(FN_STRINGS, 0);
            uint32_t it = rd(mgr + 4u * MOVE_BASE);
            int sid = strings && it ? (int32_t)ff_call_this(FN_STRING_ID, strings, 2, rd(it + 0x10), rd(it + 0x14)) : -2;
            fprintf(stderr, "hulk: traversal: frame %u: %d moves set up (slots 0x%x..; name string %d)\n", SIM->frame,
                    N_MOVES, MOVE_BASE, sid);
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
        if (v == 0xffffffffu || (v >= MOVE_BASE && v < MOVE_BASE + N_MOVES)) break;
        start++;
    }
    if (start > 100 - N_MOVES) start = 100 - N_MOVES;
    for (int p = 0; p < 100; p++) {             /* ours anywhere else: taken out */
        uint32_t v = rd(ord + 4u * (uint32_t)p);
        if (v >= MOVE_BASE && v < MOVE_BASE + N_MOVES && (p < start || p >= start + N_MOVES || (int)(v - MOVE_BASE) != p - start))
            *(uint32_t*)PTR(ord + 4u * (uint32_t)p) = 0xffffffffu;
    }
    for (int m = 0; m < N_MOVES; m++) {
        uint32_t idx = (uint32_t)(MOVE_BASE + m), pos = (uint32_t)(start + m);
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
void hulk_wasm_traversal_update(int kind, float dt) {
    for (int k = 0; k < g_tv.nmod; k++) {
        static const uint32_t off[4] = {0xf8, 0x100, 0x110, 0x118};
        for (int i = 0; i < 4; i++) wf(g_tv.mod_track[k] + off[i], g_tv.mod_val[k][i]);
    }
    g_tv.nmod = 0;
    if (!g_on) {                                 /* turned off in this session: ours leave the store again */
        uint32_t mgr = g_tv.setup_ok ? unlocks() : 0;
        if (mgr && mgr == g_tv.setup_mgr) {
            for (int m = 0; m < N_MOVES; m++) {
                uint32_t it = rd(mgr + 4u * (uint32_t)(MOVE_BASE + m));
                if (it) *(uint8_t*)PTR(it + 8) = 1;
            }
            for (int p = 0; p < 100; p++) {
                uint32_t a = mgr + 0xbf8 + 4u * (uint32_t)p, v = rd(a);
                if (v >= MOVE_BASE && v < MOVE_BASE + N_MOVES) *(uint32_t*)PTR(a) = 0xffffffffu;
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
            g_tv.land_ch = ch;
            g_tv.land_time = g_tv.clock;
            g_tv.land_speed = g_tv.motion_speed;
        }
        if (log_level() >= 2)
            fprintf(stderr, "hulk: traversal: frame %u: motion %u -> %u at %.2f units/s\n", SIM->frame, g_tv.motion, m,
                    (double)g_tv.motion_speed);
    }
    g_tv.motion_ch = ch;
    g_tv.motion = m;
    g_tv.motion_speed = hspeed(ch);
}

/* ---------------------------------------------------------------------------------------------- developer forces */
/* Force Original Moves (wdev1): a shipped store move: an index of the moves' range below ours, set up (a name key) and a
 * CUnlockableMove (dynamic_cast 0x00344e74 CUnlockable 0x0049dab8 -> CUnlockableMove 0x0049db1c, as the readers do) */
#define FIRST_MOVE 0x266
static int forced_move(uint32_t mgr, uint32_t index) {
    static int from = -1;               /* HULK_DEV_TEST_FROM=N (tests): no force before frame N (a replay stays in step) */
    if (from < 0) from = getenv("HULK_DEV_TEST_FROM") ? atoi(getenv("HULK_DEV_TEST_FROM")) : 0;
    if (!g_dev_moves || !mgr || index < FIRST_MOVE || index >= MOVE_BASE || SIM->frame < (uint32_t)from) return 0;
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
            static uint8_t seen[MOVE_BASE - FIRST_MOVE];
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
        static uint8_t seen[MOVE_BASE - FIRST_MOVE];
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
    for (uint32_t i = FIRST_MOVE; i < MOVE_BASE; i++) {
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
