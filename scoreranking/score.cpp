#include "iostream"
#include "iomanip"
#include "fstream"
#include "string"
#include "vector"
#include "algorithm"
struct items{
    std::string id;
    std::string name;
    double score;
};
void ssort(std::vector<items> &rank)
{
    if (rank.size()<1)
    {//pass
    }
    else
        for(int i = 0; i < rank.size(); i++)
            for(int j = i+1; j < rank.size(); j++)
                if(rank[i].score < rank[j].score)
                    std::swap(rank[i],rank[j]);
}
int main(int argc, char **)
{
    std::string filename("score.txt");
    //std::cin >> filename;

    std::fstream fptr(filename,std::ios::in);
    if (!fptr)
    {
        std::cerr << "File could not be opened!";
        exit(1);
    }
    std::string inid;
    std::string inname;
    double inscore;
    std::vector<items> rank;//storing scores
    int counter = 0;
    while(fptr >> inid >> inname >> inscore)
    {
        rank.push_back(items());
        rank[counter].id = inid;
        rank[counter].name = inname;
        rank[counter].score = inscore;
        counter++;
    }
    fptr.close();
    ssort(rank);
    std::cout << "Rank  " << std::setw(7) << "ID" << ' ' << std::setw(10) << "Name" << ' ' << std::setw(5) << "Score" << std::endl;
    std::cout << "----  ------- ---------- -----"<< std::endl;
    for(int i=0; i < rank.size(); i++)
    {
        if(rank[i].score == rank[i-1].score)
            //std::cout << "Rank " << std::setw(2) << i << " :";
            std::cout << "     :";
        else
            std::cout << std::setw(4) << i+1 << " :";
        std::cout << std::setw(7) << rank[i].id << ' ' << std::setw(10) << rank[i].name << ' ' << std::setw(5) << rank[i].score << std::endl;
    }
    std::ofstream ofptr("ranked_score.txt");
    for(int i = 0; i < rank.size(); i++)
    {
        ofptr << rank[i].id << ' ' << rank[i].name << ' ' << rank[i].score << std::endl;
    }
    system("pause");
}