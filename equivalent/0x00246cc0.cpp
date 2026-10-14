// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00246cc0 @ 0x00246cc0
struct Stream {
    void* slot0;
    char (__cdecl *write)(Stream* s, const void* data, unsigned int count);
};
class Writer {
public:
    char pad0[0x1c];
    Stream* stream;
    char pendingSpace;
    char pad21[7];
    char flag28;
    char FUN_00246c80();
    char Write(const void* data, unsigned int count);
};
char Writer::Write(const void* data, unsigned int count) {
    if (count == 0)
        return 1;
    if (pendingSpace) {
        if (flag28) {
            if (!FUN_00246c80())
                return 0;
        } else {
            char space = 0x20;
            if (!stream->write(stream, &space, 1))
                return 0;
        }
        pendingSpace = 0;
    }
    return stream->write(stream, data, count);
}
