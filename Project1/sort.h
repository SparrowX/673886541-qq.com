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
        srand(time(NULL)); // �������
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    };
    //��������
    Sort(const vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
    }
    void print() {
        for (int num : nums) cout << num << endl;
    }
    void InsertSort() {
        //ÿ��ѡ��һ��δ����Ԫ�أ����뵽ǰ��λ��
        //���������Ԫ�شӺ���ǰ������δ������Ԫ���ҵ����ʵ�λ��
        for (int i = 1; i < n; i++) {
            int tmp = nums[i];
            int j = i - 1;
            while (j >= 0 && tmp < nums[j]) {
                //tmpӦ�ò���nums[j]����
                //Ԫ�غ��ƣ��ڳ�λ��
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = tmp;
        }
    }
    //�Ż�1�����ֲ��ţ���С�ȽϵĴ���
    //ϣ������
    void ShellSort() {
        for (int dk = n / 2; dk >= 1; dk = dk / 2) {
            //����ļ��
            for (int i = dk; i < n; ++i) {
                //������㣬��ǰ������
                if (nums[i] < nums[i - dk]) {
                    //ÿ��������dk�������Ҫ��ǰ����
                    int tmp = nums[i], j;
                    for (j = i - dk; j >= 0 && tmp < nums[j]; j -= dk) {
                        //���Ϻ���
                        nums[j + dk] = nums[j];
                    }
                    nums[j + dk] = tmp;
                }
            }
        }
    }
    //ð��
    void BubbleSort() {
        for (int i = 0; i < n - 1; i++) {
            //����ð��
            //i��ʾ�½�
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
    //����
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
    //��ѡ��
    void SelectSort() {
        for (int i = 0; i < n - 1; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[min]) min = j;
            }
            if (min != i) swap(nums[i], nums[min]);
        }
    }
    //������
    void adjust(int len, int index) {
        int left = 2 * index + 1; // index�����ӽڵ�
        int right = 2 * index + 2;// index�����ӽڵ�

        int maxIdx = index;
        if (left<len && nums[left] > nums[maxIdx])     maxIdx = left;
        if (right<len && nums[right] > nums[maxIdx])     maxIdx = right;

        if (maxIdx != index)
        {
            swap(nums[maxIdx], nums[index]);
            adjust(len, maxIdx);
        }

    }
    // ������
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