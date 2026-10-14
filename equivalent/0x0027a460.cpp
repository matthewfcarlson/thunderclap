// STATUS: equivalent (tools/equiv.py level 3: 732 inputs, branch coverage 14/14; run with --inputs 12000)
// FUN_0027a460 @ 0x0027a460
typedef unsigned int uint_27a460;
extern uint_27a460 __cdecl FUN_0026fd80(uint_27a460 position, uint_27a460 blockSize);
struct Stream {
    virtual int transfer(uint_27a460 handle, uint_27a460 mode, uint_27a460 block, uint_27a460 offset, uint_27a460 count, uint_27a460 destination, uint_27a460 flags, uint_27a460 context);
    virtual uint_27a460 blockSize();
    virtual uint_27a460 baseOffset(uint_27a460 handle);
    int process(uint_27a460 unused, uint_27a460 handle, uint_27a460 mode, uint_27a460 offset, uint_27a460 destination, uint_27a460 count, uint_27a460* result, uint_27a460 flags, uint_27a460 context);
};
int Stream::process(uint_27a460 unused, uint_27a460 handle, uint_27a460 mode, uint_27a460 offset, uint_27a460 destination, uint_27a460 count, uint_27a460* result, uint_27a460 flags, uint_27a460 context) {
    uint_27a460 size = blockSize();
    uint_27a460 position = baseOffset(handle) + offset;
    uint_27a460 block = position / size;
    uint_27a460 start = position - FUN_0026fd80(position, size);
    uint_27a460 amount = size - start;
    if (amount >= count) amount = count;
    int status = transfer(handle, mode, block, start, amount, destination, flags, context);
    if (status != 1) return status;
    uint_27a460 remaining = count - amount;
    ++block;
    uint_27a460 dest = destination + amount;
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