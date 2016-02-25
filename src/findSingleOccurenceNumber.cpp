/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

#include<iostream>
void sort(int* A, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (A[j]>A[j + 1])
			{
				int c = A[j];
				A[j] = A[j + 1];
				A[j + 1] = c;
			}
		}
	}
}
int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL)
		return -1;
	sort(A, len);
	int i = 0;
	while (i < len)
	{
		int count = 1;
		int temp = A[i];
		int j;
		for (j = i + 1; count != 3; j++)
			if (temp != A[j])
				break;
			else
				count++;
		if (count != 3)
			return temp;
		else
			i = j;
	}
	return -1;
}