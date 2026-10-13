// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 19/19)
// FUN_0033d1c0 @ 0x0033d1c0
struct Writer { char* current; char buffer[0x208]; };
extern "C" char* __cdecl FUN_00339df0(void*, void*, unsigned*);
extern "C" void __cdecl FUN_00339470(Writer*);
extern "C" void __cdecl FUN_003394b0(Writer*, const char*, unsigned);
// equiv-conv: FUN_0033d1c0 esi edx ecx
void FUN_0033d1c0(Writer* writer, void* a, void* b) {
 unsigned count;
 char* text = FUN_00339df0(a,b,&count);
 char* end = writer->buffer + sizeof(writer->buffer);
 if (writer->current >= end) FUN_00339470(writer);
 *writer->current = '"';
 ++writer->current;
 while (count) {
 --count;
 signed char ch = *text;
 if (ch == '"' || ch == '\\' || ch == '\n') {
 if (writer->current >= end) FUN_00339470(writer);
 *writer->current = '\\';
 ++writer->current;
 if (writer->current >= end) FUN_00339470(writer);
 *writer->current = *text;
 ++writer->current;
 } else if (ch == 0) {
 FUN_003394b0(writer,"\\000",4);
 } else {
 if (writer->current >= end) FUN_00339470(writer);
 *writer->current = *text;
 ++writer->current;
 }
 ++text;
 }
 if (writer->current >= end) FUN_00339470(writer);
 *writer->current = '"';
 ++writer->current;
}
