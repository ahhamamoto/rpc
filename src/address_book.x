struct entry {
  char name<>;
  char addr<>; 
  char phone<>;
};

struct entries {
	entry * new;
	entry * old;
};

program PROG{
	version VERSAO{
		int drop() = 1;
		int insert(entry) = 2;
		int alter(entries) = 3;
		int delete(entry) = 4;
		entry consult(entry) = 5;
	} = 110;
} = 999999;
