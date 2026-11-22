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

static void apply_remastered(int value);
static void apply_frame_rate(int value) { hulk_wasm_frame_rate_apply(value); }
static void apply_render_res(int value) { hulk_wasm_render_res_apply(value); }

/* Render resolution values: 1..4 a multiple of the game's 640x480; 0 the window's (display's) pixels; 720 / 1080 /
 * 1440 / 2160 that height at the frame's 4:3 (960x720 ...). Output only: the game sees 640x480 at every value. */
static const port_setting k_settings[] = {
    {"remastered", "Remastered Edition", PS_SCREEN_GAMEPLAY, PS_ONOFF, 2, {0, 1}, {"Off", "On"},
     0, 1, 0, apply_remastered},
    {"frame_rate", "Frame Rate", PS_SCREEN_VIDEO, PS_CHOICE, 4, {30, 60, 120, 0},
     {"30 FPS", "60 FPS", "120 FPS", "Display"}, 30, 60, 1, apply_frame_rate},
    {"render_res", "Render Resolution", PS_SCREEN_VIDEO, PS_CHOICE, 9, {1, 2, 3, 4, 0, 720, 1080, 1440, 2160},
     {"Original (640x480)", "2x (1280x960)", "3x (1920x1440)", "4x (2560x1920)", "Window", "720p", "1080p", "1440p",
      "4K"},
     1, 0, 1, apply_render_res},
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

/* Runs that test or replay start from the faithful values and leave the file alone: a recording (its clock decides),
 * HULK_INPUT (scripted determinism runs) and HULK_ROLLTEST. HULK_SETTINGS pins values in any run. */
void hulk_settings_load(void) {
    if (g_loaded) return;
    g_loaded = 1;
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
    char line[256];
    int n = 0;
    for (int i = 0; i < N_SETTINGS; i++)
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
