// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// pure3d::pddiBaseContext::vfunc_37 @ 0x0031d940
namespace pure3d {
struct LightInput { unsigned char enabled; char pad[3]; unsigned type; unsigned color; unsigned position[3]; unsigned direction[3]; unsigned parameters[6]; unsigned last; };
struct LightState_31d940 { unsigned position[4]; char gap0[16]; unsigned direction[4]; char gap1[16]; float red,green,blue; unsigned gap2; float average; unsigned last; unsigned parameters[6]; unsigned type,color; unsigned char enabled; char pad[3]; };
struct LightTable { unsigned header; LightState_31d940 lights[8]; };
struct pddiBaseContext {
#define V(n) virtual void vfunc_##n();
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36)
virtual void vfunc_37(int index, const LightInput* input, unsigned flags);
V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109)
virtual void vfunc_110(int index, unsigned flags);
char padding[0x4c]; LightTable* table;
};
void pddiBaseContext::vfunc_37(int index, const LightInput* input, unsigned flags) {
if(index >= 8) return;
LightState_31d940& s = table->lights[index];
s.enabled=input->enabled; s.type=input->type; s.color=input->color;
s.red=float((s.color>>16)&255); s.green=float((s.color>>8)&255); s.blue=float(s.color&255);
s.average=float((((s.color>>16)&255)+((s.color>>8)&255)+(s.color&255))/3);
s.position[0]=input->position[0]; s.position[1]=input->position[1]; s.position[2]=input->position[2]; s.position[3]=0x3f800000;
s.direction[0]=input->direction[0]; s.direction[1]=input->direction[1]; s.direction[2]=input->direction[2]; s.direction[3]=0;
s.parameters[0]=input->parameters[0]; s.parameters[1]=input->parameters[1]; s.parameters[2]=input->parameters[2]; s.parameters[3]=input->parameters[3]; s.parameters[4]=input->parameters[4]; s.parameters[5]=input->parameters[5]; s.last=input->last;
vfunc_110(index,flags);
}
}