	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 4
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	stur	w0, [x29, #-8]
	str	x1, [sp, #16]
	ldur	w8, [x29, #-8]
	subs	w8, w8, #4
	cset	w8, ne
	tbnz	w8, #0, LBB0_2
	b	LBB0_1
LBB0_1:
	ldr	x8, [sp, #16]
	ldr	x0, [x8, #8]
	adrp	x1, l_.str@PAGE
	add	x1, x1, l_.str@PAGEOFF
	bl	_strcmp
	subs	w8, w0, #0
	cset	w8, eq
	tbnz	w8, #0, LBB0_3
	b	LBB0_2
LBB0_2:
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	mov	w8, #1
	stur	w8, [x29, #-4]
	b	LBB0_4
LBB0_3:
	ldr	x8, [sp, #16]
	ldr	x10, [x8, #16]
	ldr	x8, [sp, #16]
	ldr	x8, [x8, #24]
	mov	x9, sp
	str	x10, [x9]
	str	x8, [x9, #8]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	adrp	x1, l_.str.5@PAGE
	add	x1, x1, l_.str.5@PAGEOFF
	bl	_writeToFile
	stur	wzr, [x29, #-4]
	b	LBB0_4
LBB0_4:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"login"

l_.str.1:                               ; @.str.1
	.asciz	"Invalid arguments!\n"

l_.str.2:                               ; @.str.2
	.asciz	"usage: PP login [NAME] [SURNAME]"

l_.str.3:                               ; @.str.3
	.asciz	"Hello, %s %s!"

l_.str.4:                               ; @.str.4
	.asciz	"Data"

l_.str.5:                               ; @.str.5
	.asciz	"w"

.subsections_via_symbols
