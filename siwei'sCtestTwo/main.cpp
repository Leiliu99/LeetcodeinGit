#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int monthToDay[12] ={31,28,31,30,31,30,31,31,30,31,30,31};
    int numberOfcase;
    ifstream inFile;
    inFile.open("/Users/liulei/Desktop/siwei'sCtestTwo/input.txt");
    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }
    inFile >> numberOfcase; //read the number of test cases
    cout<<"=== Test Number: "<< numberOfcase<<" ==="<<endl;
    for(int testorder = 0; testorder < numberOfcase; testorder++){
        int testCase;
        inFile >> testCase;
        cout<<"=== Case #"<< testCase<<" ==="<<endl;
        for(int order = 0; order < 2; order++){
            int year, month, day, hour, min, sec;
            inFile >> year;
            inFile >> month;
            inFile >> day;
            inFile >> hour;
            inFile >> min;
            inFile >> sec;
            int leapday = 0;
            //cout<<year<<endl;
            if(month < 2 || (month == 2 && day < 29)){
                for(int yearTest = 1970; yearTest < year; yearTest++){
                    if( (yearTest % 100 != 0 && yearTest % 4 == 0) || yearTest %400 == 0){
                        leapday ++;
                    }
                }
            }else{
                for(int yearTest = 1970; yearTest <= year; yearTest++){
                    if( (yearTest % 100 != 0 && yearTest % 4 == 0) || yearTest %400 == 0){
                        leapday ++;
                    }
                }
            }
            //cout<< leapday<<endl;
            int yearDiffereceSec = ((year - 1970) * 365 + leapday)* 24 * 3600;
            int monthDifferenceSec = 0;
            if(month > 1){
                for(int i = 0; i < (month - 1); i++){
                    monthDifferenceSec += monthToDay[i];
                }
            }
            monthDifferenceSec *= 24 * 3600;
            int dayDifferenceSec = (day - 1) * 24 * 3600;
            int hourDifferenceSec = hour * 3600;
            int minDifferenceSec = min * 60;
            int answer = yearDiffereceSec + monthDifferenceSec + dayDifferenceSec + hourDifferenceSec + minDifferenceSec + sec;
            cout<<answer<<endl;
        }
        cout<<"=== END ==="<<endl;
    }
    inFile.close();
    return 0;
}
