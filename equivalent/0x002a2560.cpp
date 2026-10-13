// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 12/14, incomplete)
// FUN_002a2560 @ 0x002a2560
struct Partition { int* first; int* second; };
void __cdecl FUN_002a2200(Partition*, int*, int*, void*);
void __cdecl FUN_002a23d0(int*, int*, void*);
void __cdecl FUN_002a2090(int*, int*, void*, int, int);
void __cdecl FUN_002a2510(int*, int*, void*);
void __cdecl FUN_002a2560(int* first, int* last, int depth, void* compare) {
 while (last-first > 32) {
  if (depth <= 0) {
   if (last-first > 1) FUN_002a2090(first,last,compare,0,0);
   FUN_002a2510(first,last,compare);
   return;
  }
  Partition middle;
  FUN_002a2200(&middle,first,last,compare);
  depth = depth/2;
  depth += depth/2;
  if (middle.first-first < last-middle.second) {
   FUN_002a2560(first,middle.first,depth,compare);
   first=middle.second;
  } else {
   FUN_002a2560(middle.second,last,depth,compare);
   last=middle.first;
  }
 }
 if (last-first > 1) FUN_002a23d0(first,last,compare);
}
