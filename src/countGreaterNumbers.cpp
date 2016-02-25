/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare(char* str1, char* str2)
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
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0;
	while (!compare(Arr[i].date, date) && i < len)
		i++;
	if (i == len)
		return 0;
	i++;
	while (compare(Arr[i].date, date) && i < len)
		i++;
	int count = 0;
	while (i < len){
		count++;
		i++;
	}
	return count;
}
