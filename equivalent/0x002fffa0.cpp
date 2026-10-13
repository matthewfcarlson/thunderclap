// STATUS: equivalent (tools/equiv.py level 3: 20 inputs, branch coverage 28/30, incomplete)
// FUN_002fffa0 @ 0x002fffa0
struct Object { virtual void slot0(); virtual void release(); };
struct Pair { Object* first; Object* second; unsigned x,y,z; };
struct Manager {
 Object** begin; Object** end; char pad0[8];
 Object** otherBegin; Object** otherEnd; char pad1[24];
 Pair* pairsBegin; Pair* pairsEnd;
 bool remove(Object* object, unsigned flags);
};
bool Manager::remove(Object* object, unsigned flags) {
 Object** p=begin;
 Object** stop=end;
 if(p!=stop) {
  while(*p!=object) { ++p; if(p==end) break; }
  if(p!=end) {
   Object** src=p+1;
   while(src!=stop) { *p++=*src++; }
   --end;
   object->release();
  }
 }
 p=otherBegin;
 if(p!=otherEnd) {
  while(*p!=object) { ++p; if(p==otherEnd) break; }
  if(p!=otherEnd) {
   Object** last=otherEnd-1;
   otherEnd=last;
   if(p<last) *p=*last;
   object->release();
  }
 }
 bool found=false;
 if(!(flags&8)) {
  Pair* q=pairsBegin;
  if(q!=pairsEnd) {
   do {
    if(q->first==object || q->second==object) {
     Pair* last=pairsEnd-1;
     pairsEnd=last;
     if(q<last) { q->first=last->first; q->second=last->second; q->x=last->x; q->y=last->y; q->z=last->z; }
     found=true;
    } else ++q;
   } while(q!=pairsEnd);
  }
 }
 return found;
}