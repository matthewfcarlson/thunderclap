// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 16/16)
// FUN_0030c580 @ 0x0030c580
#include "gen/owners.h"
typedef unsigned int Word_30c580;
extern "C" unsigned int * __cdecl FUN_0030bf40(unsigned int *, int, unsigned int *);
owners::Buffer_30c580* owners::Buffer_30c580::FUN_0030c580(owners::Buffer_30c580* source) {
 Word_30c580* sourceBegin = source->begin;
 Word_30c580* sourceEnd = source->end;
 Word_30c580* destination = begin;
 unsigned int count = (unsigned int)(sourceEnd-sourceBegin);
 unsigned int size = (unsigned int)(end-destination);
 if (count <= size) {
  while(sourceBegin != sourceEnd) { *destination++ = *sourceBegin++; }
  end = destination;
 } else {
  unsigned int capacity = (unsigned int)(capacityEnd-destination);
  if (count <= capacity) {
   Word_30c580* split = sourceBegin + size;
   while(sourceBegin != split) { *destination++ = *sourceBegin++; }
   Word_30c580* tail = end;
   end = FUN_0030bf40(source->begin + size, (unsigned int)(count-size), tail);
  } else if (destination) {
   end = destination;
  } else if (FUN_0030a130(count)) {
   end = FUN_0030bf40(source->begin, (unsigned int)count, begin);
  }
 }
 return this;
}
