#include <stdio.h>
#include <string.h>

struct student
{
	char name[20];
	int num;
	int s;
} stu[100];

void quicksort(struct student arr[], int i, int j)
{
	int left = i, right = j, m = arr[(left + right) / 2].s;
	struct student t;
	while (left <= right)
	{
		while (arr[left].s > m)
			left++;
		while (arr[right].s < m)
			right--;
		if (left <= right)
		{
			t = arr[left];
			arr[left] = arr[right];
			arr[right] = t;
			left++;
			right--;
		}
	}
	if (right > i)
		quicksort(arr, i, right);
	if (left < j)
		quicksort(arr, left, j);
}

int main()
{
	FILE *f1 = fopen("temp\www\start.txt", "w");
	if (f1 == NULL)
	{
		printf("error1");
		return 1;
	}
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s %d %d", stu[i].name, &stu[i].num, &stu[i].s);
		fprintf(f1, "%s %d %d\n", stu[i].name, stu[i].num, stu[i].s);
	}
	quicksort(stu, 0, n - 1);
	FILE *f2 = fopen(".\\www\\end.txt", "w");
	if (f2 == NULL)
	{
		printf("error");
		return 1;
	}
	for (i = 0; i < n; i++)
	{
		fprintf(f2, "%d %s %d %d\n", i + 1, stu[i].name, stu[i].num, stu[i].s);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
