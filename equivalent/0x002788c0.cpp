// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 14/18, incomplete)
// FUN_002788c0 @ 0x002788c0
struct MountState { char pad[0xb4]; unsigned int status; char pad2[0x10]; unsigned int mountedCount; char deviceType; char pad3[6]; signed char slot; signed char unit; char pad4[8]; unsigned char mounted; char drive; void FUN_002783d0(unsigned int*, unsigned int*); void FUN_00278410(); unsigned int FUN_002787c0(unsigned int); bool FUN_002788c0(); };
struct MountRegistry { void FUN_00278060(); unsigned char FUN_002780c0(unsigned int, unsigned int); };
extern MountRegistry DAT_0052a228;
extern unsigned char DAT_0052a229;
namespace XAPILIB { unsigned int __stdcall XMountMUA(int, int, char*); }
bool MountState::FUN_002788c0() {
 int port = -1, unit = -1;
 if (deviceType != 'U') { port = (int)slot - '1'; unit = (int)this->unit - 'A'; }
 DAT_0052a228.FUN_00278060();
 if (port >= 0 && unit >= 0) {
  unsigned int shift = (port + unit * 4) & 31;
  unsigned char bit = shift < 8 ? (unsigned char)(1 << shift) : 0;
  if (DAT_0052a229 & bit) {
   if (mountedCount > 0) {
    DAT_0052a228.FUN_00278060();
    unsigned int first, second;
    FUN_002783d0(&second, &first);
    status = DAT_0052a228.FUN_002780c0(second, first) ? 3 : 4;
    return false;
   }
   DAT_0052a229 &= (unsigned char)~bit;
   FUN_00278410();
  }
 }
 if (!mounted) {
  unsigned int error = XAPILIB::XMountMUA(port, unit, &drive);
  if (error) {
   if (error == 0x70) status = 13;
   else status = FUN_002787c0(error);
   return false;
  }
 }
 mounted = 1;
 status = 0;
 return true;
}