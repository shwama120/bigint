#include <iostream> 
#include <string> 
using namespace std; 

string addBigInt(string num1, string num2 );
std::string subtractBigInt(std::string num1, std::string num2); 

using namespace std; 

int main() {

    string num1, num2; 


    cout << "First number >> ";
    cin >> num1; 
    cout << "Second number >> "; 
    cin >> num2;

   cout << "Sum >> " << addBigInt(num1, num2) << endl; 
   cout << "Sub >> " << subtractBigInt(num1, num2); 








    return 0; 
}