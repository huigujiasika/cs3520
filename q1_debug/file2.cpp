// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with the last 4 digits


Example : If areacode = 617, exchange = 424
Output : 
"I am calling to tell you to buy a subscription to Dogs Monthly Magazine!"
617-424-0001
617-424-0002
617-424-0003
...
617-424-9998
617-424-9999
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments) at the end of file.

// %include<iostream>
#include<iostream>                 // compiler error: the correct include code is #include<iostream>
  
int main(){
   char digit1, digit2, digit3, digit4; 
    // string areaCode, exchange;
   std::string areaCode, exchange;     // compiler error: we need use std::string to declare the string type.
   std::cout<< "Hello, I am a telemarketing calling making program.\n";
   std::cout<< "Enter a three-digit area code "; 
   // std::cout<<areaCode;
   std::cin>>areaCode;                // logical error: we need input areaCode.
   std::cout<<"Enter a three-digit exchange to call "; 
   // std::cout<<exchange; 
   std::cin>>exchange;                // logical error: we need input exchange.
   std::cout<< "I am calling to tell you to buy a subscription to Dogs Monthly!\n";
   // for(digit1 = 0; digit1 <= 9; --digit1){ 
   for(digit1 = '0'; digit1 <='9'; ++digit1){                   // logical error: this loop should use ++digit1
        for(digit2 = '0'; digit2 <='9'; ++digit2){              // logical error: this loop should use ++digit2
            for(digit3 = '0'; digit3 <='9'; ++digit3) {         // logical error: this loop should use ++digit3
                for(digit4 = '0'; digit4 <='9'; ++digit4) {     // logical error: this loop should use ++digit4
                    // logical error: char '0'~'9' != int 0~9 , so we need to change number to char.
                    std::cout<< areaCode << "-" << exchange << "-" << digit1 << digit2 << digit3 << digit4 << std::endl;
                }
            }
        
        }
    }
    
   std::cout<< "\nCalls completed"<<std::endl; 
   return 0;
}


// most important logical fixes
// 1. [line 31] std::cout<<areaCode; -> std::cin>>areaCode; .
// 2. [line 34  ] std::cout<<exchange; -> std::cin>>exchange; .
// 3. [line 37:40] --dight[1~4] -> ++dight[1~4].
// 3. [line 37:40] 0 -> '0', 9 -> '9' .

// most important compiler fixes
// 1. [line 22] %include<iostream> -> #include<iostream>.
// 2. [line 27] string -> std::string.