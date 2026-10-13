// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 18/18)
// FUN_00246100 @ 0x00246100
struct Reader {
 char pad[0x90];
 unsigned int line, position, length;
 signed char FUN_00245b70(unsigned int);
};
void __cdecl FUN_00245d40(Reader*);
int __cdecl FUN_00245890(const char*, int);
int __cdecl FUN_00245850(const char*, int);
int __cdecl FUN_00246100(Reader* r) {
 char buffer[128];
 char* out = buffer;
 FUN_00245d40(r);
 if (r->FUN_00245b70(r->position) == '-') {
  *out = r->FUN_00245b70(r->position);
  if (r->position < r->length) {
   if (r->FUN_00245b70(r->position) == '\n') ++r->line;
   ++r->position;
  }
  ++out;
 }
 while (r->FUN_00245b70(r->position) >= '0') {
  if (r->FUN_00245b70(r->position) > '9') break;
  *out = r->FUN_00245b70(r->position);
  if (r->position < r->length) {
   if (r->FUN_00245b70(r->position) == '\n') ++r->line;
   ++r->position;
  }
  ++out;
 }
 *out = 0;
 int size = out-buffer;
 if (buffer[0] == '-') return FUN_00245890(buffer,size);
 return FUN_00245850(buffer,size);
}
