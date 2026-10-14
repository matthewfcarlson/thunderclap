// STATUS: equivalent (tools/equiv.py level 3: 648 inputs, branch coverage 11/12, incomplete)
// FUN_001f17f0 @ 0x001f17f0
struct Item { Item* FUN_001f0760(const char*, void*, unsigned, unsigned, unsigned, unsigned); };
struct Manager { void FUN_001ef260(Item*); };
extern Manager* DAT_004e3710;
extern unsigned DAT_004d9968;
extern "C" void* __cdecl FUN_0008d710(unsigned,unsigned);
extern "C" void __fastcall __security_check_cookie(unsigned);
void __stdcall FUN_001f17f0(const char* name, void* data, unsigned a, unsigned b, unsigned c, unsigned d) {
 unsigned cookie=DAT_004d9968;
 if(name && data) {
  Manager* manager=DAT_004e3710;
  if(manager) {
   char buffer[64]={0};
   unsigned n=0; do {buffer[n]=name[n];} while(name[n++]);
   Item* item=(Item*)FUN_0008d710(0x48,6);
   if(item) item=item->FUN_001f0760(name,data,a,b,c,d);
   manager->FUN_001ef260(item);
  }
 }
 __security_check_cookie(cookie);
}