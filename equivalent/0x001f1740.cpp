// STATUS: equivalent (tools/equiv.py level 3: 2820 inputs, branch coverage 11/12, incomplete)
// FUN_001f1740 @ 0x001f1740
struct Item { Item* FUN_001f0630(const char*, void*, unsigned, unsigned); };
struct Manager { void FUN_001ef260(Item*); };
extern Manager* DAT_004e3710;
extern unsigned DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned);
extern void* __cdecl FUN_0008d710(unsigned, unsigned);
void __stdcall FUN_001f1740(const char* name, void* value, unsigned a, unsigned b) {
 unsigned cookie = DAT_004d9968;
 if (name && value) {
 Manager* manager = DAT_004e3710;
 if (manager) {
 char buffer[64] = {0};
 unsigned i=0;
 do { buffer[i]=name[i]; } while(name[i++]);
 Item* p=(Item*)FUN_0008d710(32,6);
 if(p) p=p->FUN_001f0630(name,value,a,b);
 manager->FUN_001ef260(p);
 }
 }
 __security_check_cookie(cookie);
}
