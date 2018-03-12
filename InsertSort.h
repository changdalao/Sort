#include<stdio.h>
#include<assert.h>

void Print(int* a, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void InsertSort(int* a, size_t n)//直接插入排序
{
	assert(n);
	for (size_t i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)//单次排序
		{
			if (a[end] > tmp)//查找比tmp小的位置,并且后移数据
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}

void TestInsertSort()
{
	int arr[] = { 2,8,3,4,7,9,6,0,1,5 };
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	Print(arr, sizeof(arr) / sizeof(arr[0]));
}
