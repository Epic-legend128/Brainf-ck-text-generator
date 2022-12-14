#include <iostream>
#include <cmath>
using namespace std;

//effective method to turn text into brainfuck code but it is however a bit more complicated than the method that convert2 uses
string convert1(string text) {
    string result = ">";
    for (int j = 0; j<text.length(); j++) {
        int amountOfLoops = floor(sqrt((int)text[j]));
        int inLoopPlus;
        bool found = false;
        int extra = 0;
        while (!found) {
            for (int i = amountOfLoops; i>1; i--) {
                if (((int)text[j]-extra)%i == 0) {
                    amountOfLoops = i;
                    inLoopPlus = ((int)text[j]-extra)/i;
                    found = true;
                    break;
                }
            }
            if (!found) extra++;
        }
        for (int i = 0; i<extra; i++) {
            result+="+";
        }
        result+=">";
        for (int i = 0; i<amountOfLoops; i++) {
            result+="+";
        }
        result+="[<";
        for (int i = 0; i<inLoopPlus; i++) {
            result+="+";
        }
        result+=">-]<.>";
    }
    return result;
}

//simple method but produces long pieces of brainfuck code
string convert2(string text) {
    string result = "";
    for (int i = 0; i<text.length(); i++) {
        result+="";
        for (int j = 0; j<(int)text[i]; j++) {
            result+="+";
        }
        result+=".>";
    }
    return result;
}

int main() {
    string text = "";
    cout << "Enter the text you want to turn into brainfuck language(include text only consisting of ascii characters)\n";
    getline(cin, text); //text to be converted to brainf*ck language
    cout << "The text "+text+" can be converted in brainf*ck language in 2 different ways, with the first method you get:\n"+convert1(text)+"\n and with the second method you get:\n"+convert2(text)<< endl;
    return 0;
}
