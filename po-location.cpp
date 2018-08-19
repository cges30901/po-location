#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc,char* argv[])
{
    ifstream inFile(argv[1]);
    vector<string> list;
    while( !inFile.eof())
    {
        string line;
        getline(inFile,line);
        if(line.find("#: ")==0){
            stringstream ss(line);
            string location;
            while(getline(ss, location, ' ')) {
                if(location!="#:"){
                    //remove line number
                    list.push_back(location.substr(0,location.find(':')));
                }
            }
        }
    }
    sort(list.begin(),list.end());

    string current=list.at(0);
    int count=1;
    for(unsigned int i=1;i<list.size();i++){
        if(list.at(i)!=current){ //different file from last item
            cout<<current<<' '<<count<<endl;
            current=list.at(i);
            count=1; //reset count
        }
        else{
            count+=1;
        }
    }

    inFile.close();
    return 0;
}
