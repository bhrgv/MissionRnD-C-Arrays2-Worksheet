/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int stringCompare(char* str1, char* str2)
{
	int i;
	for (i = 0; str1[i] != '\0'&&str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			break;
	}
	if (str1[i] == '\0'&&str2[i] == '\0')
		return 1;
	return 0;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction* result = NULL;
	int i;
	int count = 0;
	for (i = 0; i < ALen; i++)
	{
		int j;
		for (j = 0; j < BLen; j++)
		{
			if (stringCompare(A[i].date, B[i].date))
			{
				count++;
				struct transaction *temp = result;
				result = (struct transaction*)malloc(count*sizeof(struct transaction));
				int z, k;
				//increasing the array size dynamically
				for (z = 0; z < count - 1; z++)
				{
					result[z].amount = temp[z].amount;
					k = -1;
					do{
						k++;
						result[z].date[k] = temp[z].date[k];
					} while (result[z].date[k] != '\0');
					k = -1;
					do{
						k++;
						result[z].description[k] = temp[z].description[k];
					} while (result[z].date[k] != '\0');
				}
				//copying the new transaction
				result[count - 1].amount = A[i].amount;
				k = -1;
				do{
					k++;
					result[count - 1].date[k] = A[i].date[k];
				} while (result[count - 1].date[k] != '\0');
				k = -1;
				do{
					k++;
					result[count - 1].description[k] = A[i].description[k];
				} while (result[count - 1].date[k] != '\0');
				break;
			}
		}
	}
	return result;
}