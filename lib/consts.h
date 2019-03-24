#ifndef CONSTSH
#define CONSTSH

//https://www.geeksforgeeks.org/constants-in-c/


const short BITS = 16;
//phyical memory
//const int TOTAL_MEMORY = 1 << BITS;
const int TOTAL_MEMORY = 65536;
const short PAGE_SIZE =  256;
//2^16-8 16bit system with 256 bytes of page size
const short PAGE_COUNT = 256;
const short FRAME_SIZE = 256;
//page no - 8 bits (0-255) offset - 8 bits (0-255) , hex - 32 bits
// 1111 1111 0000 0000 - 65280
const short MASK = 0xFF00;

// 1111 1111 - 255
const short OFFSET = 0xFF;
//no of bits shift
const short SHIFT = 8;
// 16bit / page size = 2^16-8 = 2^8 * 2bytes(amount of bytes available to hold addresses)
//256 * 2 = 512b ;
const short PAGE_TABLE_ENTRY_SIZE = 512;
const short HARD_DRIVE_MEMORY = 512;
//(2049-20479)
const short LOWEST_RAND = 2048;
const short HIGHEST_RAND = 20480;
// characters(33-126)
const short LOWEST_ASCII = 32;
const short HIGHEST_ASCII = 127;

// *pointers cant be constants
char* PAGE_TABLE_LOCATION = "./data/page_table.txt";
char* PHYSICAL_MEMORY_LOCATION = "./data/physical_memory.txt";
char* HARD_DRIVE_MEMORY_LOCATION = "./data/hard_drive_memory.txt";



#endif
