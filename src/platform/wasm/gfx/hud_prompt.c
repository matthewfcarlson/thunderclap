/* Brief Move Prompts (port_settings.c `move_prompts`, wprompt1, D251; HULK_WASM_GFX=1 builds only).
 *
 * The HUD's button hint (the Y icon and "Steel Fists" at the top centre) is HUDOverlay's one hint slot, set from Lua:
 * hud_triggerButtonHintBegin(button, text id, seconds) (0x000ce700 -> 0x000ce5c0) and hud_triggerButtonHintEnd
 * (0x000cad60). The fight script's weaponization chunk (scripts/fight/common.fig) begins it with the move's text
 * (TBS_INSTRUCTION_FISTS, ...) and -1 seconds (no time limit) when the Hulk holds a weaponizable prop and the move is
 * unlocked, and ends it only when the chunk runs again without one, so in play the prompt stays up long after the cars
 * are thrown (D251). HUDOverlay (32-bit layout): +0x214 the hint's id (a counter), +0x218 the button icon (a sprite),
 * +0x224 shown (0 = fading out), +0x228/+0x22c the text id's hash (FUN_002672f0), +0x23c seconds since the last Begin,
 * +0x240 the limit. Update 0x000ce0d0 (from vfunc_3) fades it; FUN_000cf740 draws it (the text box 0x000ce280, then the
 * icon), called once from vfunc_4 0x000d05f0, the HUD's render.
 *
 * With the setting on, a weaponization prompt is hidden once it has been up for PROMPT_SECONDS or the player pressed Y
 * (its button) while it showed; a different prompt, or the same one begun again after it went away, shows again. It
 * is picture only: a site hook on vfunc_4's call of FUN_000cf740 (tools/wasm_port.py GFX_APP_SITE_HOOKS) always runs
 * the original, which updates the hint's state exactly as in the faithful game; a hidden prompt's draws are only
 * withheld from the runner (gfx.c hulk_gfx_drop_draws). Nothing in game memory changes, so it is not a per-session
 * setting. The few words remembered here are display state (a restore may show a prompt again for a moment).
 * Mission hints (jump points, the church, Hammer Toss, ...) are left alone: only the five weaponization texts.
 * HULK_PROMPT_LOG=1 logs each prompt's show and hide. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../host/hulk_host.h"
#include "../host/sim.h"

#define HUD_HINT_KEY_LO 0x228
#define HUD_HINT_KEY_HI 0x22c
#define HUD_HINT_SHOWN 0x224
#define HUD_HINT_ELAPSED 0x23c
#define PROMPT_SECONDS 5.0f
#define PAD_Y 5                 /* XINPUT_GAMEPAD: wButtons, then the analog buttons A, B, X, Y, ... */
#define PAD_PRESSED 30          /* (XINPUT_GAMEPAD_MAX_CROSSTALK) */

int hulk_gfx_drop_draws;        /* gfx.c: draws submitted while set are not passed to the runner */

static int g_on;
static uint64_t g_keys[5];
static struct {
    uint64_t key;               /* the prompt being tracked (0: none) */
    float shown, last;          /* seconds shown; the hint's own clock at the last draw */
    int was_shown, y_down, hidden;
} g;

static uint64_t text_hash(const char* s) {     /* FUN_002672f0(s, 0, 0) */
    uint64_t v = 0;
    for (; *s; s++) v = v * 0x1003full ^ (uint64_t)(int64_t)(signed char)*s;
    return v;
}

static int log_on(void) {
    static int v = -1;
    if (v < 0) v = getenv("HULK_PROMPT_LOG") ? atoi(getenv("HULK_PROMPT_LOG")) : 0;
    return v;
}

void hulk_wasm_move_prompts_apply(int value) {
    static const char* ids[5] = {"TBS_INSTRUCTION_FISTS", "TBS_INSTRUCTION_SHIELD", "TBS_INSTRUCTION_BOWLING",
                                 "TBS_INSTRUCTION_BALL_CHAIN", "TBS_INSTRUCTION_MISSILE_PACK"};
    for (int k = 0; k < 5; k++) g_keys[k] = text_hash(ids[k]);
    g_on = value != 0;
}

static int weaponization(uint64_t key) {
    for (int k = 0; k < 5; k++)
        if (key == g_keys[k]) return 1;
    return 0;
}

static int y_down(void) {
    for (int p = 0; p < 4; p++)
        if (SIM->pads[p][PAD_Y] > PAD_PRESSED) return 1;
    return 0;
}

/* whether the hint HUDOverlay `hud` holds is to be drawn */
static int prompt_hidden(uint32_t hud) {
    const uint8_t* h = (const uint8_t*)PTR(hud);
    uint64_t key = (uint64_t)*(const uint32_t*)(h + HUD_HINT_KEY_HI) << 32 | *(const uint32_t*)(h + HUD_HINT_KEY_LO);
    int shown = h[HUD_HINT_SHOWN] != 0;
    float clock = *(const float*)(h + HUD_HINT_ELAPSED);
    if (!key || !weaponization(key)) {
        g.key = 0;
        return 0;
    }
    if (key != g.key || (shown && !g.was_shown)) {      /* a new prompt (or the same one begun again) */
        g.key = key;
        g.shown = 0;
        g.last = clock;
        g.y_down = y_down();
        g.hidden = 0;
        if (log_on()) fprintf(stderr, "hulk: frame %u: move prompt %016llx shown\n", SIM->frame, (unsigned long long)key);
    }
    g.was_shown = shown;
    if (shown && !g.hidden) {
        g.shown += clock >= g.last ? clock - g.last : clock;    /* (a Begin while it shows restarts the hint's clock) */
        int y = y_down(), pressed = y && !g.y_down;
        g.y_down = y;
        if (pressed || g.shown >= PROMPT_SECONDS) {
            g.hidden = 1;
            if (log_on())
                fprintf(stderr, "hulk: frame %u: move prompt %016llx hidden (%s, %.2f s)\n", SIM->frame,
                        (unsigned long long)key, pressed ? "Y pressed" : "time", (double)g.shown);
        }
    }
    g.last = clock;
    return g.hidden;
}

void ffg_000cf740(uint32_t, uint32_t, void*, void*);    /* the hint's draw (the site hook's original) */
void ffh_hulk_app_hud_prompt(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    int hide = g_on && prompt_hidden(ecx);
    if (!g_on) g.key = 0;
    hulk_gfx_drop_draws = hide;
    ffg_000cf740(ecx, edx, st, rb);
    hulk_gfx_drop_draws = 0;
}
