#pragma once
#include<vector>
#include<iostream>
#include<cassert>
#include<ctime>
using namespace std;

class Sort{
private:
    vector<int> nums;
    int n;
public:

    vector<int> getRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        vector<int> arr(n);
        srand(time(NULL)); // 随机种子
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    };
    //插入排序
    Sort(const vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
    }
    void print() {
        for (int num : nums) cout << num << endl;
    }
    void InsertSort() {
        //每次选择一个未排序元素，插入到前面位置
        //将已排序的元素从后向前遍历，未待排序元素找到合适的位置
        for (int i = 1; i < n; i++) {
            int tmp = nums[i];
            int j = i - 1;
            while (j >= 0 && tmp < nums[j]) {
                //tmp应该插在nums[j]后面
                //元素后移，腾出位置
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = tmp;
        }
    }
    //优化1，二分插排，减小比较的次数
    //希尔排序
    void ShellSort() {
        for (int dk = n / 2; dk >= 1; dk = dk / 2) {
            //排序的间隔
            for (int i = dk; i < n; ++i) {
                //排序起点，从前向后遍历
                if (nums[i] < nums[i - dk]) {
                    //每次排序间隔dk，如果需要向前交换
                    int tmp = nums[i], j;
                    for (j = i - dk; j >= 0 && tmp < nums[j]; j -= dk) {
                        //不断后移
                        nums[j + dk] = nums[j];
                    }
                    nums[j + dk] = tmp;
                }
            }
        }
    }
    //冒泡
    void BubbleSort() {
        for (int i = 0; i < n - 1; i++) {
            //向下冒泡
            //i表示下界
            bool flag = false;
            for (int j = n - 1; j > i; j--) {
                if (nums[j - 1] > nums[j]) {
                    swap(nums[j - 1], nums[j]);
                    flag = true;
                }
            }
            if (flag == false) {
                return;
            }
        }
    }
    //快排
    void QuickSort() {
        int low = 0;
        int high = n - 1;
        q_sort(low, high);
    }
    void q_sort(int low, int high) {
        if (low < high) {
            int pivotpos = partition(low, high);
            q_sort(low, pivotpos - 1);
            q_sort(pivotpos + 1, high);
        }
    }
    int partition(int low, int high) {
        int pivot = nums[low];
        while (low < high) {
            while (low < high && nums[high] >= pivot)--high;
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot) ++low;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;

    }
    //简单选择
    void SelectSort() {
        for (int i = 0; i < n - 1; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[min]) min = j;
            }
            if (min != i) swap(nums[i], nums[min]);
        }
    }
    //堆排序
    void adjust(int len, int index) {
        int left = 2 * index + 1; // index的左子节点
        int right = 2 * index + 2;// index的右子节点

        int maxIdx = index;
        if (left<len && nums[left] > nums[maxIdx])     maxIdx = left;
        if (right<len && nums[right] > nums[maxIdx])     maxIdx = right;

        if (maxIdx != index)
        {
            swap(nums[maxIdx], nums[index]);
            adjust(len, maxIdx);
        }

    }
    // 堆排序
    void HeapSort() {
        int size = n;
        for (int i = size / 2 - 1; i >= 0; i--) {
            adjust(size, i);
        }
        for (int i = size - 1; i >= 1; i--) {
            swap(nums[0], nums[i]);
            adjust(i, 0);
        }
    }
};