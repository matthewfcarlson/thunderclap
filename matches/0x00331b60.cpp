class d3dSpheremapVertexShader { public: char pad[0x14]; struct State *state; void vfunc_13(); };
struct State { char pad[0xe4]; int value; };
extern int globalFlags;
extern int globalState;
void d3dSpheremapVertexShader::vfunc_13() { if (state->value != 1) { state->value = 1; globalFlags |= 0x800; globalState = 1; } }