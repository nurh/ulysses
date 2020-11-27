SECTIONS
{
	ENTRY(_start)
	. = 0x80000;
	.text : { *(.text) } :text
	.data : { *(.data) } :data
	.bss : { *(.bss) } :data
}
