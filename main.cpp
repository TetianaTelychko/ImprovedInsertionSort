#include <iostream>

template <typename T>
void fillArray(T array[], int length){
    for(int i = 0; i < length; ++i){
        array[i] = (T)(rand() % 600 / 10.0 + 65);
    }
}

template <typename T>
void printArray(const T array[], int length, int number){
    std::cout << "Масив №" << number << " : ";
    for(int i = 0; i < length; ++i){
        std::cout << "  " << array[i];
    }
    std::cout << "\n";
}

template <typename T>
void reverse(T *array, int length){
    for(int first = 0, last = length - 1; first < last; ++first, --last){
        T tmp = array[first];
        array[first] = array[last];
        array[last] = tmp;
    }
}

template <typename T>
void sorting(T *array, int length, int type){
    T backup = array[0];
    T min = backup;
    bool change = false;
    for(int i = 1; i < length; ++i){
        if(min > array[i]){
            min = array[i];
            array[0] = min;
            change = true;
        }
    }

    for(int i = 1; i < length; ++i){
        T tmp = array[i];
        int indexCompare = i - 1;
        while(array[indexCompare] > tmp){
            array[indexCompare + 1] = array[indexCompare];
            array[indexCompare] = tmp;
            --indexCompare;
        }
    }

    if(change){
        int i = 0;
        array[i] = backup;
        for( ; (array[i] > array[i + 1]) && (i <= (length - 2)); ++i){
            array[i] = array[i + 1];
            array[i + 1] = backup;
        }
    }

    if(type == 1){
        reverse(array, length);
    }
}


int main(){
    srand(static_cast<unsigned int>(time(nullptr)));

    const int length = 10;
    int array[length] = {};
    fillArray(array, length);
    char array2[length] = {};
    fillArray(array2, length);
    double array3[length] = {};
    fillArray(array3, length);

    printArray(array, length, 1);
    printArray(array2, length, 2);
    printArray(array3, length, 3);

    std::cout << "Виберіть метод сортування масивів (0 - зростання, 1-спад) : ";
    int type;
    std::cin >> type;

    if(type == 0 || type == 1){
        std::cout << "Сортування масивів за допомогою алгоритму \"Покращене сортування вставками\".\n";
        sorting(array, length, type);
        printArray(array, length, 1);
        sorting(array2, length, type);
        printArray(array2, length, 2);
        sorting(array3, length, type);
        printArray(array3, length, 3);
    }
    else{
        std::cout << "Немає такого варіанта !";
    }

    return 0;
}