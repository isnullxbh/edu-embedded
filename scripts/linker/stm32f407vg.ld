MEMORY
{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 1m
    RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 112k
}

SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        _text_start = .;
        *(.ivt)
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
        _text_end = .;
    } > FLASH

    _stored_data = .;

    .data : AT(_stored_data)
    {
        . = ALIGN(4);
        _data_start = .;
        *(.data*)
        . = ALIGN(4);
        _data_end = .;
    } > RAM

    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        _bss_start = .;
        *(.bss*)
        . = ALIGN(4);
        _bss_end = .;
    } > RAM
}

_stack_addr = ORIGIN(RAM) + LENGTH(RAM);
