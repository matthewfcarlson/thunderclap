$input v_color0, v_color1, v_fog, v_texcoord0, v_texcoord1, v_texcoord2, v_texcoord3

// The pixel side every backend draw uses for now (G3): texture stage 0 modulated by the diffuse colour
// (D3DTOP_MODULATE of TEXTURE and DIFFUSE; an untextured draw binds a white texel), the specular colour added
// (D3DRS_SPECULARENABLE), the alpha test and linear table fog (the D3D-side state the context keeps). The
// shaders' other combiner modes (fades, the layered and reflection stages) are G2's texture-stage key.
//   u_pddiFrag[0]  x: alpha reference (0..1), y: alpha compare (pddi enum; < 0: no test), z: add specular
//   u_pddiFrag[1]  the fog colour (w: 1 when fog is on)
//   u_pddiFrag[2]  x: fog start, y: fog end (on the vertex output's fog depth)

#include <bgfx_shader.sh>
#include "fs_vp_stage.sh"
