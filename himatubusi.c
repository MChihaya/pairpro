#include <stdio.h>
#include <string.h>
int roman2num(char*);
int main() {
    printf("XIV = %d\n", roman2num("XIV"));
    printf("CDXCV = %d\n", roman2num("CDXCV"));
    printf("MCMXLV = %d\n", roman2num("MCMXLV"));
    printf("MMMCMXCIX = %d\n", roman2num("MMMCMXCIX"));
    return 0;
}
int roman2num(char *s) {
    int result = 0;
    int l = strlen(s);
    for(int a = 0; a < l; a++){
        if(*(s+a) == 'M'){
            result =result + 1000;
        }else if (*(s+a) == 'D') {
            result = result + 500;
        }else if (*(s+a) == 'L') {
            result = result + 50;
        }else if (*(s+a) == 'V') {
            result = result + 5;
        }else if (*(s+a) == 'C') {
            if(a != l -1 && (*(s+a+1) == 'D'||*(s+a+1) == 'M')){
                result = result - 100;
            }else{
                result = result + 100;
            }
        }else if (*(s+a) == 'X') {
            if(a != l -1 && (*(s+a+1) == 'L'||*(s+a+1) == 'C')){
                result = result - 10;
            }else{
                result = result + 10;
            }
        }else if (*(s+a) == 'I') {
            if(a != l -1 && (*(s+a+1) == 'V'||*(s+a+1) == 'X')){
                result = result - 1;
            }else{
                result = result + 1;
            }
        }
    }
    return result;
}