/* The port's options in the game's menus (D224, D232; docs/wasm-port.md "Settings and the remastered edition";
 * HULK_WASM_GFX=1 builds only).
 *
 * Options gets two more entries, "Video Options" and "Gameplay Options", in the front end and in the pause menu; each
 * opens a screen listing the settings of port_settings.c's table on that screen in its nine item places (a text
 * selector bound to a named int each); a screen with more settings scrolls (wmenu1, below). The menus are game data (misc.rcf's frontend\fe_real.txt and fe_run.txt, the English strings in
 * frontend\lang\str_*.txt): nothing of them is in the repository. When the game opens misc.rcf the host serves it with
 * those files patched (an overlay: the archive's directory names the patched copies, appended after its end; every
 * other byte is the disc's), so the parser builds our screens like its own. The text below holds only what we insert
 * and our own strings; the game's text is located by anchors at run time:
 *
 *   AddNamedValueInt "Port_<screen>_<k>" 0 "Port_<screen>_<k>_Changed"   (after CameraInvertY's)
 *   AddTextButton "FEmain_left_item5" / "FEpause_text4" ... gotoscreen "port_video_options"   (in "options")
 *   AddScreen "port_video_options" { ... AddTextSelector "FEsubMenu_text<k>" / "FEpause_text<k>" { name
 *       "port_<screen>_<k>" ... NamedValue "Port_<screen>_<k>" ... } }  (before "camera_options")
 *
 * Three entry hooks (tools/wasm_port.py GFX_APP_HOOKS) connect the items to the settings:
 * - 0x000df9e0, the front end's lookup of an int callback by name: "Port_<screen>_<k>_Changed" is a handler object of
 *   the host's (a vftable whose call slot is a host method, ff_host_method; the object's second word is the place),
 *   which NamedValueInt::vfunc_1 0x000f8dd0 calls with the value when the selector changes it;
 * - 0x000f8e70, NamedValueInt's Create(name, default, callback): "Port_<screen>_<k>" starts at the choice index of the
 *   setting its place shows, and the host remembers the latest parse's object to keep it showing it;
 * - 0x000b5ad0, which sets the camera selectors from the stored flags (the front end's set-up 0x000c3ea0 and the pause
 *   menu's 0x000bcf40): a selector shows its first choice until the game's code sets it, so the hook sets ours to the
 *   settings the same way (vfunc_25, the choice's index = the named int's value).
 *
 * A fourth hook, 0x000df970 (the lookup of a front-end function by name, FEDoFunction's constructor 0x000e19d0), gives
 * the app's Quit item its action: "Port_Quit" is a host handler object like the callbacks' (wquit1). The main menu's
 * Story Mode column gets "Quit Game" (FEmain_center_item4, after Load Game), which asks the app to quit (gfx.c
 * hulk_app_request_quit: the same clean exit as the window's close button and Cmd+Q). No confirm screen and no
 * pause-menu item: see gen_quit_entry.
 *
 * The screen with the Texture Pack item (Gameplay Options) ends with two read-only lines, the texture and model packs'
 * status (labels "port_pack_status" and "port_pack_status2": the runner's texpack_status through gfx.c): their text is
 * set when the screen opens (its entry's first OnSelect is the function "Port_PackStatus", through the same hook) and
 * when the Texture Pack item changes, with the label's own setter 0x000f8500 (a text that is no string id is shown as
 * it is). Only then: a run that never opens the screen never sets them (the string table holds a fixed placeholder).
 *
 * Screens and heap are scarce: the front end's parser holds at most 66 screens of fe_real.txt (the disc has 63; a
 * 67th crashes the parse with a call through null at frame ~92), and the menus' text is parsed again in play (play3
 * at frame 26,654), where one more screen ran a later level load out of game heap (wquit1). Add rows to existing
 * screens, and test a menu change with play3 past frame 27,000.
 *
 * Scrolling (wmenu1, D238): a screen has nine places (FEsubMenu_text1..9 / FEpause_text1..9, all the locators there
 * are), and a screen with more rows shows a window of nine of them. Two more entry hooks, the screens' key handlers
 * 0x000e5710 / 0x000e6050, move it: down on the last place shows the next row there (the places are relabelled with the
 * selectors' own text setters and choice list, show_place), up on the first the row before; at the ends the cursor goes
 * round to the other end and the window with it. The window is game-facing state (g_top), the places' objects are the
 * nine the screen always had: scrolling adds no screen, no item and no named int.
 *
 * The named ints hold choice indices; the settings hold values (port_settings.h). With the remastered-edition switch
 * off a remastered-only item shows its faithful choice and turns back to it when changed. HULK_FE_OPTIONS=0 serves the
 * disc's misc.rcf unpatched; HULK_FE_OPTIONS_LOG=1 logs the items. */
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "../host/hulk_host.h"
#include "../host/hulk_io.h"
#include "../host/sim.h"
#include "port_settings.h"


/* Game-facing state of this host file (the game objects and the handlers the game holds, the screens' scroll
 * positions) lives in the tree's snapshotted section (tools/wasm_port.py GAME_STATE_SECTION), so a restore puts back
 * the menus' objects with the game (wroll1). The settings are host state (port_settings.c). */
#define GAME_STATE __attribute__((section("hulk_game_state")))
/* PLACES: a screen's item places (FEsubMenu_text1..9 / FEpause_text1..9); ROWS: settings on one screen at most */
enum { PLACES = 9, NPLACE = PS_SCREENS * PLACES, ROWS = 64 };

static int log_on(void) {
    static int on = -1;
    if (on < 0) on = getenv("HULK_FE_OPTIONS_LOG") != 0;
    return on;
}

/* the screens and their entries in Options (key: the places' names) */
static const struct { const char* screen; const char* key; const char* id; const char* label; } k_screens[PS_SCREENS] = {
    {"port_video_options", "video", "TBS_PORT_VIDEO_OPTIONS", "Video Options"},
    {"port_gameplay_options", "gameplay", "TBS_PORT_GAMEPLAY_OPTIONS", "Gameplay Options"},
};

/* ------------------------------------------------------------------------------------------- rows and places */
/* A screen's rows are the settings of port_settings.c's table on it, in the table's order (developer rows only in
 * developer mode, read at launch: wdev1). It shows them in its nine
 * places as a window (wmenu1, D238): place k shows row top + k. The places are the game's objects (a text selector
 * and its named int each), parsed once; the window moves by relabelling them (show_place), so a screen with more rows
 * than places costs no more game objects than one with nine. */
static int rows_of(int sc, int* out) {
    int n = 0;
    for (int i = 0; i < hulk_settings_count() && n < ROWS; i++)
        if (hulk_settings_at(i)->screen == sc && hulk_setting_listed(i)) out[n++] = i;
    return n;
}
static int places_of(int sc) {
    int r[ROWS], n = rows_of(sc, r);
    return n < PLACES ? n : PLACES;
}
GAME_STATE static int32_t g_top[PS_SCREENS];       /* each screen's first shown row */
static int top_of(int sc) {
    int r[ROWS], n = rows_of(sc, r), t = g_top[sc];
    return t < 0 ? 0 : t > n - PLACES ? (n > PLACES ? n - PLACES : 0) : t;
}
/* the setting place p shows (-1: no such place) */
static int place_setting(int p) {
    int sc = p / PLACES, k = p % PLACES, r[ROWS], n = rows_of(sc, r);
    return k < (n < PLACES ? n : PLACES) ? r[top_of(sc) + k] : -1;
}
/* ------------------------------------------------------------------------------------------- names */
static void nv_name(int p, char* out, size_t cap) { snprintf(out, cap, "Port_%s_%d", k_screens[p / PLACES].key, p % PLACES + 1); }
static void cb_name(int p, char* out, size_t cap) { snprintf(out, cap, "Port_%s_%d_Changed", k_screens[p / PLACES].key, p % PLACES + 1); }
static void sel_name(int p, char* out, size_t cap) { snprintf(out, cap, "port_%s_%d", k_screens[p / PLACES].key, p % PLACES + 1); }
/* rows whose choices share one set of string ids (TBS_PORT_DIGIT_<c>): the Join Code rows' digits. The game's
 * string table holds about 2,300 entries (StringTable_f7a80::FUN_000f7a80 stops at its maxStrings) and the disc's
 * str_en.txt takes 2,075 of them: every string the port adds counts (80 digit copies left the Online Co-op row, the
 * last listed, showing its raw ids; wnet1) */
static int shared_digits(int i) { return !strncmp(hulk_settings_at(i)->key, "coop_d", 6); }
/* rows whose choices are another row's (the same texts): they show that row's string ids and add only their label
 * (wtext2). The source row is always listed (its strings are always added). */
static const struct { const char* key; const char* from; } k_borrow[] = {
    {"text_spacing", "hdr"},            /* Off (Original) / On */
    {"move_prompts", "hdr"},            /* Off (Original) / On */
    {"contact", "hdr"},                 /* Off (Original) / On (wshadow1) */
    {"bounce", "hdr"},                  /* Off (Original) / On (wshadow1) */
    {"decals", "hdr"},                  /* Off (Original) / On (wdecal1) */
};
static const char* borrowed_from(int i) {
    for (unsigned k = 0; k < sizeof k_borrow / sizeof k_borrow[0]; k++)
        if (!strcmp(hulk_settings_at(i)->key, k_borrow[k].key)) return k_borrow[k].from;
    return 0;
}
/* rows whose choices are the game's own strings (no new strings, the game's languages; wskin1): the skins by their
 * cheats' names, on/off by the menus' */
static const char* game_choice_id(int i, int choice) {
    static const char* const skins[] = {"TBS_CHEAT_HULK", "TBS_CHEAT_GREY_HULK", "TBS_CHEAT_JOE_FIXIT",
                                        "TBS_CHEAT_ABOMINATION", "TBS_CHEAT_SAVAGE_BANNER", "TBS_CHEAT_FLAG_AUSTRALIA",
                                        "TBS_CHEAT_FLAG_CANADA", "TBS_CHEAT_FLAG_AMERICA", "TBS_CHEAT_FLAG_ENGLAND",
                                        "TBS_CHEAT_FLAG_FRANCE", "TBS_CHEAT_FLAG_GERMANY", "TBS_CHEAT_FLAG_ITALY",
                                        "TBS_CHEAT_FLAG_SPAIN", "TBS_CHEAT_FLAG_JAPAN"};
    const char* key = hulk_settings_at(i)->key;
    if (choice < 0) return 0;
    if (!strcmp(key, "coop_skin") && choice < (int)(sizeof skins / sizeof skins[0])) return skins[choice];
    if (!strcmp(key, "comic_skins")) return choice ? "TBS_MENU_ITEM_CHOICE_ON" : "TBS_MENU_ITEM_CHOICE_OFF";
    return 0;
}
static void str_id(int i, int choice, char* out, size_t cap) {      /* TBS_PORT_<KEY> / TBS_PORT_<KEY>_<choice> */
    const char* g = game_choice_id(i, choice);
    if (g) {
        snprintf(out, cap, "%s", g);
        return;
    }
    if (choice >= 0 && shared_digits(i)) {
        snprintf(out, cap, "TBS_PORT_DIGIT_%d", choice);
        return;
    }
    const char* from = choice >= 0 ? borrowed_from(i) : 0;
    int n = snprintf(out, cap, "TBS_PORT_%s", from ? from : hulk_settings_at(i)->key);
    if (choice >= 0) snprintf(out + n, cap - (size_t)n, "_%d", choice);
    for (char* p = out; *p; p++) *p = (char)toupper((unsigned char)*p);
}

/* a row whose choices' string ids make a long TextSelection line (the Co-op Skin row's fourteen cheat names): the
 * front end's parser crashed on it (wskin1). Such a row is parsed with its first choice only and relabelled with all
 * of them when its screen is set up (show_place, as a scrolled place is) */
static int long_row(int i) {
    const port_setting* st = hulk_settings_at(i);
    int len = 0;
    for (int c = 0; c < st->n; c++) {
        char id[64];
        str_id(i, c, id, sizeof id);
        len += (int)strlen(id) + 1;
    }
    return len > 160;
}

/* ------------------------------------------------------------------------------------------- the hooks */
/* NamedValueInt (32-bit layout, src/game/global/unk_0f86f0.cpp): name at +0x18 (0x28 bytes), the committed value at
 * +0x40, the pending one at +0x44 (vfunc_1 commits it and calls the callback with it) */
#define NV_NAME_OFF 0x18
#define NV_VALUE 0x40
#define NV_PENDING 0x44
/* TextSelector (src/game/global/TextSelector*.cpp): its label's text entry at +0x18 (every FEObject's), the shown
 * choice at +0x154, the choices' entries at +0x158 (0x38 bytes each; a text entry first) and their count at +0x1d58 */
#define SEL_LABEL 0x18
#define SEL_INDEX 0x154
#define SEL_ITEMS 0x158
#define SEL_ITEM_SIZE 0x38
#define SEL_COUNT 0x1d58
/* Each place's named int: only the one of the latest parse of the menus' text (an earlier parse's objects go with its
 * menus, the front end's when the game starts, and a write into one would land in freed game heap). */
GAME_STATE static uint32_t g_nv[NPLACE], g_nv_vft;
GAME_STATE static uint32_t g_handler[NPLACE][2], g_handler_vft[4];
GAME_STATE static uint32_t g_sel[NPLACE];       /* each place's selector when last shown (the key hook's filter) */

static int nv_is(uint32_t a, int p) {
    char name[64];
    nv_name(p, name, sizeof name);
    return a && *(uint32_t*)PTR(a) == g_nv_vft && !strncmp((const char*)PTR(a + NV_NAME_OFF), name, 0x28);
}

/* the choice an item shows: the faithful one while the setting is locked */
static int shown_index(int i) {
    const port_setting* s = hulk_settings_at(i);
    return hulk_setting_index(s, hulk_setting_locked(i) ? s->faithful : hulk_setting_user(i));
}

/* place p's selector (0x000b5ad0's way: the control by name 0x000fc260, dynamic_cast 0x00344e74 to the selector) */
static uint32_t selector_of(int p) {
    char sel[64];
    sel_name(p, sel, sizeof sel);
    uint32_t c = ff_call(0x000fc260u, 1, (uint32_t)(uintptr_t)sel);
    return c ? ff_call(0x00344e74u, 5, c, 0, 0x0049dba4u, 0x0049dbbcu, 0) : 0;
}

static int g_busy;
GAME_STATE static int32_t g_shown[NPLACE];      /* the setting each place's selector shows (its parsed row after a parse) */
/* Place p shows its setting: its named int holds the choice; `screen`: the selector too (its shown choice written and
 * the selector refreshed, slot 0; not vfunc_25, which would commit the named int again: its callback and receivers).
 * When the window has moved since, the selector is relabelled first: its label and choices
 * re-pointed at the setting's string ids with the text entries' setter 0x000f8500 (which allocates nothing for an id),
 * choices it lacks appended with its own vfunc_19 (a copy of its first; a selector holds 128 in itself, no heap), the
 * count written, then measured (slot 3) and refreshed (slot 0) as the game does after a text change. Runs that never
 * scroll (replays) only ever take the vfunc_25 path. */
static void show_place(int p, int screen) {
    int i = place_setting(p);
    if (i < 0) return;
    uint32_t k = (uint32_t)shown_index(i);
    if (nv_is(g_nv[p], p)) {
        *(uint32_t*)PTR(g_nv[p] + NV_VALUE) = k;
        *(uint32_t*)PTR(g_nv[p] + NV_PENDING) = k;
    }
    if (!screen || g_busy) return;
    g_busy = 1;
    uint32_t s = selector_of(p);
    g_sel[p] = s;
    if (s) {
        uint32_t* vft = (uint32_t*)PTR(*(uint32_t*)PTR(s));
        if (g_shown[p] != i) {
            const port_setting* st = hulk_settings_at(i);
            int n = st->n < 128 ? st->n : 128;
            uint32_t mgr = ff_call(0x000fc1b0u, 0);
            char id[64];
            str_id(i, -1, id, sizeof id);
            ff_call_this(0x000f8500u, s + SEL_LABEL, 3, (uint32_t)(uintptr_t)id, mgr, 1);
            while (*(int32_t*)PTR(s + SEL_COUNT) < n)
                ff_call_this(vft[19], s, 3, s + SEL_ITEMS, 0, 0);
            for (int c = 0; c < n; c++) {
                str_id(i, c, id, sizeof id);
                ff_call_this(0x000f8500u, s + SEL_ITEMS + (uint32_t)c * SEL_ITEM_SIZE, 3, (uint32_t)(uintptr_t)id, mgr, 1);
            }
            *(uint32_t*)PTR(s + SEL_COUNT) = (uint32_t)n;
            if (*(uint32_t*)PTR(s + SEL_INDEX) >= (uint32_t)n) *(uint32_t*)PTR(s + SEL_INDEX) = 0;
            ff_call_this(vft[3], s, 0);
            ff_call_this(vft[0], s, 0);
            g_shown[p] = i;
            if (log_on()) fprintf(stderr, "hulk: frame %u: place %s %d shows %s\n", SIM->frame, k_screens[p / PLACES].key, p % PLACES + 1, st->key);
        }
        if (*(uint32_t*)PTR(s + SEL_INDEX) != k) {
            *(uint32_t*)PTR(s + SEL_INDEX) = k;
            ff_call_this(vft[0], s, 0);
        }
    }
    g_busy = 0;
}
static void show_all(void) {
    for (int p = 0; p < NPLACE; p++) show_place(p, 1);
}

/* the Packs screen's status lines: the runner's text into the labels (a label's TextEntry at +0x18, 0x000f8500 with the
 * string manager 0x000fc1b0; dynamic_cast 0x00344e74 FEObject -> TextLabel 0x0049f48c, as 0x000b8f20 does) */
uint32_t hulk_wasm_texture_pack_status(char* buf, uint32_t cap);    /* gfx.c */
static char g_pack_status[200];
static void pack_status_show(void) {
    hulk_wasm_texture_pack_status(g_pack_status, sizeof g_pack_status);
    char* line[2] = {g_pack_status, strchr(g_pack_status, '\n')};
    if (line[1]) *line[1]++ = 0;
    for (int k = 0; k < 2; k++) {
        static const char* const names[2] = {"port_pack_status", "port_pack_status2"};
        if (!line[k] || !*line[k]) line[k] = (char*)" ";
        uint32_t c = ff_call(0x000fc260u, 1, (uint32_t)(uintptr_t)names[k]);
        uint32_t l = c ? ff_call(0x00344e74u, 5, c, 0, 0x0049dba4u, 0x0049f48cu, 0) : 0;
        if (l) ff_call_this(0x000f8500u, l + 0x18, 3, (uint32_t)(uintptr_t)line[k], ff_call(0x000fc1b0u, 0), 1);
        if (log_on()) fprintf(stderr, "hulk: frame %u: pack status %d \"%s\"%s\n", SIM->frame, k, line[k], l ? "" : " (no label)");
    }
}

/* the handlers' call slot: (this, choice index); the handler's second word is its place */
static void on_change(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    (void)edx, (void)rb;
    if (g_busy) return;
    int p = (int)*(uint32_t*)PTR(ecx + 4), i = place_setting(p);
    const port_setting* s = i >= 0 ? hulk_settings_at(i) : 0;
    if (!s) return;
    uint32_t k = ARG(0);
    if (log_on()) fprintf(stderr, "hulk: frame %u: place %s %d (%s) -> %u\n", SIM->frame, k_screens[p / PLACES].key, p % PLACES + 1, s->key, k);
    int locked = hulk_setting_locked(i);
    if (!locked && k < (uint32_t)s->n) hulk_setting_choose(i, s->values[k]);
    if (i == 0) {                       /* the edition switch: every item shows what it now stands for */
        for (int q = 0; q < NPLACE; q++) show_place(q, q != p);
    } else {
        show_place(p, locked);          /* a locked item turns back to its faithful choice */
    }
    if (!strcmp(s->key, "texture_pack")) pack_status_show();
}

/* The Online Co-op row's label shows co-op's status instead of its name while co-op is on (wnet1; netplay.c calls this
 * at each update with the text, "" when off): the place showing the row gets the text as written (0x000f8500 shows
 * a text that is no string id as it is), and its name again when the text goes. In a session the text is made from
 * what every peer knows alike and set at the same update everywhere, so the menu, which is game state, stays equal;
 * the text last set is game state too (a guest takes the host's with its state). */
GAME_STATE static char g_coop_label[96];
void hulk_wasm_net_label(const char* text) {
    if (!strncmp(text, g_coop_label, sizeof g_coop_label - 1) || g_busy) return;
    snprintf(g_coop_label, sizeof g_coop_label, "%s", text);
    int i = hulk_settings_find("coop");
    for (int p = 0; p < NPLACE; p++) {
        if (place_setting(p) != i || g_shown[p] != i) continue;
        uint32_t sel = selector_of(p);
        if (!sel) continue;
        char id[64];
        str_id(i, -1, id, sizeof id);
        uint32_t* vft = (uint32_t*)PTR(*(uint32_t*)PTR(sel));
        ff_call_this(0x000f8500u, sel + SEL_LABEL, 3, (uint32_t)(uintptr_t)(g_coop_label[0] ? g_coop_label : id),
                     ff_call(0x000fc1b0u, 0), 1);
        ff_call_this(vft[3], sel, 0);
        ff_call_this(vft[0], sel, 0);
    }
}

void ffgo_000df9e0(uint32_t, uint32_t, void*, void*);   /* the game's int-callback lookup (the hook's original) */
void ffh_hulk_app_fe_callback(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    const char* name = ARG(0) ? (const char*)PTR(ARG(0)) : 0;
    if (name && !strncmp(name, "Port_", 5)) {
        for (int p = 0; p < NPLACE; p++) {
            char cb[64];
            cb_name(p, cb, sizeof cb);
            if (strcmp(name, cb) || place_setting(p) < 0) continue;
            if (!g_handler_vft[0])
                for (int k = 0; k < 4; k++) g_handler_vft[k] = ff_host_method(on_change);
            g_handler[p][0] = (uint32_t)(uintptr_t)g_handler_vft;
            g_handler[p][1] = (uint32_t)p;
            RET((uint32_t)(uintptr_t)g_handler[p]);
            return;
        }
    }
    ffgo_000df9e0(ecx, edx, st, rb);
}

void ffgo_000f8e70(uint32_t, uint32_t, void*, void*);   /* NamedValueInt's Create (the hook's original) */
void ffh_hulk_app_named_int(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    const char* name = ARG(0) ? (const char*)PTR(ARG(0)) : 0;
    int ours = -1;
    if (name && !strncmp(name, "Port_", 5))
        for (int p = 0; p < NPLACE; p++) {
            char nv[64];
            nv_name(p, nv, sizeof nv);
            if (!strcmp(name, nv) && place_setting(p) >= 0) ours = p;
        }
    if (ours >= 0) ARG(1) = long_row(place_setting(ours)) ? 0u : (uint32_t)shown_index(place_setting(ours));
    ffgo_000f8e70(ecx, edx, st, rb);
    uint32_t a = (uint32_t)*(uint64_t*)rb;
    if (ours >= 0 && a) {
        g_nv_vft = *(uint32_t*)PTR(a);
        g_nv[ours] = a;
        int r[ROWS];
        rows_of(ours / PLACES, r);
        g_shown[ours] = long_row(r[ours % PLACES]) ? -1 : r[ours % PLACES];   /* (a parse: the place's new selector
                                                                                 * shows its parsed row; a long row
                                                                                 * is relabelled in full when shown) */
        if (log_on()) fprintf(stderr, "hulk: frame %u: %s at 0x%08x = %u\n", SIM->frame, name, a, ARG(1));
    }
}

void ffgo_000b5ad0(uint32_t, uint32_t, void*, void*);   /* the camera selectors' sync (the hook's original) */
void ffh_hulk_app_fe_sync(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_000b5ad0(ecx, edx, st, rb);
    show_all();
}

/* Scrolling (wmenu1): the screens' key handlers (FEScreenBase::vfunc_3 0x000e5710, FEMenuBase::vfunc_3 0x000e6050;
 * key 4 down, 0 up; the focused layout at +0x48, the screen's active flag at +0xab8). Down on a screen's last place
 * with rows below the window moves the window one row (the cursor stays, the places are relabelled, and the place is
 * focused again through the screen's slot 52 as the game does when nothing else can take the focus); up on the first
 * place with rows above, likewise. At the ends the game moves the cursor round (last place -> first, first -> last)
 * and the window follows it to the top / the bottom. Any other key or screen goes to the game untouched: the hook
 * reads only the focus before it compares it with the places' selectors. */
static int focus_is(uint32_t focus, uint32_t sel) {
    if (!focus || !sel) return 0;
    if (focus == sel) return 1;
    for (int w = 1; w < 0x48 / 4; w++)          /* (a layout holding the control: SingleLayout is 0x48 bytes) */
        if (*(uint32_t*)PTR(focus + 4 * (uint32_t)w) == sel) return 1;
    return 0;
}
static void fe_key(uint32_t ecx, uint32_t edx, void* st, void* rb, ffg_t original) {
    uint32_t key = ARG(0), focus = (key == 0 || key == 4) && *(uint8_t*)PTR(ecx + 0xab8) ? *(uint32_t*)PTR(ecx + 0x48) : 0;
    int wrap = -1, wrap_top = 0;
    for (int sc = 0; focus && sc < PS_SCREENS; sc++) {
        int r[ROWS], n = rows_of(sc, r);
        if (n <= PLACES) continue;
        int p = sc * PLACES + (key == 4 ? PLACES - 1 : 0), t = top_of(sc), last = n - PLACES;
        if (!focus_is(focus, g_sel[p]) || selector_of(p) != g_sel[p]) continue;
        if (key == 4 ? t < last : t > 0) {
            g_top[sc] = key == 4 ? t + 1 : t - 1;
            if (log_on()) fprintf(stderr, "hulk: frame %u: %s rows %d..%d\n", SIM->frame, k_screens[sc].key, g_top[sc] + 1, g_top[sc] + PLACES);
            for (int k = 0; k < PLACES; k++) show_place(sc * PLACES + k, 1);
            ff_call_this(((uint32_t*)PTR(*(uint32_t*)PTR(ecx)))[52], ecx, 2, focus, key == 4 ? 2 : 1);
            RET(1);
            return;
        }
        wrap = sc;
        wrap_top = key == 4 ? 0 : last;
    }
    original(ecx, edx, st, rb);
    if (wrap >= 0 && *(uint32_t*)PTR(ecx + 0x48) != focus) {
        g_top[wrap] = wrap_top;
        if (log_on()) fprintf(stderr, "hulk: frame %u: %s rows %d..%d (round)\n", SIM->frame, k_screens[wrap].key, wrap_top + 1, wrap_top + PLACES);
        for (int k = 0; k < PLACES; k++) show_place(wrap * PLACES + k, 1);
    }
}
void ffgo_000e5710(uint32_t, uint32_t, void*, void*);   /* FEScreenBase::vfunc_3 (the hook's original) */
void ffgo_000e6050(uint32_t, uint32_t, void*, void*);   /* FEMenuBase::vfunc_3 (the hook's original) */
void ffh_hulk_app_fe_key_screen(uint32_t ecx, uint32_t edx, void* st, void* rb) { fe_key(ecx, edx, st, rb, ffgo_000e5710); }
void ffh_hulk_app_fe_key_menu(uint32_t ecx, uint32_t edx, void* st, void* rb) { fe_key(ecx, edx, st, rb, ffgo_000e6050); }

/* Scroll arrows (wmenu2): while one of these screens is the front end's current one with rows hidden above / below its
 * window, the runner draws an up / a down arrow above the first place / below the last (run/app/menuarrows.cpp, a sink
 * overlay). Called at each present (gfx.c); it only reads memory (the FE manager *0x004e0a60's current screen at
 * +0x175c, that screen's active flag +0xab8 and focus +0x48, which is one of the screen's places), and the packed word
 * goes to the runner, picture only: bit 0 up, bit 1 down, bits 2..11 the arrows' x, 12..20 the up arrow's y, 21..29
 * the down arrow's y (frame pixels, 640x480); 0 none. The places are fixed: FEsubMenu_text1..9 (front end) and
 * FEpause_text1..9 (pause menu) both put row k's text at y 118 + 25k with full-width bars (the selectors hold no
 * screen position: only the entry animations' timing). */
#define FE_MGR 0x004e0a60u
#define FE_MGR_CUR 0x175c
static uint32_t rd32(uint32_t a) { return a ? *(uint32_t*)PTR(a) : 0; }
uint32_t hulk_wasm_fe_arrows(void) {
    uint32_t mgr = rd32(FE_MGR), cur = rd32(mgr + FE_MGR_CUR);
    if (!cur || !*(uint8_t*)PTR(cur + 0xab8)) return 0;
    uint32_t focus = rd32(cur + 0x48);
    for (int sc = 0; focus && sc < PS_SCREENS; sc++) {
        int r[ROWS], n = rows_of(sc, r), k = 0;
        if (n <= PLACES) continue;
        while (k < PLACES && !focus_is(focus, g_sel[sc * PLACES + k])) k++;
        if (k == PLACES) continue;
        int t = top_of(sc), up = t > 0, down = t < n - PLACES;
        uint32_t x = 320, yu = 97, yd = 341;     /* (centred; the places' rows are at y 118 + 25k in both layouts) */
        return (uint32_t)up | (uint32_t)down << 1 | x << 2 | yu << 12 | yd << 21;
    }
    return 0;
}

/* the Quit item's function: (this, argument count, arguments) -> 0, as the game's front-end functions return */
void hulk_app_request_quit(const char* why);    /* gfx.c */
static void on_quit(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    (void)ecx, (void)edx, (void)st;
    hulk_app_request_quit("the menu's Quit");
    RET(0);
}
static void on_pack_status(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    (void)ecx, (void)edx, (void)st;
    pack_status_show();
    RET(0);
}
GAME_STATE static uint32_t g_quit_handler[2], g_quit_vft[4], g_status_handler[2], g_status_vft[4];

void ffgo_000df970(uint32_t, uint32_t, void*, void*);   /* the game's front-end function lookup (the hook's original) */
void ffh_hulk_app_fe_function(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    const char* name = ARG(0) ? (const char*)PTR(ARG(0)) : 0;
    if (name && !strcmp(name, "Port_Quit")) {
        if (!g_quit_vft[0])
            for (int k = 0; k < 4; k++) g_quit_vft[k] = ff_host_method(on_quit);
        g_quit_handler[0] = (uint32_t)(uintptr_t)g_quit_vft;
        RET((uint32_t)(uintptr_t)g_quit_handler);
        return;
    }
    if (name && !strcmp(name, "Port_PackStatus")) {
        if (!g_status_vft[0])
            for (int k = 0; k < 4; k++) g_status_vft[k] = ff_host_method(on_pack_status);
        g_status_handler[0] = (uint32_t)(uintptr_t)g_status_vft;
        RET((uint32_t)(uintptr_t)g_status_handler);
        return;
    }
    ffgo_000df970(ecx, edx, st, rb);
}

/* ------------------------------------------------------------------------------------------- the menus' text */
typedef struct { char* p; uint32_t n, cap; } buf_t;
static void put(buf_t* b, const void* s, uint32_t n) {
    if (b->n + n > b->cap) {
        b->cap = (b->n + n) * 2 + 4096;
        b->p = realloc(b->p, b->cap);
    }
    memcpy(b->p + b->n, s, n);
    b->n += n;
}
static void puts_(buf_t* b, const char* s) { put(b, s, (uint32_t)strlen(s)); }
static void printf_(buf_t* b, const char* fmt, ...) __attribute__((format(printf, 2, 3)));
static void printf_(buf_t* b, const char* fmt, ...) {
    char line[1024];
    va_list ap;
    va_start(ap, fmt);
    int n = vsnprintf(line, sizeof line, fmt, ap);
    va_end(ap);
    if (n > 0) put(b, line, (uint32_t)(n < (int)sizeof line ? n : (int)sizeof line - 1));
}

static const char* find(const char* s, uint32_t n, const char* from, const char* what) {
    size_t w = strlen(what);
    for (const char* p = from; p + w <= s + n; p++)
        if (!memcmp(p, what, w)) return p;
    return 0;
}
static const char* line_end(const char* s, uint32_t n, const char* p) {
    while (p < s + n && *p != '\n') p++;
    return p < s + n ? p + 1 : p;
}
static const char* line_start(const char* s, const char* p) {
    while (p > s && p[-1] != '\n') p--;
    return p;
}

/* the screen with the Texture Pack item: it ends with the packs' status lines */
static int pack_screen(void) {
    const port_setting* s = hulk_settings_at(hulk_settings_find("texture_pack"));
    return s ? s->screen : -1;
}

/* The inserted text: `pause` 0 for fe_real.txt (the front end: FEmain_left_item<n> entries, FEsubMenu_text<k> items),
 * 1 for fe_run.txt (the pause menu: FEpause_text<n>, its bars and slide animations) */
#define CRLF "\r\n"
/* One named int per place (not per setting): each is game heap the pause menu's text holds through gameplay, and that
 * heap is short: play3's re-parse of the menus at frame 26,654 runs near its end, and one more screen there ran a
 * later load out of memory (the 0x0008d320 spin) (wquit1). */
static void gen_values(buf_t* b) {
    for (int p = 0; p < NPLACE; p++) {
        if (place_setting(p) < 0) continue;
        char nv[64], cb[64];
        nv_name(p, nv, sizeof nv);
        cb_name(p, cb, sizeof cb);
        printf_(b, "AddNamedValueInt \"%s\" 0 \"%s\"" CRLF, nv, cb);
    }
}
static void gen_entries(buf_t* b, int pause) {
    for (int sc = 0; sc < PS_SCREENS; sc++) {
        int slot = (pause ? 4 : 5) + sc;
        printf_(b, "    AddTextButton \"%s%d\"" CRLF "    {" CRLF "        text \"%s\" 1" CRLF "%s"
                   "        OnSelect gotoscreen \"%s\"" CRLF
                   "        OnHighlight function \"UpdateControlButtonString\" \"DynamicControlButtonLabel\"  \"1\"" CRLF,
                pause ? "FEpause_text" : "FEmain_left_item", slot, k_screens[sc].id,
                !pause && sc == pack_screen() ? "        OnSelect function \"Port_PackStatus\"" CRLF : "", k_screens[sc].screen);
        if (pause)
            printf_(b, "        $MACRO_INSERT FormatText" CRLF "        SelectedDrawable \"FE_selectBar\"" CRLF
                       "        NotSelectedDrawable \"FE_backgroundBar\"" CRLF
                       "        TransitionAnimEnter \"slide_down%d\"" CRLF "        TransitionAnimExit  \"slide_down%d\"" CRLF,
                    slot, slot);
        else
            printf_(b, "        $MACRO_INSERT menu_item_%d" CRLF "        halign left" CRLF, slot);
        puts_(b, "    }" CRLF CRLF);
    }
}
/* Each place is parsed showing the row it shows at the top of the list (show_place relabels it when the window moves). */
static void gen_screens(buf_t* b, int pause) {
    for (int sc = 0; sc < PS_SCREENS; sc++) {
        printf_(b, "AddScreen \"%s\"" CRLF "{" CRLF "    $MACRO_INSERT typicalScreenSetup" CRLF CRLF
                   "    AddLabel \"%s\"" CRLF "    {" CRLF "        text \"%s\" 1" CRLF
                   "        $MACRO_INSERT FormatTitleText" CRLF CRLF "        TransitionAnimEnter \"fadein\"" CRLF
                   "        TransitionAnimExit  \"fadeout\"" CRLF "    }" CRLF CRLF,
                k_screens[sc].screen, pause ? "FEpause_title" : "FEsubMenu_title", k_screens[sc].id);
        int r[ROWS], places = places_of(sc);
        rows_of(sc, r);
        for (int k = 1; k <= places; k++) {
            int p = sc * PLACES + k - 1, i = r[k - 1];
            const port_setting* s = hulk_settings_at(i);
            char nv[64], sel[64], id[64];
            nv_name(p, nv, sizeof nv);
            sel_name(p, sel, sizeof sel);
            str_id(i, -1, id, sizeof id);
            printf_(b, "    AddTextSelector \"%s%d\"" CRLF "    {" CRLF "        text \"%s\" 1" CRLF CRLF
                       "        name \"%s\"" CRLF "        TextSelection \"\"",
                    pause ? "FEpause_text" : "FEsubMenu_text", k, id, sel);
            for (int c = 0; c < (long_row(i) ? 1 : s->n); c++) {
                str_id(i, c, id, sizeof id);
                printf_(b, " %s", id);
            }
            printf_(b, CRLF "        NamedValue \"%s\"" CRLF CRLF
                       "        OnHighlight function \"UpdateControlButtonString\" \"DynamicControlButtonLabel\"  \"2\"" CRLF,
                    nv);
            if (pause)
                printf_(b, CRLF "        SelectedDrawable \"FE_selectBar\"" CRLF
                           "        NotSelectedDrawable \"FE_backgroundBar\"" CRLF CRLF
                           "        TransitionAnimEnter \"slide_down%d\"" CRLF "        TransitionAnimExit  \"slide_down%d\"" CRLF,
                        k, k);
            else
                printf_(b, "        $MACRO_INSERT menu_item_%d" CRLF, k);
            puts_(b, "    }" CRLF CRLF);
        }
        for (int l = 0; !pause && sc == pack_screen() && l < 2 && places + 1 + l <= PLACES; l++)    /* the packs' status (read-only) */
            printf_(b, "    AddLabel \"%s%d\"" CRLF "    {" CRLF "        text \"TBS_PORT_PACK_STATUS\" 1" CRLF
                       "        name \"port_pack_status%s\"" CRLF "        $MACRO_INSERT FormatText" CRLF "        halign center" CRLF
                       "    }" CRLF CRLF,
                    pause ? "FEpause_text" : "FEsubMenu_text", places + 1 + l, l ? "2" : "");
        puts_(b, "    $MACRO_INSERT SetupControlButtonLabel" CRLF "}" CRLF CRLF);
    }
}


/* the Quit item (the front end's Story Mode column, fe_real.txt only): it quits at once (Port_Quit). A confirm screen
 * cost too much: the front end's text is parsed again in play (play3 at frame 26,654), and one more screen there (or
 * the pause menu's "Quit to Desktop" and its screen) ran a later level load out of game heap (0x00266e00 ends in the
 * out-of-memory spin 0x0008d320); an item alone fits (wquit1). */
static void gen_quit_entry(buf_t* b) {
    puts_(b, "    AddTextButton \"FEmain_center_item4\"" CRLF "    {" CRLF "        text \"TBS_PORT_QUIT_GAME\" 1" CRLF
             "        OnSelect function \"Port_Quit\"" CRLF
             "        OnHighlight function \"UpdateControlButtonString\" \"DynamicControlButtonLabel\"  \"1\"" CRLF
             "        $MACRO_INSERT menu_item_4" CRLF "    }" CRLF CRLF);
}
static const struct { const char* id; const char* text; } k_quit_strings[] = {
    {"TBS_PORT_QUIT_GAME", "Quit Game"},
};

/* the line where screen `name`'s control-button label is set up (its last line before the closing brace): 0 when the
 * screen or the line is missing */
static const char* screen_tail(const char* s, uint32_t n, const char* name) {
    char want[80];
    snprintf(want, sizeof want, "AddScreen \"%s\"", name);
    const char* sc = find(s, n, s, want);
    const char* t = sc ? find(s, n, sc, "$MACRO_INSERT SetupControlButtonLabel") : 0;
    const char* next = sc ? find(s, n, sc + 1, "AddScreen \"") : 0;
    return t && (!next || t < next) ? line_start(s, t) : 0;
}

/* fe_real.txt / fe_run.txt: the named values after CameraInvertY's, the entries at the end of "options" (before its
 * control-button label), the screens before "camera_options". 0 when an anchor is missing (another disc's text): the
 * file stays as it is. */
static int patch_fe(const char* s, uint32_t n, int pause, buf_t* out) {
    const char* a = find(s, n, s, "AddNamedValueInt \"CameraInvertY\"");
    const char* opt = find(s, n, s, "AddScreen \"options\"");
    const char* b = opt ? find(s, n, opt, "$MACRO_INSERT SetupControlButtonLabel") : 0;
    const char* next = opt ? find(s, n, opt + 1, "AddScreen \"") : 0;
    const char* c = find(s, n, s, "AddScreen \"camera_options\"");
    if (!a || !b || !c || (next && b > next) || !(a < b && b < c) || find(s, n, s, "\"Port_")) return 0;
    /* the Quit item: at the end of the Story Mode column (front end only; left out when the screen is missing) */
    const char* q = pause ? 0 : screen_tail(s, n, "story_mode");
    struct { const char* at; int what; } ins[4] = {
        {line_end(s, n, a), 0}, {line_start(s, b), 1}, {line_start(s, c), 2}, {q, 3}};
    int k = q ? 4 : 3;
    for (int i = 1; i < k; i++)         /* in the file's order (a stable sort) */
        for (int j = i; j > 0 && ins[j].at < ins[j - 1].at; j--) {
            __typeof__(ins[0]) t = ins[j];
            ins[j] = ins[j - 1];
            ins[j - 1] = t;
        }
    const char* at = s;
    for (int i = 0; i < k; i++) {
        put(out, at, (uint32_t)(ins[i].at - at));
        at = ins[i].at;
        switch (ins[i].what) {
        case 0: gen_values(out); break;
        case 1: gen_entries(out, pause); break;
        case 2: gen_screens(out, pause); break;
        default: gen_quit_entry(out); break;
        }
    }
    put(out, at, (uint32_t)(s + n - at));
    return 1;
}

/* str_<lang>.txt (UTF-16LE, "KEY\tTEXT\r\n" lines): our strings, in English, appended */
static void put_string(buf_t* out, const char* id, const char* text) {
    char line[256];
    int l = snprintf(line, sizeof line, "%s\t%s\r\n", id, text);
    for (int k = 0; k < l && k < (int)sizeof line - 1; k++) put(out, (char[2]){line[k], 0}, 2);
}
/* the remastered moves' store text (traversal.c's keys; wtrav1) */
static const struct { const char* id; const char* text; } k_move_strings[] = {
    {"TBS_PORT_MV_CHARGE1", "+ Charge Sprint I"},
    {"TBS_PORT_MV_CHARGE2", "+ Charge Sprint II"},
    {"TBS_PORT_MV_CHARGE3", "+ Charge Sprint III"},
    {"TBS_PORT_MV_CHARGE_COMBO", "Sprint and keep holding the trigger"},
    {"TBS_PORT_MV_CHARGE1_DESC", "Keep holding the sprint trigger to build up speed, up to 30% faster. Let go and Hulk "
                                 "keeps charging ahead until he hits something. Charged hits deal up to 3x damage."},
    {"TBS_PORT_MV_CHARGE2_DESC", "Charge Sprint builds up to 50% more speed. Charged hits deal up to 5x damage and "
                                 "send enemies flying further."},
    {"TBS_PORT_MV_CHARGE3_DESC", "Charge Sprint builds up to 70% more speed. Charged hits deal up to 8x damage and "
                                 "send enemies flying further still."},
    {"TBS_PORT_MV_LEAP1", "+ Mega Leap I"},
    {"TBS_PORT_MV_LEAP2", "+ Mega Leap II"},
    {"TBS_PORT_MV_LEAP3", "+ Mega Leap III"},
    {"TBS_PORT_MV_LEAP_COMBO", "Jump"},
    {"TBS_PORT_MV_LEAP1_DESC", "Every jump goes 10% higher and further. Jump again just as you land to bounce higher, "
                               "up to 2 bounces in a row."},
    {"TBS_PORT_MV_LEAP2_DESC", "Every jump goes 20% higher and further. Chain up to 3 landing bounces."},
    {"TBS_PORT_MV_LEAP3_DESC", "Every jump goes 30% higher and further. Chain up to 4 landing bounces."},
    {"TBS_PORT_MV_FLING1", "+ Wall Fling I"},
    {"TBS_PORT_MV_FLING2", "+ Wall Fling II"},
    {"TBS_PORT_MV_FLING3", "+ Wall Fling III"},
    {"TBS_PORT_MV_FLING_COMBO", "Jump during a wall run"},
    {"TBS_PORT_MV_FLING1_DESC", "Jump off a wall run to be flung 30% further, carrying the run's speed. Running off the "
                                "top of a wall launches you higher."},
    {"TBS_PORT_MV_FLING2_DESC", "Wall Fling throws you 60% further off a wall run."},
    {"TBS_PORT_MV_FLING3_DESC", "Wall Fling throws you 90% further off a wall run: clear the street in one leap."},
    {"TBS_PORT_MV_AIR1", "+ Air Control I"},
    {"TBS_PORT_MV_AIR2", "+ Air Control II"},
    {"TBS_PORT_MV_AIR3", "+ Air Control III"},
    {"TBS_PORT_MV_AIR_COMBO", "Steer with the stick in the air"},
    {"TBS_PORT_MV_AIR1_DESC", "Turn faster in the air and steer sideways with the stick during jumps and falls."},
    {"TBS_PORT_MV_AIR2_DESC", "More air control: turn twice as fast and steer further."},
    {"TBS_PORT_MV_AIR3_DESC", "Full air control: turn almost three times as fast and line up any landing."},
};
static int patch_strings(const char* s, uint32_t n, buf_t* out) {
    if (n < 2 || (uint8_t)s[0] != 0xff || (uint8_t)s[1] != 0xfe || (n & 1)) return 0;
    put(out, s, n);
    if (n >= 4 && !(s[n - 4] == '\r' && s[n - 2] == '\n')) put(out, "\r\0\n\0", 4);
    for (int sc = 0; sc < PS_SCREENS; sc++) put_string(out, k_screens[sc].id, k_screens[sc].label);
    for (unsigned i = 0; i < sizeof k_quit_strings / sizeof k_quit_strings[0]; i++)
        put_string(out, k_quit_strings[i].id, k_quit_strings[i].text);
    put_string(out, "TBS_PORT_PACK_STATUS", " ");   /* (a fixed placeholder: the text is set when Video Options opens) */
    for (unsigned i = 0; i < sizeof k_move_strings / sizeof k_move_strings[0]; i++)
        put_string(out, k_move_strings[i].id, k_move_strings[i].text);
    for (int c = 0; c < 10; c++) {                  /* (the Join Code rows' digits, once: shared_digits) */
        char id[32], t[2] = {(char)('0' + c), 0};
        snprintf(id, sizeof id, "TBS_PORT_DIGIT_%d", c);
        put_string(out, id, t);
    }
    for (int i = 0; i < hulk_settings_count(); i++) {
        const port_setting* st = hulk_settings_at(i);
        if (!hulk_setting_listed(i)) continue;      /* (the developer rows' text only in developer mode, wdev1) */
        char id[64];
        str_id(i, -1, id, sizeof id);
        put_string(out, id, st->label);
        for (int c = 0; c < st->n && !shared_digits(i) && !borrowed_from(i); c++) {
            if (game_choice_id(i, c)) continue;     /* (the game's own string: wskin1) */
            str_id(i, c, id, sizeof id);
            put_string(out, id, st->names[c]);
        }
    }
    return 1;
}

/* ------------------------------------------------------------------------------------------- the archive overlay */
/* misc.rcf as the game reads it: bytes [0, head_n) (the header and the directory) from `head`, [tail_off, size)
 * (the patched files, 0x800-aligned) from `tail`, the rest from the disc. docs/formats/rcf.md. */
typedef struct {
    char path[1024];            /* the host path of misc.rcf (xapi.c HOST_PATH: a longer one never matched; wquit2) */
    int state;                  /* 0 not built, 1 patched, -1 served as it is */
    uint8_t* head;
    uint32_t head_n, disc_size, tail_off, size;
    buf_t tail;
} overlay_t;
static overlay_t g_ov;

static uint32_t rcf_hash(const char* s) {
    uint32_t h = 0;
    for (; *s; s++) {
        int c = (signed char)*s;
        if (c < 'a') c += 0x20;
        h = h * 31 + (uint32_t)c;
    }
    return h;
}

static int is_misc_rcf(const char* path) {
    const char* b = strrchr(path, '/');
    b = b ? b + 1 : path;
    return !strcasecmp(b, "misc.rcf");
}

static void overlay_build(overlay_t* o, int32_t fd) {
    o->state = -1;
    const char* e = getenv("HULK_FE_OPTIONS");
    if (e && *e == '0') return;
    uint8_t h[0x3c];
    if (hio_read(fd, h, sizeof h, 0) != (int32_t)sizeof h || memcmp(h, "ATG CORE CEMENT LIBRARY", 23)) return;
    uint32_t dir_off, dir_size, count;
    memcpy(&dir_off, h + 0x24, 4);
    memcpy(&dir_size, h + 0x28, 4);
    memcpy(&count, h + 0x38, 4);
    if (dir_off != 0x3c || dir_size != 12 * count || count > 100000) return;
    o->disc_size = hio_size(fd);
    o->head_n = dir_off + dir_size;
    o->head = malloc(o->head_n);
    if (hio_read(fd, o->head, o->head_n, 0) != (int32_t)o->head_n) return;
    o->tail_off = (o->disc_size + 0x7ff) & ~0x7ffu;
    static const char* const names[] = {"frontend\\fe_real.txt", "frontend\\fe_run.txt", "frontend\\lang\\str_en.txt",
                                        "frontend\\lang\\str_fr.txt", "frontend\\lang\\str_de.txt",
                                        "frontend\\lang\\str_es.txt", "frontend\\lang\\str_it.txt"};
    int patched = 0;
    for (unsigned i = 0; i < sizeof names / sizeof names[0]; i++) {
        uint32_t want = rcf_hash(names[i]);
        uint8_t* ent = 0;
        for (uint32_t k = 0; k < count; k++) {
            uint32_t hh;
            memcpy(&hh, o->head + dir_off + 12 * k, 4);
            if (hh == want) ent = o->head + dir_off + 12 * k;
        }
        if (!ent) continue;
        uint32_t off, size;
        memcpy(&off, ent + 4, 4);
        memcpy(&size, ent + 8, 4);
        char* s = malloc(size ? size : 1);
        if (hio_read(fd, s, size, off) != (int32_t)size) { free(s); continue; }
        buf_t out = {0};
        int ok = i == 0 ? patch_fe(s, size, 0, &out)
               : i == 1 ? patch_fe(s, size, 1, &out)
               : patch_strings(s, size, &out);
        free(s);
        if (!ok) { free(out.p); continue; }
        const char* dump = getenv("HULK_FE_OPTIONS_DUMP");     /* (a local directory: the patched files, to read) */
        if (dump && *dump) {
            char dp[600];
            snprintf(dp, sizeof dp, "%s/%s", dump, strrchr(names[i], '\\') + 1);
            int32_t df = hio_open(dp, HIO_CREATE);
            if (df >= 0) { hio_write(df, out.p, out.n, 0); hio_close(df); }
        }
        while (o->tail.n & 0x7ff) put(&o->tail, "", 1);
        uint32_t at = o->tail_off + o->tail.n;
        put(&o->tail, out.p, out.n);
        free(out.p);
        memcpy(ent + 4, &at, 4);
        memcpy(ent + 8, &out.n, 4);
        patched++;
    }
    if (!patched) return;
    o->size = o->tail_off + o->tail.n;
    o->state = 1;
    fprintf(stderr, "hulk: %s: the Video and Gameplay Options screens and Quit (%d files patched)\n", o->path, patched);
}

static overlay_t* overlay_of(const char* path, int32_t fd) {
    if (fd < 0 || !is_misc_rcf(path)) return 0;
    if (!g_ov.state) {
        snprintf(g_ov.path, sizeof g_ov.path, "%s", path);
        overlay_build(&g_ov, fd);
    }
    return g_ov.state == 1 && !strcmp(g_ov.path, path) ? &g_ov : 0;
}

/* xapi.c's ReadFile / GetFileSize (weak references there): -2 when the file has no overlay */
int64_t ff_overlay_size(const char* path, int32_t fd) {
    overlay_t* o = overlay_of(path, fd);
    return o ? (int64_t)o->size : -2;
}

int32_t ff_overlay_read(const char* path, int32_t fd, void* buf, uint32_t n, uint32_t off) {
    overlay_t* o = overlay_of(path, fd);
    if (!o) return -2;
    if (off >= o->size) return 0;
    if (n > o->size - off) n = o->size - off;
    uint8_t* d = buf;
    uint32_t done = 0;
    while (done < n) {
        uint32_t at = off + done, k;
        if (at < o->head_n) {
            k = o->head_n - at < n - done ? o->head_n - at : n - done;
            memcpy(d + done, o->head + at, k);
        } else if (at >= o->tail_off) {
            k = n - done;
            memcpy(d + done, o->tail.p + (at - o->tail_off), k);
        } else if (at >= o->disc_size) {
            k = o->tail_off - at < n - done ? o->tail_off - at : n - done;
            memset(d + done, 0, k);
        } else {
            k = o->disc_size - at < n - done ? o->disc_size - at : n - done;
            int32_t got = hio_read(fd, d + done, k, at);
            if (got <= 0) return done ? (int32_t)done : -1;
            k = (uint32_t)got;
        }
        done += k;
    }
    return (int32_t)done;
}
