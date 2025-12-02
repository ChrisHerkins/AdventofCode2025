#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int degreeTurn(bool left, int currentDegree, int turnDegree){
  if(left){
    currentDegree = (currentDegree - turnDegree);
  }
  else{
    currentDegree = (currentDegree + turnDegree);
  }
  while(currentDegree < 0){
      currentDegree += 100;
  }
  while(currentDegree > 99){
      currentDegree -= 100;
  }
  return currentDegree;
}

int main(){
  string ifile;
  cout<<"Input file name: ";
  cin>>ifile;
  ifstream infile(ifile);
  string line;
  int number;
  int count = 0;
  while(getline(infile,line)){
    bool left = line.substr(0,1) == "L";
    number = degreeTurn(left, number, stoi(line.substr(1)));
    if (number == 0){
      count++;
    }
  }
  infile.close();
  cout<<count<<endl;
  return 0;
}
