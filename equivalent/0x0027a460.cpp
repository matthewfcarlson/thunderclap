// STATUS: equivalent (tools/equiv.py level 3: 732 inputs, branch coverage 14/14; run with --inputs 12000)
// FUN_0027a460 @ 0x0027a460
typedef unsigned int uint;
extern uint __cdecl FUN_0026fd80(uint position, uint blockSize);
struct Stream {
    virtual int transfer(uint handle, uint mode, uint block, uint offset, uint count, uint destination, uint flags, uint context);
    virtual uint blockSize();
    virtual uint baseOffset(uint handle);
    int process(uint unused, uint handle, uint mode, uint offset, uint destination, uint count, uint* result, uint flags, uint context);
};
int Stream::process(uint unused, uint handle, uint mode, uint offset, uint destination, uint count, uint* result, uint flags, uint context) {
    uint size = blockSize();
    uint position = baseOffset(handle) + offset;
    uint block = position / size;
    uint start = position - FUN_0026fd80(position, size);
    uint amount = size - start;
    if (amount >= count) amount = count;
    int status = transfer(handle, mode, block, start, amount, destination, flags, context);
    if (status != 1) return status;
    uint remaining = count - amount;
    ++block;
    uint dest = destination + amount;
    while (remaining >= size) {
        status = transfer(handle, mode, block, 0, size, dest, flags, context);
        if (status != 1) return status;
        remaining -= size;
        ++block;
        dest += size;
    }
    if (remaining != 0) {
        status = transfer(handle, mode, block, 0, remaining, dest, flags, context);
        if (status != 1) return status;
    }
    *result = count;
    return 1;
}