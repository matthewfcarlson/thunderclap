/* Skins in the remaster (wskin1; HULK_WASM_GFX=1 builds only; docs/multiplayer.md 6.5 and 20, docs/wasm-port.md
 * "Skins"): per-player co-op skins (D248) and comic skins applied by themselves (D250, D250c).
 *
 * How the game's skins work (docs/multiplayer.md 6.5). A skin is one of the unlockables 0..12 (the Codes menu's
 * "Character" cheats: 0x00203890 names them) or none ("hulk"). Entering a cheat's code unlocks it (0x00093950 ->
 * 0x00093600(id, 0)); choosing it in the cheats screen turns its "on" bit on (0x000b5ca0 -> 0x00092870); the level
 * load 0x00206320 wears the first skin that is unlocked and on (0x00203a10) and loads art/global_<skin>.p3d into the
 * level loader's inventory (+0xaa0) when it changed. Every skin file names its objects alike (the CompositeDrawable
 * "hulk", "hulk_skin", "hulk_skeleton", ...), so two cannot share one inventory; the render engine makes a
 * character's model from an ObjectTemplate (FUN_001c3d90()'s registry, keyed by the drawable's name id: 0x001c4190,
 * the Render::Store at +0xc) that CRenderableCharacter instances (0x001c3b20 -> 0x001c60f0 -> 0x001c5900) copy.
 *
 * Comic skins (D250, D250c; Gameplay Options "Auto-Apply Comic Skins", remastered only, faithful off). A comic book
 * whose reward is a skin's cheat shows its code (the fight script common.fig's comic handler: um_GetUnlockableCheatCode)
 * but unlocks nothing; the player types the code in the Codes menu. With the row on:
 *   - a fresh pickup: the collectable's pick-up 0x001d8350 (a ComicBook prop, state 8, collected by a Hulk) marks a
 *     pending comic for the player whose Hulk took it; the next updates ask the game's Lua (sh_DoString 0x001d3f00,
 *     our one line over the game's own table jk_comic_to_unlockable and bindings um_IsUnlockableLocked /
 *     um_SetUnlockableLocked, the comic handler's and kmcIsCheatComicCollected's) which skins' comics are collected;
 *     a skin that has just joined that set is unlocked through um_SetUnlockableLocked (0x00093db0 -> 0x00093600, the
 *     path a typed code takes) and worn: player 0 (the host, single player) through the cheats screen's path
 *     (um_SetUnlockableOn: every skin off, this one on; 0x00203a10 wears it from the next level load, as a choice in the
 *     cheats screen does), an extra co-op Hulk at once (his Hulk is made again with it, below);
 *   - a save loaded (0x0008a8f0, the load screen's apply) and every level start: every skin whose comic the save
 *     holds is unlocked, nothing is switched (the user, 11-25: only unlock on load).
 * The save keeps only what a typed code would have written (the locked and on bits it already holds).
 *
 * Co-op skins (D248). Each extra Hulk k (coop.c) wears a skin of his own: the guest's choice (Gameplay Options
 * "Co-op Skin", the guest's own: it travels as bits 8..11 of its pad's wButtons in the lockstep sets (netplay.c), so
 * every peer has it at the same update; the game never sees those bits), or for the developer's local Hulks the
 * row's value (P1) and the pair's other (P2). A choice is allowed when the host's save has the skin unlocked, or it is
 * the co-op pair (hulk, grey_hulk: always offered in a co-op session; the save is not changed); otherwise, and when it
 * equals a Hulk's already worn, it becomes the pair's other one (docs/multiplayer.md 6.5). In a mission that forces a
 * skin (0x00206320: joefixit or a national Hulk) every extra Hulk wears the forced one (the tinted copy is not done:
 * see docs/multiplayer.md 20). A skin no player wears is never loaded: each needed one is loaded asynchronously by the
 * game's own loader (0x00203e90 without waiting, polled each update, then moved into an inventory of ours,
 * content::LoadInventory 0x00266480, on the Persistent heap 0x11 as the game loads its own), its "hulk" drawable
 * registered as a template under a name id of ours ("port_skin_<name>"); Hulk k is made when his skin is ready, and
 * while the actor spawner runs for him the character's model request (0x001c3b20, entry hook) names that template.
 * Everything is game state (hulk_game_state: requests, inventories, keys, the pending comic), computed from game state
 * and the session's pads, so peers stay in lockstep. With the rows faithful and no co-op nothing here runs.
 *
 * Knobs: HULK_SKIN_LOG=1 (loads, choices, comics); tests only: HULK_COOP_SKIN=N (this peer's Co-op Skin value, as the
 * row's), HULK_COMIC_TEST=F:K:N (at frame F, as if player K had picked up comic N: its comic_book unlockable unlocked
 * and the pickup marked; K=-1: no pickup, swept as a loaded save is), HULK_SKIN_ALLOW_ALL=1 (every choice allowed). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../host/hulk_host.h"
#include "../host/sim.h"
#include "port_settings.h"

#define GAME_STATE __attribute__((section("hulk_game_state")))
#define MAXP 3
#define NSKIN 14                        /* 0 "hulk", 1 + id for the unlockables 0..12 */

#define WORLD_PTR 0x004dd700u           /* +0x54 CGame: 0x000862a0 its level loader; +0x20 the actor manager */
#define GAME_PTR 0x004dd6ecu            /* +0x34 the unlockables manager (FUN_00086340) */
#define SCRIPT_PTR 0x004e23ccu          /* the ScriptHandler singleton (FUN_001d4c90) */
#define FN_LOADER 0x000862a0u           /* CGame: the level loader (+0xaa0 its inventory, +0xaa4 the skin's name) */
#define FN_UNLOCKS 0x00086340u          /* the unlockables manager */
#define FN_IS_LOCKED 0x00092dc0u        /* (id) */
#define FN_DOSTRING 0x001d3f00u         /* ScriptHandler::DoString(text, chunk name) */
#define FN_GETSTRING 0x001d27b0u        /* ScriptHandler::sh_GetString(global name) */
#define FN_HEAP 0x00266da0u             /* (id): the current heap, the previous one returned */
#define FN_ALLOC 0x0008d690u            /* (size) */
#define FN_INV_CTOR 0x00266480u         /* content::LoadInventory(capacity) */
#define FN_LOAD 0x00203e90u             /* loader: (path, nowait, a3, actor, target, callback, heap) -> the request */
#define FN_REQ_DONE 0x00266750u         /* request: loaded */
#define FN_REQ_STREAM 0x00266700u       /* request: what it loaded */
#define FN_REQ_RELEASE 0x00263e90u
#define FN_INV_TAKE 0x00266220u         /* inventory: take what a request loaded */
#define FN_HASH 0x002672f0u             /* (name, 0, 0) -> the 64-bit name id */
#define FN_RENDER 0x001c3d90u           /* the render engine (+0xc the object manager: templates) */
#define FN_TPL_FIND 0x001c5b00u         /* object manager: (key*) -> the template */
#define FN_TPL_INIT 0x001c5cf0u         /* ObjectTemplate (0x10 bytes): (key*, drawable) */
#define FN_TPL_ADD 0x001c5ae0u          /* object manager: (template) */
#define CASTER_DRAWABLE 0x003f6330u     /* content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>'s vftable */
#define LD_SKIN 0xaa4                   /* the level loader's chosen skin (32 bytes) */
#define PROP_STATE 0x150                /* a collectable's kind (8: ComicBook) */
#define PROP_TAKEN 0xf8                 /* collected */
#define HEAP_PERSISTENT 0x11

/* the skins: the unlockables' names (0x00203890), index 0 the default */
static const char* const k_skin[NSKIN] = {"hulk", "hulk_australia", "grey_hulk", "joefixit", "abomination_ashulk",
                                          "banner_savage", "hulk_canada", "hulk_us", "hulk_uk", "hulk_france",
                                          "hulk_german", "hulk_italy", "hulk_spain", "hulk_japan"};
#define SK_HULK 0
#define SK_GREY 2                       /* (unlockable 1) */

typedef struct {
    int32_t skin;                       /* 0: empty */
    int32_t state;                      /* 1 loading, 2 ready, -1 failed */
    uint32_t req, inv;                  /* the load request, our inventory */
    uint32_t key[2];                    /* the template's name id */
    int32_t wait;                       /* updates since the load started */
} slot_t;

static struct {
    int32_t req[MAXP];                  /* each player's request (skin index + 1; 0: none) */
    int32_t comic[MAXP];                /* a comic's skin for this player (skin index + 1; 0: none) */
    int32_t worn[MAXP];                 /* the skin Hulk k was made with (index + 1) */
    slot_t slot[2];
    int32_t spawning;                   /* the player the actor spawner runs for (0: none) */
    uint32_t spawn_key[2];
    int32_t pend_k, pend_left;          /* the pending comic: its player, updates left */
    int32_t mask_valid;
    uint32_t mask;                      /* skins whose comics are collected (bit = unlockable id) */
    uint32_t main;                      /* the main actor at the last level start */
    int32_t reskin;                     /* bit k: Hulk k must be made again (a comic's skin) */
} G GAME_STATE;

static uint32_t rd(uint32_t a) { return a ? *(uint32_t*)PTR(a) : 0; }
static uint32_t A(const void* p) { return (uint32_t)(uintptr_t)p; }
static int log_on(void) {
    static int l = -1;
    if (l < 0) l = getenv("HULK_SKIN_LOG") ? atoi(getenv("HULK_SKIN_LOG")) : 0;
    return l;
}
static uint32_t loader(void) {
    uint32_t w = rd(WORLD_PTR), g = w ? rd(w + 0x54) : 0;
    return g ? ff_call_this(FN_LOADER, g, 0) : 0;
}
static uint32_t unlocks(void) {
    uint32_t g = rd(GAME_PTR);
    return g ? ff_call_this(FN_UNLOCKS, g, 0) : 0;
}
static int skin_of_name(const char* s) {
    for (int i = 0; i < NSKIN; i++)
        if (!strncmp(s, k_skin[i], 32)) return i;
    return SK_HULK;
}
/* the skin the main actor wears (the level loader's) */
static int main_skin(void) {
    uint32_t l = loader();
    if (!l) return SK_HULK;
    char n[33];
    memcpy(n, PTR(l + LD_SKIN), 32);
    n[32] = 0;
    return skin_of_name(n);
}
static int unlocked(int sk) {
    uint32_t u = unlocks();
    return sk == SK_HULK || (u && !(ff_call_this(FN_IS_LOCKED, u, 1, (uint32_t)(sk - 1)) & 0xff));
}
static void name_id(const char* s, uint32_t out[2]) {
    uint32_t st[3] = {A(s), 0, 0};
    uint64_t rb[2] = {0, 0};
    ff_dispatch(FN_HASH, 0, 0, st, rb);
    out[0] = (uint32_t)rb[0], out[1] = (uint32_t)(rb[0] >> 32);
}

/* ------------------------------------------------------------------------------------------- the game's Lua */
static void lua(const char* text) {
    static const char chunk[] = "=port_skins";
    uint32_t sh = rd(SCRIPT_PTR);
    if (sh) ff_call_this(FN_DOSTRING, sh, 2, A(text), A(chunk));
}
/* the skins (unlockable ids, a bit each) whose comics are collected; with UNLOCK, the locked ones among them are
 * unlocked as their typed code would (um_SetUnlockableLocked). -1: the table is not there */
static uint32_t bits_of(uint32_t fn) {          /* the skins' locked (0x00092dc0) or on (0x00092de0) bits */
    uint32_t u = unlocks(), m = 0;
    for (uint32_t i = 0; u && i <= 12; i++)
        if (ff_call_this(fn, u, 1, i) & 0xff) m |= 1u << i;
    return m;
}
static int64_t comic_skins(int unlock) {
    uint32_t locked0 = log_on() ? bits_of(FN_IS_LOCKED) : 0;
    char text[700];
    snprintf(text, sizeof text,
             "__PORT_COMIC_SKINS__='' if type(jk_comic_to_unlockable)=='table' then local s,o={},'' "
             "for k,v in next,jk_comic_to_unlockable do if type(v)=='table' and type(v[2])=='number' and v[2]>=0 "
             "and v[2]<=12 and not um_IsUnlockableLocked(v[1]) then s[v[2]]=1 "
             "if %s and um_IsUnlockableLocked(v[2]) then um_SetUnlockableLocked(v[2],false) end end end "
             "for i=0,12 do if s[i] then o=o..'1' else o=o..'0' end end __PORT_COMIC_SKINS__=o end",
             unlock ? "true" : "false");
    lua(text);
    uint32_t sh = rd(SCRIPT_PTR);
    uint32_t p = sh ? ff_call_this(FN_GETSTRING, sh, 1, A("__PORT_COMIC_SKINS__")) : 0;
    if (!p || strlen((const char*)PTR(p)) != 13) return -1;
    const char* s = (const char*)PTR(p);
    int64_t m = 0;
    for (int i = 0; i < 13; i++)
        if (s[i] == '1') m |= 1ll << i;
    if (log_on() && unlock && locked0 != bits_of(FN_IS_LOCKED))
        fprintf(stderr, "hulk: skins: frame %u: unlocked by their comics: 0x%04x\n", SIM->frame,
                locked0 & ~bits_of(FN_IS_LOCKED));
    return m;
}

/* ------------------------------------------------------------------------------------------- comic skins */
static int comic_on(void) { return hulk_setting("comic_skins") != 0; }
void hulk_wasm_comic_skins_apply(int value) { (void)value; G.mask_valid = 0; }

/* the load screen's apply of a save (0x0008a8f0): the skins its comics earned are unlocked (only unlocked: D250c) */
void ffgo_0008a8f0(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_save_apply(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_0008a8f0(ecx, edx, st, rb);
    if (!comic_on()) return;
    int64_t m = comic_skins(1);
    if (m >= 0) G.mask = (uint32_t)m, G.mask_valid = 1;
    if (log_on()) fprintf(stderr, "hulk: skins: a save loaded: its comics' skins 0x%04llx unlocked\n", (long long)m);
}

uint32_t hulk_wasm_coop_player(int k);       /* coop.c */
/* a collectable's pick-up (0x001d8350, thiscall (fighter)): a comic book a Hulk took is pending for his player */
void ffgo_001d8350(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_collect(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    uint8_t before = ecx ? *(uint8_t*)PTR(ecx + PROP_TAKEN) : 1;
    uint32_t who = ARG(0);
    ffgo_001d8350(ecx, edx, st, rb);
    if (!comic_on() || !ecx || before || !*(uint8_t*)PTR(ecx + PROP_TAKEN) || rd(ecx + PROP_STATE) != 8) return;
    int k = 0;
    for (int j = 1; j < MAXP; j++)
        if (who && who == hulk_wasm_coop_player(j)) k = j;
    G.pend_k = k, G.pend_left = 150;                /* (the comic's script runs from the event queue, soon after) */
    if (log_on()) fprintf(stderr, "hulk: skins: frame %u: player %d picked up a comic book\n", SIM->frame, k);
}

static void wear_comic(int k, int id) {
    if (k == 0) {                               /* the cheats screen's choice: every skin off, this one on */
        char text[160];
        snprintf(text, sizeof text, "for i=0,12 do um_SetUnlockableOn(i,false) end um_SetUnlockableOn(%d,true)", id);
        lua(text);
    } else {
        G.comic[k] = id + 2;                    /* (skin index id + 1, stored + 1) */
        G.reskin |= 1 << k;
    }
    if (log_on()) fprintf(stderr, "hulk: skins: frame %u: player %d wears the comic's skin %s (locked 0x%04x on 0x%04x)\n",
                          SIM->frame, k, k_skin[id + 1], bits_of(FN_IS_LOCKED), bits_of(0x00092de0u));
}

static void comic_test(void) {                 /* HULK_COMIC_TEST=F:K:N (tests only) */
    static int f = -2, k, n;
    if (f == -2) {
        const char* e = getenv("HULK_COMIC_TEST");
        f = -1;
        if (e && sscanf(e, "%d:%d:%d", &f, &k, &n) != 3) f = -1;
    }
    if (f < 0 || (int)SIM->frame < f) return;
    char text[200];
    snprintf(text, sizeof text, "um_SetUnlockableLocked(constants.unlockables.comic_book_%d,false)", n);
    lua(text);
    if (k >= 0 && k < MAXP) G.pend_k = k, G.pend_left = 150;
    else {                                      /* (a save that holds it: the load's sweep, unlock only) */
        int64_t m = comic_skins(1);
        if (m >= 0) G.mask = (uint32_t)m, G.mask_valid = 1;
        fprintf(stderr, "hulk: skins: test: as a save loaded: comics' skins 0x%04llx unlocked\n", (long long)m);
    }
    fprintf(stderr, "hulk: skins: frame %u: test: comic %d collected%s\n", SIM->frame, n, k >= 0 ? " (picked up)" : "");
    f = -1;
}

static void comic_update(void) {
    if (!comic_on()) return;
    comic_test();
    if (!G.mask_valid) {                        /* (the row just turned on: what is collected now is not new) */
        int64_t m = comic_skins(0);
        if (m >= 0) G.mask = (uint32_t)m, G.mask_valid = 1;
    }
    if (G.pend_left <= 0) return;
    G.pend_left--;
    int64_t m = comic_skins(1);
    if (m < 0) return;
    uint32_t fresh = (uint32_t)m & ~G.mask;
    G.mask = (uint32_t)m;
    if (!fresh) return;
    int id = 0;
    while (!(fresh >> id & 1)) id++;
    wear_comic(G.pend_k, id);
    G.pend_left = 0;
}

/* ------------------------------------------------------------------------------------------- co-op skins */
int hulk_wasm_coop_players(void);
uint32_t hulk_net_mask(void);
int hulk_wasm_skin_local_request(void) {        /* this peer's Co-op Skin (netplay.c sends it): index + 1 */
    const char* e = getenv("HULK_COOP_SKIN");
    int v = e && *e ? atoi(e) : hulk_setting("coop_skin");
    return v >= 0 && v < NSKIN ? v + 1 : 0;
}
/* netplay.c: slot k's request in this update's set (0: none) */
void hulk_wasm_skin_session_request(int k, int req) {
    if (k > 0 && k < MAXP) G.req[k] = req >= 0 && req <= NSKIN ? req : 0;
}

static int other_of_pair(int sk) { return sk == SK_HULK ? SK_GREY : SK_HULK; }
static int forced(void) {                       /* the level wears a skin no unlockable chose (0x00206320's force) */
    int m = main_skin();
    if (m == SK_HULK) return 0;
    uint32_t u = unlocks();
    return u && (ff_call_this(0x00092de0u, u, 1, (uint32_t)(m - 1)) & 0xff) == 0;
}
/* the skin Hulk k wears now */
static int skin_for(int k) {
    int m = main_skin();
    if (forced()) return m;
    int r = G.comic[k] ? G.comic[k] - 1 : G.req[k] ? G.req[k] - 1 : -1;
    if (r < 0 && !hulk_net_mask()) r = k == 1 ? hulk_wasm_skin_local_request() - 1 : -1;     /* (the developer's) */
    if (r < 0) r = other_of_pair(m);
    static int all = -1;
    if (all < 0) all = getenv("HULK_SKIN_ALLOW_ALL") && *getenv("HULK_SKIN_ALLOW_ALL") == '1';
    if (!all && !G.comic[k] && r != SK_HULK && r != SK_GREY && !unlocked(r)) r = other_of_pair(m);
    int taken = r == m;
    for (int j = 1; j < k; j++) taken |= G.worn[j] - 1 == r;
    if (taken) {
        r = other_of_pair(m);
        for (int j = 1; j < k; j++)
            if (G.worn[j] - 1 == r) r = r == SK_GREY ? SK_HULK : SK_GREY;
    }
    return r;
}

/* extra skins only where the game heaps were scaled for co-op (section 19: the Persistent heap, 3,260 KiB in the
 * original's table, holds 22 KiB spare over play3; a skin takes ~200 KiB). Read from the image's heap table, which a
 * guest takes with the host's memory, so every peer decides alike */
#define HEAP_TABLE 0x00400520u
static int heaps_roomy(void) { return rd(HEAP_TABLE + 12 * HEAP_PERSISTENT + 4) >= 0x400000u; }

static slot_t* slot_of(int sk) {
    for (int i = 0; i < 2; i++)
        if (G.slot[i].skin == sk + 1) return &G.slot[i];
    return 0;
}
static void slot_free(slot_t* s) {
    if (s->req) ff_call_this(FN_REQ_RELEASE, s->req, 0);
    if (s->inv) ff_call_this(rd(rd(s->inv) + 4), s->inv, 0);     /* Release */
    if (log_on()) fprintf(stderr, "hulk: skins: frame %u: %s let go\n", SIM->frame, k_skin[s->skin - 1]);
    memset(s, 0, sizeof *s);
}
static void slot_load(int sk) {
    slot_t* s = 0;
    int need[2] = {0, 0};
    for (int i = 0; i < 2; i++)
        for (int k = 1; k < MAXP; k++)
            if (G.slot[i].skin && G.slot[i].skin == G.worn[k]) need[i] = 1;
    for (int i = 0; i < 2 && !s; i++)
        if (!G.slot[i].skin) s = &G.slot[i];
    for (int i = 0; i < 2 && !s; i++)
        if (!need[i]) slot_free(&G.slot[i]), s = &G.slot[i];
    uint32_t l = loader();
    if (!s || !l) return;
    int old = (int)ff_call(FN_HEAP, 1, HEAP_PERSISTENT);
    uint32_t inv = ff_call(FN_ALLOC, 1, 0x14u);
    if (inv) ff_call_this(FN_INV_CTOR, inv, 1, 0x800u);
    if (inv) ff_call_this(rd(rd(inv)), inv, 0);                   /* AddRef: ours */
    static char path[64];
    snprintf(path, sizeof path, "art/global_%s.p3d", k_skin[sk]);
    uint32_t req = inv ? ff_call_this(FN_LOAD, l, 7, A(path), 1u, 1u, 0u, inv, 0u, (uint32_t)HEAP_PERSISTENT) : 0;
    ff_call(FN_HEAP, 1, (uint32_t)old);
    s->skin = sk + 1, s->state = req ? 1 : -1, s->req = req, s->inv = inv, s->wait = 0;
    char nm[48];
    snprintf(nm, sizeof nm, "port_skin_%s", k_skin[sk]);
    name_id(nm, s->key);
    if (log_on()) fprintf(stderr, "hulk: skins: frame %u: loading %s%s\n", SIM->frame, path, req ? "" : ": FAILED");
}
/* the template under our key: made (again) when the render engine has none (a level change empties it) */
static int slot_template(slot_t* s) {
    uint32_t re = ff_call(FN_RENDER, 0), om = rd(re + 0xc);
    if (!om) return 0;
    if (ff_call_this(FN_TPL_FIND, om, 1, A(s->key))) return 1;
    uint32_t caster[1] = {CASTER_DRAWABLE}, id[2];
    name_id("hulk", id);
    uint32_t res = ff_call_this(rd(rd(s->inv) + 12), s->inv, 3, A(caster), id[0], id[1]);
    if (!res) return 0;
    int old = (int)ff_call(FN_HEAP, 1, 0xfu);
    uint32_t t = ff_call(FN_ALLOC, 1, 0x10u);
    if (t) {
        ff_call_this(FN_TPL_INIT, t, 2, A(s->key), res);
        ff_call_this(FN_TPL_ADD, om, 1, t);
    }
    ff_call(FN_HEAP, 1, (uint32_t)old);
    if (log_on()) fprintf(stderr, "hulk: skins: frame %u: %s's template %s\n", SIM->frame, k_skin[s->skin - 1],
                          t ? "made" : "FAILED");
    return t != 0;
}
static void slots_update(void) {
    for (int i = 0; i < 2; i++) {
        slot_t* s = &G.slot[i];
        if (s->state != 1) continue;
        if (ff_call_this(FN_REQ_DONE, s->req, 0) & 0xff) {
            uint32_t src = ff_call_this(FN_REQ_STREAM, s->req, 0);
            ff_call_this(FN_INV_TAKE, s->inv, 1, src);
            ff_call_this(FN_REQ_RELEASE, s->req, 0);
            s->req = 0;
            s->state = 2;
            if (log_on()) fprintf(stderr, "hulk: skins: frame %u: %s loaded\n", SIM->frame, k_skin[s->skin - 1]);
        } else if (++s->wait > 900) {
            s->state = -1;
            fprintf(stderr, "hulk: skins: frame %u: %s did not load\n", SIM->frame, k_skin[s->skin - 1]);
        }
    }
}

/* coop.c, before making Hulk k: 1 when his skin is ready (the spawner then uses it), 0 to wait; with no skin of
 * his own (the main actor's, or a failed load) 1 at once */
int hulk_wasm_skin_spawn_begin(int k) {
    if (k <= 0 || k >= MAXP) return 1;
    int sk = skin_for(k), m = main_skin();
    G.spawning = 0;
    if (sk == m || !heaps_roomy()) {               /* (original heap sizes: the main actor's skin) */
        G.worn[k] = m + 1;
        return 1;
    }
    slot_t* s = slot_of(sk);
    if (!s) {
        G.worn[k] = sk + 1;                     /* (wanted: a slot is not let go while he waits) */
        slot_load(sk);
        return 0;
    }
    if (s->state == 1) return 0;
    if (s->state < 0 || !slot_template(s)) {
        G.worn[k] = m + 1;
        return 1;
    }
    G.worn[k] = sk + 1;
    G.spawning = k;
    memcpy(G.spawn_key, s->key, 8);
    if (log_on()) fprintf(stderr, "hulk: skins: frame %u: player %d is made as %s\n", SIM->frame, k, k_skin[sk]);
    return 1;
}
void hulk_wasm_skin_spawn_end(void) { G.spawning = 0; }
/* coop.c: Hulk k must be made again (a comic gave him a skin); cleared once asked */
int hulk_wasm_skin_reskin(int k) {
    int r = G.reskin >> k & 1;
    G.reskin &= ~(1 << k);
    return r;
}
/* the character's model request (0x001c3b20, thiscall (name*, drawable*)): while the spawner makes a Hulk of ours, the
 * drawable is his skin's template */
void ffgo_001c3b20(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_char_model(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    if (G.spawning) ARG(1) = A(G.spawn_key);
    ffgo_001c3b20(ecx, edx, st, rb);
}

/* each level start (a new main actor): a comic sweep (unlock only), the comic skins forgotten, slots no Hulk wears
 * let go */
static void level_start(void) {
    if (comic_on()) {
        int64_t m = comic_skins(1);
        if (m >= 0) G.mask = (uint32_t)m, G.mask_valid = 1;
        if (log_on()) fprintf(stderr, "hulk: skins: frame %u: level start: comics' skins 0x%04llx\n", SIM->frame,
                              (long long)m);
    }
    for (int k = 0; k < MAXP; k++) G.worn[k] = 0;
    G.pend_left = 0;
}

void hulk_wasm_skins_update(int kind, float dt) {
    (void)dt;
    if (kind == 6 || kind == 7) return;
    int coop = hulk_wasm_coop_players() > 1 || G.slot[0].skin || G.slot[1].skin;
    if (!comic_on() && !coop) return;           /* (faithful, single player: nothing here runs) */
    uint32_t w = rd(WORLD_PTR), am = w ? rd(w + 0x20) : 0, mainch = am ? rd(am + 0x124) : 0;
    if (mainch && mainch != G.main) {
        G.main = mainch;
        level_start();
    }
    comic_update();
    if (coop) slots_update();
}
