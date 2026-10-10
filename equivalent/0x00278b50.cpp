// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 22/28, incomplete)
// FUN_00278b50 @ 0x00278b50
// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 22/28, incomplete)
// FUN_00278b50 @ 0x00278b50
extern unsigned char DAT_0052a228;
extern unsigned char DAT_0052a229;
namespace XAPILIB { extern "C" char* __stdcall XMUNameFromDriveLetter(unsigned int, char*, unsigned int); extern "C" unsigned int __stdcall GetLastError(); }
extern "C" int __stdcall FUN_00208b9c(char*, unsigned int*, unsigned int*, unsigned int*);
extern "C" unsigned int __stdcall FUN_00209a8e(char*);
extern "C" void __cdecl FUN_0026b800(char*, int, char*, int, int, int, int);
struct Target {
 char pad0[0x60]; unsigned int result, size, count, sector;
 char name[0x41]; char padB1[3]; unsigned int previous;
 char padB8[0x14]; char flagCC; char padCD[6]; char digit, letter;
 char padD5[9]; unsigned char drive;
 void FUN_00278060(); void FUN_00278410(); bool FUN_002788c0();
 unsigned int FUN_002787c0(char*); void FUN_00278b50();
};
struct DiskInfo { char root[4]; unsigned int low, high, last, unused, other; };
void Target::FUN_00278b50() {
 sector = 512; size = 0; count = 0;
 int row = 0, col = 0;
 if (drive != 'U') {
  name[0] = 0;
  if (flagCC == 'U') { row = -1; col = -1; }
  else { row = (signed char)digit - '1'; col = (signed char)letter - 'A'; }
  ((Target*)&DAT_0052a228)->FUN_00278060();
  if (row >= 0 && col >= 0) {
   unsigned int index = row + col * 4;
   unsigned char mask = (unsigned char)(1 << (index & 31));
   if (DAT_0052a229 & mask) FUN_00278410();
   if (!(DAT_0052a228 & mask)) { result = previous = 4; return; }
  }
  if (!FUN_002788c0()) { result = previous; return; }
  char tmp[32];
  char* path = XAPILIB::XMUNameFromDriveLetter(drive,tmp,32);
  unsigned int err = FUN_002787c0(path);
  if (err) { result = err; name[0] = 0; return; }
  for (int i=0;i<0x41;i++) name[i]=0;
  FUN_0026b800(name,1,tmp,2,0,0x41,0);
 }
 DiskInfo info;
 info.root[0]=drive; info.root[1]=':'; info.root[2]='\\'; info.root[3]=0;
 if (!FUN_00208b9c(info.root,&info.low,&info.other,&info.last)) {
  name[0]=0;
  unsigned int err=FUN_002787c0((char*)XAPILIB::GetLastError());
  result=previous=err; return;
 }
 result=previous=0;
 size=info.high ? 0xffffffff : info.low;
 unsigned int sec=FUN_00209a8e(info.root);
 if (sec) sector=sec;
 else sector=512;
 count=size/sector;
}