/*请设计实现一个重载函数运算符的类，使用该类的对象可以完成对整数数组从大到小排序。
示例：设该类对象名为obj，整数数组名为array，元素个数为N，则obj(array, N); 
将修改array的内容，使其中的元素从大到小排序。*/

#include <iostream>

class Sort {
  public:
    // 函数重载
    void operator() (int array[], int N) {
      // 整数数组从大到小排序
      QuickSort(array, 0, N-1);
    }
    
    // 快速排序
    void QuickSort(int array[], int low, int high) {
      if (low < high) {
        int pivot = Partition(array, low, high);
        QuickSort(array, low, pivot-1);
        QuickSort(array, pivot+1, high);
      }
    }

    int Partition(int array[], int low, int high) {
      int temp = array[low];
      while(low < high) {
        while(low < high && temp > array[high]) {
          --high;
        }
        array[low] = array[high];
        while(low < high && temp < array[low]) {
          ++low;
        }
        array[high] = array[low];  
      }
      array[low] = temp;
      return low;
    }
};

int main() {
  // 测试
  const int N = 5;
  int a[N] = {7,4,3,5,0};

  Sort test;
  test(a, N);

  for (int i = 0; i < N; i++) {
    std::cout << a[i] << ", ";
  }
}