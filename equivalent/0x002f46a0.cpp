// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 12/14, incomplete)
// FUN_002f46a0 @ 0x002f46a0
struct Range { unsigned short* first; unsigned short* second; };
void __cdecl FUN_002f43f0(Range* result, unsigned short* first, unsigned short* last);
void __cdecl FUN_002f4590(unsigned short* first, unsigned short* last);
void __cdecl FUN_002f4350(unsigned short* first, unsigned short* last, int, int);
void __cdecl FUN_002f4650(unsigned short* first, unsigned short* last);
void __cdecl FUN_002f46a0(unsigned short* first, unsigned short* last, int depth) {
 while (last-first > 32) {
  if (depth <= 0) {
   if (last-first > 1) FUN_002f4350(first,last,0,0);
   FUN_002f4650(first,last);
   return;
  }
  Range split;
  FUN_002f43f0(&split,first,last);
  depth = depth/2 + (depth/2)/2;
  if (split.first-first < last-split.second) {
   FUN_002f46a0(first,split.first,depth);
   first=split.second;
  } else {
   FUN_002f46a0(split.second,last,depth);
   last=split.first;
  }
 }
 if (last-first > 1) FUN_002f4590(first,last);
}
