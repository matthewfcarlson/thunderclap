// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 14/14)
// FUN_0027a370 @ 0x0027a370
typedef unsigned int uint_27a370;
extern uint_27a370 __cdecl FUN_0026fd80(uint_27a370 position, uint_27a370 size);
struct Stream {
 virtual int transfer(uint_27a370 key, uint_27a370 mode, uint_27a370 block, uint_27a370 offset, uint_27a370 count, uint_27a370 destination, uint_27a370 flags);
 virtual uint_27a370 blockSize();
 virtual uint_27a370 baseOffset(uint_27a370 key);
 int FUN_0027a370(uint_27a370 unused, uint_27a370 key, uint_27a370 mode, uint_27a370 start, uint_27a370 destination, uint_27a370 count, uint_27a370* completed, uint_27a370 flags);
};
int Stream::FUN_0027a370(uint_27a370 unused, uint_27a370 key, uint_27a370 mode, uint_27a370 start, uint_27a370 destination, uint_27a370 count, uint_27a370* completed, uint_27a370 flags) {
 uint_27a370 size = blockSize();
 uint_27a370 position = baseOffset(key) + start;
 uint_27a370 block = position / size;
 uint_27a370 offset = position - FUN_0026fd80(position, size);
 uint_27a370 amount = size - offset;
 if (amount >= count) amount = count;
 int result = transfer(key, mode, block, offset, amount, destination, flags);
 if (result != 1) return result;
 uint_27a370 remaining = count - amount;
 ++block;
 uint_27a370 dest = destination + amount;
 while (remaining >= size) {
  result = transfer(key, mode, block, 0, size, dest, flags);
  if (result != 1) return result;
  remaining -= size;
  ++block;
  dest += size;
 }
 if (remaining != 0) {
  result = transfer(key, mode, block, 0, remaining, dest, flags);
  if (result != 1) return result;
 }
 *completed = count;
 return 1;
}
