## 移动构造函数语义
```c++
void copyArray(const MyIntArray &src)
{
    MyIntArray arr(src); // copies the array
    // use arr as needed...
}

void moveArray(MyIntArray &&src)
{
    MyIntArray arr(std::move(src)); // moved the array
    // use arr as needed...
}

MyIntArray arr1(5);                // creates a new array
MyIntArray arr2(arr1);             // copies the array
MyIntArray arr3(std::move(arr2));  // moves the array
MyIntArray arr4;                   // default construction
arr4 = arr3;                       // copies the array
arr4 = std::move(arr3);            // moves the array
arr4 = MyIntArray(1);              // creates a new array and moves it

copyArray(arr4);                   // copies the array
moveArray(std::move(arr4));        // moves the array

copyArray(MyIntArray(10));         // creates a new array and copies it
moveArray(MyIntArray(10));         // creates a new array and moves it
```
