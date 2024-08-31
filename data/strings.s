	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2

@ TODO use tmc_strings to extract strings for other variants

translation:: @ 089B1D90
	.incbin "translations/English.bin"

translationFrench::
	.incbin "translations/French.bin"

translationGerman::
	.incbin "translations/German.bin"

translationSpanish::
	.incbin "translations/Spanish.bin"

translationItalian::
	.incbin "translations/Italian.bin"

