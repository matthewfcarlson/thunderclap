$input v_texcoord0

// A texture drawn over the target as it is (whud1, hud.cpp): the frame under the HUD at the present size when no
// upscaler made it (the Upscaler row off: the bilinear stretch the present does), or the upscaler's output where the
// renderer cannot blit. The sampler's filtering is the caller's.
#include <bgfx_shader.sh>

SAMPLER2D(s_rmTex0, 0);

void main()
{
    gl_FragColor = vec4(texture2DLod(s_rmTex0, v_texcoord0.xy, 0.0).rgb, 1.0);
}
