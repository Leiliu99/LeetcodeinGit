#include <iostream>
using namespace std;
int main() {
    int numberOfCase, numberOfCheckpoints;
    int numberOfPeaks;
    cin >> numberOfCase; //read the number of test cases
    for(int i = 1; i <= numberOfCase; ++i){
        numberOfPeaks = 0;
        cin >> numberOfCheckpoints; //read the number of check points in this single test case
        if(numberOfCheckpoints == 0) continue; //corner case
        int preHeight, currHeight, futHeight;
        cin >> preHeight; //read the previous height (the first check point's height here)
        for(int j = 2; j < numberOfCheckpoints; ++j){// no need for the first and the last
            if(j == 2){
                cin >> currHeight; //read the current check point's height
                cin >> futHeight; //read the future check point's height
            }else{
                cin >> futHeight;
            }
            if(currHeight > preHeight && currHeight > futHeight){
                numberOfPeaks++;
            }
            preHeight = currHeight;
            currHeight = futHeight;//update the height (for traverse)
        }
        cout<<"Case #"<< i<<": "<<numberOfPeaks<<endl;
    }
    return 0;
}
