#include "List.h"
#include <iostream>
using namespace std;

using IntList = List<int>;

void printList(const IntList& list) {
    for (const auto& item : list) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main(){
    int n=4,m=2;
    //测试默认构造函数和init
    IntList list1;
    //测试push_back,包含begin,end
    list1.push_back(1);
    list1.push_back(m);
    std::cout<<"应该输出1 2 "<<std::endl;
    printList(list1);


    //测试push_front;
    list1.push_front(n);
    list1.push_front(3);
    std::cout<<"应该输出3 4 1 2 "<<std::endl;
    printList(list1);

    //测试拷贝构造函数
    IntList list3(list1);
    std::cout<<"应该输出3 4 1 2 "<<std::endl;
    printList(list3);
    //测试构造函数
    std::initializer_list<int> list4 = {1, 2, 3, 4, 5};
    std::cout<<"应该输出1 2 3 4 5"<<std::endl;
    printList(list4);




    //测试pop_front和pop_back
    list1.pop_front();
    std::cout<<"应该输出4 1 2 "<<std::endl;
    printList(list1);
    list1.pop_back();
    std::cout<<"应该输出4 1 "<<std::endl;
    printList(list1);

    //测试front和back
    list1.front() = 5;
    if(list1.front() == 5){
        std::cout<<"front函数正确"<<std::endl;
    }else{
        std::cout<<"front函数错误"<<std::endl;
    }
    list1.back() = 2;
    if(list1.back() == 2){
        std::cout<<"back函数正确"<<std::endl;
    }else{
        std::cout<<"back函数错误"<<std::endl;
    }

    

    //测试赋值运算符
    IntList list2=list1;
    std::cout<<"应该输出5 2 "<<std::endl;
    printList(list2);

    //测试const迭代器的递增和递减，包含retrieve
    IntList::const_iterator it1 = list3.begin();
    ++it1;
    if(*it1 == 4){
        std::cout<<"前自增正确"<<std::endl;
    }else{
        std::cout<<"前自增错误"<<std::endl;
    }
    
    if(*(it1++) == 4){
        std::cout<<"后自增正确"<<std::endl;
    }else{
        std::cout<<"后自增错误"<<std::endl;
    }
    --it1;
    if(*it1 == 4){
        std::cout<<"前自减正确"<<std::endl;
    }else{
        std::cout<<"前自减错误"<<std::endl;
    }
    if(*(it1--) == 4){
        std::cout<<"后自减正确"<<std::endl;
    }else{
        std::cout<<"后自减错误"<<std::endl;
    }

    //测试无const的迭代器操作
    IntList::iterator it4 = list3.begin();
    *(++it4)=6;
    std::cout<<"应该输出3 6 1 2 "<<std::endl;
    printList(list3);
    *(it4++)=7;
    std::cout<<"应该输出3 7 1 2 "<<std::endl;
    printList(list3);
    *(it4--)=8;
    std::cout<<"应该输出3 7 8 2 "<<std::endl;
    printList(list3);
    *(--it4)=9;
    std::cout<<"应该输出9 7 8 2 "<<std::endl;
    printList(list3);


    //测试判断两个迭代器是否相等,静态的迭代器操作
    IntList::const_iterator it3 = list3.end();
    IntList::const_iterator it2 = list3.end();
    if(it3==it2){
        std::cout<<"==正确"<<std::endl;
    }else{
        std::cout<<"==错误"<<std::endl;
    }
    if(it3!=it2){
        std::cout<<"!=错误"<<std::endl;
    }else{
        std::cout<<"!=正确"<<std::endl;
    }


    //测试insert和erase
    int a=7;
    list2.insert(list2.begin(), 5);
    std::cout<<"应该输出5 5 2"<<std::endl;
    printList(list2);
    list2.insert(list2.begin(), a);
    std::cout<<"应该输出7 5 5 2"<<std::endl;
    printList(list2);
    list2.erase(list2.begin(),list2.end());
    std::cout<<"应该为空链表"<<std::endl;
    printList(list2);

}
