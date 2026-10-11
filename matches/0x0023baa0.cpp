extern "C" char DAT_00428744[];
class Reader {
  public:
    virtual void Init();
};
class FileDataReader {
  public:
    void* vf;
    int x;
    Reader* reader;
    FileDataReader(Reader* r);
};
FileDataReader::FileDataReader(Reader* r) {
    x = 0;
    vf = (void*)((int)DAT_00428744);
    reader = r;
    r->Init();
}