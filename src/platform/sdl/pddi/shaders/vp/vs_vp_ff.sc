$input a_position, a_normal, a_color0, a_color1, a_texcoord0, a_texcoord1
$output v_color0, v_color1, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3

// The fixed-function vertex path (draws with no vertex program: the default shader programs, prim streams):
// Direct3D 8's transform and lighting as public documentation describes it, from the D3D-side state the backend
// keeps (bgfxContext: the world (= modelview) and projection transforms, up to four lights, the shader's material).
// Its constants share the vertex programs' uniform (our own layout; bgfx_draw.cpp ffConstants):
//   u_vc[0..3]    the modelview's columns (view_i = dot(position, u_vc[i]))
//   u_vc[4..7]    the projection's columns
//   u_vc[8]       material diffuse     u_vc[9]  material ambient     u_vc[10] material emissive
//   u_vc[11]      material specular (w: power)
//   u_vc[12]      the ambient light
//   u_vc[13]      x: lighting on, y: the vertex colour is the diffuse (and ambient) material, z: specular on
//   u_vc[14+4i]   light i: position (w: D3D type, 0 = off), direction (w: range), colour, attenuation 0, 1, 2
// Lighting is in camera space (the lights come transformed by the modelview they were set with, D3D's VIEW is
// the identity): diffuse N.L and Blinn specular with a local viewer, point lights attenuated within their range;
// a spot light is lit as a point light (its cone is not applied: the data's lights are directional and point).
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
    if (lp.w > 2.5) {                           // directional
        l = -ld.xyz;
    } else {                                    // point (and spot)
        vec3 d = lp.xyz - pos;
        float dist = length(d);
        l = dist > 0.0 ? d / dist : vec3(0.0, 0.0, 1.0);
        float k = la.x + la.y * dist + la.z * dist * dist;
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

void main()
{
    vec4 p = vec4(a_position, 1.0);
    vec4 view = vec4(dot(p, u_vc[0]), dot(p, u_vc[1]), dot(p, u_vc[2]), dot(p, u_vc[3]));
    gl_Position = vec4(dot(view, u_vc[4]), dot(view, u_vc[5]), dot(view, u_vc[6]), dot(view, u_vc[7]));
    v_fog = view.z;

    vec4 vcol = a_color0.zyxw;
    vec4 diffuseMat = u_vc[13].y > 0.5 ? vcol : u_vc[8];
    vec4 ambientMat = u_vc[13].y > 0.5 ? vcol : u_vc[9];
    if (u_vc[13].x > 0.5) {
        vec3 n = vec3(dot(a_normal, u_vc[0].xyz), dot(a_normal, u_vc[1].xyz), dot(a_normal, u_vc[2].xyz));
        float len2 = dot(n, n);
        n = len2 > 0.0 ? n * inversesqrt(len2) : n;
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
    v_texcoord0 = vec4(a_texcoord0, 0.0, 1.0);
    v_texcoord1 = vec4(a_texcoord1, 0.0, 1.0);
    v_texcoord2 = vec4(0.0, 0.0, 0.0, 1.0);
    v_texcoord3 = vec4(0.0, 0.0, 0.0, 1.0);
}
