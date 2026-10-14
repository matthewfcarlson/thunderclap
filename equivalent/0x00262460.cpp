// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 33/34, incomplete)
// FUN_00262460 @ 0x00262460
struct PathString {
    unsigned int FUN_0023f990();
    char* FUN_0023fbb0();
    void FUN_0023fb10(unsigned int length);
};
PathString* __cdecl FUN_00262460(PathString* path) {
    unsigned int length = path->FUN_0023f990();
    if (length != 0) {
        char* buffer = path->FUN_0023fbb0();
        char* end = buffer + length + 1;
        char* read = buffer;
        char* write = buffer;
        while (read < end) {
            char ch = *read;
            if (ch == '.') {
                char next = read[1];
                if (next == '.') {
                    unsigned int skip = 2;
                    if (write < buffer + 2 || write[-2] == '.' || write[-3] == '.') {
                        write[0] = '.';
                        write[1] = '.';
                        write += 2;
                    } else {
                        char previous = write[-2];
                        write -= 2;
                        while (previous != '\\' && previous != '/') {
                            if (write == buffer) {
                                skip = 3;
                                break;
                            }
                            previous = write[-1];
                            --write;
                        }
                    }
                    read += skip;
                    continue;
                }
                if (next == '\\' || next == '/') {
                    read += 2;
                    continue;
                }
                if (next == 0) {
                    if (write > buffer) --write;
                    *write = 0;
                    read += 2;
                    continue;
                }
            }
            *write++ = ch;
            ++read;
        }
        unsigned int newLength = 0;
        while (buffer[newLength] != 0) ++newLength;
        path->FUN_0023fb10(newLength);
    }
    return path;
}
