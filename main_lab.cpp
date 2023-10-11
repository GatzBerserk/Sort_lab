#include <iostream>
using namespace std;


void simpleChoice(int* arr, int n)
{
	int permutations = 0;
	int comparisons = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int num_mem = 0;
		for (int j = i + 1; j < n; j++)
		{
			comparisons++;
			if (arr[num_mem] < arr[j])
				num_mem = j;
		}
		permutations++;
		int memory = arr[num_mem];
		arr[num_mem] = arr[n - 1 - i];
		arr[n - 1 - i] = memory;
	}
	cout << "permutations: " << permutations << "      " << "comparisons: " << comparisons;
}

void simpleExchange(int* arr, int n)
{
	int permutations = 0;
	int comparisons = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)

		{
			comparisons++;
			if (arr[j - 1] > arr[j])
			{
				permutations++;
				int memory = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = memory;
			}
		}
	}
	cout << "permutations: " << permutations << "      " << "comparisons: " << comparisons;
}
void simpleInsert(int* arr, int n)
{
	int permutations = 0;
	int comparisons = 0;
	int temp = 0;
	int num_mem = 0;
	for (int i = 1; i < n; i++)
	{
		comparisons++;
		num_mem = i;
		temp = arr[i];
		while (num_mem > 0 && temp < arr[num_mem - 1])
		{

			comparisons++;
			permutations++;
			arr[num_mem] = arr[num_mem - 1];
			num_mem--;
		}
		arr[num_mem] = temp;
	}
	cout << "permutations: " << permutations << "      " << "comparisons: " << comparisons;
}


void binarInsert(int* arr, int n)
{
	int comparisons = 0;
	int permutations = 0;
	int left = 1;
	int arr_mem, num_mem;
	for (int i = 1; i < n; i++)
	{
		arr_mem = arr[i];
		left = 1; 
		int right = i - 1;
		while (left <= right)
		{
			comparisons++;
			num_mem = (left + right) / 2;
			(arr_mem < arr[num_mem]) ? right = num_mem - 1 : left = num_mem + 1;
		}
		for (int j = i - 1; j >= left; j--)
		{
			comparisons++;
			permutations++; 
			arr[j + 1] = arr[j];
		}
		arr[left] = arr_mem;
	}
	cout << "permutations: " << permutations << "      " << "comparisons: " << comparisons;
}
void shayker(int* arr, int n)
{
	int comparisons = 0;
	int permutations = 0;
	int left = 1;
	int right = n - 1;
	int memory = n - 1;
	while (left <= right)
	{
		for (int j = right; j >= left; j--)
		{
			comparisons++;
			if (arr[j - 1] > arr[j])
			{
				permutations++;
				int stack = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = stack;
				memory = j;
			}
		}
		left = memory + 1;
		for (int j = left; j <= right; j++)
		{
			comparisons++;
			if (arr[j - 1] > arr[j])
			{
				permutations++;
				int x = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = x;
				memory = j;
			}
		}
		right = memory - 1;
	}
	cout << "permutations: " << permutations << "      " << "comparisons: " << comparisons;
}
void QuickSort(int* arr, int left, int right, int& permutation, int& comparisons)
{
	int left_func, rigth_func, mid_arr;
	left_func = left;
	rigth_func = right;
	mid_arr = arr[(left_func + rigth_func) / 2];
	do
	{
		while (arr[left_func] < mid_arr)
		{
			comparisons++;
			left_func++;
		}
		while (arr[rigth_func] > mid_arr)
		{
			comparisons++;
			rigth_func--;
		}
		if (left_func <= rigth_func)
		{
			permutation++;
			int memory = arr[left_func];
			arr[left_func] = arr[rigth_func];
			arr[rigth_func] = memory;
			left_func++;
			rigth_func--;
		}
	} while (left_func <= rigth_func);
	if (rigth_func > left)
		QuickSort(arr, left, rigth_func, permutation, comparisons);
	if (left_func < right)
		QuickSort(arr, left_func, right, permutation, comparisons);
}

void shellSort(int arr[], int n) 
{
	int comparisons = 0;
	int permutations = 0;
	for (int j = n / 2; j > 0; j /= 2)
	{
		for (int i = j; i < n; i += 1)
		{
			int temp = arr[i];
			int num_mem;
			comparisons++;
			for (num_mem = i; num_mem >= j && arr[num_mem - j] > temp;num_mem -= j)
			{
				comparisons++;
				arr[num_mem] = arr[num_mem - j];
				permutations++;
			}
			arr[j] = temp;
		}
	}
	cout << "permutations: " << permutations << "      " << "comparisons: " << comparisons;
}
void heapify(int arr[], int n, int last, int& comparisons,int& permutations) //convert to tree in heapSort
{
	int largest = last;
	int left = 2 * last + 1; 
	int right = 2 * last + 2; 
	if (left < n && arr[left] > arr[largest])
	{
		comparisons++;
		largest = right;
	}
	if (largest != last)
	{
		permutations++;
		comparisons++;
		swap(arr[last], arr[largest]);
		heapify(arr, n, largest, comparisons, permutations);
	}
}

void heapSort(int arr[], int n)
{
	int comparisons = 0;
	int permutations = 0;
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i, comparisons, permutations);
	for (int i = n - 1; i >= 0; i--)
	{
		permutations++;
		swap(arr[0], arr[i]);
		heapify(arr, i, 0, comparisons, permutations);
	}
	cout << "permutations: " << permutations << "      " << "comparisons: " << comparisons;
}



void main()
{
	int comparisons = 0;
	int permutations = 0;
	int n = 200;
	int arrayO_TwoH[200]{};
	int arrayTwoH_O[200];
	int arrayRand[200];
	for (int i = 0; i < 200; i++)
	{
		int a = rand() % 199;
		arrayRand[a] = i;
		arrayRand[i] = a;
	}

	for (int i = 0; i < 200; i++)
	{
		arrayO_TwoH[i] = i;
		arrayTwoH_O[199 - i] = i;
	}
	cout << "Simple Choise" << endl;
	cout << "Simple coise" << endl;
	cout << "Array 0 - 199" << endl;
	simpleChoice(arrayO_TwoH, n);
	cout << endl;
	cout << "Array 199 - 0" << endl;
	simpleChoice(arrayTwoH_O, n);
	cout << endl;
	cout << "Array Random" << endl;
	simpleChoice(arrayRand, n);
	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;
	for (int i = 0; i < 200; i++)
	{
		int a = rand() % 199;
		arrayRand[a] = i;
		arrayRand[i] = a;
	}

	for (int i = 0; i < 200; i++)
	{
		arrayO_TwoH[i] = i;
		arrayTwoH_O[199 - i] = i;
	}
	cout << "Simple Exchange" << endl;
	cout << "Array 0 - 199" << endl;
	simpleExchange(arrayO_TwoH, n);
	cout << endl;
	cout << "Array 199 - 0" << endl;
	simpleExchange(arrayTwoH_O, n);
	cout << endl;
	cout << "Array Random" << endl;
	simpleExchange(arrayRand, n);
	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;
	for (int i = 0; i < 200; i++)
	{
		int a = rand() % 199;
		arrayRand[a] = i;
		arrayRand[i] = a;
	}

	for (int i = 0; i < 200; i++)
	{
		arrayO_TwoH[i] = i;
		arrayTwoH_O[199 - i] = i;
	}
	cout << "Simple Insert";
	cout << "Array 0 - 199" << endl;
	simpleInsert(arrayO_TwoH, n);
	cout << endl;
	cout << "Array 199 - 0" << endl;
	simpleInsert(arrayTwoH_O, n);
	cout << endl;
	cout << "Array Random" << endl;
	simpleInsert(arrayRand, n);
	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;
	for (int i = 0; i < 200; i++)
	{
		int a = rand() % 199;
		arrayRand[a] = i;
		arrayRand[i] = a;
	}

	for (int i = 0; i < 200; i++)
	{
		arrayO_TwoH[i] = i;
		arrayTwoH_O[199 - i] = i;
	}
	cout << "Binar Insert" << endl;
	cout << "Array 0 - 199" << endl;
	binarInsert(arrayO_TwoH, n);
	cout << endl;
	cout << "Array 199 - 0" << endl;
	binarInsert(arrayTwoH_O, n);
	cout << endl;
	cout << "Array Random" << endl;
	binarInsert(arrayRand, n);
	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;
	for (int i = 0; i < 200; i++)
	{
		int a = rand() % 199;
		arrayRand[a] = i;
		arrayRand[i] = a;
	}

	for (int i = 0; i < 200; i++)
	{
		arrayO_TwoH[i] = i;
		arrayTwoH_O[199 - i] = i;
	}
	cout << "Shake" << endl;
	cout << "Array 0 - 199" << endl;
	shayker(arrayO_TwoH, n);
	cout << endl;
	cout << "Array 199 - 0" << endl;
	shayker(arrayTwoH_O, n);
	cout << endl;
	cout << "Array Random" << endl;
	shayker(arrayRand, n);
	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;
	for (int i = 0; i < 200; i++)
	{
		int a = rand() % 199;
		arrayRand[a] = i;
		arrayRand[i] = a;
	}

	for (int i = 0; i < 200; i++)
	{
		arrayO_TwoH[i] = i;
		arrayTwoH_O[199 - i] = i;
	}
	cout << "Qiuck Sort" << endl;
	QuickSort(arrayO_TwoH, 0, 199, permutations, comparisons);
	cout << "Array 0 - 199" << endl;
	cout << "permutations: " << permutations << "      " << "comparisons: " << comparisons;
	permutations = 0;
	comparisons = 0;
	cout << endl;
	QuickSort(arrayTwoH_O, 0, 199, permutations, comparisons);
	cout << "Array 199 - 0" << endl;
	cout << "permutations: " << permutations << "      " << "comparisons: " << comparisons;
	permutations = 0;
	comparisons = 0;
	cout << endl;
	QuickSort(arrayRand, 0, 199, permutations, comparisons);
	cout << "Array Random" << endl;
	cout << "permutations: " << permutations << "      " << "comparisons: " << comparisons;
	permutations = 0;
	comparisons = 0;
	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;
	for (int i = 0; i < 200; i++)
	{
		int a = rand() % 199;
		arrayRand[a] = i;
		arrayRand[i] = a;
	}

	for (int i = 0; i < 200; i++)
	{
		arrayO_TwoH[i] = i;
		arrayTwoH_O[199 - i] = i;
	}
	cout << "Shell Sort" << endl;
	cout << "Array 0 - 199" << endl;
	shellSort(arrayO_TwoH, n);
	cout << endl;
	cout << "Array 199 - 0" << endl;
	shellSort(arrayTwoH_O, n);
	cout << endl;
	cout << "Array Random" << endl;
	shellSort(arrayRand, n);
	cout << endl;
	cout << "---------------------------------------" << endl;
	for (int i = 0; i < 200; i++)
	{
		int a = rand() % 199;
		arrayRand[a] = i;
		arrayRand[i] = a;
	}

	for (int i = 0; i < 200; i++)
	{
		arrayO_TwoH[i] = i;
		arrayTwoH_O[199 - i] = i;
	}
	cout << "heapSort" << endl;
	cout << "Array 0 - 199" << endl;
	heapSort(arrayO_TwoH, n-1);
	cout << endl;
	cout << "Array 199 - 0" << endl;
	heapSort(arrayTwoH_O, n-1);
	cout << endl;
	cout << "Array Random" << endl;
	heapSort(arrayRand, n-1);
	cout << endl;
	cout << "---------------------------------------" << endl;

}