# Light shafts (the app's Light Shafts option)

wrays1, 2026-11-28 (D249/D250: the user's visual pick #5). A remastered-edition picture option of the wasm app's runner
(run/app/rays.cpp, shaders fs_rm_rays.sc / fs_rm_raysapply.sc), an rm pass (rm_pass.h, wr2). Output only: nothing
reads or writes the module's memory, and play3's checkpoint records are the same with the row on or off.

| row | values (faithful first) | remastered default | Quality index |
|---|---|---|---|
| `light_shafts` Light Shafts | Off (Original), On | On | rm::kLightShafts = 32 |

The row borrows hdr's choice strings (fe_options.c `k_borrow`): it adds one string, its label.

## 1. Which approach

Two common ways to draw light shafts:

- **Screen-space radial blur** from the sun's position on screen (occluders from the depth buffer). Cheap, but it shows
  only while the sun is on or near the screen. In play3 the key light is high (the desert's and the city's travel
  direction (-0.58, -0.81, 0.07): ~54 degrees up) and the game's camera looks roughly level, so the sun is almost never
  on screen; this would draw nothing most of the time.
- **Ray-marched in-scattering through the shadow map.** Each view ray is walked from the camera to the surface (or to
  the shadows' reach for the sky), and at each step the sun shadows' atlas (shadows.cpp) says whether that bit of air is
  lit. Shafts come from any occluder in the shadows' range, the sun on screen or off it, and the Hulk, cars and props
  cast volumetric shadows too. This is the one used.

## 2. The pass (rays.cpp)

- **Where.** In the world's pass, once its opaque draws are done, at its first translucent / stencil / 2D draw (the
  point where the ambient occlusion and the atmosphere run; after both), else at the frame's first effect. The shafts
  are under the particles, glows, explosions and the HUD: a flash adds nothing to them and they add nothing to a
  flash (no part in white-outs).
- **The march** (fs_rm_rays.sc, half size, RGBA16F): 24 steps along the view ray, closer together near the camera
  (t ~ s^2), to the surface or the shadows' reach (30/150 units High, 60 Low, in view depth); each step takes one
  compare tap in the atlas's characters/objects row and one in the world's row (both cascades, chosen by view depth as
  the receivers do). The air's density falls off with height above the camera (e^(-0.012 h)) and is zero in the first
  6 units (the Hulk stays crisp). A Henyey-Greenstein lobe (g 0.7, capped at 5x the side-on value) makes it strongest
  looking towards the sun.
- **Only the difference shows.** The atmosphere (and the game's fog) already put the sun's light into the air
  uniformly. The pass takes a share of each ray's air as already lit (`base`, 0.85) and draws only the difference: air
  lit more than that adds the key light's colour, air shadowed more dims what is behind it (at most 30%). An open,
  fully lit view gets a faint lift; the contrast is where light and shadow meet in the air.
- **Steady without TAA.** The march starts at a 4x4 Bayer offset per pixel; the apply (fs_rm_raysapply.sc, full size)
  gathers the 4x4 half-size texels around each pixel, each offset once, with depth weights (edges stay sharp), so the
  noise cancels in every frame and nothing accumulates over time (wlook3's rule). The shadow cascades are texel-snapped,
  so the shafts do not shimmer as the camera moves.
- **Night: lamp cones.** Each street lamp of the Night Lights' list (rm_city.sh kind 1, light mostly downwards) gets a
  soft cone of light in the mist below its head, per pixel in closed form from the tile lists (the ray's nearest
  approach to the cone's axis, a gaussian across it widening downwards, fading to its end, clipped at the surface): the
  same form as the headlight beams of rm_city.sh, pointed down. The atmosphere's spherical glow around each lamp head
  stays as it was. The mission beacons are left alone: Night Lights skips beam-like glows (wfx1: the beacon flooded a
  rooftop), so they are not in the list. The sun part takes the night's key light at 0.15 (play3's night key light is a
  warm street rig, (0.52, 0.55, 0.33): stronger, it washed the night city yellow).
- **Needs.** The sun part needs Shadows (Low or High: the atlas); the lamp cones need Night Lights. With neither, the
  pass draws nothing.

## 3. Water

Water (wwater1) copies the scene's colour before the first blended water draw (in `late`, before any draw hook), and
the shafts are drawn at the first translucent draw: when that draw is the sea, the shafts land under the water surface
(its 80-94% opacity covers most of them) and the refraction copy is taken before them, so nothing is counted twice; the
air above the sea gets less of the shafts than the air over land. Elsewhere the water draws over the shafts like any
translucent draw.

## 4. Linux and Android

- Every sampler the programs declare is bound on every submit: the depth (stage 0), the shadow atlas (stage 4; the
  shadow pass's 1x1 dummy when there is no sun part) and the night lights' list (stage 5; a 1x1 empty list of its own
  when there are none), and the apply's depth and half-size target. After its submits the pass re-binds the lighting
  pass's samplers for the draw being handed over (`rm::lightingRebind`; Vulkan drops texture bindings at each submit).
- Handles: one half-size RGBA16F target (a texture and a frame buffer), one frame buffer over the scene's colour, one
  1x1 texture: three textures/frame buffers in all, made once and remade only when the scene target changes.
- The shaders build for metal, spirv and essl (tools/rm_shaders.py). Not run on a Linux or Android device in this lane.
- Untested on OpenGL (origin bottom-left): the tile lookup scales gl_FragCoord to the full size and rm_city.sh's flip
  takes the full height, as the atmosphere's does.

## 5. Results, checks and cost

- **Defaults** (`HULK_RAYS=strength,density,falloff,dim,g,lamps,steps,moon,base` tunes them): 1, 0.0015, 0.012, 2,
  0.7, 0.2, 24, 0.15, 0.85. Earlier tries: the plain in-scattering (no `base`) was a uniform haze of +8 levels over the
  desert with no visible structure; base 0.7 kept most of it; lamps 0.3 and the moon at 0.35 lifted the night city by
  +5.5 levels (a wash). `HULK_RAYS_SHOW=1` shows the half-size result alone (rgb x 4, the dimming in red);
  `HULK_RAYS_LOG=1` counts runs; `HULK_RAYS_AB=N` times the pass.
- **What it looks like** (play3 on Metal, mac2, 1280x960, every remastered default pinned plus hud_res, particles,
  char_light, text_spacing, move_prompts, contact, bounce, decals, dof, lens_flare, aberration, water, aspect 4:3; app
  112407, tests 112410 on / 112411 off; build/wrays1/crops, never committed): by day the air gains a faint warm depth
  towards the sun and the far canyon (+4..7 levels over the desert, f2500 / f7000), the alley's shadowed air beside the
  wall stays darker than the lit street; at night the lamp heads' glow in the mist is stronger and wider (f36000,
  f42000; the cones are faint at play3's distances), the smoke alley (f54000) gains a little depth and no brightening of
  the cloud itself (the shafts are under the particles). The city dusk/day frame f30000 barely changes (-0.05 mean).
  play3's sun is high (~54 degrees), so true shafts (light between occluders against shadowed air) are rare in its
  frames; they show where a tall wall or the Hulk shadows the air near the camera.
- **Game state**: play3's checkpoint records with the row on (112410) and off (112411) are byte-identical over the
  common 54,120 frames (the same three known transients against the reference, first 5,880). The faithful edition is
  untouched: the row's faithful value is Off, which makes the pass idle (no views, `midFrame` false).
- **Cost** (metal-ab 112412, studio M2 Ultra, play3 to 40,000, `HULK_RAYS_AB=30`, the same pinned settings): bgfx's
  frame GPU timer 2.20 -> 2.40 ms (+0.20 ms; it reads ~1.8x high, so ~0.11 ms real), render thread +0.02 ms. On the
  M3 Air at 1280x960 that is ~0.2-0.3 ms; Steam Deck (800p, ~0.45x the M3) ~0.3 ms; an Android handheld ~0.4-0.6 ms.
  Within the 0.5 ms a new full-screen pass may take (docs/performance.md section 3).

## 6. Not done yet

- Smoke and dust do not scatter the shafts themselves (the shafts are drawn under the particles); a volumetric smoke
  term would need the particles' density in the march.
- The lamp cones are faint at play3's distances; a stronger cone setting was not tried against a near lamp.
- No shafts from beyond the shadows' reach (150 units High, 60 Low).
- Not run on Linux (Vulkan) or Android; the shaders build for spirv and essl.
