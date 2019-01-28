#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork (int &a);

int main()
{
  int q = 5 ;

  thread t  (DoWork, ref(q));
cout << "Hello World!" << endl;
for (size_t i = 0 ; i<10; ++i)
{
  cout<< "ID of thread = "<<this_thread::get_id()<<"\tmain works"<<i<<endl;
  this_thread::sleep_for(chrono ::milliseconds (500));
}

cout<< q<<endl;
t.join();
return 0;
}

void DoWork (int &a){

  this_thread::sleep_for(chrono::milliseconds (2000));
  cout<< "ID of thread " << this_thread::get_id()<<"========\tDowork STARTED\t========";

  this_thread::sleep_for(chrono::milliseconds(1000));
  a*=2;
  cout<< "ID of thread " << this_thread::get_id()<<"========\tDowork STOOPWS\t========";
}
