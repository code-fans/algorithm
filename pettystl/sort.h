

namespace pettystl {
    // 显示数组
    template<typename T> void displayArray(T data[], int len);

    // 选择排序
    template<typename T>  void selectSort(T data[], int len, bool ascending = true);

    // 冒泡排序
    template<typename T> void bubbleSort(T data[], int len, bool ascending = true);

    // 插入排序
    template<typename T> void insertSort(T data[], int len ,bool ascending = true);

}