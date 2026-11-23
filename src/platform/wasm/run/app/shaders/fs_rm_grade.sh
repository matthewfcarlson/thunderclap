// Colour grade (wlook1, docs/look.md "Colour grade"; Video Options > Colour Grade: Original / Natural / Cinematic): a
// parametric grade of the displayable picture, applied in HDR's tone map (fs_rm_tonemap.sc), before the game's own
// effects, bloom, fader and HUD. Display-referred (the game's picture is
// gamma-encoded 0..1). run/app/grade.cpp sets the parameters per frame from the preset and the location's time of day.
//   u_rmGrade[0]  x contrast (1: none), y saturation (1: none), z vibrance (more saturation where there is little),
//                 w 1: grade on
//   u_rmGrade[1]  rgb the shadows' tint (a multiplier of luminance 1), w the pivot of the contrast curve
//   u_rmGrade[2]  rgb the highlights' tint, w the black lift (negative: deeper blacks)
//   u_rmGrade[3]  x the vignette's strength, y exposure (a gain), z the tints' strength, w the split between
//                 shadows and highlights (luminance)
uniform vec4 u_rmGrade[4];

float gradeLum(vec3 c) { return dot(c, vec3(0.2126, 0.7152, 0.0722)); }

vec3 gradeApply(vec3 x, vec2 uv)
{
    x = max(x * u_rmGrade[3].y, vec3_splat(0.0));
    // contrast: an S around the pivot that leaves 0 and 1 where they are (monotonic for contrast up to ~1.5)
    vec3 y = saturate(x);
    vec3 over = x - y;                                          // (HDR light above 1 is kept as it is)
    float p = u_rmGrade[1].w;
    y = y + (u_rmGrade[0].x - 1.0) * (y - p) * 4.0 * y * (vec3_splat(1.0) - y);
    // split toning: a cool or warm cast in the shadows and the highlights, the luminance kept
    float L = gradeLum(y);
    float s = u_rmGrade[3].w;
    float ws = 1.0 - smoothstep(0.0, s * 1.6, L);
    float wh = smoothstep(s * 0.7, 1.0, L);
    vec3 tint = mix(vec3_splat(1.0), u_rmGrade[1].rgb, ws * u_rmGrade[3].z) *
                mix(vec3_splat(1.0), u_rmGrade[2].rgb, wh * u_rmGrade[3].z);
    y *= tint;
    // saturation and vibrance (the most where the colour is weakest; skin and the Hulk's green barely move)
    L = gradeLum(y);
    float sat = max(y.r, max(y.g, y.b)) - min(y.r, min(y.g, y.b));
    float k = u_rmGrade[0].y + u_rmGrade[0].z * (1.0 - saturate(sat * 2.0));
    y = max(mix(vec3_splat(L), y, k), vec3_splat(0.0));         // (before the toe: it divides by y - lift)
    // the black lift (negative: a deeper toe) and a soft vignette
    float lift = u_rmGrade[2].w;
    y = lift >= 0.0 ? y * (1.0 - lift) + lift : y * y * (1.0 - lift) / (y - lift);   // (a toe: 0 and 1 stay)
    vec2 d = (uv - 0.5) * vec2(1.0, 0.82);
    y *= 1.0 - u_rmGrade[3].x * smoothstep(0.25, 0.75, dot(d, d) * 2.0);
    return max(y, vec3_splat(0.0)) + over;
}
