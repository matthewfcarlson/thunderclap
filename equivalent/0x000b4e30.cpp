// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 11/12, incomplete)
// FUN_000b4e30 @ 0x000b4e30
#include "decls/address.h"
typedef unsigned __int64 U64_b4e30;
struct Key_b4e30 { unsigned lo, hi; void FUN_0027b040(const char*); };
struct Entry_b4e30 { Key_b4e30 first, second, third, fourth; unsigned a,b; };
struct Object { char pad[0x470]; Entry_b4e30 entries[128]; void target(const char*,const char*,const char*,const char*,unsigned,unsigned); };
void Object::target(const char* s1,const char* s2,const char* s3,const char* s4,unsigned a,unsigned b) {
 if (!*s1) return;
 U64_b4e30 key=FUN_0027b020(s1);
 FUN_0027b020(s2); FUN_0027b020(s3); FUN_0027b020(s4);
 for (int i=0;i<128;++i) {
 Entry_b4e30& e=entries[i];
 if (!(e.first.lo|e.first.hi)) {
 e.first.FUN_0027b040(s1); e.second.FUN_0027b040(s2); e.third.FUN_0027b040(s3); e.fourth.FUN_0027b040(s4); e.a=a; e.b=b; return;
 }
 if (e.first.lo==(unsigned)key && e.first.hi==(unsigned)(key>>32)) return;
 }
}
