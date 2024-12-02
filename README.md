# ObsiFish-OS

*Текущая версия - 0.1.0*

ObsiFish OS - простая и быстрая операционная система

![GitHub top language](https://img.shields.io/github/languages/top/alexeev-prog/ObsiFish-OS)
![GitHub](https://img.shields.io/github/license/alexeev-prog/ObsiFish-OS)
![GitHub Repo stars](https://img.shields.io/github/stars/alexeev-prog/ObsiFish-OS)
![GitHub issues](https://img.shields.io/github/issues/alexeev-prog/ObsiFish-OS)

## Почему ObsiFish OS?

Операционная система ObsiFish OS была создана не для работы на компьютерах, и до релиза врядли она будет способна выполнять минимальные команды или программы. Мы не гарантируем, что она будет лучше чем DOS системы.

ObsiFish OS создана как домашний проект, который дал бы мне (а может, и вам) знания о работе операционной системе, девайсов, основ программирования и Computer Science.

## Установка

Перед запуском, установите make, nasm, gcc

```bash
# Установка тулчейна (i386 elf gcc компилятор)
# При возникающих ошибках создайте issue
wget http://newos.org/toolchains/i386-elf-4.9.1-Linux-x86_64.tar.xz
sudo mkdir /usr/local/i386elfgcc
sudo tar -xf i386-elf-4.9.1-Linux-x86_64.tar.xz -C /usr/local/i386elfgcc --strip-components=1
export PATH=$PATH:/usr/local/i386elfgcc/bin

# Установка и компиляция
git clone https://github.com/alexeev-prog/ObsiFish-OS.git
cd ObsiFish-OS

make fullbuild
make run
```

## Документация
Пользовательскую документацию можно получить по [этой ссылке](./docs/ru/index.md).

[Релизы программы]: https://github.com/alexeev-prog/ObsiFish-OS/releases

## Поддержка
Если у вас возникли сложности или вопросы по использованию ObsiFish OS, создайте 
[обсуждение](https://github.com/alexeev-prog/ObsiFish-OS/issues/new/choose) в данном репозитории или напишите на электронную почту <bro.alexeev@gmail.com>.

## Возможности

 + бутсектор и система сборки
 + MetalShell
 + драйвера клавиатуры
 + драйвера другие
 + cpu
 + libc
 + malloc
 + RSOD
 + цвета

## Литература, источники

По языку ассемблера:

 + Зубков С. В. «Assembler для DOS, Windows и Unix»
 + [Введение в машинный код](http://wasm.ru/article.php?article=1022001)
 + [Программирование на ассемблере под DOS](http://wasm.ru/article.php?article=1022003)
 + [Введение в ассемблер](https://hackware.ru/?p=8654)
 + [ASCII таблица](https://www.asciitable.com/)
 + [Погружение в ассемблер](https://xakep.ru/2017/09/11/asm-course-1/)
 + [От изучающего ассемблер до взломщика программ](https://wasm.in/attachments/skljarov-i-izuchaem-assembler-za-7-dnej-pdf.2906/)
 + [Руководство по ассемблеру MASM intel x86_64](https://metanit.com/assembler/tutorial/)

По языку Си:

 + Керниган Б., Ритчи Д. «Язык программирования C»
 + Шилдт Г. «Полный справочник по C»

По устройству операционных систем:

 + Таненбаум Э. «Современные операционные системы»
 + Таненбаум Э. «Операционные системы: Разработка и реализация»
 + Олифер В., Олифер Н. «Сетевые операционные системы»
 + [OSDEV Wiki](http://osdev.org)

По архитектуре ЭВМ:

 + Таненбаум Э. «Архитектура компьютера»
 + Гук М. «Аппаратные средства IBM PC. Энциклопедия»
 + Петцольд Ч. «Код. Тайный язык информатики»

Справочная информация

 + [Dan Rollins’s TechHelp](http://webpages.charter.net/danrollins/techhelp/index.htm)
 + [Intel Software Developer Manual](http://www.intel.com/products/processor/manuals/)
