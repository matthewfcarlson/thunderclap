// STATUS: equivalent (tools/equiv.py level 3: 162 inputs, branch coverage 27/32, incomplete)
// FUN_00288ad0 @ 0x00288ad0
struct Entry_288ad0 { char padding[8]; unsigned int low; unsigned int high; };
struct Table_288ad0 {
 char padding[0x24];
 int unsorted;
 int count;
 Entry_288ad0 **entries;
 Entry_288ad0 * FUN_00288ad0(unsigned int low, unsigned int high);
};
Entry_288ad0 * Table_288ad0::FUN_00288ad0(unsigned int low, unsigned int high) {
 if (count <= 0) return 0;
 if (unsorted) {
  for (int i=0; i<count; ++i) {
   Entry_288ad0 *entry=entries[i];
   if (entry->low==low && entry->high==high) return entries[i];
  }
  return 0;
 }
 int first=0, last=count-1;
 int middle=last/2;
 while(first<last) {
  Entry_288ad0 *entry=entries[middle];
  if (entry->high>high || (entry->high==high && entry->low>low)) last=middle-1;
  else if (entry->high<high || (entry->high==high && entry->low<low)) first=middle+1;
  else return entries[middle];
  middle=first+(last-first)/2;
 }
 Entry_288ad0 *entry=entries[middle];
 if(entry->low==low && entry->high==high) return entry;
 return 0;
}
