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
void ShellSort(int* a, size_t n)
{
	assert(a);
	int gap = 3;//将数组分组
	int end;
	int tmp;
	while (gap)
	{
		for (size_t i = 0; i < n; i++)
		{
			end = i + gap;
			tmp = a[end + gap];
			while (gap + end < n)//单次排序
			{
				if (a[end] > tmp)//大于则向后移动数据
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			//找到插入数据的正确位置，进行插入
			a[end + gap] = tmp;
		}
		gap /= 2;
	}
}
void TestShellSort()
{
	int a[] = { 9,8,7,6,10,4,3,2,1,0,5 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}