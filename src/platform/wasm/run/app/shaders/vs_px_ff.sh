// Per-pixel lighting (docs/lighting.md): the fixed-function vertex path of shaders/vp/vs_vp_ff.sh (same constants,
// transform, HUD edge shift, normal and texture coordinates) with the lights left to fs_px_stage.sh. A lit draw
// passes its colour without the lights (emissive + ambient material x ambient light); an unlit one its vertex colours.
#include <bgfx_shader.sh>

uniform vec4 u_vc[96];
#ifdef PX_CAST
uniform vec4 u_rmCast[4];      // (wr3a) camera space -> the shadow map's clip space, rows
#endif

// vs_vp_ff.sh's texgen (D3D's texture coordinate generation and transform for one stage)
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
    if (u_vc[55].x != 0.0 && gl_Position.w > 0.0) {
        float xn = gl_Position.x / gl_Position.w / u_vc[55].y;
        gl_Position.x += sign(xn) * u_vc[55].x * smoothstep(0.05, 0.2, abs(xn)) * gl_Position.w;
    }
    vec4 vcol = a_color0.zyxw;
    vec4 ambientMat = u_vc[13].y > 0.5 ? vcol : u_vc[9];
    vec3 n = vec3(dot(a_normal, u_vc[52].xyz), dot(a_normal, u_vc[53].xyz), dot(a_normal, u_vc[54].xyz));
    float len2 = dot(n, n);
    if (u_vc[13].w > 0.5)
        n = len2 > 0.0 ? n * inversesqrt(len2) : n;
    float len = sqrt(dot(n, n));
    v_pxnormal = vec4(len > 0.0 ? n / len : vec3(0.0, 0.0, 0.0), len);
    v_pxpos = view.xyz;
    if (u_vc[13].x > 0.5) {
        // the diffuse material where the vertex colour is it (never in this game) rides in the specular slot
        v_pxbase = vec4(u_vc[10].rgb + ambientMat.rgb * u_vc[12].rgb, 0.0);
        v_pxspec = u_vc[13].y > 0.5 ? vcol : u_vc[8];
    } else {
        v_pxbase = vcol;
        v_pxspec = a_color1.zyxw;
    }
    v_texcoord0 = texgen(0, view.xyz, n, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3);
    v_texcoord1 = texgen(1, view.xyz, n, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3);
    v_texcoord2 = texgen(2, view.xyz, n, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3);
    v_texcoord3 = texgen(3, view.xyz, n, a_texcoord0, a_texcoord1, a_texcoord2, a_texcoord3);
#ifdef PX_DECAL
    gl_Position.z -= 4.0e-6 * gl_Position.w;   // (wlook0: a decal over the draw it repeats: wins the depth test)
#endif
#ifdef PX_CAST
    gl_Position = vec4(dot(vec4(view.xyz, 1.0), u_rmCast[0]), dot(vec4(view.xyz, 1.0), u_rmCast[1]),
                       dot(vec4(view.xyz, 1.0), u_rmCast[2]), 1.0);   // (wr3a: a shadow caster, the sun's view)
#endif
}
