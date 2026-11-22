/* The port's options in the game's menus (D224, D232; docs/wasm-port.md "Settings and the remastered edition";
 * HULK_WASM_GFX=1 builds only).
 *
 * Options gets two more entries, "Video Options" and "Gameplay Options", in the front end and in the pause menu; each
 * opens a screen with one item per setting of port_settings.c's table on that screen (a text selector bound to a named
 * int). The menus are game data (misc.rcf's frontend\fe_real.txt and fe_run.txt, the English strings in
 * frontend\lang\str_*.txt): nothing of them is in the repository. When the game opens misc.rcf the host serves it with
 * those files patched (an overlay: the archive's directory names the patched copies, appended after its end; every
 * other byte is the disc's), so the parser builds our screens like its own. The text below holds only what we insert
 * and our own strings; the game's text is located by anchors at run time:
 *
 *   AddNamedValueInt "Port_<key>" 0 "Port_<key>_Changed"               (after CameraInvertY's)
 *   AddTextButton "FEmain_left_item5" / "FEpause_text4" ... gotoscreen "port_video_options"   (in "options")
 *   AddScreen "port_video_options" { ... AddTextSelector "FEsubMenu_text<k>" / "FEpause_text<k>" { ... NamedValue
 *       "Port_<key>" ... } }                                            (before "camera_options")
 *
 * Three entry hooks (tools/wasm_port.py GFX_APP_HOOKS) connect the items to the settings:
 * - 0x000df9e0, the front end's lookup of an int callback by name: "Port_<key>_Changed" is a handler object of the
 *   host's (a vftable whose call slot is a host method, ff_host_method; the object's second word is the setting's
 *   index), which NamedValueInt::vfunc_1 0x000f8dd0 calls with the value when the selector changes it;
 * - 0x000f8e70, NamedValueInt's Create(name, default, callback): "Port_<key>" starts at the setting's choice index,
 *   and the host remembers the objects (one per front-end slot) to keep them showing the same value;
 * - 0x000b5ad0, which sets the camera selectors from the stored flags (the front end's set-up 0x000c3ea0 and the pause
 *   menu's 0x000bcf40): a selector shows its first choice until the game's code sets it, so the hook sets ours to the
 *   settings the same way (vfunc_25, the choice's index = the named int's value).
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


/* Game-facing state of this host file (the game objects and the handlers the game holds) lives in the tree's
 * snapshotted section (tools/wasm_port.py GAME_STATE_SECTION), so a restore puts back the menus' objects with the
 * game (wroll1). The settings are host state (port_settings.c). */
#define GAME_STATE __attribute__((section("hulk_game_state")))
enum { MAXS = 16, SLOTS = 4 };

static int log_on(void) {
    static int on = -1;
    if (on < 0) on = getenv("HULK_FE_OPTIONS_LOG") != 0;
    return on;
}

/* ------------------------------------------------------------------------------------------- names */
static void nv_name(int i, char* out, size_t cap) { snprintf(out, cap, "Port_%s", hulk_settings_at(i)->key); }
static void cb_name(int i, char* out, size_t cap) { snprintf(out, cap, "Port_%s_Changed", hulk_settings_at(i)->key); }
static void sel_name(int i, char* out, size_t cap) { snprintf(out, cap, "port_%s_selector", hulk_settings_at(i)->key); }
static void str_id(int i, int choice, char* out, size_t cap) {      /* TBS_PORT_<KEY> / TBS_PORT_<KEY>_<choice> */
    int n = snprintf(out, cap, "TBS_PORT_%s", hulk_settings_at(i)->key);
    if (choice >= 0) snprintf(out + n, cap - (size_t)n, "_%d", choice);
    for (char* p = out; *p; p++) *p = (char)toupper((unsigned char)*p);
}

/* ------------------------------------------------------------------------------------------- the hooks */
/* NamedValueInt (32-bit layout, src/game/global/unk_0f86f0.cpp): name at +0x18 (0x28 bytes), the committed value at
 * +0x40, the pending one at +0x44 (vfunc_1 commits it and calls the callback with it) */
#define NV_NAME_OFF 0x18
#define NV_VALUE 0x40
#define NV_PENDING 0x44
GAME_STATE static uint32_t g_nv[MAXS][SLOTS], g_nv_vft;     /* each setting's named ints (one per front-end slot) */
GAME_STATE static uint32_t g_handler[MAXS][2], g_handler_vft[4];

static int nv_is(uint32_t p, int i) {
    char name[64];
    nv_name(i, name, sizeof name);
    return p && *(uint32_t*)PTR(p) == g_nv_vft && !strncmp((const char*)PTR(p + NV_NAME_OFF), name, 0x28);
}

/* the choice an item shows: the faithful one while the setting is locked */
static int shown_index(int i) {
    const port_setting* s = hulk_settings_at(i);
    return hulk_setting_index(s, hulk_setting_locked(i) ? s->faithful : hulk_setting_user(i));
}

static int g_busy;
/* the item's selector on the screen now (0x000b5ad0's way: the control by name 0x000fc260, dynamic_cast 0x00344e74
 * to the selector, its vfunc_25 sets the choice) */
static void selector_show(int i) {
    char sel[64];
    sel_name(i, sel, sizeof sel);
    uint32_t c = ff_call(0x000fc260u, 1, (uint32_t)(uintptr_t)sel);
    uint32_t s = c ? ff_call(0x00344e74u, 5, c, 0, 0x0049dba4u, 0x0049dbbcu, 0) : 0;
    if (s) ff_call_this(((uint32_t*)PTR(*(uint32_t*)PTR(s)))[25], s, 1, (uint32_t)shown_index(i));
}
/* every named int of setting i shows its choice; `screen`: the selector too */
static void refresh(int i, int screen) {
    uint32_t k = (uint32_t)shown_index(i);
    for (int j = 0; j < SLOTS; j++)
        if (nv_is(g_nv[i][j], i)) {
            *(uint32_t*)PTR(g_nv[i][j] + NV_VALUE) = k;
            *(uint32_t*)PTR(g_nv[i][j] + NV_PENDING) = k;
        }
    if (screen && !g_busy) {
        g_busy = 1;
        selector_show(i);
        g_busy = 0;
    }
}

/* the handlers' call slot: (this, choice index) */
static void on_change(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    (void)edx, (void)rb;
    if (g_busy) return;
    int i = (int)*(uint32_t*)PTR(ecx + 4);
    const port_setting* s = hulk_settings_at(i);
    if (!s) return;
    uint32_t k = ARG(0);
    if (log_on()) fprintf(stderr, "hulk: frame %u: Port_%s_Changed -> %u\n", SIM->frame, s->key, k);
    int locked = hulk_setting_locked(i);
    if (!locked && k < (uint32_t)s->n) hulk_setting_choose(i, s->values[k]);
    if (i == 0) {                       /* the edition switch: every item shows what it now stands for */
        for (int j = 1; j < hulk_settings_count(); j++) refresh(j, 1);
        refresh(0, 0);
    } else {
        refresh(i, locked);             /* a locked item turns back to its faithful choice */
    }
}

void ffgo_000df9e0(uint32_t, uint32_t, void*, void*);   /* the game's int-callback lookup (the hook's original) */
void ffh_hulk_app_fe_callback(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    const char* name = ARG(0) ? (const char*)PTR(ARG(0)) : 0;
    if (name && !strncmp(name, "Port_", 5)) {
        for (int i = 0; i < hulk_settings_count() && i < MAXS; i++) {
            char cb[64];
            cb_name(i, cb, sizeof cb);
            if (strcmp(name, cb)) continue;
            if (!g_handler_vft[0])
                for (int k = 0; k < 4; k++) g_handler_vft[k] = ff_host_method(on_change);
            g_handler[i][0] = (uint32_t)(uintptr_t)g_handler_vft;
            g_handler[i][1] = (uint32_t)i;
            RET((uint32_t)(uintptr_t)g_handler[i]);
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
        for (int i = 0; i < hulk_settings_count() && i < MAXS; i++) {
            char nv[64];
            nv_name(i, nv, sizeof nv);
            if (!strcmp(name, nv)) ours = i;
        }
    if (ours >= 0) ARG(1) = (uint32_t)shown_index(ours);
    ffgo_000f8e70(ecx, edx, st, rb);
    uint32_t p = (uint32_t)*(uint64_t*)rb;
    if (ours >= 0 && p) {
        g_nv_vft = *(uint32_t*)PTR(p);
        int k = 0;
        while (k < SLOTS - 1 && nv_is(g_nv[ours][k], ours) && g_nv[ours][k] != p) k++;
        g_nv[ours][k] = p;
        if (log_on()) fprintf(stderr, "hulk: frame %u: %s at 0x%08x = %u\n", SIM->frame, name, p, ARG(1));
    }
}

void ffgo_000b5ad0(uint32_t, uint32_t, void*, void*);   /* the camera selectors' sync (the hook's original) */
void ffh_hulk_app_fe_sync(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_000b5ad0(ecx, edx, st, rb);
    g_busy = 1;
    for (int i = 0; i < hulk_settings_count() && i < MAXS; i++) selector_show(i);
    g_busy = 0;
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

/* the screens and their entries in Options */
static const struct { const char* screen; const char* id; const char* label; } k_screens[PS_SCREENS] = {
    {"port_video_options", "TBS_PORT_VIDEO_OPTIONS", "Video Options"},
    {"port_gameplay_options", "TBS_PORT_GAMEPLAY_OPTIONS", "Gameplay Options"},
};

/* The inserted text: `pause` 0 for fe_real.txt (the front end: FEmain_left_item<n> entries, FEsubMenu_text<k> items),
 * 1 for fe_run.txt (the pause menu: FEpause_text<n>, its bars and slide animations) */
#define CRLF "\r\n"
static void gen_values(buf_t* b) {
    for (int i = 0; i < hulk_settings_count() && i < MAXS; i++) {
        char nv[64], cb[64];
        nv_name(i, nv, sizeof nv);
        cb_name(i, cb, sizeof cb);
        printf_(b, "AddNamedValueInt \"%s\" 0 \"%s\"" CRLF, nv, cb);
    }
}
static void gen_entries(buf_t* b, int pause) {
    for (int sc = 0; sc < PS_SCREENS; sc++) {
        int slot = (pause ? 4 : 5) + sc;
        printf_(b, "    AddTextButton \"%s%d\"" CRLF "    {" CRLF "        text \"%s\" 1" CRLF
                   "        OnSelect gotoscreen \"%s\"" CRLF
                   "        OnHighlight function \"UpdateControlButtonString\" \"DynamicControlButtonLabel\"  \"1\"" CRLF,
                pause ? "FEpause_text" : "FEmain_left_item", slot, k_screens[sc].id, k_screens[sc].screen);
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
static void gen_screens(buf_t* b, int pause) {
    for (int sc = 0; sc < PS_SCREENS; sc++) {
        printf_(b, "AddScreen \"%s\"" CRLF "{" CRLF "    $MACRO_INSERT typicalScreenSetup" CRLF CRLF
                   "    AddLabel \"%s\"" CRLF "    {" CRLF "        text \"%s\" 1" CRLF
                   "        $MACRO_INSERT FormatTitleText" CRLF CRLF "        TransitionAnimEnter \"fadein\"" CRLF
                   "        TransitionAnimExit  \"fadeout\"" CRLF "    }" CRLF CRLF,
                k_screens[sc].screen, pause ? "FEpause_title" : "FEsubMenu_title", k_screens[sc].id);
        int k = 0;
        for (int i = 0; i < hulk_settings_count() && i < MAXS; i++) {
            const port_setting* s = hulk_settings_at(i);
            if (s->screen != sc || k >= (pause ? 9 : 9)) continue;
            k++;
            char nv[64], sel[64], id[64];
            nv_name(i, nv, sizeof nv);
            sel_name(i, sel, sizeof sel);
            str_id(i, -1, id, sizeof id);
            printf_(b, "    AddTextSelector \"%s%d\"" CRLF "    {" CRLF "        text \"%s\" 1" CRLF CRLF
                       "        name \"%s\"" CRLF "        TextSelection \"\"",
                    pause ? "FEpause_text" : "FEsubMenu_text", k, id, sel);
            for (int c = 0; c < s->n; c++) {
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
        puts_(b, "    $MACRO_INSERT SetupControlButtonLabel" CRLF "}" CRLF CRLF);
    }
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
    a = line_end(s, n, a);
    b = line_start(s, b);
    c = line_start(s, c);
    put(out, s, (uint32_t)(a - s));
    gen_values(out);
    put(out, a, (uint32_t)(b - a));
    gen_entries(out, pause);
    put(out, b, (uint32_t)(c - b));
    gen_screens(out, pause);
    put(out, c, (uint32_t)(s + n - c));
    return 1;
}

/* str_<lang>.txt (UTF-16LE, "KEY\tTEXT\r\n" lines): our strings, in English, appended */
static void put_string(buf_t* out, const char* id, const char* text) {
    char line[256];
    int l = snprintf(line, sizeof line, "%s\t%s\r\n", id, text);
    for (int k = 0; k < l && k < (int)sizeof line - 1; k++) put(out, (char[2]){line[k], 0}, 2);
}
static int patch_strings(const char* s, uint32_t n, buf_t* out) {
    if (n < 2 || (uint8_t)s[0] != 0xff || (uint8_t)s[1] != 0xfe || (n & 1)) return 0;
    put(out, s, n);
    if (n >= 4 && !(s[n - 4] == '\r' && s[n - 2] == '\n')) put(out, "\r\0\n\0", 4);
    for (int sc = 0; sc < PS_SCREENS; sc++) put_string(out, k_screens[sc].id, k_screens[sc].label);
    for (int i = 0; i < hulk_settings_count() && i < MAXS; i++) {
        const port_setting* st = hulk_settings_at(i);
        char id[64];
        str_id(i, -1, id, sizeof id);
        put_string(out, id, st->label);
        for (int c = 0; c < st->n; c++) {
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
    char path[200];
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
    fprintf(stderr, "hulk: %s: the Video and Gameplay Options screens (%d files patched)\n", o->path, patched);
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
