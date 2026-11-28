// Water (wwater1, run/app/water.cpp, docs/water.md): the ripples, shared by the water's program (fs_px_water.sc) and
// its reflection G-buffer draw (fs_rm_ssrwater.sc), so the reflection is bent by the same waves the player sees.
//   u_rmWater[0..2]  camera space -> world: rows (xyz; w the translation)
//   u_rmWater[3..5]  world -> camera space: the view's rows (xyz; a normal's transform)
//   u_rmWater[6]     x the display clock (seconds), y the ripples' slope scale (0: flat), z the cosine of the steepest
//                    face taken as level water, w the screen-space reflection's strength on water (the G-buffer's)
uniform vec4 u_rmWater[7];

vec3 waterWorld(vec3 cam)
{
    vec4 c = vec4(cam, 1.0);
    return vec3(dot(c, u_rmWater[0]), dot(c, u_rmWater[1]), dot(c, u_rmWater[2]));
}

vec3 waterToCamera(vec3 w)
{
    return vec3(dot(w, u_rmWater[3].xyz), dot(w, u_rmWater[4].xyz), dot(w, u_rmWater[5].xyz));
}

// world up in camera space (the view's second column)
vec3 waterUp()
{
    return normalize(vec3(u_rmWater[3].y, u_rmWater[4].y, u_rmWater[5].y));
}

// one travelling wave's slope: direction d (unit), wavelength l (world units), steepness a (slope amplitude); deep-water
// speed (w = sqrt(g k)); faded out where a pixel covers more than a sixth of its length (no shimmer in the distance)
vec2 waterWave(vec2 p, float t, float px, vec2 d, float l, float a)
{
    float k = 6.2831853 / l;
    float ph = k * dot(d, p) + sqrt(9.8 * k) * t;
    float fade = clamp((l / max(px, 1e-4) - 3.0) / 6.0, 0.0, 1.0);
    return d * (a * fade * cos(ph));
}

// the water's height slope (dh/dx, dh/dz) at world point p (x, z) at time t; px: the pixel's world footprint
vec2 waterSlope(vec2 p, float t, float px)
{
    // (a slow, large warp of the waves' coordinates: the sum of straight waves otherwise reads as a regular lattice)
    p += vec2(sin(p.y * 0.071 + t * 0.05), sin(p.x * 0.083 - t * 0.04)) * 4.0;
    vec2 s = waterWave(p, t, px, vec2(0.80, 0.60), 9.7, 0.10);
    s += waterWave(p, t, px, vec2(-0.39, 0.92), 5.3, 0.10);
    s += waterWave(p, t, px, vec2(0.97, -0.24), 3.1, 0.09);
    s += waterWave(p, t, px, vec2(-0.71, -0.70), 1.9, 0.08);
    s += waterWave(p, t, px, vec2(0.26, 0.97), 1.17, 0.07);
    s += waterWave(p, t, px, vec2(-0.94, 0.34), 0.71, 0.06);
    s += waterWave(p, t, px, vec2(0.55, -0.83), 0.43, 0.05);
    return s * u_rmWater[6].y;
}

// the ripples' normal in camera space at camera-space point pos
vec3 waterNormal(vec3 pos, out vec3 world, out vec2 slope)
{
    world = waterWorld(pos);
    vec2 fw = fwidth(world.xz);
    float px = max(fw.x, fw.y);
    slope = waterSlope(world.xz, u_rmWater[6].x, px);
    return normalize(waterToCamera(vec3(-slope.x, 1.0, -slope.y)));
}

// the face is level water: its normal (from the position's derivatives) within u_rmWater[6].z of up
bool waterLevel(vec3 pos)
{
    vec3 f = cross(dFdx(pos), dFdy(pos));
    float l2 = dot(f, f);
    if (l2 <= 0.0)
        return false;
    return abs(dot(f * inversesqrt(l2), waterUp())) > u_rmWater[6].z;
}
