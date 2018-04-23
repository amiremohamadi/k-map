struct Pair {int i, j;};

class list
{
    private:
      Pair arr[16];
      int pointer = 0;

    public:
      list();
      ~list();
      void append(Pair);
      void clear();
      Pair get(int);
      int size();
      void print();
};

class superList
{
    private:
      list arr[64];
      int pointer = 0;

    public:
      superList();
      void append(list);
      void remove(int);
      void clear();
      list get(int);
      int size();
      void print();
};