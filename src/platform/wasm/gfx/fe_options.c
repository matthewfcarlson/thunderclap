/* The app's own options in the game's menus (D224; docs/wasm-port.md "The frame-rate option"; HULK_WASM_GFX=1
 * builds only).
 *
 * "Frame Rate: 30 FPS / 60 FPS" is a fourth item of the camera options screen, in the front end's options and in the
 * pause menu. The menus are game data (misc.rcf's frontend\fe_real.txt and fe_run.txt, the English strings in
 * frontend\lang\str_*.txt): nothing of them is in the repository. When the game opens misc.rcf the host serves it
 * with those three files patched (an overlay: the archive's directory names the patched copies, appended after its
 * end; every other byte is the disc's), so the parser builds the item like any other:
 *
 *   AddNamedValueInt "PortFrameRate" 0 "PortFrameRateChanged"     (after CameraInvertY's)
 *   AddTextSelector "FEsubMenu_text4" / "FEpause_text4" { ... NamedValue "PortFrameRate" ... }
 *
 * Two entry hooks (tools/wasm_port.py GFX_APP_HOOKS) connect it to the host:
 * - 0x000df9e0, the front end's lookup of an int callback by name: "PortFrameRateChanged" is a handler object of the
 *   host's (a vftable whose call slot is a host method, ff_host_method), which NamedValueInt::vfunc_1 0x000f8dd0 calls
 *   with the value when the selector changes it;
 * - 0x000f8e70, NamedValueInt's Create(name, default, callback): "PortFrameRate" starts at the saved setting, and the
 *   host remembers the objects (one per front-end slot) to keep them showing the same value;
 * - 0x000b5ad0, which sets the camera-invert selectors from the stored flags (the front end's set-up 0x000c3ea0 and
 *   the pause menu's 0x000bcf40): a selector shows its first choice until the game's code sets it, so the hook sets
 *   ours to the setting the same way (vfunc_25, the choice's index = the value).
 *
 * The setting: 0 = 30 fps in gameplay (the original's SwapBuffers pacing, the default), 1 = 60. It is saved in
 * HULK_SAVE_DIR/port_settings.txt ("frame_rate=60"), not in the game's save. Replays ignore the file (the recording's
 * clock decides) and never write it. hulk_wasm_fps60() is what the frame end (gfx.c: one 60 Hz field a present
 * instead of two) and the present pacing (sdl_platform.cpp platformFramePace) follow. HULK_FE_OPTIONS=0 serves the
 * disc's misc.rcf unpatched. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "../host/hulk_host.h"
#include "../host/hulk_io.h"
#include "../host/sim.h"

int ff_replay_active(void);     /* replay.cpp */

#define NV_NAME "PortFrameRate"
#define CB_NAME "PortFrameRateChanged"

/* Game-facing state of this host file (the setting the game clock follows, the game objects and the handler the game
 * holds) is game state: it lives in the tree's snapshotted section (tools/wasm_port.py GAME_STATE_SECTION), so a
 * restore puts back the setting with the menus' objects that show it (wroll1). The settings file is host state: after
 * a restore past a change it keeps the newer value, which the next start reads (g_loaded stays: no reread). */
#define GAME_STATE __attribute__((section("hulk_game_state")))
static int g_loaded;
GAME_STATE static int g_fps60;

static const char* settings_path(char* out, size_t cap) {
    const char* d = getenv("HULK_SAVE_DIR");
    snprintf(out, cap, "%s/port_settings.txt", d ? d : "build/wasm/save");
    return out;
}

static void settings_load(void) {
    if (g_loaded) return;
    g_loaded = 1;
    if (ff_replay_active()) return;
    char path[600], buf[256];
    int32_t f = hio_open(settings_path(path, sizeof path), HIO_READ);
    if (f < 0) return;
    int32_t n = hio_read(f, buf, sizeof buf - 1, 0);
    hio_close(f);
    if (n <= 0) return;
    buf[n] = 0;
    const char* p = strstr(buf, "frame_rate=");
    if (p) g_fps60 = atoi(p + 11) == 60;
    if (g_fps60) fprintf(stderr, "hulk: frame rate 60 (%s)\n", path);
}

static void settings_save(void) {
    if (ff_replay_active()) return;
    char path[600], line[64];
    const char* d = getenv("HULK_SAVE_DIR");
    hio_mkdir(d ? d : "build/wasm/save");
    int32_t f = hio_open(settings_path(path, sizeof path), HIO_CREATE);
    if (f < 0) return;
    int n = snprintf(line, sizeof line, "frame_rate=%d\n", g_fps60 ? 60 : 30);
    hio_write(f, line, (uint32_t)n, 0);
    hio_close(f);
}

/* 1: gameplay at 60 fps (the menu's setting, or HULK_FPS_CAP=60) */
int hulk_wasm_fps60(void) {
    static int cap60 = -1;
    if (cap60 < 0) {
        const char* c = getenv("HULK_FPS_CAP");
        cap60 = c && atoi(c) == 60;
    }
    settings_load();
    return g_fps60 || cap60;
}

/* ------------------------------------------------------------------------------------------- the hooks */
/* NamedValueInt (32-bit layout, src/game/global/unk_0f86f0.cpp): name at +0x18 (0x28 bytes), the committed value at
 * +0x40, the pending one at +0x44 (vfunc_1 commits it and calls the callback with it) */
#define NV_NAME_OFF 0x18
#define NV_VALUE 0x40
#define NV_PENDING 0x44
GAME_STATE static uint32_t g_nv[4], g_nv_vft;     /* the "PortFrameRate" objects (one per front-end slot) and their vftable */

static int nv_ours(uint32_t p) {
    return p && *(uint32_t*)PTR(p) == g_nv_vft && !strncmp((const char*)PTR(p + NV_NAME_OFF), NV_NAME, 0x28);
}

/* the handler's call slot: (this, value) */
static void on_frame_rate(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    (void)ecx, (void)edx, (void)rb;
    int v = ARG(0) != 0;
    if (getenv("HULK_FE_OPTIONS_LOG")) fprintf(stderr, "hulk: frame %u: %s -> %u\n", SIM->frame, CB_NAME, ARG(0));
    if (v != g_fps60) {
        g_fps60 = v;
        fprintf(stderr, "hulk: frame rate %d (the options menu)\n", v ? 60 : 30);
        settings_save();
    }
    for (int i = 0; i < 4; i++)         /* the other slot's selector shows the same */
        if (nv_ours(g_nv[i])) {
            *(uint32_t*)PTR(g_nv[i] + NV_VALUE) = (uint32_t)v;
            *(uint32_t*)PTR(g_nv[i] + NV_PENDING) = (uint32_t)v;
        }
}

GAME_STATE static uint32_t g_handler[2], g_handler_vft[4];

void ffgo_000df9e0(uint32_t, uint32_t, void*, void*);   /* the game's int-callback lookup (the hook's original) */
void ffh_hulk_app_fe_callback(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    if (ARG(0) && !strcmp((const char*)PTR(ARG(0)), CB_NAME)) {
        if (!g_handler[0]) {
            for (int i = 0; i < 4; i++) g_handler_vft[i] = ff_host_method(on_frame_rate);
            g_handler[0] = (uint32_t)(uintptr_t)g_handler_vft;
        }
        RET((uint32_t)(uintptr_t)g_handler);
        return;
    }
    ffgo_000df9e0(ecx, edx, st, rb);
}

void ffgo_000f8e70(uint32_t, uint32_t, void*, void*);   /* NamedValueInt's Create (the hook's original) */
void ffh_hulk_app_named_int(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    int ours = ARG(0) && !strcmp((const char*)PTR(ARG(0)), NV_NAME);
    if (ours) ARG(1) = (uint32_t)hulk_wasm_fps60();
    ffgo_000f8e70(ecx, edx, st, rb);
    uint32_t p = (uint32_t)*(uint64_t*)rb;
    if (ours && p) {
        g_nv_vft = *(uint32_t*)PTR(p);
        int k = 0;
        while (k < 3 && nv_ours(g_nv[k]) && g_nv[k] != p) k++;
        g_nv[k] = p;
        if (getenv("HULK_FE_OPTIONS_LOG"))
            fprintf(stderr, "hulk: frame %u: %s at 0x%08x = %u\n", SIM->frame, NV_NAME, p, ARG(1));
    }
}

void ffgo_000b5ad0(uint32_t, uint32_t, void*, void*);   /* the camera selectors' sync (the hook's original) */
void ffh_hulk_app_fe_sync(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_000b5ad0(ecx, edx, st, rb);
    static const char sel[] = "port_frame_rate_selector";
    /* as 0x000b5ad0 finds its selectors: the control by name (0x000fc260), dynamic_cast (0x00344e74) to the selector */
    uint32_t c = ff_call(0x000fc260u, 1, (uint32_t)(uintptr_t)sel);
    uint32_t s = c ? ff_call(0x00344e74u, 5, c, 0, 0x0049dba4u, 0x0049dbbcu, 0) : 0;
    if (s) ff_call_this(((uint32_t*)PTR(*(uint32_t*)PTR(s)))[25], s, 1, (uint32_t)hulk_wasm_fps60());
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

static const char k_value[] = "AddNamedValueInt \"" NV_NAME "\" 0 \"" CB_NAME "\"\r\n";
static const char k_item_fe[] =
    "    AddTextSelector \"FEsubMenu_text4\"\r\n"
    "    {\r\n"
    "        text \"TBS_PORT_FRAME_RATE\" 1\r\n"
    "\r\n"
    "        name \"port_frame_rate_selector\"\r\n"
    "        TextSelection \"\" TBS_PORT_FPS_30 TBS_PORT_FPS_60\r\n"
    "        NamedValue \"" NV_NAME "\"\r\n"
    "\r\n"
    "        OnHighlight function \"UpdateControlButtonString\" \"DynamicControlButtonLabel\"  \"2\"\r\n"
    "        $MACRO_INSERT menu_item_4\r\n"
    "    }\r\n"
    "\r\n";
static const char k_item_pause[] =
    "    AddTextSelector \"FEpause_text4\"\r\n"
    "    {\r\n"
    "        text \"TBS_PORT_FRAME_RATE\" 1\r\n"
    "\r\n"
    "        name \"port_frame_rate_selector\"\r\n"
    "        TextSelection \"\" TBS_PORT_FPS_30 TBS_PORT_FPS_60\r\n"
    "        NamedValue \"" NV_NAME "\"\r\n"
    "\r\n"
    "        OnHighlight function \"UpdateControlButtonString\" \"DynamicControlButtonLabel\"  \"2\"\r\n"
    "\r\n"
    "        SelectedDrawable \"FE_selectBar\"\r\n"
    "        NotSelectedDrawable \"FE_backgroundBar\"\r\n"
    "\r\n"
    "        TransitionAnimEnter \"slide_down4\"\r\n"
    "        TransitionAnimExit  \"slide_down4\"\r\n"
    "    }\r\n"
    "\r\n";
static const char* const k_strings[][2] = {
    {"TBS_PORT_FRAME_RATE", "Frame Rate"}, {"TBS_PORT_FPS_30", "30 FPS"}, {"TBS_PORT_FPS_60", "60 FPS"},
};

/* fe_real.txt / fe_run.txt: the named value after CameraInvertY's, the item at the end of "camera_options" (before
 * its control-button label). 0 when an anchor is missing (another disc's text): the file stays as it is. */
static int patch_fe(const char* s, uint32_t n, const char* item, buf_t* out) {
    const char* a = find(s, n, s, "AddNamedValueInt \"CameraInvertY\"");
    const char* scr = find(s, n, s, "AddScreen \"camera_options\"");
    const char* b = scr ? find(s, n, scr, "$MACRO_INSERT SetupControlButtonLabel") : 0;
    if (!a || !b || b < a || find(s, n, s, NV_NAME)) return 0;
    a = line_end(s, n, a);
    while (b > scr && b[-1] != '\n') b--;      /* the start of its line */
    put(out, s, (uint32_t)(a - s));
    puts_(out, k_value);
    put(out, a, (uint32_t)(b - a));
    puts_(out, item);
    put(out, b, (uint32_t)(s + n - b));
    return 1;
}

/* str_<lang>.txt (UTF-16LE, "KEY\tTEXT\r\n" lines): the item's strings, in English, appended */
static int patch_strings(const char* s, uint32_t n, buf_t* out) {
    if (n < 2 || (uint8_t)s[0] != 0xff || (uint8_t)s[1] != 0xfe || (n & 1)) return 0;
    put(out, s, n);
    if (n >= 4 && !(s[n - 4] == '\r' && s[n - 2] == '\n')) put(out, "\r\0\n\0", 4);
    for (unsigned i = 0; i < sizeof k_strings / sizeof k_strings[0]; i++) {
        char line[128];
        int l = snprintf(line, sizeof line, "%s\t%s\r\n", k_strings[i][0], k_strings[i][1]);
        for (int k = 0; k < l; k++) put(out, (char[2]){line[k], 0}, 2);
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
        int ok = i == 0 ? patch_fe(s, size, k_item_fe, &out)
               : i == 1 ? patch_fe(s, size, k_item_pause, &out)
               : patch_strings(s, size, &out);
        free(s);
        if (!ok) { free(out.p); continue; }
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
    fprintf(stderr, "hulk: %s: the options menus' frame-rate item (%d files patched)\n", o->path, patched);
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
