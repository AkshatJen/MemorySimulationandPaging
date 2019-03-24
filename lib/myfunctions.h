#ifndef MYFUNCTIONSH
#define MYFUNCTIONSH
void my_swap_function(char*,char*);
void hey_printf_print_this(char*);
void free_that_memory(char*);
char* get_physical_memory(int);
char* get_page_table_memory(short);
short get_page_number(short, short, short);
short get_me_that_ascii(short,short);
void put_physical_memory(char* , char*, int);
void put_page_table(char*);
void put_hard_drive_memory_table(char*, char* , short,short,short);
short get_rand(short,short);

#endif
