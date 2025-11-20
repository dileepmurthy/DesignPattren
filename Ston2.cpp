/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
class SingleTon{
    private:
            SingleTon(){
                cout<<"SingleTon instance created"<<endl;
            }
            SingleTon(const SingleTon&)= delete;
            SingleTon& operator=(SingleTon&)= delete;
    public:
        static SingleTon* getInstance(){
            static SingleTon* instance;
            if(instance==nullptr)
                instance= new SingleTon();
            return instance;
            
        }
        void showMessage() const{
            cout<<"SingleTon instance calling"<<endl;
        }
            
};


int main()
{
    SingleTon *s1= SingleTon::getInstance();
    s1->showMessage();
    SingleTon *s2= SingleTon::getInstance();
     s2->showMessage();
    if(s1==s2)
        cout<<"Both the objects are pointing to same class instance"<<endl;
    

    return 0;
}
