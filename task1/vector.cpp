#include<iostream>
#include<limits.h>

typedef enum {LEFT,RIGHT} direction;

class vector
{
private:
    int * ptr;
    int size;
    int capacity;

    void reallocArray();
    void rotateLeftOneElement();
    void rotateRightOneElement();
public:
    vector(int cap);

    void display();

    void add(int element);

    void insert(int ele,int index);

    void deleteIndex(int index);

    int search(int ele);

    void set(int ele , int index);

    int get(int index);

    void maxAndMin();

    int sum();

    float average();

    void reverse();

    void merge(vector& v);

    void rotate(int numOfIterations , direction d);

    ~vector();
};

vector::vector(int cap)
{   
    this->ptr = new int[cap];
    this->size = 0;
    this->capacity = cap;
}

void vector::display(){
    if(this->size == 0){
        std::cout<<"The array is empty";
        return;
    }

    std::cout << "ELements in the array:";
    for(int i=0;i< this->size;i++){
        std::cout << ptr[i]<<" ";
    }
    std::cout<<"\n";
}

void vector::reallocArray(){
    int new_capacity = 2 * this->capacity;
    int *arr = new int[new_capacity];
    if(arr == NULL) std::cout<<"there is no memory.\n";
    for(int i = 0;i < this->size ; i++){
        arr[i] = this->ptr[i];
    }
    
    int* temp = this->ptr;
    delete[] temp;
    this->ptr = arr;
    this->capacity = new_capacity;
}

void vector::add(int element){
    if(this->size == this->capacity){
        reallocArray();
    }

    ptr[this->size] = element;
    size++;
}

void vector::insert(int ele,int index){
    if(this->size == this->capacity){
        reallocArray();
    }

    int i = this->size - 1;
    while(i >= index){
        ptr[i + 1] = ptr[i];
        i--;
    }

    ptr[index] = ele;
    this->size++;
}

void vector::deleteIndex(int index){
    if(this->size == 0){
        std::cout<<"The array is empty";
        return;
    }

    if(index < 0 || index >= this->size){
        std::cout<<"wrong index.\n";
        return;
    }

    int i = index;
    while(i < this->size-1){
        ptr[i] = ptr[i+1];
        i++;
    }

    this->size--;
}

int vector::search(int ele){
    if(this->size == 0){
        std::cout<<"The array is empty";
        return -1;
    }

    int i=0;
    bool flag = false;
    for(;i<this->size;i++){
        if(ptr[i] == ele){
            flag = true;
            break;
        }
    }

    if(flag) std::cout<<"the element is at index :"<<i<<"\n";
    else std::cout<<"element not found";
    return i;
}

void vector::set(int ele , int index){
    if(index < 0 || index >= this->size){
        std::cout<<"please enter a valid index";
        return;
    }

    ptr[index] = ele;
}

int vector::get(int index){
    if(this->size == 0){
        std::cout<<"The array is empty";
        return -1;
    }

    if(index < 0 || index >= this->size) std::cout<<"please enter a valid index";

    return ptr[index];
}

void vector::maxAndMin(){
    if(this->size == 0){
        std::cout<<"The array is empty";
        return;
    }

    int max = INT_MIN;
    int min = INT_MAX;
    for(int i=0; i<this->size;i++){
        if(ptr[i] > max) max = ptr[i];
        if(ptr[i] < min) min = ptr[i];
    }

    std::cout<<"The max value is:"<<max <<"\n" <<"The min Value is:"<< min <<"\n";
}

int vector::sum(){
    if(this->size == 0){
        std::cout<<"The array is empty";
        return -1;
    }

    int sum = 0;
    for(int i=0;i<this->size;i++){
        sum += ptr[i];
    }

    std::cout<<"The sum of the elements is:" <<sum<<"\n";
    return sum;
}

float vector::average(){
    if(this->size == 0){
        std::cout<<"The array is empty";
        return -1;
    }

    return ((float)sum())/this->size;
}

void vector::reverse(){
    int temp;
    for(int i=0 ;i<this->size/2;i++){
        temp = ptr[i];
        ptr[i] = ptr[this->size-1-i];
        ptr[this->size-1-i] = temp;
    }
}

void vector::merge(vector& v){
    if(this->size == 0){
        std::cout<<"The array is empty";
        return;
    }

    while(this->capacity < this->size + v.size){
        reallocArray();
    }

    int i = this->size;
    int j=0;
    while(i < this->size + v.size){
        ptr[i] = v.ptr[j];
        i++;
        j++;
    }

    this->size = this->size + v.size;
}

void vector::rotateLeftOneElement(){
    if(this->size == 0){
        std::cout<<"The array is empty";
        return;
    }

    int temp = this->ptr[0];
    for(int i=0;i<this->size-1;i++){
        this->ptr[i] = this->ptr[i+1];
    }

    this->ptr[this->size - 1] = temp;
}

void vector::rotateRightOneElement(){
    if(this->size == 0){
        std::cout<<"The array is empty";
        return;
    }

    int temp = this->ptr[this->size - 1];
    for(int i=size-1;i>0;i--){
        this->ptr[i] = this->ptr[i-1];
    }

    this->ptr[0] = temp;
}

void vector::rotate(int numOfIterations , direction d){
    if(this->size == 0){
        std::cout<<"The array is empty";
        return;
    }

    if(d == LEFT){
        for(int i=0;i<numOfIterations;i++){
            rotateLeftOneElement();
        }
    }else{
        for(int i=0;i<numOfIterations;i++){
            rotateRightOneElement();
        }
    }
}

vector::~vector()
{
    delete[] ptr;
}


int main(){
    vector v{5};

    v.add(10);
    v.add(20);
    v.add(30);

    v.display();
    
    v.add(3);
    v.add(5);

    v.display();
    v.add(100);
    v.add(50);

    v.display();

    v.insert(1,3);

    v.display();

    v.deleteIndex(2);

    v.display();

    v.maxAndMin();

    v.reverse();
    v.display();

    v.rotate(2,LEFT);
    v.display();

    vector vnew{2};
    vnew.add(1000);
    vnew.add(2000);
    vnew.display();
    
    v.merge(vnew); 
    v.display();

}