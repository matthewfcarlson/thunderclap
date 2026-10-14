// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 16/16)
// FUN_0030c580 @ 0x0030c580
typedef unsigned int Word_30c580;
extern Word_30c580* __cdecl FUN_0030bf40(Word_30c580* source, unsigned int count, Word_30c580* destination);
struct Buffer_30c580 {
 Word_30c580* begin;
 Word_30c580* end;
 Word_30c580* capacityEnd;
 bool FUN_0030a130(unsigned int count);
 Buffer_30c580* assign(Buffer_30c580* source);
};
Buffer_30c580* Buffer_30c580::assign(Buffer_30c580* source) {
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
   end = FUN_0030bf40(source->begin + size, count-size, tail);
  } else if (destination) {
   end = destination;
  } else if (FUN_0030a130(count)) {
   end = FUN_0030bf40(source->begin, count, begin);
  }
 }
 return this;
}
