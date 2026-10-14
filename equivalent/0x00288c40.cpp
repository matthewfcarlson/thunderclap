// STATUS: equivalent (tools/equiv.py level 3: 181 inputs, branch coverage 27/32, incomplete)
// FUN_00288c40 @ 0x00288c40
struct Entry { char pad[8]; unsigned int low, high; };
struct Table {
 char pad[0x24]; int unsorted; int count; Entry **entries;
 int FUN_00288c40(unsigned int low, unsigned int high);
};
int Table::FUN_00288c40(unsigned int low, unsigned int high) {
 if (count <= 0) return -1;
 if (unsorted) {
  for (int i=0; i<count; ++i) {
   Entry *entry=entries[i];
   if (entry->low==low && entry->high==high) return i;
  }
  return -1;
 }
 int first=0, last=count-1;
 int middle=last/2;
 Entry **items=entries;
 while(first<last) {
  unsigned int a=items[middle]->low;
  unsigned int b=items[middle]->high;
  if(b>high || (b==high && a>low)) last=middle-1;
  else if(b<high || (b==high && a<low)) first=middle+1;
  else return middle;
  middle=first+(last-first)/2;
 }
 Entry *entry=entries[middle];
 if(entry->low==low && entry->high==high) return middle;
 return -1;
}