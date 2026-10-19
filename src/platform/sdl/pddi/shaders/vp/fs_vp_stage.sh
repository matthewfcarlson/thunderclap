// The body of the stage fragment shaders (fs_vp_stage*.sc): bgfx pairs a vertex and a fragment shader only when
// the fragment shader's inputs are exactly the vertex shader's outputs, so there is one per output set of the
// vertex-program shaders: all seven (ff, skin, skin_onebone), five (refract, skin_refract), three
// (simple_proximity, no specular colour).

SAMPLER2D(s_pddiTex0, 0);
uniform vec4 u_pddiFrag[3];

// pddi compare (the game's table 0x4d3a6c): 0 never 1 always 2 less 3 lequal 4 greater 5 gequal 6 equal 7 notequal
bool passes(int f, float a, float r)
{
    if (f == 0) return false;
    if (f == 2) return a < r;
    if (f == 3) return a <= r;
    if (f == 4) return a > r;
    if (f == 5) return a >= r;
    if (f == 6) return a == r;
    if (f == 7) return a != r;
    return true;
}

void main()
{
    vec4 c = texture2D(s_pddiTex0, v_texcoord0.xy) * v_color0;
#ifndef FS_NO_SPECULAR
    c.rgb = c.rgb + v_color1.rgb * u_pddiFrag[0].z;
#endif
    int f = int(u_pddiFrag[0].y);
    if (f >= 0 && !passes(f, c.a, u_pddiFrag[0].x))
        discard;
    if (u_pddiFrag[1].w > 0.5) {
        float range = u_pddiFrag[2].y - u_pddiFrag[2].x;
        float k = range != 0.0 ? saturate((u_pddiFrag[2].y - v_fog) / range) : 1.0;
        c.rgb = mix(u_pddiFrag[1].rgb, c.rgb, k);
    }
    gl_FragColor = saturate(c);
}
