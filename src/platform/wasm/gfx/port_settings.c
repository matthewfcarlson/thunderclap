/* The port's settings and the remastered-edition switch (port_settings.h; docs/wasm-port.md "Settings and the
 * remastered edition"; HULK_WASM_GFX=1 builds only).
 *
 * Adding a setting: one row in k_settings (key, label, screen, kind, choices, faithful value, remastered default,
 * remastered_only, apply). The menus (fe_options.c) make its item from the row; the file keeps it by key. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../host/hulk_host.h"
#include "../host/hulk_io.h"
#include "port_settings.h"

int ff_replay_active(void);     /* replay.cpp */

/* the appliers (their modules) */
void hulk_wasm_frame_rate_apply(int value);                             /* gfx.c (fps2): the display rate */
void hulk_wasm_render_res_apply(int value);                             /* gfx.c: the runner's render size */
void hulk_wasm_aspect_apply(int value);                                 /* gfx.c: the display's aspect (wvid1) */
void hulk_wasm_hud_edge_apply(int value);                               /* gfx.c: the HUD frame at the edges */
void hulk_wasm_fog_apply(int value);                                    /* gfx.c: the runner's fog override */
void hulk_wasm_draw_distance_apply(int value);                          /* draw_distance.c: World::Render's fade */
void hulk_wasm_texture_pack_apply(int value);                           /* gfx.c: the runner's texture pack (wpack1) */
uint32_t hulk_wasm_texture_pack_list(char* buf, uint32_t cap);          /* gfx.c: the installed packs' names */
void hulk_wasm_quality_apply(int what, int value);                      /* gfx.c: the runner's passes (wr2) */

static void apply_remastered(int value);
static void apply_frame_rate(int value) { hulk_wasm_frame_rate_apply(value); }
static void apply_render_res(int value) { hulk_wasm_render_res_apply(value); }
static void apply_aspect(int value) { hulk_wasm_aspect_apply(value); }
static void apply_fog(int value) { hulk_wasm_fog_apply(value); }
static void apply_hud_edge(int value) { hulk_wasm_hud_edge_apply(value); }
static void apply_draw_distance(int value) {
    hulk_wasm_draw_distance_apply(value);
    hulk_wasm_quality_apply(5, value);            /* (the far field starts beyond it: rm_pass.h kDrawDistance) */
}
static void apply_texture_pack(int value) { hulk_wasm_texture_pack_apply(value); }
static void apply_mipmaps(int value) { hulk_wasm_quality_apply(1, value); }      /* (run/app/rm_pass.h Quality) */
static void apply_aniso(int value) { hulk_wasm_quality_apply(2, value); }
static void apply_msaa(int value) { hulk_wasm_quality_apply(3, value); }
static void apply_far_field(int value) { hulk_wasm_quality_apply(4, value); }
static void apply_lighting(int value) { hulk_wasm_quality_apply(6, value); }
static void apply_dyn_lights(int value) { hulk_wasm_quality_apply(7, value); }

/* Render resolution values: 1..4 a multiple of the game's 640x480; 0 the window's (display's) pixels; 720 / 1080 /
 * 1440 / 2160 that height at the display's aspect (960x720 at 4:3 ...). Output only: the game sees 640x480 at every
 * value.
 * Aspect ratio (wvid1, D234): 43 / 169 / 1610 / 219 (21:9 is 64:27, 2560x1080), 0 the window's (clamped to 4:3 ..
 * 21:9). The game's own widescreen: the display reports the aspect (as an Xbox 16:9 mode does: anamorphic 640x480),
 * cameras widen horizontally (Hor+, ComputeRealFOV 0x9f790) and the HUD lays out on the wider frame. It changes the
 * simulation (the logic view's frustum: ambient despawn, om::Stream, the rubble spawn; docs/wasm-port.md "Aspect
 * ratio"), so like the frame rate it is a per-session setting that replays and tests pin to 4:3, and netplay peers
 * must share it (the item locks during netplay).
 * HUD frame (wvid1): at an aspect wider than 4:3 the HUD's corner brackets (four fixed models drawn for a 4:3 frame)
 * stay in the middle (0, the original's 16:9) or move out to the picture's edges (1); the game lays out the rest.
 * Draw distance (wvid1): World::Render's room fade start (0x4c53bc; band 0x4c53c4 scaled with it) while it runs,
 * render-only; 270 is the original's. Fog: 0 the game's, 1 reduced (planes x2.5), 2 off (the runner's packets).
 * Texture pack (wpack1): 0 off, else an installed pack (<app dir>/mods/<pack>/, run/app/texpack.cpp) named by the
 * FNV-1a hash of its folder name (31 bits, never 0), so the file keeps the choice when packs are added or removed; the
 * choices are filled from the runner's list at load (fill_texture_packs); the remastered default is the first pack.
 * Output only (the runner replaces textures at upload).
 * Mipmaps, Anisotropic Filtering, Anti-Aliasing (wr2, D236; run/app/rm_pass.cpp): the runner's picture options,
 * output only. Mipmaps 1: the textures the game gives fewer levels than the full chain get one made by the runner (from
 * textures loaded after the change); anisotropic filtering 16 (bgfx's Metal renderer has one level: 16x); MSAA on the
 * scene target (samples; the occlusion queries' counts are scaled back). Far Field (experimental, off by default):
 * the rooms the game has not drawn, beyond the draw distance, drawn by the runner from the disc (run/app/farfield.cpp,
 * docs/far-field.md).
 * Lighting, Dynamic Lights (wlight1; run/app/lighting.cpp, docs/lighting.md): the game's lights evaluated per pixel
 * (1) instead of per vertex (0); health orbs as point lights (1) on the draws around them, the baked world included.
 * Output only. */
static port_setting k_settings[] = {
    {"remastered", "Remastered Edition", PS_SCREEN_GAMEPLAY, PS_ONOFF, 2, {0, 1}, {"Off", "On"},
     0, 1, 0, apply_remastered},
    {"frame_rate", "Frame Rate", PS_SCREEN_VIDEO, PS_CHOICE, 4, {30, 60, 120, 0},
     {"30 FPS", "60 FPS", "120 FPS", "Display"}, 30, 60, 1, apply_frame_rate},
    {"render_res", "Render Resolution", PS_SCREEN_VIDEO, PS_CHOICE, 9, {1, 2, 3, 4, 0, 720, 1080, 1440, 2160},
     {"Original (640x480)", "2x (1280x960)", "3x (1920x1440)", "4x (2560x1920)", "Window", "720p", "1080p", "1440p",
      "4K"},
     1, 0, 1, apply_render_res},
    {"aspect", "Aspect Ratio", PS_SCREEN_VIDEO, PS_CHOICE, 5, {43, 169, 1610, 219, 0},
     {"4:3 (Original)", "16:9", "16:10", "21:9", "Window"}, 43, 0, 1, apply_aspect},
    {"hud_frame", "HUD Frame", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Centred (Original)", "Screen Edges"}, 0, 1, 1,
     apply_hud_edge},
    {"draw_distance", "Draw Distance", PS_SCREEN_VIDEO, PS_CHOICE, 3, {270, 400, 700},
     {"Original", "Far", "Very Far"}, 270, 400, 1, apply_draw_distance},
    {"fog", "Fog", PS_SCREEN_VIDEO, PS_CHOICE, 3, {0, 1, 2}, {"On (Original)", "Reduced", "Off"}, 0, 1, 1, apply_fog},
    {"texture_pack", "Texture Pack", PS_SCREEN_VIDEO, PS_CHOICE, 1, {0}, {"Off"}, 0, 0, 1, apply_texture_pack},
    {"mipmaps", "Mipmaps", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Original", "Full"}, 0, 1, 1, apply_mipmaps},
    {"aniso", "Anisotropic Filtering", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 16}, {"Off (Original)", "16x"}, 0, 16, 1,
     apply_aniso},
    {"msaa", "Anti-Aliasing", PS_SCREEN_VIDEO, PS_CHOICE, 4, {0, 2, 4, 8},
     {"Off (Original)", "MSAA 2x", "MSAA 4x", "MSAA 8x"}, 0, 4, 1, apply_msaa},
    {"far_field", "Far Field", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On (Experimental)"}, 0, 0, 1,
     apply_far_field},
    {"lighting", "Lighting", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Per-Vertex (Original)", "Per-Pixel"}, 0, 1, 1,
     apply_lighting},
    {"dyn_lights", "Dynamic Lights", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "Health Orbs"}, 0, 1, 1,
     apply_dyn_lights},
};
enum { N_SETTINGS = sizeof k_settings / sizeof k_settings[0] };

static int g_loaded, g_pinned, g_user[N_SETTINGS];

int hulk_remastered_build(void) { return 1; }
int hulk_settings_count(void) { return N_SETTINGS; }
const port_setting* hulk_settings_at(int i) { return i >= 0 && i < N_SETTINGS ? &k_settings[i] : 0; }
int hulk_settings_find(const char* key) {
    for (int i = 0; i < N_SETTINGS; i++)
        if (!strcmp(k_settings[i].key, key)) return i;
    return -1;
}
int hulk_setting_index(const port_setting* s, int value) {
    for (int k = 0; k < s->n; k++)
        if (s->values[k] == value) return k;
    return 0;
}
static int valid(const port_setting* s, int value) {
    for (int k = 0; k < s->n; k++)
        if (s->values[k] == value) return 1;
    return 0;
}

static const char* settings_dir(void) {
    const char* d = getenv("HULK_SAVE_DIR");
    return d ? d : "build/wasm/save";
}

/* "key=value" lines (or comma-separated pairs: HULK_SETTINGS) into g_user */
static void parse(const char* p) {
    while (*p) {
        while (*p == ' ' || *p == '\n' || *p == '\r' || *p == ',' || *p == '\t') p++;
        const char* eq = p;
        while (*eq && *eq != '=' && *eq != '\n' && *eq != ',') eq++;
        if (*eq != '=') { p = eq; continue; }
        char key[64];
        size_t n = (size_t)(eq - p) < sizeof key - 1 ? (size_t)(eq - p) : sizeof key - 1;
        memcpy(key, p, n);
        key[n] = 0;
        int i = hulk_settings_find(key), v = strncmp(eq + 1, "display", 7) ? atoi(eq + 1) : 0;   /* (fps2's spelling) */
        if (i >= 0 && valid(&k_settings[i], v)) g_user[i] = v;
        p = eq + 1;
        while (*p && *p != '\n' && *p != ',') p++;
    }
}

static void save(void) {
    if (g_pinned) return;
    char path[600], buf[1024];
    hio_mkdir(settings_dir());
    snprintf(path, sizeof path, "%s/port_settings.txt", settings_dir());
    int32_t f = hio_open(path, HIO_CREATE);
    if (f < 0) return;
    int n = 0;
    for (int i = 0; i < N_SETTINGS; i++)
        n += snprintf(buf + n, sizeof buf - (size_t)n, "%s=%d\n", k_settings[i].key, g_user[i]);
    hio_write(f, buf, (uint32_t)n, 0);
    hio_close(f);
}

int hulk_setting_locked(int i) {
    hulk_settings_load();
    const port_setting* s = hulk_settings_at(i);
    return s && s->remastered_only && !g_user[0];
}
int hulk_remastered(void) {
    hulk_settings_load();
    return g_user[0] != 0;
}
int hulk_setting_user(int i) {
    hulk_settings_load();
    return i >= 0 && i < N_SETTINGS ? g_user[i] : 0;
}
static int effective(int i) { return hulk_setting_locked(i) ? k_settings[i].faithful : g_user[i]; }
int hulk_setting(const char* key) {
    hulk_settings_load();
    int i = hulk_settings_find(key);
    return i < 0 ? 0 : effective(i);
}

static void apply_all(void) {
    for (int i = 1; i < N_SETTINGS; i++)
        if (k_settings[i].apply) k_settings[i].apply(effective(i));
}
static void apply_remastered(int value) { (void)value; apply_all(); }

/* The texture_pack row's choices: Off and each pack the runner found (names shown as ASCII letters, digits and simple
 * punctuation, at most 24 characters) */
static char g_pack_names[PS_MAX_CHOICES][28];
static void fill_texture_packs(void) {
    int i = hulk_settings_find("texture_pack");
    if (i < 0) return;
    port_setting* s = &k_settings[i];
    char buf[1024];
    uint32_t count = hulk_wasm_texture_pack_list(buf, sizeof buf);
    const char* p = buf;
    s->n = 1;
    for (uint32_t k = 0; k < count && s->n < PS_MAX_CHOICES && *p; k++) {
        const char* e = strchr(p, '\n');
        if (!e) break;
        uint32_t h = 2166136261u;                 /* (texpack_name_hash: FNV-1a of the folder name) */
        for (const char* q = p; q < e; q++) h = (h ^ (uint8_t)*q) * 16777619u;
        h &= 0x7fffffff;
        char* o = g_pack_names[s->n];
        int n = 0;
        for (const char* q = p; q < e && n < 24; q++) {
            char c = *q;
            int ok = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ' ||
                     c == '-' || c == '.' || c == '(' || c == ')' || c == '\'' || c == '!' || c == '&';
            o[n++] = ok ? c : c == '_' ? ' ' : '?';
        }
        o[n] = 0;
        s->values[s->n] = h ? (int)h : 1;
        s->names[s->n] = o;
        s->n++;
        p = e + 1;
    }
    s->remastered = s->n > 1 ? s->values[1] : 0;
}

/* Runs that test or replay start from the faithful values and leave the file alone: a recording (its clock decides),
 * HULK_INPUT (scripted determinism runs) and HULK_ROLLTEST. HULK_SETTINGS pins values in any run. */
void hulk_settings_load(void) {
    if (g_loaded) return;
    g_loaded = 1;
    fill_texture_packs();
    const char* in = getenv("HULK_INPUT");
    const char* roll = getenv("HULK_ROLLTEST");
    const char* file = getenv("HULK_SETTINGS_FILE");      /* 1: a scripted run reads and writes the file (tests) */
    g_pinned = ff_replay_active() || (((in && *in) || (roll && *roll)) && !(file && *file == '1'));
    for (int i = 0; i < N_SETTINGS; i++)
        g_user[i] = g_pinned ? k_settings[i].faithful : k_settings[i].remastered;
    if (!g_pinned) {
        char path[600], buf[1024];
        snprintf(path, sizeof path, "%s/port_settings.txt", settings_dir());
        int32_t f = hio_open(path, HIO_READ);
        if (f >= 0) {
            int32_t n = hio_read(f, buf, sizeof buf - 1, 0);
            hio_close(f);
            if (n > 0) {
                buf[n] = 0;
                parse(buf);
            }
        }
    }
    const char* e = getenv("HULK_SETTINGS");
    if (e && *e) {
        g_pinned = 1;                   /* pinned values are never saved */
        parse(e);
    }
    char line[512];
    int n = 0;
    for (int i = 0; i < N_SETTINGS && n < (int)sizeof line - 40; i++)
        n += snprintf(line + n, sizeof line - (size_t)n, " %s=%d", k_settings[i].key, effective(i));
    fprintf(stderr, "hulk: settings%s%s\n", line, g_pinned ? " (pinned)" : "");
    apply_all();
}

void hulk_setting_choose(int i, int value) {
    hulk_settings_load();
    const port_setting* s = hulk_settings_at(i);
    if (!s || !valid(s, value) || hulk_setting_locked(i) || g_user[i] == value) return;
    g_user[i] = value;
    fprintf(stderr, "hulk: setting %s=%d (the options menu)\n", s->key, value);
    save();
    if (s->apply) s->apply(effective(i));
}
