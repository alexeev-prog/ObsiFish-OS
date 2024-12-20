; ------------------------------------------------------------------------------
;  ObsiFish OS Bootloader source code
;  File: boot/puts_chars32.asm
;  Title: Функция вывода строки на экран в 32-битном защищенном режиме
;  Last Change Date: 30 October 2023, 12:28 (UTC)
;  Author: alexeev-prog
;  License: GNU GPL v3
; ------------------------------------------------------------------------------
; Description:
;	Плюсы 32-битного режима: возможность использовать 32-битные регистры и
;	адрессацию памяти, защищенную память виртуальную память
;	Минусы: отсутствие БИОС прерываний, требование наличия GDT (об этом позже)
;	В этой программе мы напишем новую функцию печати строки, но без прерываний
;	БИОСа, а напрямую манипулируя VGA видеопамятью, вместо вызова int 0x10.
;	VGA размещена начиная с адреса 0xb8000, и у VGA имеется специальный
;	текстовый режим, поэтому нам не придется напрямую рисовать пиксели.
;	Особенности:
;	1. Символ представляется в виде 2-х байтов. Первый байт = сам символ,
;	второй байт = 4 бита на цвет текста и еще 4 на цвет фона. 
;	Например, чтобы распечатать символ 'A' белым текстом на черном фоне, мы
;	испольузуем 0x410f: 0x41 == 'A', 0 == белый, f == черный.
; ------------------------------------------------------------------------------


[bits 32]					; Используем 32-битный режим

							; Определяем некоторые константы
VIDEO_MEMORY equ 0xb8000	; = адрес начала памяти VGA
;; Цвета символов ;;
;;  > 0x0f - белый на черном
;;  > 0x1f - белый на синем
WHITE_ON_BLACK equ 0x0f
WHITE_ON_BLUE equ 0x1F      
WHITE_ON_GREEN equ 0x2F
WHITE_ON_RED equ 0x4F

puts_chars_pm:
	pusha
	mov edx, VIDEO_MEMORY	; Перемещаем в EDX адрес начала массива видеопамяти

puts_chars_pm_loop:
							; Помним, что AX (2б) = AH(1б) и AL(1б)
	mov al, [ebx]			; Сохраняем символ из EBX в AL
	mov ah, WHITE_ON_BLUE	; Устанавливаем цвет символов в AH
							; таким образом AX получается равен символу + цвету

	cmp al, 0				; if (AL == 0), т.е. если конец массива, то
	je puts_chars_pm_done	; заканчиваем выполнение функции
							; else:
	mov [edx], ax			; video_memory[EDX] = AX
	add ebx, 1				; переходим к следующему символу (+1, просто массив)
	add edx, 2				; переходим к следующему адресу в VGA (+2 т.к.
							; два байта на символ)

	jmp puts_chars_pm_loop

puts_chars_pm_done:
	popa
	ret
