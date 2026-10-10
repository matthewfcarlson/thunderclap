// STATUS: equivalent (tools/equiv.py level 3: 146 inputs, branch coverage 33/34, incomplete)
// FUN_00267660 @ 0x00267660
char* __cdecl FUN_00267660(char* path)
{
    if (!path) return path;
    char* end = path;
    while (*end) ++end;
    ++end;
    char* read = path;
    char* write = path;
    while (read < end) {
        char ch = *read;
        if (ch == '.') {
            char next = read[1];
            if (next == '.') {
                if (write < path + 2 || write[-2] == '.' || write[-3] == '.') {
                    write[0] = '.';
                    write[1] = '.';
                    write += 2;
                    read += 2;
                } else {
                    char prev = write[-2];
                    write -= 2;
                    if (prev == '\\' || prev == '/') {
                        read += 2;
                    } else {
                        for (;;) {
                            if (write == path) {
                                read += 3;
                                break;
                            }
                            prev = write[-1];
                            --write;
                            if (prev == '\\') {
                                read += 2;
                                break;
                            }
                            if (prev == '/') {
                                read += 2;
                                break;
                            }
                        }
                    }
                }
            } else if (next == '\\' || next == '/') {
                read += 2;
            } else if (next == 0) {
                if (write > path) --write;
                *write = 0;
                read += 2;
            } else {
                *write++ = *read++;
            }
        } else {
            *write++ = *read++;
        }
    }
    return path;
}
