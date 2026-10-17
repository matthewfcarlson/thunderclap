// STATUS: equivalent (tools/equiv.py level 3: 2247 inputs, branch coverage 4/4)
// FUN_002b0cd0 @ 0x002b0cd0
struct Entry { char data[16]; };
struct Owner {
 char padding[0x2c];
 Entry* begin;
 Entry* end;
 void FUN_002b0870();
 void FUN_002b0ba0(void*);
 void FUN_002b0cd0(void*);
};
struct Other { void FUN_002d0c80(); };
void __cdecl FUN_002b0a70(Entry*, void*);
void Owner::FUN_002b0cd0(void* arg) {
 FUN_002b0870();
 ((Other*)arg)->FUN_002d0c80();
 FUN_002b0ba0(arg);
 unsigned int i = 0;
 if (((int)((char*)end - (char*)begin) >> 4) != 0) {
  do {
   FUN_002b0a70((Entry*)((char*)begin + i * 16), arg);
   ++i;
  } while (i < (unsigned int)((int)((char*)end - (char*)begin) >> 4));
 }
}