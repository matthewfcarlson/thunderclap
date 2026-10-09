class Reader { public: virtual void Init(); };
class FileDataReader { public: void* vf; int x; Reader* reader; FileDataReader(Reader* r); };
FileDataReader::FileDataReader(Reader* r) { x = 0; vf = (void*)0x428744; reader = r; r->Init(); }