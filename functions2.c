#include "main.h"

/**
 * change_sign - A function to change the numbers signs
 * @integer: a number
 * @temp: a number
 * Return: void
 */

void change_sign(int *integer, int *temp)
{
	(*integer) *= (-1);
	(*temp) *= (-1);
}

/**
 * free_statments - a function to free strings
 * @string: 1st string to free
 * @str: 2nd string to free
 * Return: void
*/
void free_statments(char *string, char *str)
{
    free(str);
    free(string);
}