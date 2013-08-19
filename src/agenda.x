struct data {
	char *name;
	char *addr;
	char *phone;
};

struct data_alter {
	char *old_name;
	char *new_name;
	char *new_addr;
	char *new_phone;
};

program PROG {
	version VERSION {
		void INITIALIZE() = 1;
		void INSERT(data) = 2;
		void ALTER(data_alter) = 3;
		void REMOVE(data) = 4;
		void CONSULT(data) = 5;
	} = 10;
} = 100;