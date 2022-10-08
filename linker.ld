/* entry point of our kernel */  
ENTRY(_start)  
  
SECTIONS  
{  
    /* we need 10MB of space atleast */  
    . = 10M;  
  
    /* text section */  
    .text BLOCK(4K) : ALIGN(4K)  
    {  
        *(.multiboot)  
        *(.text)  
    }  
  
    /* read only data section */  
    .rodata BLOCK(4K) : ALIGN(4K)  
    {  
        *(.rodata)  
    }  
  
    /* data section */  
    .data BLOCK(4K) : ALIGN(4K)  
    {  
        *(.data)  
    }  
  
    /* bss section */  
    .bss BLOCK(4K) : ALIGN(4K)  
    {  
        *(COMMON)  
        *(.bss)  
    }  
  
}  