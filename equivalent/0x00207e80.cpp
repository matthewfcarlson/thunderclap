// STATUS: equivalent (tools/equiv.py level 3: 412 inputs, branch coverage 12/12)
// FUN_00207e80 @ 0x00207e80
#define V(n) virtual void slot##n();
struct Manager { V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) };
extern Manager* DAT_0052c2a8;
extern unsigned char DAT_004c91d8;
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl sprintf(char*, const char*, ...);
struct Item { int FUN_00266710(); };
struct Result { void FUN_00204f00(); };
struct Object {
 char pad0[0x24]; char name[0x56c]; int count590; char pad594[8]; int count59c; char pad5a0[4]; unsigned char states[0x400]; char pad9a4[0x148]; Item* item; unsigned char flag;
 void FUN_00203e30(Item*); void FUN_00207410(); void FUN_00206a40(int); Result* FUN_00204540(const char*);
 void FUN_00207e80();
};
void Object::FUN_00207e80() {
 unsigned int cookie=DAT_004d9968;
 char buffer[256];
 DAT_0052c2a8->slot91();
 if(item) {
  int status=item->FUN_00266710();
  flag=1;
  if(status!=3) FUN_00203e30(item);
  FUN_00207410();
 }
 for(int i=0;i<1024;++i) {
  if(states[i]==1 || states[i]==3) {
   FUN_00206a40(i);
   sprintf(buffer,"%s_r%03d",name,i);
   if(DAT_004c91d8) FUN_00204540(buffer)->FUN_00204f00();
  }
  states[i]=0;
 }
 count59c=0; count590=0;
 __security_check_cookie(cookie);
}
