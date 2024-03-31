#include <iostream> 
#include <string>
  

std::string addBigInt(std::string num1, std::string num2 ) {

std::string zeros = ""; 
int res[1000] = {0};  
int carry = 0; 

int len1 = num1.size(); 
int len2 = num2.size(); 

int size_diff = len1 - len2; 

if(size_diff < 0) 
size_diff *= -1; 
for(int i = 0; i < size_diff; i++) 
zeros += "0"; 
if(len1 < len2) 
num1 = zeros + num1;
else if(len1 > len2) 
num2 = zeros + num2; 

int n1, n2; 

for(int i = num1.size() -1; i >= 0; i--) {

n1 = num1[i] - '0'; 
n2 = num2[i] - '0'; 

int sum = n1 + n2 + carry; 
res[i+1] = sum % 10; 
carry = sum / 10; 


}

if(carry != 0) 
res[0] = carry; 

std::string result = ""; 

for(int i = 0; i < len1 + 1; i++) 
result += std::to_string(res[i]); 


return result; 

}