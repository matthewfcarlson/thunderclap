// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 24/30, incomplete)
// FUN_0027ac30 @ 0x0027ac30
class RDLReader {
public:
    bool FUN_0027ac30(char **out);
    virtual void vfn0();

    void *stream;
    signed char *buf;
    int pos;
    int size;
    char section[0x40];
};

int FUN_00345804(const char *str, const char *fmt, char *out);

bool RDLReader::FUN_0027ac30(char **out)
{
    if (!stream)
        return false;

    signed char *b = buf;
    if (b[pos] < 0x20) {
        while (pos != size) {
            pos++;
            if (buf[pos] >= 0x20)
                break;
        }
    }

    int i = pos;
    if (i == size || b[i] != '[')
        return false;

    if (b[i] != '\r') {
        for (;;) {
            if (b[i] == '\n')
                break;
            if (i == size)
                break;
            signed char next = buf[i + 1];
            i++;
            if (next == '\r')
                break;
        }
    }
    if (i != size)
        b[i] = 0;
    FUN_00345804((const char *)buf + pos, " [ %s ]", section);
    pos = i;
    *out = section;
    return true;
}
