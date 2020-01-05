#include <stdio.h>

int init[] = {22, 34, 3, 32, 82, 55, 89, 50, 22, 37, 5, 64, 35, 9, 70};
void swapData(int *a, int *b)
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

void foreachArr(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void resetArrData(int *arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		arr[i] = init[i];
	}
	printf("reset arr \n");
}

//冒泡排序
//冒泡排序（英语：Bubble Sort）是一种简单的排序算法。
//它重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序（如从大到小、首字母从A到Z）错误就把他们交换过来。
void bubbleSort(int arr[], int len)
{
	int i, j = 0;
	int tmp;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swapData(&arr[j], &arr[j + 1]);
		}
	}
}

//选择排序
//选择排序（Selection sort）是一种简单直观的排序算法。
//它的工作原理如下。首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
//以此类推，直到所有元素均排序完毕。
void selectSort(int arr[], int len)
{
	int i, minPos, j;
	for (i = 0; i < len - 1; i++)
	{
		minPos = i;
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[minPos])
				minPos = j; //找到最小值位置
		}
		swapData(&arr[minPos], &arr[i]);
	}
}

//插入排序
//插入排序（英语：Insertion Sort）是一种简单直观的排序算法。它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
//插入排序在实现上，通常采用in-place排序（即只需用到 {\displaystyle O(1)} {\displaystyle O(1)}的额外空间的排序），因而在从后向前扫描过程中，需要反复把已排序元素逐步向后
//挪位，为最新元素提供插入空间。
void insertionSort(int arr[], int len)
{
	int i, j, temp;
	for (i = 1; i < len; i++)
	{
		temp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
			arr[j] = arr[j - 1];
		arr[j] = temp;
	}
}

//快速排序
//在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，再分别对小数区与大数区进行排序。
void quick_sort_recursive(int arr[], int start, int end)
{
	if (start >= end)
		return;
	int mid = arr[end];
	int left = start, right = end - 1;
	while (left < right)
	{
		while (arr[left] < mid && left < right)
			left++;
		while (arr[right] >= mid && left < right)
			right--;
		swapData(&arr[left], &arr[right]);
	}
	if (arr[left] >= arr[end])
		swapData(&arr[left], &arr[end]);
	else
		left++;
	if (left)
		quick_sort_recursive(arr, start, left - 1);
	quick_sort_recursive(arr, left + 1, end);
}

void quick_sort(int arr[], int len)
{
	quick_sort_recursive(arr, 0, len - 1);
}

void main()
{
	int len = (int)sizeof(init) / sizeof(*init);
	int arr[len];
	resetArrData(arr, len); //重置
	foreachArr(arr, len);
	bubbleSort(arr, len); //排序
	foreachArr(arr, len);

	resetArrData(arr, len);//重置
	foreachArr(arr, len);
	selectSort(arr, len);//排序
	foreachArr(arr, len);

	resetArrData(arr, len);//重置
	foreachArr(arr, len);
	insertionSort(arr, len);//排序
	foreachArr(arr, len);

	resetArrData(arr, len);//重置
	foreachArr(arr, len);
	quick_sort(arr, len);//排序
	foreachArr(arr, len);
}