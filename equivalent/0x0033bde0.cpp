// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 6/6)
// FUN_0033bde0 @ 0x0033bde0
struct Buffer_33bde0 { char *position; int level; void *state; char data[512]; };
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" const char * __cdecl FUN_00339df0(void *, int, unsigned int *);
extern "C" void __cdecl FUN_00339630(void *, Buffer_33bde0 *);
extern "C" void __cdecl FUN_00339470(Buffer_33bde0 *);
extern "C" void __cdecl FUN_00339540(Buffer_33bde0 *);
int __cdecl FUN_0033bde0(void *state) {
 unsigned int cookie = DAT_004d9968;
 unsigned int length;
 Buffer_33bde0 buffer;
 const char *text = FUN_00339df0(state,1,&length);
 FUN_00339630(state,&buffer);
 if(length) {
  do {
   --length;
   if(buffer.position >= buffer.data+512) FUN_00339470(&buffer);
   *buffer.position = text[length];
   ++buffer.position;
  } while(length);
 }
 --length;
 FUN_00339540(&buffer);
 __security_check_cookie(cookie);
 return 1;
}