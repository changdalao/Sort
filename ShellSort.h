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
///////////////////////////////////////////////////////////////
/*
上述代码有bug，遗留问题解决
bug->23行，当end+gap越界时，访问到了非法数据
但是没报错，不知道为什么？
先用C++容器vector解决
*/
///////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
using namespace std;
void ShellSort(vector<int>& arr)
{
	if (arr.size() == 0)
		return;
	int gap = 3;//分组
	int end = 0;
	int tmp = 0;
	
	while (gap) {
		for (int i = 0; i<arr.size() - 1; i++) {
			bool judge = true;
			end = i;
			if (end + gap<arr.size())
				tmp = arr[end + gap];
			else
				tmp = arr[end];
			while (end + gap<arr.size() && end >= 0 && arr[end]>tmp) {
				arr[end + gap] = arr[end];
				end -= gap;
				judge = false;
			}
			if (judge == false)
				arr[end + gap] = tmp;
			else
				continue;
		}
		gap /= 2;
	}
}
int main()
{
	int arr[] = { 2,9,3,7,6,8,4,1,5 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	ShellSort(v);
	system("pause");
	return 0;
}

