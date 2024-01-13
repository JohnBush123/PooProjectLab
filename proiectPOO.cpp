#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <windows.h>
#include <string.h>
#include <chrono>
#include <ctime>

using namespace std;

class FileReader
{
public:
    // Constructor
    FileReader() {}

    // Function to read from a CSV file
    std::vector<std::vector<std::string>> readCSV(const std::string& filename)
    {
        std::vector<std::vector<std::string>> data;
        std::ifstream file(filename);

        if (!file.is_open())
        {
            std::cerr << "Error opening CSV file: " << filename << std::endl;
            return data;
        }

        std::string line;
        while (std::getline(file, line))
        {
            std::vector<std::string> row;
            std::istringstream iss(line);
            std::string field;

            while (std::getline(iss, field, ','))
            {
                row.push_back(field);
            }

            data.push_back(row);
        }

        file.close();
        return data;
    }

    // Function to read from a TXT file
    std::vector<std::string> readTXT(const std::string& filename)
    {
        std::vector<std::string> lines;
        std::ifstream file(filename);

        if (!file.is_open())
        {
            std::cerr << "Error opening TXT file: " << filename << std::endl;
            return lines;
        }

        std::string line;
        while (std::getline(file, line))
        {
            lines.push_back(line);
        }

        file.close();
        return lines;
    }
};


class TITLE
{
public:
    string title;
    string subtitle;
};

class TEXT
{
public:
    string title1;
    string text;
};

class CALCULUS
{
public:
    int num1,num2,r;
    string s;
};
class Display
{
public:
    string data;
};
class CSVTXT
{
public:
    string data;
};
class TextInput
{
public:
    string description;
    string text2;
};
class NUMBER
{
public:
    string descriptionNumber;
    float num;
};
class FLOW : public TITLE, public TEXT, public CALCULUS, public CSVTXT, public TextInput, public NUMBER
{
public:
    int deleteflow()
    {
        system("cls");
        string flowToDel;
        ifstream file("ListOfFlows.txt");
        if (!file.is_open())
        {
            std::cerr << "Error opening the file!" << std::endl;
            return 1;  // Exit the program with an error code
        }
        std::string line;
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }
        file.close();
        cout<<"What flow do you want to delete?\n";
        cin>>flowToDel;
        ifstream fisier("ListOfFlows.txt");
        vector<string> vecStr;
        while(getline(fisier, line))
        {
            if(!(line==flowToDel))
                vecStr.push_back(line);
        }
        for(const auto& l:vecStr){
            cout<<l<<'\n';
        }
        flowToDel=flowToDel+".txt";
        const char* fileDel=flowToDel.c_str();
        if (remove(fileDel) != 0)
        {
            perror("Error deleting the file");//perror afiseaza la final :no such file or directory
            return 1;
        }
        else
        {
            std::cout << "File deleted successfully." << std::endl;
        }
        fisier.close();

        ofstream fisier1("ListOfFlows.txt");
        for(const auto& l : vecStr){
            fisier1<<l<<'\n';
        }
        fisier1.close();
        return 0;
    }
    void creareflow()
    {
        string titluF, descriereF;
        cout << "What is the name for the document where the flow is gonna be saved? \n";
        cin >> titluF;
        ofstream fisier("ListOfFlows.txt", std::ios::app);
        fisier<<titluF<<endl;
        fisier.close();
        titluF = titluF + ".txt";

        ofstream outputFile(titluF);

        if (!outputFile)
        {
            cerr << "Error opening file: " << titluF << endl;
            return;
        }

        cout << "Give the flow a description on a line: ";
        cin.ignore(); // Ignoră newline-ul rămas în buffer după citirea anterioară
        getline(cin, descriereF);

        int y = 1;

        cout << "What steps do you want to add?\n"
             << "1. Title step (introduce a title and a subtitle)\n"
             << "2. Text step (introduce a title and a copy of a paragraph)\n"
             << "3. Text input (introduce a paragraph that describes something)\n"
             << "4. Number input (introduce numbers)\n"
             << "5. Calculus input (in this step you add some numbers and make some relevant math)\n"
             << "6. Display step (in this step you can display something from a document)\n"
             << "7. OUTPUT step (this step saves your data in a txt file)\n"
             << "0. END flow step (this is the step you add at the end)\n"
             << "Press the index of the steps so you can select the steps you want: \n";


        while (y != 0)
        {

            cin >>y;

            // Adaugă valoarea lui y pe prima linie a fișierului
            outputFile<<y;
            if(y==0)
            {
                outputFile<<'\n';
                outputFile<<0<<"-this is how many times the flow was completed"<<'\n';
                break;
            }
        }
        auto now = std::chrono::system_clock::now();

        // Convert the current timepoint to a time_t type
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);


        // Convert the time_t value to a struct tm
        std::tm* localTime = std::localtime(&currentTime);

        // Extract the current hour and minute from the struct tm
        int currentHour = localTime->tm_hour;
        int currentMinute = localTime->tm_min;
        outputFile<<"Time of creation: "<<currentHour<<":"<<currentMinute<<'\n';
        outputFile << descriereF << endl;

        // Închide fișierul la finalul procesului
        outputFile.close();
    }

    int completareflow()
    {
        cout<<"Existing flow:\n";

        ifstream file("ListOfFlows.txt");

        if (!file.is_open())
        {
            std::cerr << "Error opening the file!" << std::endl;
            return 1;  // Exit the program with an error code
        }

        std::string line;
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }
        string flowT;
        cout<<"What flow do you want to acces?(add the name without the extension)\n";
        cin>>flowT;
        flowT=flowT+".txt";
        char a;
        int i,v[10],w[10],ok=0;
        for(i=0; i<10; i++)
        {
            v[i]=0;
            w[i]=0;
        }
        i=0;
        ifstream inputFile(flowT);
        while(inputFile.get(a))
        {
            if(a=='0')
                break;
            else if(a=='1')
            {
                system("cls");
                v[i]=int(a)-48;
                int q;
                cout<<"\nYou have to do the title step.\n Press 1 to execute\n Press2 to skip\n;";
                cin>>q;
                w[i]=q;
                i++;
                if(q==1)
                {
                    cout<<"Give us the title:\n";
                    cin>>title;
                    cout<<"Give us the subtitle:\n";
                    cin>>subtitle;
                }
                else if(q==2)
                {
                    cout<<"Step skiped!";
                }
            }
            else if(a=='2')
            {
                system("cls");
                v[i]=int(a)-48;
                int q;
                cout<<"You have to do the title step.\n Press 1 to execute\n Press2 to skip\n";
                cin>>q;
                w[i]=q;
                i++;
                if(q==1)
                {
                    cout<<"Give us the title:\n";
                    cin>>title1;
                    cout<<"Give us the paragraph(add the text and to end the input press 0):\n";
                    char caracter;
                    while (true)
                    {
                        caracter=getchar();
                        if (caracter == '0')
                        {
                            break;
                        }
                        text += caracter;
                    }
                }
                else if(q==2)
                {
                    cout<<"Step skiped!";
                }
            }
            else if (a == '3')
            {
                system("cls");
                v[i]=int(a)-48;
                int q;
                cout<<"This is the text input step. You have to add a description and a text.\nPress 1 to execute.\nPress 2 to skip\n";
                cin>>q;
                w[i]=q;
                i++;
                if(q==1)
                {
                    cout<<"Give us the description on a line:\n";
                    getchar();
                    getline(cin, description);
                    cout<<"Give us the text(add the text and to end the input press 0):\n";
                    char caracter;
                    while (true)
                    {
                        caracter=getchar();
                        if (caracter == '0')
                        {
                            break;
                        }
                        text2 += caracter;
                    }

                }
                else if(q==2)
                {
                    cout<<"Step skiped!";
                }

            }
            else if (a == '4')
            {
                system("cls");
                int q;
                v[i]=int(a)-48;
                cout<<"This is the NUMBER input step. You have to add a description of the number meaning, and the number.\n Press 1 to execute.\n Press 2 to skip.\n";
                cin>>q;
                w[i]=q;
                i++;
                if(q==1)
                {
                    cout<<"Give us the description on a line:\n";
                    getchar();
                    getline(cin, descriptionNumber);
                    cout<<"Give us the number:\n";
                    cin>>num;
                }
                else if(q==2)
                {
                    cout<<"Step skiped!";
                }
            }
            else if (a == '5')
            {
                system("cls");
                v[i]=int(a)-48;
                int q;
                cout<<"This is CALCULUS step. You have to add 2 numbers and the type of calculus you want to do (min,max,+,-,*,/).\nPress 1 to execute/\nPress 2 to skip.\n";
                cin>>q;
                w[i]=q;
                i++;
                if(q==1)
                {
                    cout<<"Give us the numbers:(one space between the numbers)\n";
                    cin>>num1>>num2;
                    cout<<"Give us the type of the calculus:\n";
                    cin>>s;
                    if(s[0]=='+')
                        r=num1+num2;
                    else if(s[0]=='-')
                        r=num1-num2;
                    else if(s[0]=='*')
                        r=num1*num2;
                    else if(s[0]=='/')
                        r=num1/num2;
                    else if(s[1]=='i')
                        r=min(num1,num2);
                    else if(s[1]=='a')
                        r=max(num1,num2);


                    cout<<"This is your result: "<<r;
                }
                else if(q==2)
                {
                    cout<<"Step skiped!";
                }
            }
            else if (a == '6')
            {
                system("cls");
                v[i]=int(a)-48;
                string y;
                cout<<"Do you want to display information from a file?(press1)\nSkip(press2)\n";
                cin>>y;
                w[i]=int(y[0])-48;
                i++;

                if(y=="1")
                {
                    string k;
                    system("cls");
                    cout<<"From a txt(press1)\nFrom a csv(press2)\nCancel action(press0)\n";
                    cin>>k;
                    if(k[0]=='0')
                    {
                        cout<<"Action canceled!\n";
                    }
                    else if(k[0]='1')
                    {
                        ok=1;
                        cout<<"Give us the file adress:\n";
                        string adress;
                        cin>>adress;
                        FileReader reader;
                        vector<string> txtData = reader.readTXT(adress);
                        for (const auto& line : txtData)
                        {
                            cout << line << endl;
                            data +=line;
                        }

                    }
                    else if(k[0]=='2')
                    {
                        ok=2;
                        cout<<"Give us the file adress:\n";
                        string adress;
                        cin>>adress;
                        FileReader reader;
                        vector<vector<string>> csvData = reader.readCSV(adress);
                        for (const auto& row : csvData)
                        {
                            for (const auto& field : row)
                            {
                                cout << field << "\t";
                                data +=field;
                            }
                            cout << endl;
                        }
                    }
                }
            }
            else if (a == '7')
            {

                int nr_completari;
                vector<string> vectorDeLinii;
                cout<<"This is the output step. All the information you used/created will be saved in the flow file.\n";
                ifstream file1(flowT);
                if(!file.is_open())
                {
                    cerr<<"Erorr with the file openning.";
                    return 1;
                }
                else
                {
                    string linie;
                    while (std::getline(file1, linie))
                    {
                        vectorDeLinii.push_back(linie);
                    }
                    nr_completari=int(vectorDeLinii[1][0])-48;
                    nr_completari=nr_completari+49;
                    vectorDeLinii[1][0]=static_cast<char>(nr_completari);
                }
                ofstream outPut(flowT);
                outPut<<vectorDeLinii[0]<<'\n';
                outPut<<vectorDeLinii[1]<<'\n';
                outPut<<vectorDeLinii[2]<<'\n';
                outPut<<vectorDeLinii[3]<<'\n';
                for(int j=0; j<i; j++)
                {
                    if (v[j] == 1)
                    {
                        cout << "This is the title step." << endl;
                        outPut << "This is the title step." << endl;
                        if (w[j] == 1)
                        {
                            cout << "Title: " << title << endl;
                            outPut << "Title: " << title << endl;
                            cout << "Subtitle: " << subtitle << endl;
                            outPut << "Subtitle: " << subtitle << endl;
                        }
                        else if (w[j] == 2)
                        {
                            cout << "Skipped step!" << endl;
                            outPut << "Skipped step!" << endl;
                        }
                    }
                    else if (v[j] == 2)
                    {
                        cout << "This is the text step." << endl;
                        outPut << "This is the text step." << endl;
                        if (w[j] == 1)
                        {
                            cout << "Title: " << title1 << endl;
                            outPut << "Title: " << title1 << endl;
                            cout << "Text: " << text << endl;
                            outPut << "Text: " << text << endl;
                        }
                        else if (w[j] == 2)
                        {
                            cout << "Skipped step!" << endl;
                            outPut << "Skipped step!" << endl;
                        }
                    }
                    else if (v[j] == 3)
                    {
                        cout << "This is the text input step." << endl;
                        outPut << "This is the text input step." << endl;
                        if (w[j] == 1)
                        {
                            cout << "Description: " << description << endl;
                            outPut << "Description: " << description << endl;
                            cout << "Text: " << text2 << endl;
                            outPut << "Text: " << text2 << endl;
                        }
                        else if (w[j] == 2)
                        {
                            cout << "Skipped step!" << endl;
                            outPut << "Skipped step!" << endl;
                        }
                    }
                    else if (v[j] == 4)
                    {
                        cout << "This is the number input step." << endl;
                        outPut << "This is the number input step." << endl;
                        if (w[j] == 1)
                        {
                            cout << "Description: " << descriptionNumber << endl;
                            outPut << "Description: " << descriptionNumber << endl;
                            cout << "Number: " << num << endl;
                            outPut << "Number: " << num << endl;
                        }
                        else if (w[j] == 2)
                        {
                            cout << "Skipped step!" << endl;
                            outPut << "Skipped step!" << endl;
                        }
                    }
                    else if (v[j] == 5)
                    {
                        cout << "This is the calculus step." << endl;
                        outPut << "This is the calculus step." << endl;
                        if (w[j] == 1)
                        {
                            cout << "This is the equation: " << num1 << s << num2 << '=' << r << endl;
                            outPut << "This is the equation: " << num1 << s << num2 << '=' << r << endl;
                        }
                        else if (w[j] == 2)
                        {
                            cout << "Skipped step!" << endl;
                            outPut << "Skipped step!" << endl;
                        }
                    }
                    else if (v[j] == 6)
                    {
                        cout << "This is the display step." << endl;
                        outPut << "This is the display step." << endl;
                        if (w[j] == 1)
                        {
                            if (ok == 1)
                            {
                                cout << "You display from a TXT." << endl;
                                outPut << "You display from a TXT." << endl;
                                cout << "Data: " << data << endl;
                                outPut << "Data: " << data << endl;
                            }
                            else if (ok == 2)
                            {
                                cout << "You display from a CSV." << endl;
                                outPut << "You display from a CSV." << endl;
                                cout << "Data: " << data << endl;
                                outPut << "Data: " << data << endl;
                            }
                        }
                        else if (w[j] == 2)
                        {
                            cout << "Skipped step!" << endl;
                            outPut << "Skipped step!" << endl;
                        }
                    }

                }

            }
        }
    }
};

int main ()
{
    string x;
    cout<<"Do you want to create a new flow?(press1)\nDo you want to use an existing flow?(press2)\nDo you want to delete a flow?(press3)\nExit(press0)\n";
    cin>>x;
    FLOW f;
    while(x.length()>1 && x[0]!='1' && x[0]!='2')
    {
        cout<<"Incorect input!\n";
        cin>>x;
    }
    if(x[0]=='1')
    {
        f.creareflow();
    }
    else if(x[0]=='2')
    {
        f.completareflow();
    }
    else if(x[0]=='3')
    {
        f.deleteflow();
    }
    else if(x[0]=='0')
    {
        cout<<"Programe closed!";
        return 0;
    }

    return 0;
}
