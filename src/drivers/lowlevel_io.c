/*------------------------------------------------------------------------------
*  ObsiFish OS Drivers source code
*  File: drivers/lowlevel_io.c
*  Title:	Низкоуровневые I/O функции для работы с девайсами
*  Last Change Date: 30 October 2023, 12:28 (UTC)
*  Author: alexeev-prog
*  License: GNU GPL v3
* ------------------------------------------------------------------------------
*	Description:
*		Обычно есть два способа взаимодействовать с hardware - memory-mapped I/O
*		и I/O ports. 
*		Если девайс использует memory-mapped I/O, то чтобы передать ему 
*		какую-либо информацию, нужно записать ее в специальный адрес. Например, 
*		чтобы вывести символ на экран, мы записывали его в адрес 0xb8000.
*		Если девайс использует I/O ports, то для взаимодействия с ним
*		используются инструкции ассемблера in и out.
*
*       Чтобы работать с дейвасом, нам достаточно знать что в нем есть некий
*       контролирующий чип, который делает всю грязную работу за нас и позволяет
*       процессору взаимодействовать с напрямую с железом дейваса. У такого чипа
*       есть регистры в которые можно что-то записывать или что-то из них
*       читать, и значение этих регистров указывет чипу что делать.
*
*       Как мы будем читать/писать в регистры контролирующих чипов девайса? Вот
*       что нужно знать:
*       1. В архитектуре процессоров Интел, регистры контроля девайсами
*       расположены в специальном I/O адресном пространстве.
*       2. Инструкции ввода-ввывода используют такой синтаксис (intel syntax):
*       in <записать результат сюда (регистр процессора)>, <прочитать
*                                       содержимое отсюда (регистр девайса)>
*       out <записать сюда (регистр девайса)>, <вот это>
*       3. К сожалению, в языке Си нет подобных конструкций, так что нам
*       придется использовать inline assembly.
* ----------------------------------------------------------------------------*/


unsigned char   port_byte_in(unsigned short port)
{
    /* Функция-обертка над assembly, читающая 1 байт из параметра port */
    /* unsigned short port: адрес регистра какого-либо девайса, из которого */
    /* мы что-то прочтем. */

    /* Используется другой синтаксис ассембли (GAS). Обратите внимание, что */
    /* выражение "mov dest, src" в GAS мы запишем как "mov src, dest", т.е. */
    /* "in dx, al" означает прочитать содержимое порта (адрес которого */
    /* находится в DX) и положить в AL. */
    /* Символ % означает регистр, а т.к. % - escape symbol, то мы */
    /* пишем еще один %. */
    /* Перемещаем результат в регистр AL т.к. размер AL == 1 байт */
    unsigned char result;
	__asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
	/* разберем только что вызванную функцию: */
	/* "in %%dx, %%al"		- Прочитать содержимое порта и положить это в AL */
	/* : "=a" (result)		- Положить значение AL в переменную result */
	/* : "d" (port)			- Загрузить port в регистр EDX (extended DX: 32b) */
    return (result);		/* Возвращаем прочитанное содержимое из port */
}


void    port_byte_out(unsigned short port, unsigned char data)
{
    /* Функция-обертка над assembly, пишущая data (1 байт) в port */
    /* unsigned short port: адрес регистра девайса, в который что-то запишем */
    /* unsigned char data: 1 байт какой-то информации (например, символ) */
	__asm__("out %%al, %%dx" : : "a" (data), "d" (port));
	/* разберем только что вызванную функцию: */
	/* "out %%al, %%dx"		- Записать data в port */
	/* : : "a" (data)		- Загрузить data в регистр EAX */
	/* : "d" (port)			- Загрузить port в регистр EDX */
}


unsigned char   port_word_in(unsigned short port)
{
    /* Функция-обертка над assembly, читающая 2 байта из параметра port */
    /* Перемещаем результат в регистр AX т.к. размер AX == 2 байта */
    unsigned short result;
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return (result);
}


void port_word_out(unsigned short port, unsigned short data)
{
    /* Функция-обертка над assembly, пишущая data (2 байта, т.е. word) в port */
    __asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}
