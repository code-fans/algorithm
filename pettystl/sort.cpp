#include <iostream>
#include <iomanip>

namespace pettystl {
    // 显示数组
    template<typename T> void displayArray(T data[], int len)
    {
        for (int i = 0; i < len; i++)
            std::cout << std::setw(6) << data[i];
        std::cout << std::endl;
    }

    //交换数组元素
    template<typename T> void swapData(T data[], int pos1, int pos2)
    {
        if (pos1 != pos2){
            T temp = data[pos1];
            data[pos1] = data[pos2];
            data[pos2] = temp;
        }
    }

    // 选择排序
    template<typename T>  void selectSort(T data[], int len, bool ascending)
    {
        int min, m;
        for(int i=0; i<len-1; i++){
            min=i;
            for(int s=i+1; s<len; s++){
                if (data[min] > data[s] == ascending)
                    min=s;
            }
            swapData(data, min, i);
        }
    }

    // 冒泡排序
    template<typename T> void bubbleSort(T data[], int len, bool ascending)
    {
        for(int i=0; i<len-1; i++) {
            //定义一个检查变量
            bool hasSorted = true;
            //减少没有必要的循环
            for(int k=0; k<len-1-i; k++) { 
                if (data[k] > data[k+1] == ascending) {
                    swapData(data, k, k+1);
                    hasSorted = false;
                }
            }
            // 如果已经排序好了，直接跳出最外层循环
            if(hasSorted)
                break;
        }
    }

    // 插入排序
    template<typename T> void insertSort(T data[], int len ,bool ascending){
        int j;
        T b;
        for (int i=1; i<len; i++){
            j = i;
            b = data[j];
            while (j>0 && b < data[j-1] == ascending) {
                data[j] = data[j-1];
                j--;
            }
            data[j] = b;
        }
    }

}