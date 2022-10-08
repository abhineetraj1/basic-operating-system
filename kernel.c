#include"kernel.h"
  
static UINT16 VGA_DefaultEntry(unsigned char to_print) {
    return (UINT16) to_print | (UINT16)WHITE_COLOR << 9;
}
  
void printString(char *str)  
{  
  int index = 0;  
  while(str[index]){  
    TERMINAL_BUFFER[VGA_INDEX] = VGA_DefaultEntry(str[index]);  
    index++;  
    VGA_INDEX++;  
  }  
}

int digitCount(int num)  
{  
  int count = 0;  
  if(num == 0)  
    return 1;  
  while(num > 0){  
    count++;  
    num = num/10;  
  }  
  return count;  
}  
  
void itoa(int num, char *number)  
{  
  int digit_count = digitCount(num);  
  int index = digit_count - 1;  
  char x;  
  if(num == 0 && digit_count == 1){  
    number[0] = '0';  
    number[1] = '\0';  
  }else{  
    while(num != 0){  
      x = num % 10;  
      number[index] = x + '0';  
      index--;  
      num = num / 10;  
    }  
    number[digit_count] = '\0';  
  }
}

static int Y_INDEX = 1;  
  
void printNewLine()  
{  
  if(Y_INDEX >= 55){  
    Y_INDEX = 0;  
    Clear_VGA_Buffer(&TERMINAL_BUFFER);  
  }  
  VGA_INDEX = 80*Y_INDEX;  
  Y_INDEX++;  
}

void KERNEL_MAIN()  
{  
  TERMINAL_BUFFER = (UINT16*) VGA_ADDRESS;  
  printString("Hello world!");
  printNewLine();
  printString("This operating system is made by Abhineet Raj");  
  printNewLine();
  printString("Github- https://github.com/abhineetraj1")
  printNewLine();
  printString("Bye world");
  printNewLine();
  printString("Thank you!!")
  printNewLine();
}