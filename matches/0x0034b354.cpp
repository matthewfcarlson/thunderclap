// cl-flags: /O1
struct FILE_ {
    char pad[0xd];
    unsigned char flag;
    char pad2[2];
    int fd;
};
extern "C" int _flush(FILE_*);
extern "C" int _commit(int);
extern "C" int _fflush_lk(FILE_* s) {
    if (_flush(s))
        return -1;
    if (s->flag & 0x40) {
        return _commit(s->fd) ? -1 : 0;
    }
    return 0;
}
