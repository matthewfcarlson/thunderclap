// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 6/6)
// FUN_0033bea0 @ 0x0033bea0
// cl-flags: /GS
struct Work_33bea0 { unsigned count; unsigned char *cursor; unsigned char buffer[512]; };
extern unsigned char * __cdecl FUN_00339df0(void *, int, Work_33bea0 *);
extern void __cdecl FUN_00339630(void *, unsigned char **);
extern void __cdecl FUN_00339470(unsigned char **);
extern int __cdecl FUN_00345475(int);
extern void __cdecl FUN_00339540(unsigned char **);
int __cdecl FUN_0033bea0(void *input) {
 Work_33bea0 work;
 unsigned char *source = FUN_00339df0(input, 1, &work);
 FUN_00339630(input, &work.cursor);
 for (unsigned i = 0; i < work.count; ++i) {
  if (work.cursor >= work.buffer + 512) FUN_00339470(&work.cursor);
  int c = FUN_00345475(source[i]);
  *work.cursor = (unsigned char)c;
  ++work.cursor;
 }
 FUN_00339540(&work.cursor);
 return 1;
}