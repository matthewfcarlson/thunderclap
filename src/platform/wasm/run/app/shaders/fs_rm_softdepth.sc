$input v_texcoord0

// Soft particles (wfx1, run/app/particles.cpp): the scene's depth so far as linear camera depth (D3D depth linearised
// as fs_rm_aoapply.sc does), for fs_px_soft.sc to read while the game's sprites draw into the scene (a depth target is
// never sampled while it is attached). Nothing drawn: 65000 (the sky; within a half float).
//   u_rmSoftCopy  the world projection's c6.z, c6.w, c7.z, c7.w
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);         // the scene's depth
uniform vec4 u_rmSoftCopy;

void main()
{
    float d = texture2DLod(s_rmTex0, v_texcoord0.xy, 0.0).x;
    float z = 65000.0;
    if (d < 0.99999)
        z = min((u_rmSoftCopy.y - d * u_rmSoftCopy.w) / min(d * u_rmSoftCopy.z - u_rmSoftCopy.x, -1e-7), 65000.0);
    gl_FragColor = vec4(z, 0.0, 0.0, 1.0);
}
