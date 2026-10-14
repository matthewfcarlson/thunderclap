// STATUS: equivalent (tools/equiv.py level 3: 162 inputs, branch coverage 27/32, incomplete)
// FUN_00288ad0 @ 0x00288ad0
struct Entry { char padding[8]; unsigned int low; unsigned int high; };
struct Table {
 char padding[0x24];
 int unsorted;
 int count;
 Entry **entries;
 Entry * FUN_00288ad0(unsigned int low, unsigned int high);
};
Entry * Table::FUN_00288ad0(unsigned int low, unsigned int high) {
 if (count <= 0) return 0;
 if (unsorted) {
  for (int i=0; i<count; ++i) {
   Entry *entry=entries[i];
   if (entry->low==low && entry->high==high) return entries[i];
  }
  return 0;
 }
 int first=0, last=count-1;
 int middle=last/2;
 while(first<last) {
  Entry *entry=entries[middle];
  if (entry->high>high || (entry->high==high && entry->low>low)) last=middle-1;
  else if (entry->high<high || (entry->high==high && entry->low<low)) first=middle+1;
  else return entries[middle];
  middle=first+(last-first)/2;
 }
 Entry *entry=entries[middle];
 if(entry->low==low && entry->high==high) return entry;
 return 0;
}
