$input a_position, a_normal, a_color0, a_color1, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3
$output v_color0, v_color1, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3

// A deliberately wrong copy of shaders/vp/vs_vp_ff.sc for tests/shaders: a point light's linear attenuation term
// is dropped. tools/d3d_ff.py prove --src must fail the configurations with point lights (and only those).

// The fixed-function vertex path (draws with no vertex program: the default shader programs, prim streams):
// Direct3D 8's transform and lighting as public documentation describes it, from the D3D-side state the backend
// keeps (bgfxContext: the world (= modelview) and projection transforms, up to four lights, the shader's material).
// Its constants share the vertex programs' uniform (our own layout; bgfx_draw.cpp ffConstants):
//   u_vc[0..3]    the modelview's columns (view_i = dot(position, u_vc[i]))
//   u_vc[4..7]    the projection's columns
//   u_vc[8]       material diffuse     u_vc[9]  material ambient     u_vc[10] material emissive
//   u_vc[11]      material specular (w: power)
//   u_vc[12]      the ambient light
//   u_vc[13]      x: lighting on, y: the vertex colour is the diffuse (and ambient) material (never in this game:
//                 FUN_00320c60 sets every material source to D3DMCS_MATERIAL), z: specular on,
//                 w: NORMALIZENORMALS (the game never sets it: Direct3D's default, off)
//   u_vc[14+4i]   light i: position (w: D3D type, 0 = off), direction (w: range), colour, attenuation 0, 1, 2
//   u_vc[32+4s]   stage s's texture transform (D3DTS_TEXTUREs) as columns
//   u_vc[48+s]    stage s's texture coordinates: x the source (0-3 a uv set of the vertex, 10 the camera-space
//                 normal, 11 the camera-space position, 12 the camera-space reflection vector: D3DTSS_TEXCOORDINDEX),
//                 y the transform's output count (D3DTTFF: 0 none)
//   u_vc[52..54]  the normal matrix's rows: the inverse transpose of the modelview's 3x3 (Direct3D's normal transform)
// Lighting is in camera space (the lights come transformed by the modelview they were set with, D3D's VIEW is
// the identity): diffuse N.L and Blinn specular with a local viewer, point lights attenuated within their range,
// directions normalised as Direct3D does; a spot light is lit as a point light (its cone is not applied: the data's
// lights are directional and point). Normals go through the inverse transpose and are renormalised only under
// NORMALIZENORMALS. Proven against tools/d3d_ff.py's reference of the Direct3D 8 pipeline as the game sets it up
// (docs/shaders.md, "Fixed function").
// Fog: the camera-space depth (the w of the game's projections), turned into a factor by the fragment shader.
// a_color0/1 hold D3DCOLORs as they lie in memory (B, G, R, A), hence the swizzles.

#include <bgfx_shader.sh>

uniform vec4 u_vc[96];

vec3 lightTerm(int i, vec3 pos, vec3 n, vec3 eye, inout vec3 spec)
{
    vec4 lp = u_vc[14 + 4 * i];
    vec4 ld = u_vc[15 + 4 * i];
    vec4 lc = u_vc[16 + 4 * i];
    vec4 la = u_vc[17 + 4 * i];
    vec3 l;
    float att = 1.0;
    if (lp.w > 2.5) {                           // directional (Direct3D normalises the direction)
        float dl2 = dot(ld.xyz, ld.xyz);
        l = dl2 > 0.0 ? -ld.xyz * inversesqrt(dl2) : vec3(0.0, 0.0, 0.0);
    } else {                                    // point (and spot)
        vec3 d = lp.xyz - pos;
        float dist = length(d);
        l = dist > 0.0 ? d / dist : vec3(0.0, 0.0, 1.0);
        float k = la.x + la.z * dist * dist;          // WRONG: the linear attenuation term dropped
        att = (dist <= ld.w && k > 0.0) ? 1.0 / k : 0.0;
    }
    float ndl = dot(n, l);
    if (ndl <= 0.0)
        return vec3(0.0, 0.0, 0.0);
    vec3 h = normalize(l + eye);
    float ndh = max(dot(n, h), 0.0);
    if (u_vc[13].z > 0.5 && ndh > 0.0)
        spec += lc.rgb * (att * pow(ndh, max(u_vc[11].w, 0.0001)));
    return lc.rgb * (att * ndl);
}

// D3D's texture coordinate generation and transform for one stage: a uv set goes in as (u, v, 1, 0) (Direct3D's
// rule for 2D coordinates: their translation is the third row), a generated vector as (x, y, z, 1). (The vertex's
// uv sets are passed in: bgfx's HLSL-based profiles see attributes in main only.)
vec4 texgen(int s, vec3 viewPos, vec3 n, vec2 t0, vec2 t1, vec2 t2, vec2 t3)
{
    vec4 ctl = u_vc[48 + s];
    vec4 c;
    if (ctl.x < 0.5) c = vec4(t0, 1.0, 0.0);
    else if (ctl.x < 1.5) c = vec4(t1, 1.0, 0.0);
    else if (ctl.x < 2.5) c = vec4(t2, 1.0, 0.0);
    else if (ctl.x < 3.5) c = vec4(t3, 1.0, 0.0);
    else if (ctl.x < 10.5) c = vec4(n, 1.0);
    else if (ctl.x < 11.5) c = vec4(viewPos, 1.0);
    else {
        float len2 = dot(viewPos, viewPos);
        vec3 e = len2 > 0.0 ? viewPos * inversesqrt(len2) : vec3(0.0, 0.0, 1.0);
        c = vec4(e - 2.0 * dot(n, e) * n, 1.0);
    }
    if (ctl.y > 0.5)
        c = vec4(dot(c, u_vc[32 + 4 * s]), dot(c, u_vc[33 + 4 * s]), dot(c, u_vc[34 + 4 * s]),
                 dot(c, u_vc[35 + 4 * s]));
    return c;
}

void main()
{
    vec4 p = vec4(a_position, 1.0);
    vec4 view = vec4(dot(p, u_vc[0]), dot(p, u_vc[1]), dot(p, u_vc[2]), dot(p, u_vc[3]));
    gl_Position = vec4(dot(view, u_vc[4]), dot(view, u_vc[5]), dot(view, u_vc[6]), dot(view, u_vc[7]));
    v_fog = view.z;

    vec4 vcol = a_color0.zyxw;
    vec4 diffuseMat = u_vc[13].y > 0.5 ? vcol : u_vc[8];
    vec4 ambientMat = u_vc[13].y > 0.5 ? vcol : u_vc[9];
    vec3 n = vec3(dot(a_normal, u_vc[52].xyz), dot(a_normal, u_vc[53].xyz), dot(a_normal, u_vc[54].xyz));
    float len2 = dot(n, n);
    if (u_vc[13].w > 0.5)
        n = len2 > 0.0 ? n * inversesqrt(len2) : n;
    if (u_vc[13].x > 0.5) {
        vec3 eye = -normalize(view.xyz);
        vec3 diffuse = vec3(0.0, 0.0, 0.0);
        vec3 spec = vec3(0.0, 0.0, 0.0);
        for (int i = 0; i < 4; i++) {
            if (u_vc[14 + 4 * i].w > 0.5)
                diffuse += lightTerm(i, view.xyz, n, eye, spec);
        }
        vec3 c = u_vc[10].rgb + ambientMat.rgb * u_vc[12].rgb + diffuseMat.rgb * diffuse;
        v_color0 = saturate(vec4(c, diffuseMat.a));
        v_color1 = saturate(vec4(spec * u_vc[11].rgb, 0.0));
    } else {
        v_color0 = vcol;
        v_color1 = a_color1.zyxw;
    }
    v_texcoord0 = texgen(0, view.xyz, n, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3);
    v_texcoord1 = texgen(1, view.xyz, n, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3);
    v_texcoord2 = texgen(2, view.xyz, n, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3);
    v_texcoord3 = texgen(3, view.xyz, n, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3);
}
