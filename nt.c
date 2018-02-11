#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 64

//TODO functions...
void parse_command(int argc, char** argv, struct nt_obj nt);
unsigned int read_value(char *v);
void convert_normalized_to_binstr(unsigned int v, char *result);
void usage();
int valid_bin(char *num_str);
int valid_hex(char *num_str);
void show_all_struct_data(struct nt_obj nt);
void transform_all_format(struct nt_obj nt);
//tips: given no matter decimal, binary or hexadecimal, machine recognizes it and can convert it into int!
//      but the 32 bit representation would be needed...

struct nt_obj{ //TODO
  char input_str[MAX_STR_LEN];
  int width;
  int start_pos;
  int end_pos;
  unsigned int value;
  char output_bin_readable[MAX_STR_LEN];
  char output_bin_machine[MAX_STR_LEN];
  char output_hexadecimal[MAX_STR_LEN];
  char output_decimal_unsigned[MAX_STR_LEN];
  char output_decimal_signed[MAX_STR_LEN];
  int original_base;//2, 10, 16
};

int main(int argc, char** argv){
  struct nt_obj nt;
  parse_command(argc, argv, nt);
    
  //phase 1: checking if all input were correctly handled
  show_all_struct_data(nt);

  //phase 2: transfer!
  //according to given base, into different functions
//  transform_all_format(nt); //TODO

  //phase 3: change output strings according to special requirements
  //such as range, bitwidth
}


void parse_command(int argc, char** argv, struct nt_obj nt){
  int i=1;

  while(i < argc){
        
    if(strcmp(argv[i], "-b" ) == 0){ //bit width adjustment
      nt.width = argv[i+1];
      i+=2;
    }
    else if(strcmp(argv[i], "-r" ) == 0){ //range adjustment
      char range_req[33];//string of range requirement
      range_req = argv[i+1];
      /*read the range requirement*/
      nt.start_pos = atoi(strtok(range_req, ","));
      nt.end_pos = atoi(strtok(NULL, ","));
      i+=2;
    }
    else{//value given
      char given_value[12];//TODO
      given_value = read_value(argv[i]);
      if(){//TODO when it is usable value

        int value;
        value = given_value;
        nt.value = value;
        i+=1;
      }
    }
  }
    
  if(i == 1){ //no argument given
    usage();
    //TODO here? return? exit?
    printf("no argument input");
    usage();  }
    
}


unsigned int read_value(char *v){
//firstly, distinguish whether it is binary, decimal, or hexadecimal
//TODO printing, to show human-readable form of input ONLY
    
  if(v[0] == '0' && v[1] =='b'){
    //it could be binary
      
    if(valid_bin(v) == 1){//TODO check if it is valid binary num
      unsigned int num;
      num = atoi(v);
      printf("read_value: binary = %u", num);
      nt.value = num;

      nt.original_base = 2;
    }
    else{
      //TODO invalid input.
      printf("not a valid bin");
      exit();
    }
  }
  else if(v[0] == '0' && v[1] =='x'){){
      //it could be hexadecimal
      
      if(valid_hex(v) == 1){//TODO check if valid hex num
        unsigned int num;
        num = atoi(v);
        printf("read_value: hex = %u", num);
        nt.value = num;
        nt.original_base = 16;
      }
      else{
        //TODO invalid input.
        printf("not a valid hex");
        exit();
      }

  }
  else{
    // could be decimal
    int num;
    num = atoi(v);
    if (num == 0 && string[0] != '0'){
      printf("Not a Number!");
      exit();
      //TODO err msg, usage, exit
        
    }
    else{
      printf("read_value: decimal = %d", num);
      nt.value = num;
      nt.original_base = 10;
    }

  }
  
    
//TODO change nt.original_base


//secondly, decide whether able to accomodate this number
//(too large or too small, etc)


//thirdly, if all good, assign this num into nt

    
}


    
//TODO
void convert_normalized_to_binstr(unsigned int v, char *result){
  printf("given num:%d\n", v);
  printf("unsigned %u\n", v);
  int i;
  int bp = 31;
  int bv =0;
  result[0] = '\0';
        
  for(i = 0;i < 32; i++){
    bv = (v >> bp) & 0b1;
    result[i] = bv ? '1' : '0';
    bp -= 1;
  }
    
  printf("binary string: %s\n", result);
}
   
void usage(){
  printf("usage: ./nt [-b output_width] [-r range] value\n");
  printf("output_width can be: 4, 8, 12, 16, 20, 24, 28, 32\n");
  printf("range is x,y, where x is the start bit index and y is the end bit index\n");
  printf("value can be one of following:\n");
  printf("unsigned int (i.e., 713)\n");
  printf("signed int (i.e., -713)\n");
  printf("binary (i.e., 0b110010101)\n");
  printf("hexadecimal (i.e., 0xBEEF)\n";
  exit(-1);
}
    
    
int valid_bin(char *num_str){
    printf("checking if valid bin...\n");
    return 1; //TODO
}

int valid_hex(char *num_str){
    printf("checking if valid hex...\n");
    return 1; //TODO
}


//TODO data checker
void show_all_struct_data(struct nt_obj nt){
    printf("type: %s", nt.original_base);
    printf("content: %u", nt.value);
    if(nt.width != NULL){
        printf("width: %d", nt.width);
    }
    if(nt.start_pos != NULL && nt.end_pos != NULL){
        printf("from %d to %d", nt.start_pos, nt.end_pos);
    }
}

void transform_all_format(struct nt_obj nt){
    if(nt.original_base == 2){
        nt.output_bin_machine = nt.value;
        nt.output_bin_readable = bin_for_human(nt.output_bin_machine);
        nt.output_hexadecimal =
        nt.output_decimal_unsigned =
        nt.output_decimal_signed =
    }
    else if (nt.original_base == 10){
        
    }
    else if (nt.original_base == 16){
        
    }
    else{ //invalid cases? TODO
        
    }
}


char* bin_for_human(char *binary_value){
  char readable_bin[32];
 
}







