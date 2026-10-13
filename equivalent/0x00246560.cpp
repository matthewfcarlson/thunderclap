// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 26/26)
// FUN_00246560 @ 0x00246560
struct Reader {
 char pad[0x90];
 unsigned line;
 unsigned position;
 unsigned end;
 unsigned FUN_00245b70(unsigned index);
};
unsigned __cdecl FUN_00246560(Reader* reader, char* output, unsigned capacity, const char* delimiters) {
 bool quoted = false;
 unsigned result = reader->position;
 if (result < reader->end) {
  char* limit = output + capacity - 1;
  while ((unsigned)output < (unsigned)limit) {
   result = reader->FUN_00245b70(reader->position);
   unsigned char ch = (unsigned char)result;
   if (ch == '"') quoted = !quoted;
   else {
    const char* p = delimiters;
    while (*p) {
     if (ch == (unsigned char)*p) {
      if (!quoted) {
       *output = 0;
       result = reader->position;
       if (result < reader->end) {
        if ((unsigned char)reader->FUN_00245b70(result) == '\n') ++reader->line;
        result = reader->position + 1;
        reader->position = result;
       }
       return result;
      }
      break;
     }
     ++p;
    }
   }
   *output++ = ch;
   result = reader->position;
   if (result < reader->end) {
    result = reader->FUN_00245b70(result);
    if ((unsigned char)result == '\n') ++reader->line;
    ++reader->position;
   }
   if (reader->position >= reader->end) break;
  }
 }
 *output = 0;
 return result;
}
