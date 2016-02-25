/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int greater(char* date1, char* date2)
{
	int i = 6;
	while (i < 10)
	{
		if (date1[i] > date2[i])
			return 1;
		else if (date1[i] < date2[i])
			return 2;
		else
			i++;
	}
	i = 3;
	while (i < 5)
	{
		if (date1[i] > date2[i])
			return 1;
		else if (date1[i] < date2[i])
			return 2;
		else
			i++;
	}
	i = 0;
	while (i < 2)
	{
		if (date1[i] > date2[i])
			return 1;
		else if (date1[i] < date2[i])
			return 2;
		else
			i++;
	}
	return 1;
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction* result = (struct transaction*)malloc((ALen + BLen)*sizeof(struct transaction));
	int i = 0, j = 0, z = 0;
	while (i < ALen && j < BLen)
	{
		int index = greater(A[i].date, B[j].date);
		if (index == 2)
		{
			result[z].amount = A[i].amount;
			int k = -1;
			do
			{
				k++;
				result[z].date[k] = A[i].date[k];
			} while (result[z].date[k] != '\0');
			k = -1;
			do
			{
				k++;
				result[z].description[k] = A[i].description[k];
			} while (result[z].description[k] != '\0');
			i++;
		}
		else
		{
			result[z].amount = B[j].amount;
			int k = -1;
			do
			{
				k++;
				result[z].date[k] = B[j].date[k];
			} while (result[z].date[k] != '\0');
			k = -1;
			do
			{
				k++;
				result[z].description[k] = B[j].description[k];
			} while (result[z].description[k] != '\0');
			j++;
		}
		z++;
	}
	while (i < ALen)
	{
		result[z].amount = A[i].amount;
		int k = -1;
		do
		{
			k++;
			result[z].date[k] = A[i].date[k];
		} while (result[z].date[k] != '\0');
		k = -1;
		do
		{
			k++;
			result[z].description[k] = A[i].description[k];
		} while (result[z].description[k] != '\0');
		i++;
		z++;
	}
	while (j < BLen)
	{
		result[z].amount = B[j].amount;
		int k = -1;
		do
		{
			k++;
			result[z].date[k] = B[j].date[k];
		} while (result[z].date[k] != '\0');
		k = -1;
		do
		{
			k++;
			result[z].description[k] = B[j].description[k];
		} while (result[z].description[k] != '\0');
		j++;
		z++;
	}
	return result;
}