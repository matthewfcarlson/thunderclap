struct Entry { int type; int val; int pad[4]; };
class ScriptReader {
public:
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
	virtual bool v9(int a, int b, float* out);
	int Find(int a, int b, int c);
	char pad[0x12c - 4];
	int count;
	char pad2[0x138 - 0x130];
	Entry e[1];
};
bool ScriptReader::v9(int a, int b, float* out)
{
	int i = Find(a, b, 3);
	if (i >= 0 && i < count) {
		switch (e[i].type) {
		case 1: *out = (float)e[i].val; return true;
		case 2: *out = *(float*)&e[i].val; return true;
		}
	}
	return false;
}
