#include <stdio.h>

int main() {
    // Write C code here
    int button;
    
    scanf("%d", &button);
    
    switch (button){
        case 1:printf("play game"); 
        break;
        
        case 2:printf("load game"); 
        break;
        
        case 3:printf("shop"); 
        break;
        
        case 4:printf("settings"); 
        break;
        
        case 5:printf("exit game"); 
        break;
        
        default: printf("please press a button");
        break;
    }
    
    
}
