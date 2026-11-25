# Soft particles (the app's Particles option)

wfx1, 2026-11-25 (D249: the user's top visual upgrade). A remastered-edition picture option of the wasm app's runner
(run/app/particles.cpp, shaders fs_px_soft.sc / fs_rm_softdepth.sc), an rm pass (rm_pass.h, wr2). Output only: the
game's own draws change program, nothing reads or writes the module's memory, and play3's checkpoint records are the
same with any setting.

| row | values (faithful first) | remastered default |
|---|---|---|
| `particles` Particles | Original, Soft | Soft |

## What the game draws

Smoke, dust, sparks, fire and explosion flashes are camera-facing quads the game streams each frame (play3 f39000 /
f54000 draw dumps, `HULK_LIGHT_DUMP`): transient vertices already in camera space (the modelview's translation is 0),
fixed function, unlit, shader `simple` (kind 0), material 0x99ffffff with no ambient, fog on, depth tested without
depth writes, in the world's pass after its opaque traversal. Smoke and dust blend src-alpha / inv-src-alpha, fire and
flashes one / one. A batch is one draw of 6 vertices a quad (up to several hundred).

Drawn flat, a big sprite ends in a hard straight line where its plane cuts the ground or a wall (f54000: the Sonic Clap
dust cloud against the alley wall and the street), and a flash whose sprite reaches the camera fills the frame.

## The pass

- **Which draws.** A draw of the world's pass (the game pass of the frame's first room draw) that is transient, fixed
  function, unlit, kind 0, blended (src-alpha / inv-src-alpha or one; one / one or inv-src-alpha), depth tested, no
  depth write, no stencil, no occlusion query, and whose first triangle faces the camera (its normal within ~37 degrees
  of the view ray or of the view axis). A decal or a trail lying on a surface fails the last test and keeps its
  faithful program (it would fade into the surface it lies on). Buffer draws (the game's glow meshes, beacon pillars)
  are left alone.
- **The depth copy.** A depth target is never sampled while it is attached (Metal and Vulkan both forbid the feedback),
  so at the frame's first such draw the pass splits the world pass (`rm::viewsHere`) and copies the scene's depth so
  far into an R32F target (R16F where R32F can't be drawn) as linear camera depth (fs_rm_softdepth.sc, the world
  projection from `rm::frameCamera`; nothing drawn: 65,000). One copy a frame, one target of the scene's size.
- **The program.** vs_px_ff (the faithful fixed-function transform) + fs_px_soft: the faithful generic combiner
  (shaders/vp/fs_vp_stage.sh, stages from u_pddiFrag), alpha test and fog unchanged, then
  - coverage x smoothstep((scene depth - sprite depth) / 1.0 unit) (the soft edge where it meets the scene) x
    smoothstep((sprite depth - 0.4) / 1.6) (near the camera);
  - smoke and dust (not additive) lit, at the combiner's output where the pixel shows: darkened by up to 30% in the sun's shadow (the shadow pass's atlas, a wide
    five-tap lookup at a point pushed towards the sun, no normal: a flat card standing in a volume is otherwise cut by
    the shadow's edge into hard dark wedges, as the first try at 55% with a 4-tap lookup did at f54000), plus the Night
    Lights' city lights (rm_city.sh) as a volume (no N.L) at 0.35 of a lit surface's light (at full strength a lamp
    beside the f54000 dust cloud turned it yellow-green);
  - additive sprites: a colour gain under HDR (1 by default: see "The flash" below).
  The fade scales alpha for src-alpha blends and colour and alpha for one / x blends. bgfx hands the varyings and
  gl_FragColor to `main` only (its HLSL-style profiles), so the fade rides in a private global from the vertex colour
  macro (`v_color0`, the combiner's first read) to the combiner's only vec4 clamp (`saturate(c)`, redefined for this
  file). The pddi shaders and the Wine image are untouched.
- **Samplers.** Stage 4 (shadow atlas or the dummy), 5 (the city lights, or none) and 6 (the depth copy) are bound for
  every draw of ours; a copy of one of our draws submitted again by another pass is bound again through
  `rm::lightingRebind` -> `rm::particlesRebind` (wlinux2: Vulkan reads an unbound sampler as garbage).
- **Handles.** One texture + frame buffer (the depth copy), two programs, four uniforms.

## The beacon (Night Lights, f30000)

The green mission beacon is eight crossed additive quads, 9.3 units tall (prim buffers of 4 vertices). Night Lights took
each as a glow and made eight 24-unit lights of strength 1.5 that flooded the whole rooftop, grass and fence green
(remastered only). nightlights.cpp now skips beam-like glows: a model-space box whose longest side is over 2 units and
over 3x the next (a beacon's pillar, a searchlight's shaft); the game's lamp halos, signs and vehicle glows are round or
short.

## The flash (f39000)

The explosion at f39000 whites out most of the frame in the faithful picture too: dozens of additive sprites (one /
one) stacked over the car. Under HDR their sum is unbounded before the tone map. The near fade takes off the sprites
that reach the camera; `HULK_SOFT`'s sixth value scales additive sprites under HDR (default 1, the game's brightness).

## Cost

`metal-ab` over play3 to 56,500 at 1280x960, every remastered default pinned, mac2 (M3 Max), `HULK_SOFT_AB=30`
(bgfx's frame GPU timer, which reads ~1.8x high): job 112154 GPU 1.940 -> 2.355 ms (+0.42; ~0.23 ms real), render
thread +0.05 ms. The fade alone (light off, `HULK_SOFT=1,0.4,1.6,0,0,1`, job 112151) is +0.17 ms; lighting every
smoke pixel before the combiner was +0.62 (112150), so the light is applied at the combiner's output and only where
the pixel shows (most of a smoke sprite's texels are clear). Frames without sprites pay nothing (no copy, no views).
On the M3 Air (~4x less GPU) that is ~1 ms on smoky frames, within the remastered frame's headroom (~7.5 of 12 ms).

## Knobs

- `HULK_SOFT=fade,nearStart,nearLength,cityLight,shadow,additiveHdrGain` (defaults 1, 0.4, 1.6, 0.35, 0.3, 1)
- `HULK_SOFT_LOG=1`: soft draws, depth copies and rejected (not facing) draws every 300 frames
- `HULK_SOFT_AB=N`: the pass off and on in turns of N presented frames, with its GPU cost line (`metal-ab`)

## Checking on Linux (Vulkan)

On the handheld, with Particles Soft and Khronos validation on (`VK_INSTANCE_LAYERS=VK_LAYER_KHRONOS_validation`): a
city fight with smoke and an explosion (play3 ~39,000 and ~54,000 from a save), HUD and minimap up. Look for: smoke
that fades into the street and walls (no straight cut line), no black or garbage squares where sprites draw (an
unbound sampler), no validation errors naming stage 4, 5 or 6 or a depth-attachment/sampled layout conflict, and the
rooftop beacon lighting only its pad at night.
