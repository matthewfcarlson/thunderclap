// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 20/20)
// FUN_00246220 @ 0x00246220
struct Reader {
 char padding[0x90];
 unsigned line;
 unsigned position;
 unsigned end;
 signed char FUN_00245b70(unsigned index);
};
void __cdecl FUN_00245d40(Reader* reader);
bool __cdecl FUN_00246220(Reader* reader, unsigned* result) {
 FUN_00245d40(reader);
 unsigned value = 0;
 if (reader->position >= reader->end) return false;
 for (;;) {
  signed char ch = reader->FUN_00245b70(reader->position);
  if (ch == 9 || ch == 32 || ch == 10 || ch == 13) {
   *result = value; return true;
  }
  if (reader->position >= reader->end) {
   *result = value; return true;
  }
  ch = reader->FUN_00245b70(reader->position);
  if (ch < '0' || ch > '9') {
   *result = 0; return false;
  }
  value = value * 10 + ch - '0';
  if (reader->position < reader->end) {
   ch = reader->FUN_00245b70(reader->position);
   if (ch == 10) ++reader->line;
   ++reader->position;
  }
 }
}
