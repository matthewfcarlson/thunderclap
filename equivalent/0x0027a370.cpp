// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 14/14)
// FUN_0027a370 @ 0x0027a370
typedef unsigned int uint;
extern uint __cdecl FUN_0026fd80(uint position, uint size);
struct Stream {
 virtual int transfer(uint key, uint mode, uint block, uint offset, uint count, uint destination, uint flags);
 virtual uint blockSize();
 virtual uint baseOffset(uint key);
 int FUN_0027a370(uint unused, uint key, uint mode, uint start, uint destination, uint count, uint* completed, uint flags);
};
int Stream::FUN_0027a370(uint unused, uint key, uint mode, uint start, uint destination, uint count, uint* completed, uint flags) {
 uint size = blockSize();
 uint position = baseOffset(key) + start;
 uint block = position / size;
 uint offset = position - FUN_0026fd80(position, size);
 uint amount = size - offset;
 if (amount >= count) amount = count;
 int result = transfer(key, mode, block, offset, amount, destination, flags);
 if (result != 1) return result;
 uint remaining = count - amount;
 ++block;
 uint dest = destination + amount;
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
