; ------------------------------------------------------------------------------
;  ObsiFish OS Bootloader source code
;  File: boot/kernel_entry.asm
;  Title:	Код, служащий входной точкой для функции kmain из kernel.c
;  Last Change Date: 30 October 2023, 12:28 (UTC)
;  Author: alexeev-prog
;  License: GNU GPL v3
; ------------------------------------------------------------------------------
; Description: null
; ------------------------------------------------------------------------------


[bits 32]
[extern kmain]			; Определяем 'внешнюю' штуку с названием kmain - она понадобится
						; линкеру чтобы собрать все вместе
call kmain				; Вызываем определенную выше функцию, которая будет доступна
						; после линковки. Это функция kmain из kernel.c
jmp $
