// STATUS: equivalent (tools/equiv.py level 3: 357 inputs, branch coverage 15/16, incomplete)
// FUN_00092470 @ 0x00092470
extern "C" int __cdecl sprintf(char *, const char *, ...);
extern unsigned __int64 __cdecl FUN_0027b020(const char *);
extern unsigned long DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned long);
struct Item { char pad[8]; unsigned char state; };
struct Observer { void FUN_000c2c10(int); };
struct Table {
 Item *items[866];
 Observer *observer;
 bool FUN_00092470(int first, int last, const char *format, unsigned __int64 key, unsigned char state);
};
bool Table::FUN_00092470(int first, int last, const char *format, unsigned __int64 key, unsigned char state) {
 unsigned long cookie=DAT_004d9968;
 char buffer[256];
 bool found=false;
 for (int n=0; first+n <= last; ++n) {
  sprintf(buffer, format, n);
  if (FUN_0027b020(buffer) == key) {
   int index=first+n-1;
   if(index>=first && index<=last) {
    Item *item=items[index];
    if(item->state!=state) {
     item->state=state;
     if(observer) observer->FUN_000c2c10(index);
    }
   }
   found=true;
   break;
  }
 }
 __security_check_cookie(cookie);
 return found;
}