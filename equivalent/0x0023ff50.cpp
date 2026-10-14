// STATUS: equivalent (tools/equiv.py level 3: 690 inputs, branch coverage 26/26)
// FUN_0023ff50 @ 0x0023ff50
extern char *DAT_004cc02c;
extern char DAT_003f335c[];
extern void __cdecl FUN_0023fa40(char **result, const char *source, unsigned int length, unsigned int capacity);
extern void __cdecl FUN_00247570(void *allocation);
struct Header_23ff50 { unsigned int reserved; unsigned short references; unsigned short capacity; };
struct String { char *data; unsigned short kind; unsigned short unused; unsigned short length; String *append(String *other); };
String *String::append(String *other) {
 unsigned int oldLength = length;
 unsigned int total = oldLength + other->length;
 Header_23ff50 *header = reinterpret_cast<Header_23ff50 *>(data) - 1;
 if (kind == 2 && header->references <= 1 && header->capacity >= total) {
  const char *source = other->data == DAT_004cc02c ? DAT_003f335c : other->data;
  char *dest = data + oldLength;
  char c;
  do { c = *source++; *dest++ = c; } while (c);
  length = (unsigned short)total;
  return this;
 }
 const char *source = data == DAT_004cc02c ? DAT_003f335c : data;
 char *newData;
 FUN_0023fa40(&newData, source, oldLength, total);
 source = data == DAT_004cc02c ? DAT_003f335c : data;
 char *dest = newData;
 char c;
 do { c = *source++; *dest++ = c; } while(c);
 source = other->data == DAT_004cc02c ? DAT_003f335c : other->data;
 dest = newData + length;
 do { c = *source++; *dest++ = c; } while(c);
 if (kind == 2) {
  Header_23ff50 *oldHeader = reinterpret_cast<Header_23ff50 *>(data) - 1;
  if (oldHeader->references == 1) {
   if (data != DAT_004cc02c) FUN_00247570(oldHeader);
  } else --oldHeader->references;
 }
 data = newData;
 kind = 2;
 length = (unsigned short)(length + other->length);
 return this;
}