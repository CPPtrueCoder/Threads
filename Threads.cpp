#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int Sum(int a, int b);

int main() {
  int result;
  thread t ([&result] () { result = Sum(2, 5); });

cout << "Hello World!" << endl;
for (size_t i = 0; i < 10; ++i) {
  cout << "ID of thread = " << this_thread::get_id() << "\tmain works" << i
       << endl;
  this_thread::sleep_for(chrono ::milliseconds(500));
}
t.join();
cout<< "Sum Result =  " <<result << endl;
return 0;
}

int Sum(int a, int b) {

  this_thread::sleep_for(chrono::milliseconds(2000));
  cout << "ID of thread " << this_thread::get_id()
       << " ========\tDowork STARTED\t========";

  this_thread::sleep_for(chrono::milliseconds(5000));

  cout << "ID of thread " << this_thread::get_id()
       << "========\tDowork STOOPWS\t========"<<endl;
  return a + b;
}
