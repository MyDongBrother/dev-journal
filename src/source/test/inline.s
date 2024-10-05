	.file	"inline.cpp"
	.text
	.p2align 4
	.type	_Z15complexSequencei.part.0, @function
_Z15complexSequencei.part.0:
.LFB10:
	.cfi_startproc
	cmpl	$1, %edi
	jle	.L16
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	leal	1(%rdi), %r12d
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	xorl	%ebp, %ebp
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movl	$2, %ebx
.L7:
	testb	$1, %bl
	jne	.L3
	leal	-1(%rbx), %edi
	movl	$2, %eax
	cmpl	$2, %ebx
	je	.L6
	call	_Z15complexSequencei.part.0
	addl	%eax, %eax
.L6:
	addl	$1, %ebx
	addl	%eax, %ebp
	cmpl	%r12d, %ebx
	jne	.L7
	movslq	%ebp, %rax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L3:
	.cfi_restore_state
	movl	%ebx, %edi
	movl	$3, %eax
	subl	$2, %edi
	je	.L6
	movl	$4, %eax
	cmpl	$1, %edi
	je	.L6
	call	_Z15complexSequencei.part.0
	addl	$3, %eax
	jmp	.L6
	.p2align 4,,10
	.p2align 3
.L16:
	.cfi_def_cfa_offset 8
	.cfi_restore 3
	.cfi_restore 6
	.cfi_restore 12
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE10:
	.size	_Z15complexSequencei.part.0, .-_Z15complexSequencei.part.0
	.align 2
	.p2align 4
	.globl	_ZN10InlineDemo10inlineDemoEi
	.type	_ZN10InlineDemo10inlineDemoEi, @function
_ZN10InlineDemo10inlineDemoEi:
.LFB4:
	.cfi_startproc
	endbr64
	cmpl	$1, %esi
	jg	.L481
	movl	$1, %r8d
	movq	%r8, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L481:
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	leal	1(%rsi), %r10d
	movl	$2, %edx
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
.L213:
	testb	$1, %dl
	jne	.L24
	leal	-1(%rdx), %r11d
	cmpl	$2, %edx
	je	.L25
	movl	$2, %ecx
.L118:
	testb	$1, %cl
	jne	.L26
	leal	-1(%rcx), %ebp
	cmpl	$2, %ecx
	je	.L27
	movl	$2, %r8d
.L72:
	testb	$1, %r8b
	jne	.L28
	leal	-1(%r8), %r12d
	cmpl	$2, %r8d
	je	.L29
	movl	$2, %r9d
	testb	$1, %r9b
	jne	.L30
.L482:
	leal	-1(%r9), %r14d
	cmpl	$2, %r9d
	je	.L31
	movl	$2, %ebx
.L40:
	testb	$1, %bl
	jne	.L32
	leal	-1(%rbx), %r15d
	cmpl	$2, %ebx
	je	.L33
	movl	$2, %r13d
.L36:
	testb	$1, %r13b
	jne	.L34
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L35
.L441:
	call	_Z15complexSequencei.part.0
.L35:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L36
.L33:
	addl	$1, %ebx
	cmpl	%r14d, %ebx
	jle	.L40
	.p2align 4,,10
	.p2align 3
.L31:
	addl	$1, %r9d
	cmpl	%r12d, %r9d
	jg	.L29
	testb	$1, %r9b
	je	.L482
.L30:
	leal	-2(%r9), %r14d
	cmpl	$1, %r14d
	jbe	.L31
	movl	$2, %ebx
.L49:
	testb	$1, %bl
	jne	.L41
	leal	-1(%rbx), %r15d
	cmpl	$2, %ebx
	je	.L42
	movl	$2, %r13d
.L45:
	testb	$1, %r13b
	jne	.L43
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L44
.L443:
	call	_Z15complexSequencei.part.0
.L44:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L45
.L42:
	addl	$1, %ebx
	cmpl	%r14d, %ebx
	jle	.L49
	jmp	.L31
	.p2align 4,,10
	.p2align 3
.L119:
	leal	-2(%rcx), %ebx
	cmpl	$1, %ebx
	ja	.L483
.L120:
	addl	$1, %ecx
	cmpl	%ecx, %r9d
	jge	.L211
	.p2align 4,,10
	.p2align 3
.L25:
	addl	$1, %edx
	cmpl	%r10d, %edx
	jne	.L213
	movslq	%esi, %rdx
	leal	-1(%rsi), %ecx
	movl	$1, %r8d
	leaq	-1(%rdx), %rax
	movq	%rax, %rdi
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	jmp	.L214
	.p2align 4,,10
	.p2align 3
.L484:
	subq	$1, %rax
.L214:
	imulq	%rdx, %r8
	movq	%rax, %rdx
	cmpq	%rax, %rcx
	jne	.L484
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%r8, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L26:
	.cfi_restore_state
	leal	-2(%rcx), %ebx
	cmpl	$1, %ebx
	ja	.L485
.L27:
	addl	$1, %ecx
	cmpl	%r11d, %ecx
	jle	.L118
	jmp	.L25
	.p2align 4,,10
	.p2align 3
.L24:
	leal	-2(%rdx), %r9d
	cmpl	$1, %r9d
	jbe	.L25
	movl	$2, %ecx
.L211:
	testb	$1, %cl
	jne	.L119
	leal	-1(%rcx), %ebp
	cmpl	$2, %ecx
	je	.L120
	movl	$2, %r8d
.L165:
	testb	$1, %r8b
	jne	.L121
	leal	-1(%r8), %r12d
	cmpl	$2, %r8d
	je	.L122
	movl	$2, %r11d
	testb	$1, %r11b
	jne	.L123
.L486:
	leal	-1(%r11), %r14d
	cmpl	$2, %r11d
	je	.L124
	movl	$2, %ebx
.L133:
	testb	$1, %bl
	jne	.L125
	leal	-1(%rbx), %r15d
	cmpl	$2, %ebx
	je	.L126
	movl	$2, %r13d
.L129:
	testb	$1, %r13b
	jne	.L127
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L128
.L457:
	call	_Z15complexSequencei.part.0
.L128:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L129
.L126:
	addl	$1, %ebx
	cmpl	%ebx, %r14d
	jge	.L133
	.p2align 4,,10
	.p2align 3
.L124:
	addl	$1, %r11d
	cmpl	%r11d, %r12d
	jl	.L122
	testb	$1, %r11b
	je	.L486
.L123:
	leal	-2(%r11), %r14d
	cmpl	$1, %r14d
	jbe	.L124
	movl	$2, %ebx
.L142:
	testb	$1, %bl
	jne	.L134
	leal	-1(%rbx), %r15d
	cmpl	$2, %ebx
	je	.L135
	movl	$2, %r13d
.L138:
	testb	$1, %r13b
	jne	.L136
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L137
.L459:
	call	_Z15complexSequencei.part.0
.L137:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L138
.L135:
	addl	$1, %ebx
	cmpl	%ebx, %r14d
	jge	.L142
	jmp	.L124
	.p2align 4,,10
	.p2align 3
.L121:
	leal	-2(%r8), %r12d
	cmpl	$1, %r12d
	ja	.L487
.L122:
	addl	$1, %r8d
	cmpl	%r8d, %ebp
	jge	.L165
	jmp	.L120
	.p2align 4,,10
	.p2align 3
.L28:
	leal	-2(%r8), %r12d
	cmpl	$1, %r12d
	ja	.L488
.L29:
	addl	$1, %r8d
	cmpl	%ebp, %r8d
	jle	.L72
	jmp	.L27
	.p2align 4,,10
	.p2align 3
.L485:
	movl	$2, %r8d
	testb	$1, %r8b
	jne	.L73
.L489:
	leal	-1(%r8), %r12d
	cmpl	$2, %r8d
	je	.L74
	movl	$2, %r9d
.L95:
	testb	$1, %r9b
	jne	.L75
	leal	-1(%r9), %r14d
	cmpl	$2, %r9d
	je	.L76
	movl	$2, %ebp
.L85:
	testb	$1, %bpl
	jne	.L77
	leal	-1(%rbp), %r15d
	cmpl	$2, %ebp
	je	.L78
	movl	$2, %r13d
.L81:
	testb	$1, %r13b
	jne	.L79
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L80
.L449:
	call	_Z15complexSequencei.part.0
.L80:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L81
.L78:
	addl	$1, %ebp
	cmpl	%ebp, %r14d
	jge	.L85
	.p2align 4,,10
	.p2align 3
.L76:
	addl	$1, %r9d
	cmpl	%r12d, %r9d
	jle	.L95
	.p2align 4,,10
	.p2align 3
.L74:
	addl	$1, %r8d
	cmpl	%ebx, %r8d
	jg	.L27
	testb	$1, %r8b
	je	.L489
.L73:
	leal	-2(%r8), %r12d
	cmpl	$1, %r12d
	jbe	.L74
	movl	$2, %r9d
	testb	$1, %r9b
	jne	.L96
.L490:
	leal	-1(%r9), %r14d
	cmpl	$2, %r9d
	je	.L97
	movl	$2, %ebp
.L106:
	testb	$1, %bpl
	jne	.L98
	leal	-1(%rbp), %r15d
	cmpl	$2, %ebp
	je	.L99
	movl	$2, %r13d
.L102:
	testb	$1, %r13b
	jne	.L100
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L101
.L453:
	call	_Z15complexSequencei.part.0
.L101:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L102
.L99:
	addl	$1, %ebp
	cmpl	%ebp, %r14d
	jge	.L106
	.p2align 4,,10
	.p2align 3
.L97:
	addl	$1, %r9d
	cmpl	%r12d, %r9d
	jg	.L74
	testb	$1, %r9b
	je	.L490
.L96:
	leal	-2(%r9), %r14d
	cmpl	$1, %r14d
	jbe	.L97
	movl	$2, %ebp
.L115:
	testb	$1, %bpl
	jne	.L107
	leal	-1(%rbp), %r15d
	cmpl	$2, %ebp
	je	.L108
	movl	$2, %r13d
.L111:
	testb	$1, %r13b
	jne	.L109
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L110
.L455:
	call	_Z15complexSequencei.part.0
.L110:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L111
.L108:
	addl	$1, %ebp
	cmpl	%r14d, %ebp
	jle	.L115
	jmp	.L97
	.p2align 4,,10
	.p2align 3
.L483:
	movl	$2, %r8d
	testb	$1, %r8b
	jne	.L166
.L491:
	leal	-1(%r8), %r12d
	cmpl	$2, %r8d
	je	.L167
	movl	$2, %r11d
.L188:
	testb	$1, %r11b
	jne	.L168
	leal	-1(%r11), %r14d
	cmpl	$2, %r11d
	je	.L169
	movl	$2, %ebp
.L178:
	testb	$1, %bpl
	jne	.L170
	leal	-1(%rbp), %r15d
	cmpl	$2, %ebp
	je	.L171
	movl	$2, %r13d
.L174:
	testb	$1, %r13b
	jne	.L172
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L173
.L465:
	call	_Z15complexSequencei.part.0
.L173:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L174
.L171:
	addl	$1, %ebp
	cmpl	%ebp, %r14d
	jge	.L178
	.p2align 4,,10
	.p2align 3
.L169:
	addl	$1, %r11d
	cmpl	%r11d, %r12d
	jge	.L188
	.p2align 4,,10
	.p2align 3
.L167:
	addl	$1, %r8d
	cmpl	%r8d, %ebx
	jl	.L120
	testb	$1, %r8b
	je	.L491
.L166:
	leal	-2(%r8), %r12d
	cmpl	$1, %r12d
	jbe	.L167
	movl	$2, %r11d
	testb	$1, %r11b
	jne	.L189
.L492:
	leal	-1(%r11), %r14d
	cmpl	$2, %r11d
	je	.L190
	movl	$2, %ebp
.L199:
	testb	$1, %bpl
	jne	.L191
	leal	-1(%rbp), %r15d
	cmpl	$2, %ebp
	je	.L192
	movl	$2, %r13d
.L195:
	testb	$1, %r13b
	jne	.L193
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L194
.L469:
	call	_Z15complexSequencei.part.0
.L194:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L195
.L192:
	addl	$1, %ebp
	cmpl	%ebp, %r14d
	jge	.L199
	.p2align 4,,10
	.p2align 3
.L190:
	addl	$1, %r11d
	cmpl	%r11d, %r12d
	jl	.L167
	testb	$1, %r11b
	je	.L492
.L189:
	leal	-2(%r11), %r14d
	cmpl	$1, %r14d
	jbe	.L190
	movl	$2, %ebp
.L208:
	testb	$1, %bpl
	jne	.L200
	leal	-1(%rbp), %r15d
	cmpl	$2, %ebp
	je	.L201
	movl	$2, %r13d
.L204:
	testb	$1, %r13b
	jne	.L202
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L203
.L471:
	call	_Z15complexSequencei.part.0
.L203:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L204
.L201:
	addl	$1, %ebp
	cmpl	%ebp, %r14d
	jge	.L208
	jmp	.L190
	.p2align 4,,10
	.p2align 3
.L168:
	leal	-2(%r11), %r14d
	cmpl	$1, %r14d
	jbe	.L169
	movl	$2, %ebp
.L187:
	testb	$1, %bpl
	jne	.L179
	leal	-1(%rbp), %r15d
	cmpl	$2, %ebp
	je	.L180
	movl	$2, %r13d
.L183:
	testb	$1, %r13b
	jne	.L181
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L182
.L467:
	call	_Z15complexSequencei.part.0
.L182:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L183
.L180:
	addl	$1, %ebp
	cmpl	%ebp, %r14d
	jge	.L187
	jmp	.L169
	.p2align 4,,10
	.p2align 3
.L75:
	leal	-2(%r9), %r14d
	cmpl	$1, %r14d
	jbe	.L76
	movl	$2, %ebp
.L94:
	testb	$1, %bpl
	jne	.L86
	leal	-1(%rbp), %r15d
	cmpl	$2, %ebp
	je	.L87
	movl	$2, %r13d
.L90:
	testb	$1, %r13b
	jne	.L88
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L89
.L451:
	call	_Z15complexSequencei.part.0
.L89:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L90
.L87:
	addl	$1, %ebp
	cmpl	%ebp, %r14d
	jge	.L94
	jmp	.L76
.L487:
	movl	$2, %r11d
	testb	$1, %r11b
	jne	.L144
.L493:
	leal	-1(%r11), %r14d
	cmpl	$2, %r11d
	je	.L145
	movl	$2, %ebx
.L154:
	testb	$1, %bl
	jne	.L146
	leal	-1(%rbx), %r15d
	cmpl	$2, %ebx
	je	.L147
	movl	$2, %r13d
.L150:
	testb	$1, %r13b
	jne	.L148
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L149
.L461:
	call	_Z15complexSequencei.part.0
.L149:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L150
.L147:
	addl	$1, %ebx
	cmpl	%ebx, %r14d
	jge	.L154
	.p2align 4,,10
	.p2align 3
.L145:
	addl	$1, %r11d
	cmpl	%r11d, %r12d
	jl	.L122
	testb	$1, %r11b
	je	.L493
.L144:
	leal	-2(%r11), %r14d
	cmpl	$1, %r14d
	jbe	.L145
	movl	$2, %ebx
.L163:
	testb	$1, %bl
	jne	.L155
	leal	-1(%rbx), %r15d
	cmpl	$2, %ebx
	je	.L156
	movl	$2, %r13d
.L159:
	testb	$1, %r13b
	jne	.L157
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L158
.L463:
	call	_Z15complexSequencei.part.0
.L158:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L159
.L156:
	addl	$1, %ebx
	cmpl	%ebx, %r14d
	jge	.L163
	jmp	.L145
.L488:
	movl	$2, %r9d
	testb	$1, %r9b
	jne	.L51
.L494:
	leal	-1(%r9), %r14d
	cmpl	$2, %r9d
	je	.L52
	movl	$2, %ebx
.L61:
	testb	$1, %bl
	jne	.L53
	leal	-1(%rbx), %r15d
	cmpl	$2, %ebx
	je	.L54
	movl	$2, %r13d
.L57:
	testb	$1, %r13b
	jne	.L55
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L56
.L445:
	call	_Z15complexSequencei.part.0
.L56:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L57
.L54:
	addl	$1, %ebx
	cmpl	%r14d, %ebx
	jle	.L61
	.p2align 4,,10
	.p2align 3
.L52:
	addl	$1, %r9d
	cmpl	%r12d, %r9d
	jg	.L29
	testb	$1, %r9b
	je	.L494
.L51:
	leal	-2(%r9), %r14d
	cmpl	$1, %r14d
	jbe	.L52
	movl	$2, %ebx
.L70:
	testb	$1, %bl
	jne	.L62
	leal	-1(%rbx), %r15d
	cmpl	$2, %ebx
	je	.L63
	movl	$2, %r13d
.L66:
	testb	$1, %r13b
	jne	.L64
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L65
.L447:
	call	_Z15complexSequencei.part.0
.L65:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L66
.L63:
	addl	$1, %ebx
	cmpl	%r14d, %ebx
	jle	.L70
	jmp	.L52
.L53:
	leal	-2(%rbx), %r15d
	cmpl	$1, %r15d
	jbe	.L54
	movl	$2, %r13d
.L60:
	testb	$1, %r13b
	jne	.L58
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L59
.L446:
	call	_Z15complexSequencei.part.0
.L59:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L60
	jmp	.L54
.L146:
	leal	-2(%rbx), %r15d
	cmpl	$1, %r15d
	jbe	.L147
	movl	$2, %r13d
.L153:
	testb	$1, %r13b
	jne	.L151
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L152
.L462:
	call	_Z15complexSequencei.part.0
.L152:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L153
	jmp	.L147
.L170:
	leal	-2(%rbp), %r15d
	cmpl	$1, %r15d
	jbe	.L171
	movl	$2, %r13d
.L177:
	testb	$1, %r13b
	jne	.L175
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L176
.L466:
	call	_Z15complexSequencei.part.0
.L176:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L177
	jmp	.L171
.L191:
	leal	-2(%rbp), %r15d
	cmpl	$1, %r15d
	jbe	.L192
	movl	$2, %r13d
.L198:
	testb	$1, %r13b
	jne	.L196
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L197
.L470:
	call	_Z15complexSequencei.part.0
.L197:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L198
	jmp	.L192
.L32:
	leal	-2(%rbx), %r15d
	cmpl	$1, %r15d
	jbe	.L33
	movl	$2, %r13d
.L39:
	testb	$1, %r13b
	jne	.L37
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L38
.L442:
	call	_Z15complexSequencei.part.0
.L38:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L39
	jmp	.L33
.L125:
	leal	-2(%rbx), %r15d
	cmpl	$1, %r15d
	jbe	.L126
	movl	$2, %r13d
.L132:
	testb	$1, %r13b
	jne	.L130
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L131
.L458:
	call	_Z15complexSequencei.part.0
.L131:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L132
	jmp	.L126
.L98:
	leal	-2(%rbp), %r15d
	cmpl	$1, %r15d
	jbe	.L99
	movl	$2, %r13d
.L105:
	testb	$1, %r13b
	jne	.L103
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L104
.L454:
	call	_Z15complexSequencei.part.0
.L104:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L105
	jmp	.L99
.L77:
	leal	-2(%rbp), %r15d
	cmpl	$1, %r15d
	jbe	.L78
	movl	$2, %r13d
.L84:
	testb	$1, %r13b
	jne	.L82
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L83
.L450:
	call	_Z15complexSequencei.part.0
.L83:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L84
	jmp	.L78
.L41:
	leal	-2(%rbx), %r15d
	cmpl	$1, %r15d
	jbe	.L42
	movl	$2, %r13d
.L48:
	testb	$1, %r13b
	jne	.L46
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L47
.L444:
	call	_Z15complexSequencei.part.0
.L47:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L48
	jmp	.L42
.L134:
	leal	-2(%rbx), %r15d
	cmpl	$1, %r15d
	jbe	.L135
	movl	$2, %r13d
.L141:
	testb	$1, %r13b
	jne	.L139
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L140
.L460:
	call	_Z15complexSequencei.part.0
.L140:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L141
	jmp	.L135
.L179:
	leal	-2(%rbp), %r15d
	cmpl	$1, %r15d
	jbe	.L180
	movl	$2, %r13d
.L186:
	testb	$1, %r13b
	jne	.L184
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L185
.L468:
	call	_Z15complexSequencei.part.0
.L185:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L186
	jmp	.L180
.L86:
	leal	-2(%rbp), %r15d
	cmpl	$1, %r15d
	jbe	.L87
	movl	$2, %r13d
.L93:
	testb	$1, %r13b
	jne	.L91
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L92
.L452:
	call	_Z15complexSequencei.part.0
.L92:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L93
	jmp	.L87
.L155:
	leal	-2(%rbx), %r15d
	cmpl	$1, %r15d
	jbe	.L156
	movl	$2, %r13d
.L162:
	testb	$1, %r13b
	jne	.L160
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L161
.L464:
	call	_Z15complexSequencei.part.0
.L161:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L162
	jmp	.L156
.L107:
	leal	-2(%rbp), %r15d
	cmpl	$1, %r15d
	jbe	.L108
	movl	$2, %r13d
.L114:
	testb	$1, %r13b
	jne	.L112
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L113
.L456:
	call	_Z15complexSequencei.part.0
.L113:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L114
	jmp	.L108
.L200:
	leal	-2(%rbp), %r15d
	cmpl	$1, %r15d
	jbe	.L201
	movl	$2, %r13d
.L207:
	testb	$1, %r13b
	jne	.L205
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L206
.L472:
	call	_Z15complexSequencei.part.0
.L206:
	addl	$1, %r13d
	cmpl	%r13d, %r15d
	jge	.L207
	jmp	.L201
.L62:
	leal	-2(%rbx), %r15d
	cmpl	$1, %r15d
	jbe	.L63
	movl	$2, %r13d
.L69:
	testb	$1, %r13b
	jne	.L67
	leal	-1(%r13), %edi
	cmpl	$2, %r13d
	je	.L68
.L448:
	call	_Z15complexSequencei.part.0
.L68:
	addl	$1, %r13d
	cmpl	%r15d, %r13d
	jle	.L69
	jmp	.L63
.L67:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L68
	jmp	.L448
.L55:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L56
	jmp	.L445
.L193:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L194
	jmp	.L469
.L100:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L101
	jmp	.L453
.L205:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L206
	jmp	.L472
.L112:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L113
	jmp	.L456
.L202:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L203
	jmp	.L471
.L109:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L110
	jmp	.L455
.L58:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L59
	jmp	.L446
.L151:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L152
	jmp	.L462
.L175:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L176
	jmp	.L466
.L196:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L197
	jmp	.L470
.L37:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L38
	jmp	.L442
.L130:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L131
	jmp	.L458
.L103:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L104
	jmp	.L454
.L82:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L83
	jmp	.L450
.L160:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L161
	jmp	.L464
.L148:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L149
	jmp	.L461
.L64:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L65
	jmp	.L447
.L157:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L158
	jmp	.L463
.L127:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L128
	jmp	.L457
.L34:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L35
	jmp	.L441
.L79:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L80
	jmp	.L449
.L172:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L173
	jmp	.L465
.L91:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L92
	jmp	.L452
.L184:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L185
	jmp	.L468
.L181:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L182
	jmp	.L467
.L88:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L89
	jmp	.L451
.L139:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L140
	jmp	.L460
.L46:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L47
	jmp	.L444
.L136:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L137
	jmp	.L459
.L43:
	leal	-2(%r13), %edi
	cmpl	$1, %edi
	jbe	.L44
	jmp	.L443
	.cfi_endproc
.LFE4:
	.size	_ZN10InlineDemo10inlineDemoEi, .-_ZN10InlineDemo10inlineDemoEi
	.align 2
	.p2align 4
	.globl	_ZN10InlineDemo17outline_factorialEi
	.type	_ZN10InlineDemo17outline_factorialEi, @function
_ZN10InlineDemo17outline_factorialEi:
.LFB8:
	.cfi_startproc
	endbr64
	movl	$1, %r8d
	testl	%esi, %esi
	jle	.L495
	movslq	%esi, %rdx
	leal	-1(%rsi), %ecx
	movl	$1, %r8d
	leaq	-1(%rdx), %rax
	movq	%rax, %rdi
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	jmp	.L498
	.p2align 4,,10
	.p2align 3
.L499:
	subq	$1, %rax
.L498:
	imulq	%rdx, %r8
	movq	%rax, %rdx
	cmpq	%rcx, %rax
	jne	.L499
.L495:
	movq	%r8, %rax
	ret
	.cfi_endproc
.LFE8:
	.size	_ZN10InlineDemo17outline_factorialEi, .-_ZN10InlineDemo17outline_factorialEi
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
