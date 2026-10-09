class List { public: char **begin; char **end; };
class Obj { public: virtual int a(); virtual int b(); virtual int c(); virtual int d(); virtual int e(); virtual int f(); virtual int ready(); char pad[16]; List *list; volatile unsigned char result; unsigned char run(); };
unsigned char Obj::run() {
 if (ready() == 1 && list) {
  result = 0;
  unsigned int i=0;
  while (i < (unsigned int)(list->end-list->begin)) {
   if (((Obj*)list->begin[i])->run()) result=1;
   ++i;
  }
 }
 return result;
}