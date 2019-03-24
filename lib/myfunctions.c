#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "myfunctions.h"

void my_swap_function(char* physical_memory, char* hard_drive_memory){
  short temp = *physical_memory;
  *physical_memory = *hard_drive_memory;
  *hard_drive_memory = temp;
}

void hey_printf_print_this(char* printable){
  printf("%s\n",printable );
}

void free_that_memory(char* memory){
  free(memory);
}

char* get_physical_memory(int total_memory){
  char *physical_memory = malloc(total_memory);
  return physical_memory;

}

char* get_page_table_memory (short page_table_size){
  char *page_table = malloc(page_table_size);
  return page_table;
}

short get_page_number(short value , short mask , short shift) {
   //value & mask -> offset
   return ((value & mask)>>shift);
}

short get_me_that_ascii(short low , short high){
  return get_rand(low,high);
}

void put_physical_memory(char* location, char* physical_memory , int totalSize)
{
    FILE *ppmfile;
    ppmfile = fopen(location, "w");
    fprintf(ppmfile, "Address   \t|\t    Frame   \t|\t Content\n----------\t|\t------------\t|\t----------\n");
    for(int x = 0; x < totalSize; ++x) //pass in Address Size
    {
        fprintf(ppmfile, "0x%x   \t\t\t|\t    %d\t\t\t\t\t|\t%c\n", x , x/256, get_me_that_ascii(32,127));
        physical_memory++;
        // printf("Function Value: %c\n", *physicalMemory);
    }
    fclose(ppmfile);
}

void put_page_table(char* location)
{
    FILE *pptfile;
    pptfile = fopen(location, "w");
    fprintf(pptfile, "Page     \t|\tPage Table Entry\n---------\t|\t-------------\n");
    fclose(pptfile);
}

void put_hard_drive_memory_table(char* location, char* hard_drive_memory , short totalSize,short lowascii,short highascii){
    FILE *phdmtfile;
    phdmtfile = fopen(location, "w");
    fprintf(phdmtfile, "Page     \t|\t  Content  \n");
    for(short x = 0; x < totalSize; ++x) //pass in Address Size
    {
        fprintf(phdmtfile, "0x%x   \t\t\t|\t    %c\n", x , get_me_that_ascii(lowascii,highascii));
        hard_drive_memory++;

    }

    fclose(phdmtfile);


}

//https://en.wikipedia.org/wiki//dev/random
//https://stackoverflow.com/questions/2572366/how-to-use-dev-random-or-urandom-in-c
// Using PRNG which is provided by UNIX
short get_rand(short low , short high){
  //2049
  low = low + 1 ;
  // 20480 - 2049 = 18431
  high = high - low ;
  unsigned char buffer[4];
  int fd = open("/dev/urandom", O_RDONLY);
  read(fd, buffer, 4);
  //buffer now contains the random data
  close(fd);
  // 4 * 4char is 32 bits , which is int
  // type conversion - preserves accurate values passed , also helpful while dealing with void pointers
  // deferencing , Accessing value of buffer
  // https://www.youtube.com/watch?v=H4MQXBF6FN4&index=3&list=PLD28639E2FFC4B86A
  unsigned int newbuffer = *(int *)&buffer;
  //printf("%X\n",newbuffer);
  srand(newbuffer);
  // 0 + 2049 = 2049
  // 18430 + 2049 = 20479
  //printf("%d\n", rand() % high + low);   //using new highs and lows to get values in between(boundary exclusive)
  return rand() % high + low;

}
