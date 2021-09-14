#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;


void addS(string subject){
    string templine,clss;
    bool isClassexist = false;
    int count=0;
    fstream filein;
    fstream fileout;
 
    if (subject == "math"){
        
        string filesM[] = {"ma.csv","mb.csv","mc.csv","md.csv","me.csv"};
        cout << endl;
        cout << "There are 5 classes in Math stream" << endl<<endl;
       
        cout << "Please Enter the Class Name (ma,mb,mc,md,me) : ";
        getline(cin,clss);
        cout << endl;
   
        for (int cc =0;cc <=5;cc++){
            string clstofile = clss + ".csv";
            if (clstofile == filesM[cc]){
                fileout.open(filesM[cc], ios::out | ios::app);
                filein.open(filesM[cc], ios::in);
                isClassexist = true;
                
            }
               
            }
               
          
        if(isClassexist){
            while(getline(filein,templine)){
                count++;
            }
         
            if (count == 40){
                cout << "The class " << clss << " has maximum number of students" << endl;
            }else{
                bool isContinuo = true;
                while(isContinuo){
                    string data[4] = {};
                    string datatypes[] = {"Name","Combine Math Marks","Physics Marks", "Chemistry Marks"};
                    for (int l = 0 ; l < 4; l++){
                        cout << "Enter the Student " << datatypes[l] << " : ";
                        getline(cin,data[l]);

                        if(data[l] == "done"){
                            isContinuo = false;
                            cout<<endl;
                            break;
                        }
                    }
                    if(isContinuo){
                        fileout << count+1 << ", "<< data[0] << ", " << data[1] << ", " << data[2] << ", " << data[3] << "\n";
                        cout<<endl;
                        cout << "Type 'done' if you want to return to main commands and save data to file" << endl<<endl;
                        count++;
                    }
                    
                }
               
            }

        }else{
            cout << "Wrong Class Name" << endl;
        }
       

    }
    else{
        
        string filesS[] = {"sa.csv","sb.csv","sc.csv"};
        cout << endl;
        cout << "There are 3 classes in Science stream" << endl<<endl;

        cout << "What is the class (sa,sb,sc) : ";
        getline(cin,clss);
        cout << endl;
   
        for (int cc =0;cc <=5;cc++){
            string clstofile = clss + ".csv";
            if (clstofile == filesS[cc]){
                fileout.open(filesS[cc], ios::out | ios::app);
                filein.open(filesS[cc], ios::in);
                isClassexist = true;
              
            }
               
            }
               
          
        if(isClassexist){
            while(getline(filein,templine)){
                count++;
            }
        
            if (count == 40){
                cout << "The class " << clss << " has maximum number of students" << endl;
            }else{
                bool isContinuo = true;
                while (isContinuo){
               
                
                string data[4] = {};
                string datatypes[] = {"Name","Biology Marks","Physics Marks", "Chemistry Marks"};

                for (int l = 0 ; l < 4; l++){
                    cout << "Enter the Student " << datatypes[l] << " : ";
                    getline(cin,data[l]);
                    if(data[l] == "done"){
                        isContinuo = false;
                        cout<<endl;
                        break;
                    }

                }
              
                    if (isContinuo){
                        fileout << count+1 <<", "<< data[0] << ", " << data[1] << ", " << data[2] << ", " << data[3] << "\n";
                        cout << endl;
                        cout << "Type 'done' to return to main commands and save data to file" << endl<<endl;
                        count++;
                    }
                }
            }

        }else{
            cout << "Wrong Class Name" << endl;
        }
    }
}
   

void showData(string stream){
    fstream fileinS;
    string line,value,clss,mainsub,openfile;
    vector<string> data;
    int size;
    string filesM[] = {"ma","mb","mc","md","me"};
    string filesB[] = {"sa","sb","sc"};
    bool isClassexist = false;

    cout <<endl;
    if (stream == "math"){
        size = 5; 
        mainsub = "Mathematics";
    }else{
        size = 3;
        mainsub = "Biology";
    
    }
    cout << endl;
    cout << "====================== " << mainsub << " Stream =====================" << endl<<endl;
    cout << left << setw(4) <<"ID" << setw(7) <<"Class" <<setw(15) << "Name" << setw(14) << mainsub << setw(9) << "Physics" << setw(11) << "Chemistry" << endl;
    for (int f = 0; f < size; f++){
       
        if (stream== "math"){
            openfile = filesM[f]+".csv";
            clss = filesM[f];
        }else{
            openfile = filesB[f]+".csv";  
            clss = filesB[f]; 
        }
      
        fileinS.open(openfile, ios::in);
   
    
        
        while(getline(fileinS,line)){
            stringstream s(line);
            data.clear();
            while(getline(s,value,',')){

                data.push_back(value);
            }  
            cout << left << setw(4) << data[0]<< setw(6) << clss << setw(15) << data[1] << setw(14) << data[2] << setw(10) << data[3] << setw(12) << data[4] << endl;
        }
        fileinS.close();
        cout<< endl;

    }

    
    
}


void rankStudents(string CorS){
    fstream fileinR;
    fstream fileoutR;
    bool isfileexist = false;
    string stream,className,word,line;
    string filesbio[] = {"sa","sb","sc"};
    string filesMath[] = {"ma","mb","mc","md","me"};
    vector<string> row;
    vector<int> totalarr;
    vector<int> alltotalarr;
    vector<int> real;
    vector<string> names;
    vector<string> ids;
    vector<int> mainsubmarks;
    vector<int> phymarks;
    vector<int> chemmarks;
    
    string file,rankfile,subheader;
    map<int,int> ranks;
    map<int,int> ranksSchool;

    
    int mainsub,phy,chem,total,bio,size;
    int mainSubsum = 0;
    int physum = 0;
    int chemsum = 0;
   
    totalarr.clear();

        fileoutR.open("tempory.csv", ios::out);

        if (CorS == "math"){
            size = 5; 
        }else{
            size = 3;
        }
        for (int cc =0;cc < size ;cc++){
            if(CorS == "math"){
                file = filesMath[cc] + ".csv";
                className = filesMath[cc];
                rankfile = "mathRank.csv";
                subheader = "Mathematics Stream";
                
            }else{
                file = filesbio[cc] + ".csv";
                className = filesbio[cc];
                rankfile = "bioRank.csv";
                subheader = "Biology Stream";
                
            }
            
                
            fileinR.open(file, ios::in); 
            real.clear();
            names.clear();
            ids.clear();
            totalarr.clear();
            while(getline(fileinR,line)){

                row.clear();
                stringstream brline(line);
                while(getline(brline,word,',')){
                    row.push_back(word);
                }
                stringstream ma(row[2]);
                stringstream py(row[3]);
                stringstream ch(row[4]);
                ma >> mainsub;
                py >> phy;
                ch >> chem;
                total = mainsub + phy + chem;
                mainSubsum += mainsub;
                physum += phy;
                chemsum += chem;
                
                mainsubmarks.push_back(mainsub);
                phymarks.push_back(phy);
                chemmarks.push_back(chem);
                totalarr.push_back(total);
                alltotalarr.push_back(total);
                real.push_back(total);
                names.push_back(row[1]);
                ids.push_back(row[0]);
            }
            fileinR.close();
            
            //find class ranks according to total marks
            int previousval = 0;
            int ranking = 0;
            sort(totalarr.begin(), totalarr.end(), greater<int>());
           
            //find class ranks and store in a map       
            for (int i = 0; i < totalarr.size();i++){
                
                    if (previousval != totalarr[i]){   
                         ranking ++;
                         ranks.insert(pair <int,int> {totalarr[i],ranking});
                    }
                    previousval = totalarr[i];
            }

            //get class rank from map and store in a file 
            for (int x = 0 ; x < real.size(); x++){
             
                fileoutR << ids[x] << ", " << className << ", " << names[x] << ", "<< real[x] << ", " << ranks[real[x]] << endl;
            }
            
               
        }
        // find mean of each subjects
        double subMeans[3] = {};
    
        double subsize = mainsubmarks.size();
        subMeans[0] = mainSubsum/subsize;
        subMeans[1] = physum/subsize;
        subMeans[2] = chemsum/subsize;
  
        
        // find standart devision of each subject
        double sumOfmainSqure = 0.0;
        double sumOfphySqure = 0.0;
        double sumOfchemSqure = 0.0;
        for (int m = 0 ;  m < subsize ; m++){
            sumOfmainSqure += pow((mainsubmarks[m]-subMeans[0]),2);
            sumOfphySqure += pow((phymarks[m]-subMeans[1]),2);
            sumOfchemSqure += pow((chemmarks[m]-subMeans[2]),2);


        }
        
        double standartDivisons[3] = {};
        standartDivisons[0] = sqrt((sumOfmainSqure/(subsize - 1)));
        standartDivisons[1] = sqrt((sumOfphySqure/(subsize - 1)));
        standartDivisons[2] = sqrt((sumOfchemSqure/(subsize - 1)));

     

        // find Z-core of each three subject and get avg Z-core
        vector<double> zcore;
        vector<double> zcoreTosort;
        for (int z = 0 ; z < subsize;z++){
            double zcores[3] = {};
            zcores[0] = (mainsubmarks[z] - subMeans[0])/standartDivisons[0];
            zcores[1] = (phymarks[z] - subMeans[1])/standartDivisons[1];
            zcores[2] = (chemmarks[z] - subMeans[2])/standartDivisons[2];

            double avgZ = (zcores[0]+zcores[1]+zcores[2])/3;
            
            zcore.push_back(avgZ);
            zcoreTosort.push_back(avgZ);
        }

        map<double,int> zrank;
        sort(zcoreTosort.begin(), zcoreTosort.end(),greater<double>());
        // ranks acoording to z core
        int previousZ = 0;
        int rankingZ = 0;
        for(int zr = 0; zr < zcoreTosort.size(); zr++){
               if (previousZ != zcoreTosort[zr]){   
                        rankingZ ++;
                        zrank.insert(pair <double,int> {zcoreTosort[zr],rankingZ});
                }
                previousZ = zcoreTosort[zr];
            
        }


        row.clear();
        fileinR.close();
        fileoutR.close();

        //find Stream (school) Ranks
        int previousval = 0;
        int ranking = 0;
        sort(alltotalarr.begin(), alltotalarr.end(), greater<int>());
        for (int j = 0 ; j < alltotalarr.size();j++){
                if (previousval != alltotalarr[j]){   
                        ranking ++;
                        ranksSchool.insert(pair <int,int> {alltotalarr[j],ranking});
                }
                previousval = alltotalarr[j];
        }

        fileinR.open("tempory.csv",ios::in);
        fileoutR.open(rankfile,ios::out);
        cout << endl;
        cout << "==============================   " << subheader <<"  ==============================="<<endl<<endl;

        cout << left<< setw(4) << "ID" << setw(7) << "Class" 
        << setw(15) << "Name"<<  setw(7) << "Total" <<  setw(12)  << 
        "Class Rank"<<  setw(13) << "Stream Rank" << right << setw(10) << "Z-Core" << setw(15)<< "Rank(Z-core)" << endl;
        int linecount = 0;
        while(getline(fileinR,line)){
            row.clear();
            stringstream brline(line);
            while(getline(brline,word,',')){
                row.push_back(word);
            }
            stringstream s(row[3]);
            s >> total;
         
            fileoutR << row[0] << ", " << row[1] << ", " << row[2]<< ", "<< row[3] << ", " << row[4]<< ", "<< ranksSchool[total]<< ", " << zcore[linecount] << endl;
            cout << left<< setw(3) << row[0] << setw(6) << row[1] << setw(16) << row[2]<<  setw(7) <<
             row[3] <<  setw(13)  << row[4]<<  setw(13) << ranksSchool[total]<< right << setw(10) << zcore[linecount] <<setw(14) << zrank[zcore[linecount]] << endl;
            linecount ++;

        }
        fileinR.close();
        cout << endl;
        remove("tempory.csv");

}
            

int main(){
    int ex = 1;
    cout << "+--------------------------Instruction--------------------------+" << endl;
    cout << "|          Type 'add math/bio' to add data into files           |"  << endl;
    cout << "|     Type 'rank math/bio' to rank Students and show z-core     |" << endl;
    cout << "|          Type 'show math/bio' to show students marks          |" << endl;
    cout << "|              Type 'exit' to quit from applicaton              |" << endl;
    cout << "|                                                               |" << endl;
    cout << "|           Please Enter data into files before rank            |" << endl;
    cout << "+---------------------------------------------------------------+" << endl<<endl;

    while(ex == 1){
        string commands;
        cout << "COMMAND : ";
        getline(cin,commands);

        vector<string> com;
        string comWord;
        stringstream getCom(commands);
        com.clear();
        while (getline(getCom,comWord, ' ')) {
			com.push_back(comWord);
		}
    

        if (com[0] == "add"){
            if (com[1] == "math"){
                addS("math");
            }else if (com[1] == "bio"){
                addS("bio");
            }else{
                cout << " Wrong Command" << endl;
            }
                
        }else if(com[0]=="show"){
            if (com[1] == "math"){
                showData("math");
            }else if(com[1] == "bio"){
                showData("bio");
            }else{
                cout << " Wrong Command" << endl;
            }
        
        }else if(com[0] == "rank"){
            if (com[1] == "math"){
                rankStudents("math");
            }else if(com[1] == "bio"){
                rankStudents("bio");
            }else{
                cout << " Wrong Command" << endl;
            }
        }
        else if(com[0] == "exit"){
            ex = 0;
        }
       
    }
   
    return 0;
}