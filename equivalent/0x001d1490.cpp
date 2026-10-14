// STATUS: equivalent (tools/equiv.py level 3: 921 inputs, branch coverage 34/36, incomplete)
// FUN_001d1490 @ 0x001d1490
extern int __cdecl FUN_00096670(const char *, const char *, unsigned int);
extern int __cdecl FUN_00096600(const char *, const char *);
struct Entry_1d1490 { int header; char text[1]; };
struct Table_1d1490 {
 Entry_1d1490 *entries[20];
 int count;
 char *FUN_001d1490(const char *prefix, const char *previous);
};
char *Table_1d1490::FUN_001d1490(const char *prefix, const char *previous) {
 if (!prefix || !*prefix || count <= 0) return 0;
 int i = 0;
 for (;;) {
  unsigned int length = 0;
  while (prefix[length]) ++length;
  if (FUN_00096670(prefix, entries[i]->text, length) == 0) break;
  ++i;
  if (i >= count) return 0;
 }
 if (i < 0) return 0;
 int first = i;
 if (!previous || !*previous) return entries[i]->text;
 unsigned int length = 0;
 while (prefix[length]) ++length;
 if (FUN_00096670(prefix, previous, length) != 0) return entries[i]->text;
 while (i < count) {
  if (FUN_00096600(entries[i]->text, previous) == 0) {
   if (i < 0 || i == count - 1) return entries[first]->text;
   length = 0;
   while (prefix[length]) ++length;
   if (FUN_00096670(prefix, entries[i+1]->text, length) == 0) return entries[i+1]->text;
   return entries[first]->text;
  }
  ++i;
 }
 return entries[first]->text;
}
