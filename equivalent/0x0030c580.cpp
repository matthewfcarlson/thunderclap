// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 16/16)
// FUN_0030c580 @ 0x0030c580
typedef unsigned int Word;
extern Word* __cdecl FUN_0030bf40(Word* source, unsigned int count, Word* destination);
struct Buffer {
 Word* begin;
 Word* end;
 Word* capacityEnd;
 bool FUN_0030a130(unsigned int count);
 Buffer* assign(Buffer* source);
};
Buffer* Buffer::assign(Buffer* source) {
 Word* sourceBegin = source->begin;
 Word* sourceEnd = source->end;
 Word* destination = begin;
 unsigned int count = (unsigned int)(sourceEnd-sourceBegin);
 unsigned int size = (unsigned int)(end-destination);
 if (count <= size) {
  while(sourceBegin != sourceEnd) { *destination++ = *sourceBegin++; }
  end = destination;
 } else {
  unsigned int capacity = (unsigned int)(capacityEnd-destination);
  if (count <= capacity) {
   Word* split = sourceBegin + size;
   while(sourceBegin != split) { *destination++ = *sourceBegin++; }
   Word* tail = end;
   end = FUN_0030bf40(source->begin + size, count-size, tail);
  } else if (destination) {
   end = destination;
  } else if (FUN_0030a130(count)) {
   end = FUN_0030bf40(source->begin, count, begin);
  }
 }
 return this;
}
