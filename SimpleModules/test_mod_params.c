#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>
 

// Module metadata
MODULE_AUTHOR("Andrei Tokmakov");
MODULE_DESCRIPTION("TestModuleParams");
MODULE_LICENSE("GPL");

 
static short int myshort = 1;
static int myint = 420;
static long int mylong = 9999;
static char *mystring = "blah";
static int myintarray[2] = { 420, 420 };
static int arr_argc = 0;
 
/* module_param(foo, int, 0000)
 * Первым аргументом указывается имя параметра.
 * Вторым указывается его тип.
 * Третьим указываются биты разрешений
 * для представления параметров в sysfs (если не нуль) позднее.
 */
module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");
 
/* module_param_array(name, type, num, perm);
 * Первым аргументом идёт имя параметра (в данном случае массива).
 * Второй аргумент – это тип элементов массива.
 * Третий – это указатель на переменную, которая будет хранить количество элементов массива, инициализированных пользователем при загрузке модуля.
 * Четвёртый аргумент – это биты разрешения.
 */
module_param_array(myintarray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintarray, "An array of integers");
 
static int __init hello_5_init(void)
{
    int i;
 
    pr_info("Hello, world 5\n=============\n");
    pr_info("myshort is a short integer: %hd\n", myshort);
    pr_info("myint is an integer: %d\n", myint);
    pr_info("mylong is a long integer: %ld\n", mylong);
    pr_info("mystring is a string: %s\n", mystring);
 
    for (i = 0; i < ARRAY_SIZE(myintarray); i++)
        pr_info("myintarray[%d] = %d\n", i, myintarray[i]);
 
    pr_info("got %d arguments for myintarray.\n", arr_argc);
    return 0;
}
 
static void __exit hello_5_exit(void)
{
    pr_info("Goodbye, world 5\n");
}
 
module_init(hello_5_init);
module_exit(hello_5_exit);



/*


$ sudo insmod test_mod_params.ko mystring="bebop" myintarray=-1
$ sudo dmesg -t | tail -9

        Hello, world 5
        =============
        myshort is a short integer: 1
        myint is an integer: 420
        mylong is a long integer: 9999
        mystring is a string: bebop
        myintarray[0] = -1
        myintarray[1] = 420
        got 1 arguments for myintarray.


$ sudo rmmod test_mod_params
$ sudo dmesg -t | tail -1

        Goodbye, world 5

$ sudo insmod test_mod_params.ko mystring="supercalifragilisticexpialidocious" myintarray=-1,-1
$ sudo dmesg -t | tail -9

        Hello, world 5
        =============
        myshort is a short integer: 1
        myint is an integer: 420
        mylong is a long integer: 9999
        mystring is a string: supercalifragilisticexpialidocious
        myintarray[0] = -1
        myintarray[1] = -1
        got 2 arguments for myintarray.


$ sudo rmmod test_mod_params
$ sudo dmesg -t | tail -1

        Goodbye, world 5

$ sudo insmod test_mod_params.ko mylong=hello

        insmod: ERROR: could not insert module test_mod_params.ko: Invalid parameters

*/