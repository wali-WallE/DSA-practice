#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PracticeVector{
private: 
vector<double> v;
public:

    void Insert(double amount){
    v.push_back(amount);
    }

    void deleteT(int index){
        cout<< "original : ";
        for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";}
        cout << endl;

        if (index >= 0 && index < v.size()) {
        v.erase(v.begin() + index);
        } else {
        cout << "Invalid index!" << endl;
        }
        
        cout << "after deleting : ";
        for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
        }
        cout << endl;

    }

    void findUpdate(double oldVal, double newVal){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == old){
            v[i] = new; 
        }
    }
    cout << "after updating : ";
    for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
    }
    cout << endl;

}
    void calculateStats(){
    int count = v.size();
    
    cout << "Count of transactions is: " << count << endl;
    
    double maxi = v[0];
    double mini = v[0];
    for(int i = 0; i < v.size(); i++){
        if(v[i] > maxi ){maxi = v[i];}
        if(v[i] < mini ){mini = v[i];}
    }
    cout << "Maximum is : " << maxi << endl;
    cout << "Minimum is : " << mini << endl;
    int total = 0;
    int average;
    for(int i = 0; i < v.size(); i++){
        total += v[i];
        average = total/v.size();     
    }
        cout << "average is : " << average << endl;   
    }

    void Display(bool ascending){
        for(int i = 0; i<v.size()-1; i++){
            for(int j = 0; j<v.size()-i-1; j++){
                if(ascending && v[j] > v[j+1]){
                    double temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                }
                if(!ascending && v[j] < v[j+1]){
                    double temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                }
            }
        }
        if(ascending) cout << "ascending sorted : ";
        else cout << "descending sorted : ";

        for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    PracticeVector pv;
    pv.Insert(2500);
    pv.Insert(3200);
    pv.Insert(1800);
    pv.Insert(2500);
    pv.Insert(4000);

    pv.deleteT(2);

    pv.findUpdate(2500,2600);
    pv.calculateStats();
    pv.Display(false);
}
