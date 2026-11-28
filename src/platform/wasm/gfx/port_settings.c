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
void hulk_wasm_tutorial_skip_apply(int value);                          /* tutorial_skip.c: the star (wskip1) */
void hulk_wasm_traversal_apply(int value);                              /* traversal.c: the remaster moves (wtrav1) */
void hulk_wasm_traversal_force_charge(int value);                       /* traversal.c: developer forces (wdev1) */
void hulk_wasm_traversal_force_leap(int value);
void hulk_wasm_traversal_force_moves(int value);
void hulk_wasm_traversal_force_fling(int value);                        /* (wtrav2) */
void hulk_wasm_traversal_force_air(int value);
void hulk_wasm_coop_apply(int value);                                   /* coop.c: Hulks in one instance (wcoop1) */
void hulk_wasm_comic_skins_apply(int value);                            /* skins.c: comic skins (wskin1) */
uint32_t hulk_wasm_texture_pack_list(char* buf, uint32_t cap);          /* gfx.c: the installed packs' names */
void hulk_wasm_quality_apply(int what, int value);                      /* gfx.c: the runner's passes (wr2) */
void hulk_wasm_text_spacing_apply(int value);                           /* text_spacing.c: glyph advances (wtext2) */
void hulk_wasm_move_prompts_apply(int value);                           /* hud_prompt.c: the HUD's move prompt (wprompt1) */

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
static void apply_hdr(int value) { hulk_wasm_quality_apply(8, value); }
static void apply_ao(int value) { hulk_wasm_quality_apply(9, value); }
static void apply_shadows(int value) { hulk_wasm_quality_apply(10, value); }
static void apply_windows(int value) { hulk_wasm_quality_apply(11, value); }
static void apply_reflections(int value) { hulk_wasm_quality_apply(12, value); }
static void apply_night_lights(int value) { hulk_wasm_quality_apply(13, value); }
static void apply_atmosphere(int value) { hulk_wasm_quality_apply(14, value); }
static void apply_grade(int value) { hulk_wasm_quality_apply(15, value); }
static void apply_upscaler(int value) { hulk_wasm_quality_apply(17, value); }
static void apply_render_scale(int value) { hulk_wasm_quality_apply(18, value); }
static void apply_grass(int value) { hulk_wasm_quality_apply(16, value); }
static void apply_perf_overlay(int value) { hulk_wasm_quality_apply(19, value); }
static void apply_hud_res(int value) { hulk_wasm_quality_apply(20, value); }
static void apply_particles(int value) { hulk_wasm_quality_apply(21, value); }
static void apply_char_light(int value) { hulk_wasm_quality_apply(22, value); }
static void apply_contact(int value) { hulk_wasm_quality_apply(23, value); }
static void apply_bounce(int value) { hulk_wasm_quality_apply(24, value); }
static void apply_decals(int value) { hulk_wasm_quality_apply(25, value); }
static void apply_dof(int value) { hulk_wasm_quality_apply(26, value); }          /* (wlens1: run/app/lens.cpp) */
static void apply_lens_flare(int value) { hulk_wasm_quality_apply(27, value); }
static void apply_vignette(int value) { hulk_wasm_quality_apply(28, value); }
static void apply_aberration(int value) { hulk_wasm_quality_apply(29, value); }
static void apply_grain(int value) { hulk_wasm_quality_apply(30, value); }
static void apply_water(int value) { hulk_wasm_quality_apply(31, value); }
static void apply_light_shafts(int value) { hulk_wasm_quality_apply(32, value); }   /* (wrays1: run/app/rays.cpp) */
static void apply_text_spacing(int value) { hulk_wasm_text_spacing_apply(value); }
static void apply_move_prompts(int value) { hulk_wasm_move_prompts_apply(value); }
static void apply_tutorial_skip(int value) { hulk_wasm_tutorial_skip_apply(value); }
static void apply_traversal(int value) { hulk_wasm_traversal_apply(value); }
void hulk_wasm_net_apply(int value);                                   /* netplay.c: online co-op (wnet1) */
static void apply_coop(int value) {             /* (only a change: at load it is off, as it was) */
    static int last;
    if (value != last) hulk_wasm_net_apply(value);
    last = value;
}
#define DIGITS {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}
static int is_session_row(const char* key) { return !strncmp(key, "coop", 4); }   /* never saved or loaded */
static void apply_developer(int value);

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
 * Output only.
 * HDR, Ambient Occlusion, Shadows (wr3a; run/app/hdr.cpp, ao.cpp, shadows.cpp, docs/hdr-shadows.md): the scene in half
 * floats, tone mapped before the game's own bloom (1); screen-space occlusion on the world and the objects (1); sun
 * shadow maps for the characters and objects, onto the world and each other, replacing the game's stencil shadows (1 one
 * 1024 map, 2 two 2048 cascades). Output only.
 * Windows (wlook0; run/app/windows.cpp, docs/look.md "Interior mapping"): the buildings' window glass shows a room
 * behind it (1: a procedural room per window bay, ray-cast in the fragment shader, lit by day or by a lamp where the
 * game paints the pane lit, the game's reflection over it by Fresnel) instead of the game's painted glass (0). Output
 * only.
 * Reflections (wssr1; run/app/ssr.cpp, docs/reflections.md): screen-space reflections on wet ground (strongest at
 * night), building glass and environment-mapped objects, over the game's own reflection maps (1 half size, 2 full
 * size). Output only.
 * Night Lights (wlook2; run/app/nightlights.cpp, docs/night.md): the city's own glows (street lamps, signs, vehicle
 * lights) light the world around them at night (1): pools under the lamps, spill on walls, cars and characters; per
 * pixel, from a tiled light list. Output only.
 * Atmosphere (wlook2; run/app/atmosphere.cpp, docs/night.md): the game's sky dome re-graded with a gradient, stars, a
 * moon and the city's glow on the clouds, height fog and aerial perspective over the game's own fog, and the lamps'
 * glow in the night mist (1); 0 the game's sky and fog. The Fog row still sets the game's fog and scales this one.
 * Output only.
 * Grade (wlook1; run/app/grade.cpp, docs/look.md "Colour grade"): a colour grade of the scene before the game's own
 * effects and the HUD (1 Natural: a little more contrast and colour; 2 Cinematic: firmer contrast, cool shadows and
 * warm highlights by the location's time of day, a soft vignette), inside HDR's tone map (no pass of its own: with HDR
 * off nothing is graded). Output only.
 * Anti-Aliasing's TAA (wperf1; run/app/taa.cpp, docs/performance.md): value 1, the scene single-sampled, its draws
 * jittered and resolved against a reprojected history before the game's effects. Output only.
 * Upscaler, Render Scale (wperf1; run/app/upscale.cpp, docs/performance.md): the scene drawn at a share of the
 * render resolution (100% .. 50%: FSR's Ultra Quality 1.3x, Quality 1.5x, Balanced 1.7x, Performance 2x; 0, Auto,
 * the largest share within 1280x960 pixels, at least 50%: app.cpp rrSize) and brought
 * to the present size by the upscaler: Off the bilinear stretch as before, FSR 1 (AMD's EASU + RCAS, MIT), and
 * (wperf2) the temporal ones, which also anti-alias and so imply TAA whatever the Anti-Aliasing row says ("(TAA)" in
 * their names): Temporal (ours, an FSR 2-class resolve: run/app/upscale.cpp) and MetalFX (Apple's, macOS; elsewhere
 * ours). Auto: the platform's temporal upscaler (MetalFX on macOS, ours elsewhere) when Anti-Aliasing is TAA, else
 * FSR 1 (an MSAA choice stays MSAA); on Android FSR 1. Output only (the game sees 640x480 at every scale).
 * Grass (wgrass1; run/app/grass.cpp, docs/grass.md): blades on the game's grass ground, instanced clumps in world space
 * taking the ground's colour, swaying in the wind and bent aside by the characters, fading out to the flat ground with
 * distance (1 low: 12 units, 3 blades a clump; 2 high: 24 units, 5 blades). Output only: nothing collides with them.
 * HUD Resolution (whud1; run/app/hud.cpp, docs/performance.md 4.3): when the scene is drawn below the window's size
 * and upscaled, the HUD, menus and subtitles (the frame's draws after the game's last effect) are drawn again at the
 * present size over the upscaled frame (1, Display) instead of being upscaled with it (0). Output only.
 * Particles (wfx1; run/app/particles.cpp, docs/particles.md): the game's smoke, dust, fire and explosion sprites fade
 * where they meet the ground and walls and near the camera (1, Soft), smoke and dust take the sun's shadow and the Night
 * Lights' city lights, and under HDR additive flashes are toned down; 0 the game's flat sprites. Output only.
 * Character Lighting (whulk1; run/app/lighting.cpp, docs/lighting.md "Characters"): the Hulk (every co-op Hulk too:
 * the game's skinned draws) drawn per pixel with a rim of back light along his silhouette (the key light's, and at
 * night the city's lights and the night sky's), light wrapped a little past the terminator and rolling off softly
 * instead of clipping flat, and detail normals from his texture (1, Enhanced). Output only.
 * Contact Shadows / Bounce Light (wshadow1; run/app/contact.cpp, docs/hdr-shadows.md "Contact shadows and bounce
 * light"): short screen-space shadows towards the sun where feet, tyres, debris and props meet the ground, and one
 * bounce of the lit surfaces' colour onto their neighbours (the sunlit street onto walls and the Hulk, his green onto
 * the ground). Each Off / On (hdr's choice strings, fe_options.c k_borrow). Output only.
 * Lasting Decals (wdecal1; run/app/decals.cpp, docs/destruction.md "Lasting decals"): the cracks, craters, scorch
 * marks and footprints the Hulk leaves stay (the runner keeps up to 1,024 past the game's 85 until the game clears its
 * queue, at a mission's end), and every decal is fitted to the surface the camera sees: pulled over it (no z-fighting)
 * and faded where the collision mesh it lies on floats over a kerb or a gap. Off / On (hdr's strings). Output only.
 * Lens effects (wlens1, D249; run/app/lens.cpp, docs/hdr-shadows.md "Lens effects"): drawn over the scene at the
 * game's first framebuffer effect (with HDR on, after its tone map), so the game's bloom, fader and the HUD come after
 * them and the HUD is never touched. Cutscene Depth of Field: in the game's in-engine cutscenes only (the letterbox is
 * up; lens.c), never in play or on movies, focused on the Hulk when he is in the shot, else the nearest subject in
 * the frame's middle, with a bokeh gather; wide shots stay sharp (a thin lens's blur).
 * Lens Flare: ghosts and a soft glare from the sun (the key light's direction, where the sky is clear) and from small
 * strong lights (lamps, signs, orbs, flashes). Vignette: a soft darkening of the corners (Cinematic grade has its own,
 * lighter). Chromatic Aberration: colour fringes at the screen's edges, only while the camera shakes hard (big
 * impacts; lens.c reads the camera's shakes). Film Grain: a fine, luminance-weighted grain. Each Off / On (hdr's choice
 * strings). Output only.
 * Water (wwater1; run/app/water.cpp, docs/water.md): the game's sea, lake and river surfaces ripple in the key
 * light, bend what the game draws under them, clear in the shallows, reflect the sky and (with Reflections) the scene
 * by Fresnel, glint in the sun and the moon, and foam at the shore (1, Enhanced); 0 the game's flat water. Output only.
 * Light Shafts (wrays1; run/app/rays.cpp, docs/light-shafts.md): the sun's light in the air, marched through the sun
 * shadows' atlas, so shafts show between buildings and over canyon edges (with Shadows on), and at night soft cones of
 * light in the mist under the street lamps (with Night Lights on) (1, On). Output only.
 * Performance Overlay (wperf1; run/app/perfov.cpp): a corner readout of the frame rate, frame time, render size and
 * upscaler (1), plus a graph of the last 240 frames' times and their CPU / GPU split (2). Both editions (a runner
 * overlay); output only.
 * Tighter Text Spacing (wtext2, D250; text_spacing.c): each glyph's advance loses its cell's blank trailing columns,
 * measured from the player's own font atlas when the font loads (the shipped fonts leave gaps after w, k, x, Y, A:
 * "lik e"); the original trims only v, o and r by hand. The glyph tables are game memory and the game lays text out from
 * them, so it is per session: replays and tests pin it off, netplay peers must share it.
 * Brief Move Prompts (wprompt1, D251; hud_prompt.c): the HUD's weaponization prompt (Y and "Steel Fists", ...), which
 * the game leaves up until the fight script next runs without a prop in the Hulk's hands, goes once it has shown for 5
 * seconds or Y was pressed; another prompt (or the same one begun again) shows. Picture only: the game's HUD runs as in
 * the original and only the prompt's draws are withheld, so it is not per session.
 * Tutorial skip (wskip1): a star behind the Hulk's start in the two tutorial missions (c00m01, c00m02) ends the mission
 * through its own success path when he walks into it (tutorial_skip.c). It changes the game (the mission ends), so it
 * is per session: replays and tests pin it off, netplay peers must share it.
 * Traversal moves (wtrav1, D242): the remastered moves (traversal.c): the charging sprint and higher leaps bought in
 * the moves store (their store entries exist only with it on) and the landing bounce. It changes the simulation, so it
 * is per session: replays and tests pin it off, netplay peers must share it.
 * Developer rows (wdev1): `developer=1` in the file (no menu item) or HULK_DEV=1 turns developer mode on; its rows
 * (keys `dev_*`) are listed after the other Gameplay Options and take effect only in that mode, else their
 * faithful value (Off). They force purchases for testing without buying them: Force Charge Sprint / Force Mega Leap
 * (the traversal levels as if bought; with Traversal Moves on) and Force Original Moves (every shipped store move
 * counts as unlocked and bought). Nothing is written to the game: traversal.c answers through hooks, and the save
 * keeps only real purchases. They are kept in the file like any setting (still set at the next launch while
 * developer mode stays on). They change the simulation, so they are per session: replays and tests pin them off,
 * netplay peers must share them. Developer mode is read at launch (the menus' places are parsed once). */
static port_setting k_settings[] = {
    {"remastered", "Remastered Edition", PS_SCREEN_GAMEPLAY, PS_ONOFF, 2, {0, 1}, {"Off", "On"},
     0, 1, 0, apply_remastered},
    {"frame_rate", "Frame Rate", PS_SCREEN_VIDEO, PS_CHOICE, 4, {30, 60, 120, 0},
     {"30 FPS", "60 FPS", "120 FPS", "Display"}, 30, 60, 1, apply_frame_rate},
    {"render_res", "Render Resolution", PS_SCREEN_VIDEO, PS_CHOICE, 9, {1, 2, 3, 4, 0, 720, 1080, 1440, 2160},
     {"Original (640x480)", "2x (1280x960)", "3x (1920x1440)", "4x (2560x1920)", "Window", "720p", "1080p", "1440p",
      "4K"},
     1, 0, 1, apply_render_res},
    {"upscaler", "Upscaler", PS_SCREEN_VIDEO, PS_CHOICE, 5, {0, 1, 2, 3, 4},
     {"Off (Original)", "Auto", "FSR 1", "Temporal (TAA)", "MetalFX (TAA)"}, 0, 1, 1, apply_upscaler},
    {"render_scale", "Render Scale", PS_SCREEN_VIDEO, PS_CHOICE, 6, {100, 0, 77, 67, 59, 50},
     {"Native", "Auto", "Ultra Quality (77)", "Quality (67)", "Balanced (59)", "Performance (50)"}, 100, 0, 1,
     apply_render_scale},
    {"perf_overlay", "Performance Overlay", PS_SCREEN_VIDEO, PS_CHOICE, 3, {0, 1, 2}, {"Off", "FPS", "Graph"}, 0, 0, 0,
     apply_perf_overlay},
    {"aspect", "Aspect Ratio", PS_SCREEN_VIDEO, PS_CHOICE, 5, {43, 169, 1610, 219, 0},
     {"4:3 (Original)", "16:9", "16:10", "21:9", "Window"}, 43, 0, 1, apply_aspect},
    {"hud_frame", "HUD Frame", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Centred (Original)", "Screen Edges"}, 0, 1, 1,
     apply_hud_edge},
    {"hud_res", "HUD Resolution", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Render (Original)", "Display"}, 0, 1, 1,
     apply_hud_res},
    {"text_spacing", "Tighter Text Spacing", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On"}, 0, 1, 1,
     apply_text_spacing},
    {"move_prompts", "Brief Move Prompts", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On"}, 0, 1, 1,
     apply_move_prompts},
    {"draw_distance", "Draw Distance", PS_SCREEN_VIDEO, PS_CHOICE, 3, {270, 400, 700},
     {"Original", "Far", "Very Far"}, 270, 400, 1, apply_draw_distance},
    {"fog", "Fog", PS_SCREEN_VIDEO, PS_CHOICE, 3, {0, 1, 2}, {"On (Original)", "Reduced", "Off"}, 0, 1, 1, apply_fog},
    {"texture_pack", "Texture Pack", PS_SCREEN_GAMEPLAY, PS_CHOICE, 1, {0}, {"Off"}, 0, 0, 1, apply_texture_pack},
    {"mipmaps", "Mipmaps", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Original", "Full"}, 0, 1, 1, apply_mipmaps},
    {"aniso", "Anisotropic Filtering", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 16}, {"Off (Original)", "16x"}, 0, 16, 1,
     apply_aniso},
    {"msaa", "Anti-Aliasing", PS_SCREEN_VIDEO, PS_CHOICE, 5, {0, 2, 4, 8, 1},
     {"Off (Original)", "MSAA 2x", "MSAA 4x", "MSAA 8x", "TAA"}, 0, 1, 1, apply_msaa},
    {"far_field", "Far Field", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On (Experimental)"}, 0, 0, 1,
     apply_far_field},
    {"lighting", "Lighting", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Per-Vertex (Original)", "Per-Pixel"}, 0, 1, 1,
     apply_lighting},
    {"dyn_lights", "Dynamic Lights", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "Health Orbs"}, 0, 1, 1,
     apply_dyn_lights},
    {"char_light", "Character Lighting", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Original", "Enhanced"}, 0, 1, 1,
     apply_char_light},
    {"contact", "Contact Shadows", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On"}, 0, 1, 1,
     apply_contact},
    {"bounce", "Bounce Light", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On"}, 0, 1, 1, apply_bounce},
    {"decals", "Lasting Decals", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On"}, 0, 1, 1, apply_decals},
    {"hdr", "HDR", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On"}, 0, 1, 1, apply_hdr},
    {"ao", "Ambient Occlusion", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On"}, 0, 1, 1, apply_ao},
    {"shadows", "Shadows", PS_SCREEN_VIDEO, PS_CHOICE, 3, {0, 1, 2}, {"Original", "Low", "High"}, 0, 2, 1,
     apply_shadows},
    {"windows", "Windows", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Original", "Interiors"}, 0, 1, 1, apply_windows},
    {"reflections", "Reflections", PS_SCREEN_VIDEO, PS_CHOICE, 3, {0, 1, 2}, {"Off (Original)", "Low", "High"}, 0, 1,
     1, apply_reflections},
    {"night_lights", "Night Lights", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On"}, 0, 1, 1,
     apply_night_lights},
    {"atmosphere", "Atmosphere", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Original", "Enhanced"}, 0, 1, 1,
     apply_atmosphere},
    {"light_shafts", "Light Shafts", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On"}, 0, 1, 1,
     apply_light_shafts},
    {"grade", "Colour Grade", PS_SCREEN_VIDEO, PS_CHOICE, 3, {0, 1, 2}, {"Original", "Natural", "Cinematic"}, 0, 2, 1,
     apply_grade},
    {"dof", "Cutscene Depth of Field", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On"}, 0, 1, 1,
     apply_dof},
    {"lens_flare", "Lens Flare", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On"}, 0, 1, 1,
     apply_lens_flare},
    {"vignette", "Vignette", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On"}, 0, 0, 1, apply_vignette},
    {"aberration", "Chromatic Aberration", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On"}, 0, 1, 1,
     apply_aberration},
    {"grain", "Film Grain", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Off (Original)", "On"}, 0, 0, 1, apply_grain},
    {"particles", "Particles", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Original", "Soft"}, 0, 1, 1, apply_particles},
    {"water", "Water", PS_SCREEN_VIDEO, PS_CHOICE, 2, {0, 1}, {"Original", "Enhanced"}, 0, 1, 1, apply_water},
    {"grass", "Grass", PS_SCREEN_VIDEO, PS_CHOICE, 3, {0, 1, 2}, {"Original", "Blades Low", "Blades High"}, 0, 2, 1,
     apply_grass},
    {"tutorial_skip", "Tutorial Skip", PS_SCREEN_GAMEPLAY, PS_ONOFF, 2, {0, 1}, {"Off", "On"}, 0, 1, 1,
     apply_tutorial_skip},
    {"remaster_moves", "Traversal Moves", PS_SCREEN_GAMEPLAY, PS_ONOFF, 2, {0, 1}, {"Off", "On"}, 0, 1, 1,
     apply_traversal},
    /* (wskin1, D250) a comic book whose reward is a skin's code unlocks and wears it; a loaded save's comics unlock
     * theirs (skins.c). Changes the game: per session. Choices show the game's own On/Off strings (fe_options.c). */
    {"comic_skins", "Auto-Apply Comic Skins", PS_SCREEN_GAMEPLAY, PS_ONOFF, 2, {0, 1}, {"Off", "On"}, 0, 1, 1,
     hulk_wasm_comic_skins_apply},
    /* (wskin1, D248) this player's Hulk in someone else's co-op game (skins.c): 0 the default, 1 + the skin
     * unlockable's id. Each peer's own (never taken from the host: hulk_settings_line leaves it out); it travels in
     * the session's pads. The choices show the game's own cheat names (fe_options.c game_choice_id). */
    {"coop_skin", "Co-op Skin", PS_SCREEN_GAMEPLAY, PS_CHOICE, 14, {0, 2, 3, 4, 5, 1, 6, 7, 8, 9, 10, 11, 12, 13},
     {"Hulk", "Grey Hulk", "Joe Fixit", "Abomination", "Savage Banner", "Australia", "Canada", "America", "England",
      "France", "Germany", "Italy", "Spain", "Japan"},
     0, 0, 1, 0},
    /* online co-op (wnet1, D246; netplay.c): the join code's eight digits, then the switch. Never saved or loaded: a game
     * starts with co-op off. Remastered only. */
    {"coop_d1", "Join Code 1", PS_SCREEN_GAMEPLAY, PS_CHOICE, 10, DIGITS, 0, 0, 1, 0},
    {"coop_d2", "Join Code 2", PS_SCREEN_GAMEPLAY, PS_CHOICE, 10, DIGITS, 0, 0, 1, 0},
    {"coop_d3", "Join Code 3", PS_SCREEN_GAMEPLAY, PS_CHOICE, 10, DIGITS, 0, 0, 1, 0},
    {"coop_d4", "Join Code 4", PS_SCREEN_GAMEPLAY, PS_CHOICE, 10, DIGITS, 0, 0, 1, 0},
    {"coop_d5", "Join Code 5", PS_SCREEN_GAMEPLAY, PS_CHOICE, 10, DIGITS, 0, 0, 1, 0},
    {"coop_d6", "Join Code 6", PS_SCREEN_GAMEPLAY, PS_CHOICE, 10, DIGITS, 0, 0, 1, 0},
    {"coop_d7", "Join Code 7", PS_SCREEN_GAMEPLAY, PS_CHOICE, 10, DIGITS, 0, 0, 1, 0},
    {"coop_d8", "Join Code 8", PS_SCREEN_GAMEPLAY, PS_CHOICE, 10, DIGITS, 0, 0, 1, 0},
    {"coop", "Online Co-op", PS_SCREEN_GAMEPLAY, PS_CHOICE, 3, {0, 1, 2}, {"Off", "Host a Game", "Join a Game"}, 0, 0, 1,
     apply_coop},
    {"developer", "Developer Mode", PS_SCREEN_NONE, PS_ONOFF, 2, {0, 1}, {"Off", "On"}, 0, 0, 0, apply_developer},
    {"dev_charge", "Force Charge Sprint", PS_SCREEN_GAMEPLAY, PS_CHOICE, 4, {0, 1, 2, 3}, {"Off", "I", "II", "III"},
     0, 0, 0, hulk_wasm_traversal_force_charge},
    {"dev_leap", "Force Mega Leap", PS_SCREEN_GAMEPLAY, PS_CHOICE, 4, {0, 1, 2, 3}, {"Off", "I", "II", "III"},
     0, 0, 0, hulk_wasm_traversal_force_leap},
    {"dev_moves", "Force Original Moves", PS_SCREEN_GAMEPLAY, PS_CHOICE, 2, {0, 1}, {"Off", "All Bought"},
     0, 0, 0, hulk_wasm_traversal_force_moves},
    {"dev_fling", "Force Wall Fling", PS_SCREEN_GAMEPLAY, PS_CHOICE, 4, {0, 1, 2, 3}, {"Off", "I", "II", "III"},
     0, 0, 0, hulk_wasm_traversal_force_fling},
    {"dev_air", "Force Air Control", PS_SCREEN_GAMEPLAY, PS_CHOICE, 4, {0, 1, 2, 3}, {"Off", "I", "II", "III"},
     0, 0, 0, hulk_wasm_traversal_force_air},
    {"dev_coop_local", "Co-op Hulks", PS_SCREEN_GAMEPLAY, PS_CHOICE, 3, {1, 2, 3}, {"Off", "2 Hulks", "3 Hulks"},
     1, 1, 0, hulk_wasm_coop_apply},
};
enum { N_SETTINGS = sizeof k_settings / sizeof k_settings[0] };

static int g_loaded, g_pinned, g_user[N_SETTINGS];
static int g_dev_env;               /* HULK_DEV=1 (never saved) */

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
        if (!is_session_row(k_settings[i].key))
            n += snprintf(buf + n, sizeof buf - (size_t)n, "%s=%d\n", k_settings[i].key, g_user[i]);
    hio_write(f, buf, (uint32_t)n, 0);
    hio_close(f);
}

static int is_developer(const port_setting* s) { return !strncmp(s->key, "dev_", 4); }
int hulk_developer_mode(void) {
    hulk_settings_load();
    int i = hulk_settings_find("developer");
    return g_dev_env || (i >= 0 && g_user[i]);
}
int hulk_setting_locked(int i) {
    hulk_settings_load();
    const port_setting* s = hulk_settings_at(i);
    return s && ((s->remastered_only && !g_user[0]) || (is_developer(s) && !hulk_developer_mode()));
}
int hulk_setting_listed(int i) {
    const port_setting* s = hulk_settings_at(i);
    return s && s->screen >= 0 && s->screen < PS_SCREENS && (!is_developer(s) || hulk_developer_mode());
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
static void apply_developer(int value) {        /* the developer rows take effect or go back to faithful */
    (void)value;
    for (int i = 0; i < N_SETTINGS; i++)
        if (is_developer(&k_settings[i]) && k_settings[i].apply) k_settings[i].apply(effective(i));
}

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
                for (int i = 0; i < N_SETTINGS; i++)
                    if (is_session_row(k_settings[i].key)) g_user[i] = k_settings[i].faithful;
            }
        }
    }
    const char* dev = getenv("HULK_DEV");
    g_dev_env = dev && *dev == '1' && !ff_replay_active();
    const char* e = getenv("HULK_SETTINGS");
    if (e && *e) {
        g_pinned = 1;                   /* pinned values are never saved */
        parse(e);
    }
    char line[1024];
    int n = 0;
    for (int i = 0; i < N_SETTINGS && n < (int)sizeof line - 40; i++)
        n += snprintf(line + n, sizeof line - (size_t)n, " %s=%d", k_settings[i].key, effective(i));
    fprintf(stderr, "hulk: settings%s%s%s\n", line, g_pinned ? " (pinned)" : "", g_dev_env ? " (HULK_DEV)" : "");
    apply_all();
}

/* the rows that change the simulation (the per-session ones above): in a recording's run (a replay or a playthrough
 * session, wplay4) the menus leave them at their pinned values, so a session's menu presses replay the same */
static int changes_game(const port_setting* s) {
    static const char* keys[] = {"aspect", "hud_frame", "draw_distance", "tutorial_skip", "remaster_moves", "developer",
                                 "text_spacing", "comic_skins", "coop_skin"};
    for (unsigned k = 0; k < sizeof keys / sizeof keys[0]; k++)
        if (!strcmp(s->key, keys[k])) return 1;
    return is_developer(s);
}
void hulk_setting_choose(int i, int value) {
    hulk_settings_load();
    const port_setting* s = hulk_settings_at(i);
    if (!s || !valid(s, value) || hulk_setting_locked(i) || g_user[i] == value) return;
    if (ff_replay_active() && changes_game(s)) {
        fprintf(stderr, "hulk: setting %s stays %d (a recording's run: it changes the game)\n", s->key, g_user[i]);
        return;
    }
    g_user[i] = value;
    fprintf(stderr, "hulk: setting %s=%d (the options menu)\n", s->key, value);
    save();
    if (s->apply) s->apply(effective(i));
}

/* co-op (wnet1, netplay.c): a session's peers run the host's settings, all of them (the menus are game state too: a
 * guest's menus follow the host's presses and must show what the host's show). The host hands its values over at a
 * join; the guest takes them for the session only, never saving them (its own file stays as it was). */
int hulk_settings_line(char* buf, int cap) {
    hulk_settings_load();
    int n = 0;
    for (int i = 0; i < N_SETTINGS && n < cap - 40; i++) {
        if (!strcmp(k_settings[i].key, "coop_skin")) continue;       /* (each player's own: wskin1) */
        int v = !strcmp(k_settings[i].key, "developer") ? hulk_developer_mode() : g_user[i];
        n += snprintf(buf + n, (size_t)(cap - n), "%s%s=%d", n ? "," : "", k_settings[i].key, v);
    }
    return n;
}
void hulk_settings_session(const char* line) {
    hulk_settings_load();
    g_pinned = 1;
    g_dev_env = 0;
    parse(line);
    fprintf(stderr, "hulk: settings from the co-op host (for this session only)\n");
    apply_all();
}
