// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::pddiBaseContext::vfunc_22 @ 0x0031e8d0
namespace pure3d {
struct Matrix { unsigned int words[16]; };
struct MatrixStack { char pad[8]; unsigned int index; Matrix* data; };
struct pddiBaseContext {
#define V(n) virtual void vfunc_##n();
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21)
virtual void vfunc_22(int which, const Matrix* matrix);
V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107)
virtual void vfunc_108(int which);
char pad[28]; MatrixStack* stacks[4];
};
void pddiBaseContext::vfunc_22(int which, const Matrix* matrix) {
 MatrixStack* stack = stacks[which];
 unsigned int index = ++stack->index;
 unsigned int* destination = stack->data[index].words;
 const unsigned int* source = destination - 16;
 for (int i=0; i<16; ++i) destination[i] = source[i];
 stack = stacks[which];
 destination = stack->data[stack->index].words;
 for (int j=0; j<16; ++j) destination[j] = matrix->words[j];
 vfunc_108(which);
}
}
