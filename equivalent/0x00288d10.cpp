// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 17/18, incomplete)
// FUN_00288d10 @ 0x00288d10
struct Window { float start; float length; };
struct Entry { unsigned key1, key2; Window windows[2]; };
struct Object {
 char pad0[16]; float period; char pad1[32]; unsigned count; Entry* entries;
 bool FUN_00288d10(float time, unsigned key1, unsigned key2, unsigned* index, float* fraction);
};
bool Object::FUN_00288d10(float time, unsigned key1, unsigned key2, unsigned* index, float* fraction) {
 if (!entries) return false;
 for (unsigned i=0; i<count; ++i) {
  Entry& entry=entries[i];
  if (entry.key1!=key1 || entry.key2!=key2) continue;
  for (unsigned j=0; j<2; ++j) {
   double elapsed=(double)time-entry.windows[j].start;
   if (elapsed<0.0) elapsed+=(double)period-1.0f;
   if (elapsed<entry.windows[j].length && entry.windows[j].length>0.0f) {
    *index=j;
    *fraction=(float)(elapsed/entries[i].windows[j].length);
    return true;
   }
  }
 }
 return false;
}
